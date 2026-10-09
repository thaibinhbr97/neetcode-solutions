/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

// find a node that is the root node from subRoot
// once found, compare the subTree and the subRoot to see if they are the same
// same structure and same value
class Solution {  
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (p == null && q != null) return false;
        if (p != null && q == null) return false;
        if (p.val != q.val) return false;
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        // base cases
        if (subRoot == null) return true; // an empty tree is always a sub tree
        if (root == null) return false; // a non-empty subRoot cannot be a subtree of an empty tree
        
        if (isSameTree(root, subRoot)) {
            return true; // found our subtree
        }

        return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
    }
}
