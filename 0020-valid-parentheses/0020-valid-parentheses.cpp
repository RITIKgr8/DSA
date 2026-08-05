class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        while(s[i] != '\0'){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else{
                if(st.empty()){
                    return false;
                }
                char top = st.top();
                if((top == '(' && s[i] == ')') || (top == '{' && s[i] == '}') || (top == '[' && s[i] == ']')){
                    st.pop();
                }else{
                    return false;
                }
            }
            i++;
        }
        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};