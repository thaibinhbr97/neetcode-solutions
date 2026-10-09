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

class Solution {
    record Pair(boolean isBalanced, int height) {};
    public Pair isBalancedHelper(TreeNode node) {
        // <isBalanced, height>
        if (node == null) {
            return new Pair(true, 0);
        }
        Pair left = isBalancedHelper(node.left);
        Pair right = isBalancedHelper(node.right);

        int nodeHeight = 1 + Math.max(left.height(), right.height());
        int difference = Math.abs(left.height() - right.height());
        boolean isNodeBalanced = (left.isBalanced() && right.isBalanced() && difference <= 1);

        return new Pair(isNodeBalanced, nodeHeight);
    }
    public boolean isBalanced(TreeNode root) {
        return isBalancedHelper(root).isBalanced();
    }
}
