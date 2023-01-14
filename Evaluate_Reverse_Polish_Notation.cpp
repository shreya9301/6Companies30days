//DAY - 1

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        // if(n == 1 and (stoi(tokens[0]) >= -200 and stoi(tokens[0] <= 200)))
        //     return stoi(tokens[0]);
        stack<int> st;
        int i = 0;
        while(i < n){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                int res;
                switch(tokens[i][0]){
                    case '+' : res = op1 + op2;
                        break;
                    case '-' : res = op2 - op1;
                        break;
                    case '*' : res = op1 * op2;
                        break;
                    case '/' : res = op2 / op1;
                        break;
                    default : res = 0;
                }
                st.push(res);
            }else
                st.push(stoi(tokens[i]));
            i++;
        }
        return st.top();
    }
};
