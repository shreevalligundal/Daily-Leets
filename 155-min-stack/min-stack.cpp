class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(minst.empty()){
            minst.push(value);
        }else{
            minst.push(min(value, minst.top()));
        }

        
    }
    
    void pop() {
        st.pop();
        minst.pop();
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
/*
Problem

Design a stack that supports:
push(x)
pop()
top()
getMin()

The important requirement is:
getMin() must return the minimum element in O(1) time

Pattern
Stack + Auxiliary Stack

Main Idea
Use a second stack to keep track of the minimum value corresponding to every state of the main stack.
Maintain a second stack called minStack.
Normal stack → stores all elements.
minStack → stores the minimum element at each stage

Main Stack:
"What elements are present?"

Min Stack:
"What is the minimum at this exact stack level?"

3. Approach
push(x)
Push x into the normal stack.
If minStack is empty, push x.
Otherwise compare x with minStack.top().
Push the smaller value into minStack.
pop()

When we remove the top element:

Pop from the normal stack.
Pop from minStack as well.

Because both stacks represent the same sequence of operations



*/












/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */