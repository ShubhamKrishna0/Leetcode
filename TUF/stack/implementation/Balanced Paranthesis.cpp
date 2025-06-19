#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    bool isMatched(char open , char close){
        if((open == '(' && close == ')')||
          (open == '{' && close == '}')||
          (open == '[' && close == ']')
    )
            return true;
        return false;
    }

    public:
    bool isValid(string str) {
        stack<char> st;

        for (int i = 0; i < str.length(); i++) {
            if(str[i]=='('||str[i]=='['||str[i]=='{'){
                st.push(str[i]);
            }
            //else if closing bracket is found
            else{
                if(st.empty())
                    return false;

                char ch = st.top();
                st.pop();

                if(!isMatched(ch , str[i]))
                    return false;
            }
        }
        return st.empty();
    }
};