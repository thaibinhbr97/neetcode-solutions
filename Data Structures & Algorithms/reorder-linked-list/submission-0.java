/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) return;

        ArrayList<ListNode> nodes = new ArrayList<>();
        ListNode curr = head;
        while (curr != null) {
            nodes.add(curr);
            curr = curr.next;
        }

        int left = 0;
        int right = nodes.size() - 1;
        while (left < right) {
            ListNode leftNode = nodes.get(left);
            leftNode.next = nodes.get(right);
            left++;

            if (left >= right) break;

            ListNode rightNode = nodes.get(right);
            rightNode.next = nodes.get(left);
            right--;
        }
        nodes.get(left).next = null;
    }
}
