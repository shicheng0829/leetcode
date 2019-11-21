class Foo
{
public:
    Foo()
    {
        count = 1;
    }
    std::mutex m;
    std::condition_variable cv;
    int count = 0;
    void first(function<void()> printFirst)
    {

        // printFirst() outputs "first". Do not change or remove this line.
        unique_lock<mutex> lk(m);
        cv.wait(lk, [this] { return count == 1; });
        count++;
        printFirst();
        lk.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond)
    {

        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex> lk(m);
        cv.wait(lk, [this] { return count == 2; });
        count++;
        printSecond();
        lk.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird)
    {

        // printThird() outputs "third". Do not change or remove this line.
        unique_lock<mutex> lk(m);
        cv.wait(lk, [this] { return count == 3; });
        count++;
        printThird();
        lk.unlock();
        cv.notify_all();
    }
};