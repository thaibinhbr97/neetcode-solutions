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
    public ListNode reverseList(ListNode head) {
             // 0  ->  1 ->  2   ->    3
    //prev <- curr    next
    // curr = next

        // base case: if head is None, return
        if (head == null) return head;
        
        // now head has at least 1 ListNode
        ListNode currentNode = head;
        ListNode previousNode = null;
        while (currentNode != null) {
            ListNode nextNode = currentNode.next;
            currentNode.next = previousNode;
            previousNode = currentNode;
            currentNode = nextNode;
        }
        return previousNode;
    }
}
