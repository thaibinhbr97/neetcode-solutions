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
    public TreeNode invertTree(TreeNode root) {
        // // recursive
        // // time: O(n)
        // // space: O(n)
        // if (root == null) {
        //     return null;
        // }
        // // swap the children
        // TreeNode temp = root.left;
        // root.left = root.right;
        // root.right = temp;

        // invertTree(root.left);
        // invertTree(root.right);
        // return root;

        // // iterative using stack (dfs)
        // // time: O(n)
        // // space: O(n)
        // if (root == null) {
        //     return null;
        // }
        // Stack<TreeNode> stack = new Stack<>();
        // stack.push(root);
        // while (!stack.isEmpty()) {
        //     TreeNode node = stack.pop();

        //     // swap node's left and right child
        //     TreeNode temp = node.left;
        //     node.left = node.right;
        //     node.right = temp;

        //     // if left child and right child still exist, we have more work to do meaning we need to swap its left and right child as well. Therefore, we need to add to the stack to process later
        //     if (node.left != null) {
        //         stack.push(node.left);
        //     }
        //     if (node.right != null) {
        //         stack.push(node.right);
        //     }
        // }
        // return root;

        // iterative using queue (bfs)
        // level-order-traversal
        if (root == null) {
            return null;
        }
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.remove();

            // swap node's left and right child
            TreeNode temp = node.left;
            node.left = node.right;
            node.right = temp;

            // adding children back to the queue if it exists
            if (node.left != null) {
                queue.add(node.left);
            }
            if (node.right != null) {
                queue.add(node.right);
            }
        }
        return root;
    }
}
