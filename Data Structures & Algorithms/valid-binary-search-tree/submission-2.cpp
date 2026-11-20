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
    // // time: O(n^2)
    // // space: O(n)
    // bool left_check(int value, int limit) {
    //     return value < limit;
    // }
    // bool right_check(int value, int limit) {
    //     return value > limit;
    // }
    // bool allLess(TreeNode* node, int limit) {
    //     if (!node) return true;
    //     return left_check(node->val, limit) && allLess(node->left, limit) && allLess(node->right, limit);
    // }
    // bool allGreater(TreeNode* node, int limit) {
    //     if (!node) return true;
    //     return right_check(node->val, limit) && allGreater(node->left, limit) && allGreater(node->right, limit);
    // }
    // bool isValidBST(TreeNode* root) {
    //     if (!root) return true;
    //     return allLess(root->left, root->val) && allGreater(root->right, root->val) && isValidBST(root->left) && isValidBST(root->right);
    // }

    // time: O(n)
    // space: O(h)
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }
    bool isValid(TreeNode* node, long low, long high) {
        if (!node) return true;
        if (node->val >= high || node->val <= low) {
            return false;
        }
        return isValid(node->left, low, node->val) && isValid(node->right, node->val, high);
    }
};
