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

        // // iterative approach
        // // time: O(n)
        // // space: O(1)
        // // base case: if head is None, return
        // if (head == null) return head;
        
        // // now head has at least 1 ListNode
        // ListNode currentNode = head;
        // ListNode previousNode = null;
        // while (currentNode != null) {
        //     ListNode nextNode = currentNode.next;
        //     currentNode.next = previousNode;
        //     previousNode = currentNode;
        //     currentNode = nextNode;
        // }
        // return previousNode;

        // recursive approach
        // time: O(n)
        // space: O(n) if considering a number of callstacks/recursive call
        // base case: empty list
        if (head == null) return null;
        // single node left (become a head of a reversed list)
        if (head.next == null) {
            return head;
        }

        ListNode newHead = reverseList(head.next);
        head.next.next = head; // point the next node back to the current node
        head.next = null; // disconnect original forward pointer to break cycle

        return newHead;
    }
}
