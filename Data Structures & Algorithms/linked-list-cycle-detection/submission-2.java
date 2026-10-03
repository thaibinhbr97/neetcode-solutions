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
        // // time: O(n), n is a length of the linked list
        // // space: O(n) for visited
        // HashSet<ListNode> visited = new HashSet<ListNode>();
        // ListNode curr = head;
        // while (curr != null) {
        //     if (visited.contains(curr)) return true;
        //     visited.add(curr);
        //     curr = curr.next;
        // }
        // return false;

        // small and fast pointer approach
        // time: O(n)
        // space: O(1)
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            fast = fast.next;
            if (slow == fast) return true;
            slow = slow.next;
            fast = fast.next;
        }
        return false;
    }
}
