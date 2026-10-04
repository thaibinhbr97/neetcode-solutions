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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // head = 1 -> 2 -> 3 -> 4 -> 5
        // n = 2
        // find the size of a linked list, size
        // get to the node at index size - n = 5 - 2 = 3 and rewire the 
        // a linked list, keep track of prev and curr node for the rewiring
        // total time for traversal: 2 times 
        // time: O(n), n is a size of linked list
        // space: O(1)
        ListNode curr = head;
        int size = 0;
        while (curr != null) {
            size++;
            curr = curr.next;
        }
        int removeIndex = size - n;
        if (removeIndex == 0) {
            return head.next;
        }
        curr = head;
        ListNode prev = new ListNode(0);
        prev.next = head;
        int i = 0;
        while (i < removeIndex) {
            prev = prev.next;
            curr = curr.next;
            i++;
        }
        // now we reach the removed node
        prev.next = curr.next;
        curr = null;
        return head;
    }
}
