class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }

        stack<char> myStack;
        unordered_map<char, char> charMap;
        charMap['('] = ')';
        charMap['{'] = '}';
        charMap['['] = ']';

        for (char c: s) {
            if (c == ')' || c == ']' || c == '}') {
                if (myStack.empty()) {
                    return false;
                }
                char top = myStack.top();
                if (charMap[top] != c) {
                    return false;
                } else {
                    myStack.pop();
                }
            } else {
                myStack.push(c);
            }
        }

        return myStack.empty();
    }
};
