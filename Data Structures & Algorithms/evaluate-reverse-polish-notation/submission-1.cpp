class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // see integer -> push to stack; otherwise (see operator), pop two numbers from stack
        // and do calculation, then push the result back to the stack
        // the last result is we need after all calculation
        // time: O(n), space: O(n)
        stack<int> st;
        for (const string& token: tokens) {
            // if token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                if (token == "+") st.push(num1 + num2);
                else if (token == "-") st.push(num1 - num2);
                else if (token == "*") st.push(num1 * num2);
                else if (token == "/") st.push(num1 / num2);
            } 
            // if it is not an operator, it's a multi digit number (positive or negative)
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
