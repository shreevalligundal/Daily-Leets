class Solution {
public:
    string removeDuplicates(string s) {
        int top = -1;
        for(int i =0 ; i < s.size(); i++){
            if(top >= 0 && s[top] == s[i]){
                top--;
            }else{
                s[++top] = s[i];
            }
        }
        return s.substr(0, top + 1);
    }
};