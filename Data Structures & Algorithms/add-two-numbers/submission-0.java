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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        // 7 -> 2 -> 3
        // p1
        // 4 -> 5 -> 6
        // p2
        // 1, carry over = 1, 
        // when there is a carry over, we will add to the next operation
        // 357
        // 6
        // 7 -> 5 -> 3
        // 6
        // 3, carry over = 1 -> 5 + 1 = 6, 3 
        ListNode dummy = new ListNode();
        ListNode curr = dummy;
        int carry = 0;
        while (l1 != null || l2 != null || carry != 0) {
            int total = carry;

            if (l1 != null) {
                total += l1.val;
                l1 = l1.next;
            }

            if (l2 != null) {
                total += l2.val;
                l2 = l2.next;
            }
            
            int val = total % 10;
            carry = total / 10;
            curr.next = new ListNode(val);
            curr = curr.next;
        }
        return dummy.next;
    }
}
