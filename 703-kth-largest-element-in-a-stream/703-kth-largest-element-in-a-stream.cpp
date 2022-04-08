class KthLargest
{
    public:
        priority_queue<int, vector < int>, greater < int>> pq;
    int gg = 0;
    KthLargest(int k, vector<int> &nums)
    {

        gg = k;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
        }
    }

    int add(int val)
    {
        while (pq.size() && pq.size() > gg)
        {
            pq.pop();
        }
        if (pq.size() < gg)
        {
            pq.push(val);
            return pq.top();
        }
       	//cout << pq.top() << endl;

        int x = pq.top();
        if (x > val)
        {
            return x;
        }
        else
        {

            pq.pop();
            pq.push(val);
            return pq.top();
        }
    }
};

/**
 *Your KthLargest object will be instantiated and called as such:
 *KthLargest* obj = new KthLargest(k, nums);
 *int param_1 = obj->add(val);
 */