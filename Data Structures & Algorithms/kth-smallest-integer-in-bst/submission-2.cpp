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
        // inorder with a shared counter; stop at the k-th visited node
        // time: O(h + k)
        // space: O(h)
        int result = 0;
        dfs(root, k, result);
        return result;
    }
    void dfs(TreeNode* root, int& k, int& result) {
        // inorder traversal
        if (!root) return;
        
        dfs(root->left, k, result);
        if (k == 0) return; // answer found in left subtree
        
        k--;
        if (k == 0) {
            result = root->val;
            return; // no need to visit right subtree
        }
        
        dfs(root->right, k, result);
    }
};
