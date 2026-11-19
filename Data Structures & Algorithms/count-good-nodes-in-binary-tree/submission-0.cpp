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
int result = 0;
public:
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        dfs(root, root->val);
        return result;
    }
    void dfs(TreeNode* node, int maxSoFar) {
        if (!node) {
            return;
        }
        if (node->val >= maxSoFar) {
            maxSoFar = node->val;
            result++;
        }
        dfs(node->left, maxSoFar);
        dfs(node->right, maxSoFar);
    }
};
