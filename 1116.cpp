class ZeroEvenOdd
{
private:
    int n;
    int count = 1;
    bool iszero = true;
    mutex m;
    condition_variable cv;

public:
    ZeroEvenOdd(int n)
    {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber)
    {
        while (count <= n)
        {
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this] { return iszero == true; });
            if (count <= n)
            {
                printNumber(0);
            }
            iszero = false;
            lk.unlock();
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber)
    {
        while (count <= n)
        {
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this] { return iszero == false && count % 2 == 0; });
            if (count <= n)
            {
                printNumber(count);
                count++;
                iszero = true;
            }
            lk.unlock();
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber)
    {
        while (count <= n)
        {
            unique_lock<mutex> lk(m);
            cv.wait(lk, [this] { return iszero == false && count % 2 == 1; });
            if (count <= n)
            {
                printNumber(count);
                count++;
                iszero = true;
            }
            lk.unlock();
            cv.notify_all();
        }
    }
};