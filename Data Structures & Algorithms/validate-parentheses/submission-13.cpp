class Solution {
public:
    bool isValid(string s) {
        // f (s.size() % 2 == 1) {
        //     return false;
        // }

        // stack<char> myStack;
        // unordered_map<char, char> charMap;
        // charMap['('] = ')';
        // charMap['{'] = '}';
        // charMap['['] = ']';

        // for (char c: s) {
        //     if (c == ')' || c == ']' || c == '}') {
        //         if (myStack.empty()) {
        //             return false;
        //         }
        //         char top = myStack.top();
        //         if (charMap[top] != c) {
        //             return false;
        //         } else {
        //             myStack.pop();
        //         }
        //     } else {
        //         myStack.push(c);
        //     }
        // }
        // return myStack.empty();

        // time: O(n), space: O(1)
        stack<char> st;
        unordered_map<char,char> parenMap;
        parenMap[')'] = '(';
        parenMap['}'] = '{';
        parenMap[']'] = '[';
        for (char ch: s) {
            if (parenMap.count(ch)) {
                if (st.empty() || st.top() != parenMap[ch]) {
                    return false;
                }
                st.pop();
            } else {
                st.push(ch);
            }
        }
        return st.empty();
    }
};
