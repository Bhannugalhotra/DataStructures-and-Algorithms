class MedianFinder
{
    priority_queue<int>  max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    
public:
    
    void addNum(int num)
    {
        if(max_heap.empty() or num <= max_heap.top())
            max_heap.push(num);
        
        else
            min_heap.push(num);
        
        if(max_heap.size() > min_heap.size() + 1)
            min_heap.push(max_heap.top()), max_heap.pop();
        
        else if(min_heap.size() > max_heap.size())
            max_heap.push(min_heap.top()), min_heap.pop();
    }
    
    double findMedian()
    {
        double ans;
        
        if(max_heap.size() > min_heap.size())
            ans = max_heap.top();
        
        else
            ans = double(max_heap.top() + min_heap.top()) / 2;
        
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */