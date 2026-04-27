#include <cmath>
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
    // int height(TreeNode* node) {
    //     if (!node) return 0;
    //     int leftHeight = height(node->left);
    //     int rightHeight = height(node->right);
    //     return 1 + max(leftHeight, rightHeight);
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // // The logic for when p > q or p < q are the same so we only need to keep one
        // // Time: O(logn)
        // // Space: O(1) without recursive stack
        // bool isPSmaller = p->val < q->val ? true : false;
        // if (isPSmaller) {
        //     if ((p->val < root->val) && (q->val < root->val)) {
        //         return lowestCommonAncestor(root->left, p, q);
        //     } else if ((p->val > root->val) && (q->val > root->val)) {
        //         return lowestCommonAncestor(root->right, p, q);
        //     } else {
        //         return root;
        //     }
        // // p is now larger than q
        // } else {
        //     if ((p->val < root->val) && (q->val < root->val)) {
        //         return lowestCommonAncestor(root->left, p, q);
        //     } else if ((p->val > root->val) && (q->val > root->val)) {
        //         return lowestCommonAncestor(root->right, p, q);
        //     } else {
        //         return root;
        //     }            
        // }

        // // Time: O(logn)
        // // Space: O(1) without recursive stack
        // if ((p->val < root->val) && (q->val < root->val)) {
        //     return lowestCommonAncestor(root->left, p, q);
        // } else if ((p->val > root->val) && (q->val > root->val)) {
        //     return lowestCommonAncestor(root->right, p, q);
        // } else {
        //     return root;
        // }      

        // Iterative approach
        while (root) {
            if ((p->val < root->val) && (q->val < root->val)) {
                root = root->left;
            } else if ((p->val > root->val) && (q->val > root->val)) {
                root = root->right;
            } else {
                return root;
            }
        }
    }
};
