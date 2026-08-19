class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*
        Traverse from right to left.
        For every temperature:
        Remove all temperatures that are
        less than or equal to the current temperature.
        If the stack is not empty:
        answer[i] = stack.top() - i
        Push current index.
        */
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i = n -1; i>=0; i--){
            while(!st.empty() && temperatures[i] >= temperatures[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};