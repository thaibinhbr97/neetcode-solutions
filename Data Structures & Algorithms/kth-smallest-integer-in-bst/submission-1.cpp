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
int result;
public:
    // int kthSmallest(TreeNode* root, int k) {
    //     // using the property of bst and inorder traversal to get the correct order, then return the smallest k
    //     // time: O(n)
    //     // space: O(n)
    //     vector<int> arr;
    //     dfs(root, arr);
    //     return arr[k-1];
    // }
    // void dfs(TreeNode* root, vector<int>& arr) {
    //     // inorder traversal
    //     if (!root) return;
    //     dfs(root->left, arr);
    //     arr.push_back(root->val);
    //     dfs(root->right, arr);
    // }

    int kthSmallest(TreeNode* root, int k) {
        // using the property of bst and inorder traversal to get the correct order and the count to return early using the property of bst for the smallest node is at the bottom left and we can start counting going up to count the smallest k.
        // time: O(n)
        // space: O(1)
        dfs(root, k, result);
        return result;
    }
    void dfs(TreeNode* root, int& k, int& result) {
        // inorder traversal
        if (!root) return;
        dfs(root->left, k, result);
        
        k--;
        if (k == 0) {
            result = root->val;
        }
        
        dfs(root->right, k, result);
    }
};
