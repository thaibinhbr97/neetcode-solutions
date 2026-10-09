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
    // // dfs (recursively)
    // // time: O(n)
    // // space: O(n)
    // private int maxDiameter = 0;
    // public int calculateHeight(TreeNode node) {
    //     if (node == null) {
    //         return 0;
    //     }
    //     int leftHeight = calculateHeight(node.left);
    //     int rightHeight = calculateHeight(node.right);
    //     this.maxDiameter = Math.max(this.maxDiameter, leftHeight + rightHeight);

    //     return 1 + Math.max(leftHeight, rightHeight);
    // }
    // public int diameterOfBinaryTree(TreeNode root) {
    //     maxDiameter = 0;
    //     calculateHeight(root);
    //     return maxDiameter;
    // }

    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }

        HashMap<TreeNode, int[]> hashMap = new HashMap<>(); // TreeNode: [height, diameter]
        hashMap.put(null, new int[]{0,0});
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode node = stack.peek();
            if (node.left != null && !hashMap.containsKey(node.left)) {
                stack.push(node.left);
            } else if (node.right != null && !hashMap.containsKey(node.right)) {
                stack.push(node.right);
            } else {
                stack.pop();         
            
                int[] leftData = hashMap.get(node.left);
                int[] rightData = hashMap.get(node.right);

                int leftHeight = leftData[0];
                int leftDiameter = leftData[1];
                int rightHeight = rightData[0];
                int rightDiameter = rightData[1];
                
                int height = 1 + Math.max(leftHeight, rightHeight);
                int diameter = Math.max(leftHeight + rightHeight, Math.max(leftDiameter, rightDiameter));

                hashMap.put(node, new int[]{height, diameter});
            }
        }
        return hashMap.get(root)[1];
        
    }
}
