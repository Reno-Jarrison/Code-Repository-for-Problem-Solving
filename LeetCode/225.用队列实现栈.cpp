class MyStack {
public:
    queue<int> q;
    void push(int x) {
        int size = q.size();
        q.push(x);
        while (size--)
            q.push(q.front()), q.pop();
    }
    int pop() {
        int ans = q.front();
        q.pop();
        return ans;
    }
    int top() { 
        return q.front(); 
    }
    bool empty() {
        return q.empty(); 
    }
};