class MedianFinder
{
public:
    /** initialize your data structure here. */
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        less.push(num);
        more.push(less.top());
        less.pop();
        if (more.size() > less.size())
        {
            less.push(more.top());
            more.pop();
        }
    }

    double findMedian()
    {
        if (less.size() == more.size())
        {
            return (less.top() + more.top()) * 0.5;
        }
        else
        {
            return less.top();
        }
    }
    priority_queue<int> less;
    priority_queue<int, vector<int>, greater<int>> more;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */