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
// -> not CORRECT since what if we found the node that equals in val and we check if they are the same tree starting from that node, they are not subtree of each other, but at the deeper level, there exists the other node that is the same of subRoot. Now, since we return early we cannot go down the tree anymore and find this node.
// THUS, we need to check if they are the same tree for all nodes from root

// at every node, we check if the subRoot is the sub tree of this node from root. If it is, we check if they are the same tree starting from this node.
// We use isSameTree to take care of the comparision between this node and the sub root node in the other method
// dfs (recursive)
// time: O(n*m), n size of root, m size of subRoot
// space: O(n + m) -> O(2n) -> O(n)
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
