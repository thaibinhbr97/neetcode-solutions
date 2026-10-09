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

// // dfs (recursive)
// // time: O(n)
// // space: O(n)
// class Solution {
//     record Pair(boolean isBalanced, int height) {};
//     public Pair isBalancedHelper(TreeNode node) {
//         // <isBalanced, height>
//         if (node == null) {
//             return new Pair(true, 0);
//         }
//         Pair left = isBalancedHelper(node.left);
//         Pair right = isBalancedHelper(node.right);

//         int nodeHeight = 1 + Math.max(left.height(), right.height());
//         int difference = Math.abs(left.height() - right.height());
//         boolean isNodeBalanced = (left.isBalanced() && right.isBalanced() && difference <= 1);

//         return new Pair(isNodeBalanced, nodeHeight);
//     }
//     public boolean isBalanced(TreeNode root) {
//         return isBalancedHelper(root).isBalanced();
//     }
// }


class Solution {
    public int getHeight(TreeNode node) {
        if (node == null) {
            return 0;
        }
        return 1 + Math.max(getHeight(node.left), getHeight(node.right));
    }
    public boolean isBalanced(TreeNode root) {
        if (root == null) {
            return true;
        }
        int leftHeight = getHeight(root.left);
        int rightHeight = getHeight(root.right);
        int difference = Math.abs(leftHeight - rightHeight);
        if (difference > 1) return false;
        return isBalanced(root.left) && isBalanced(root.right);
    }
}

