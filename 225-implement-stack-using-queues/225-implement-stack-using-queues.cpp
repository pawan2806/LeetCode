class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    
    void gg(queue<int> &q){
        if(q.empty()){
            return ;
        }
        int x=q.front();
        q.pop();
        gg(q);
        q.push(x);
        
    }
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {

        gg(q1);
        int x=q1.front();
        q1.pop();
        gg(q1);
        return x;
    }
    
    /** Get the top element. */
    int top() {
        gg(q1);
        int x=q1.front();
         gg(q1);
        return x;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */