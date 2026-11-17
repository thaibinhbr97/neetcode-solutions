/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> levelOrder(TreeNode* root) {
        // // bfs
        // // time: O(n)
        // // space: O(n)
        // vector<vector<int>> result;
        // if (!root) return result;

        // queue<TreeNode*> q;
        // q.push(root);
        
        // while (!q.empty()) {
        //     vector<int> level;
        //     int size = q.size();

        //     for (int i = size; i > 0; i--) {
        //         TreeNode* node = q.front();
        //         q.pop();
        //         if (node) {
        //             if (node->left) q.push(node->left);
        //             if (node->right) q.push(node->right);
        //             level.push_back(node->val);
        //         }
        //     }
        //     result.push_back(level);
        // }
        // return result;

        // dfs
        // time:
        // space:
        dfs(root, 0);
        return result;
    }
    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        if (result.size() == depth) {
            result.push_back(vector<int>{});
        }
        result[depth].push_back(node->val);
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }

};
