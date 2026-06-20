class Solution {
public:
    void backtrack(int n, vector<string>& result, string& path, int openParens, int closeParens) {
        // base case:
        if (openParens == n && closeParens == n) {
            result.push_back(path);
            return;
        }
        if (openParens > n || closeParens > n) {
            return;
        }
        if (openParens < n) {
            path.push_back('(');
            backtrack(n, result, path, openParens + 1, closeParens);
            path.pop_back();
        }
        if (closeParens < openParens) {
            path.push_back(')');
            backtrack(n, result, path, openParens, closeParens + 1);
            path.pop_back();
        }
    }
// public:
//     void backtrack(int n, vector<string>& result, string path, int openParens, int closeParens) {
//         // base case:
//         if (openParens == n && closeParens == n) {
//             result.push_back(path);
//             return;
//         }
//         if (openParens > n || closeParens > n) {
//             return;
//         }
//         if (openParens < n) {
//             backtrack(n, result, path + "(", openParens + 1, closeParens);
//         }
//         if (closeParens < openParens) {
//             backtrack(n, result, path + ")", openParens, closeParens + 1);
//         }
//     }
    vector<string> generateParenthesis(int n) {
        // (), n = 1
        // ()(), (()), n = 2
        // ()()(), ((())), (()()), ()(()), (())() n = 3
        // (), ((
        // 1. l(open) < n   
        // 2. l(open) > l(close)

        // 1.base: len of open == len of close == n -> append current option to the result
        // 2. l(open) > n || l(close) > n: return -> not want to explore anymore
        // 3. l(open) > l(close) -> add more close parens -> satisfy cond 
        // 4. l(close) > l(open): ()) -> never reach requirement -> not satisfy cond -> BACKTRACK until l(open) == l(close)
        vector<string> result;
        string path = "";
        backtrack(n, result, path, 0, 0);
        return result;
    }
};
