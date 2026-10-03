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
    public boolean hasCycle(ListNode head) {
        HashSet<ListNode> visited = new HashSet<ListNode>();
        ListNode curr = head;
        while (curr != null) {
            if (visited.contains(curr)) return true;
            visited.add(curr);
            curr = curr.next;
        }
        return false;
    }
}
