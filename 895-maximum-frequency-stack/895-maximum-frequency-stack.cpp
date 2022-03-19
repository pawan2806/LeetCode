class FreqStack
{
    public:
       	// map<int, vector < int>> m;
       	// stack<int> s;
       	// map<int, int> mfreq;
       	// int count = 0;
        map<int, stack < int>> freqStack;
        map<int, int> freqMap;
        int maxcount = 0;
        FreqStack() {}

    void push(int val)
    {
        freqMap[val]++;
        maxcount = max(maxcount, freqMap[val]);
        freqStack[freqMap[val]].push(val);

    }

    int pop()
    {
        
       int ret = freqStack[maxcount].top();
        freqStack[maxcount].pop();
        freqMap[ret]--;
        if(freqStack[maxcount].empty())
            maxcount--;
        return ret;

    }
};

/**
 *Your FreqStack object will be instantiated and called as such:
 *FreqStack* obj = new FreqStack();
 *obj->push(val);
 *int param_2 = obj->pop();
 */