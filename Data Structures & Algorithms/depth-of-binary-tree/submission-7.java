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
    public int maxDepth(TreeNode root) {
        // // max depth will be the maximum depth between left branch and right branch. Therefore, we can use the recursive approach to get down to the left node and count up from there. Everytime we count up from the leaf node, we will add 1 to the depth and pass the depth result up to the parent node
        // // recursive approach
        // // time: O(n)
        // // space: O(h) for depth of the tree, O(n) for degenerate tree and O(logn) for balanced tree
        // if (root == null) {
        //     return 0;
        // }
        // int leftDepth = maxDepth(root.left);
        // int rightDepth = maxDepth(root.right);
        // return 1 + Math.max(leftDepth, rightDepth);

        // // iterative approach (dfs)
        // // time: O(n)
        // // space: O(n)
        // if (root == null) {
        //     return 0;
        // }
        // Stack<Pair<TreeNode, Integer>> stack = new Stack<>();
        // stack.push(new Pair<TreeNode, Integer>(root, 1));
        // int maxDepth = 0;
        // while (!stack.isEmpty()) {
        //     Pair<TreeNode, Integer> pair = stack.pop();
        //     TreeNode node = pair.getKey();
        //     int depth = pair.getValue();

        //     if (node != null) {
        //         maxDepth = Math.max(maxDepth, depth);
        //         stack.push(new Pair<TreeNode, Integer>(node.left, depth + 1));
        //         stack.push(new Pair<TreeNode, Integer>(node.right, depth + 1));
        //     }
        // }
        // return maxDepth;

        // iterative approach (bfs)
        // time: O(n)
        // space: O(n)
        if (root == null) {
            return 0;
        }
        Queue<TreeNode> queue = new ArrayDeque<>();
        queue.offer(root);
        int level = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                if (node.left != null) {
                    queue.offer(node.left);
                }
                if (node.right != null) {
                    queue.offer(node.right);
                }
            }
            level++;
        }
        return level;
    }
}
