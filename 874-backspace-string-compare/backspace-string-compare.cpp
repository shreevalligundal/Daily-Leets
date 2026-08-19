class Solution {
public:
    string build(string s){
        stack<int> st;
        for(char ch : s){
            if(ch != '#'){
                st.push(ch);
            }else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        return build(s)==build(t);
    }
};


/* 1. Intuition

The # character acts like the Backspace key.
Whenever we encounter:
A normal character → Add it.
# → Remove the last character (if any).
A stack naturally supports this behavior because:
Push → Typing a character.
Pop → Pressing backspace.
After processing both strings, compare the final results.

2. Approach
Create two stacks (or build two processed strings).
Traverse the first string:
If the character is not #, push it.
If the character is # and the stack is not empty, pop.
Repeat the same process for the second string.
Compare the processed strings.
If they are equal, return true; otherwise, return false.

3. Why This Works
The stack always contains the characters that remain after applying all backspaces.
Whenever # appears:
The most recently added character is removed.
This exactly mimics the behavior of a text editor.

4. Algorithm
Create an empty stack.
For every character:
    If character != '#'
        Push
    Else
        If stack is not empty
            Pop
Repeat for both strings.
Compare the final processed strings.

Complexity
Time Complexity : O(n+m)
Space Complexity: O(n+m)
*/