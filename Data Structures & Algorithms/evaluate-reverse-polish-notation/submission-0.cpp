class Solution {
public:
    bool isOP(string op){
        return op == "+" || op == "-" || op == "*" || op == "/";
    }
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stk;
        for(string &s : tokens){
            if(isOP(s)){
                int val1 = stk.top(); stk.pop();
                int val2 = stk.top(); stk.pop();
                if(s == "+") stk.push(val1 + val2);
                else if(s == "-") stk.push(val2 - val1);
                else if(s == "*") stk.push(val2 * val1);
                else if(s == "/") stk.push(val2 / val1);
            }else stk.push(stoi(s));
        }
        return stk.top();
    }
};
