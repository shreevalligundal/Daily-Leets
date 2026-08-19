class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i = 2*n-1;i>=0;i--){
            int num = nums[i%n];
            while(!st.empty() && st.top() <= num){
                st.pop();
            }
            if(i<n && !st.empty()){
                ans[i] = st.top();
            }
            st.push(num);
        }
        return ans;
        
    }
};

/*
Key Takeaways
Do not physically duplicate the array.
Simulate doubling using i % n.
Traverse from 2*n - 1 down to 0.
Store indices in the stack so you can access values and maintain positions.

Why This Works
Traversing twice simulates a circular array.
The stack always contains indices of elements greater than the current element.
Smaller or equal elements are removed because they can never be the next greater element.
During the second half of the traversal (the "virtual" extra copy), we only prepare the stack.
During the first half (i < n), we compute the final answers

Complexity
Time Complexity : O(n)
Space Complexity : O(n)

Each index is:
pushed at most twice (once in each traversal),
popped at most twice.
Overall operations are proportional to 2n, which simplifies to O(n)

Approach
Create an answer array initialized with -1.
Create an empty stack to store indices.
Traverse from 2*n - 1 to 0.
Find the actual index using:
idx = i % n;
Remove all elements from the stack that are less than or equal to the current element.
If the stack is not empty, its top is the next greater element.
Store the answer only during the first pass (i < n).
Push the current index onto the stack.

Algorithm :
Create answer array with -1.
Create empty stack.
Traverse from (2*n - 1) to 0.
    idx = i % n
    While stack is not empty AND
          nums[stack.top()] <= nums[idx]:
            Pop
    If i < n:
        If stack is not empty:
            ans[idx] = nums[stack.top()]
    Push idx.
Return answer.

*/