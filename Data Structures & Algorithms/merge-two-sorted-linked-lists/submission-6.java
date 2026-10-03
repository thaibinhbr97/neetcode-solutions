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
    // // iterative
    // // time: O(n), n is size of a linked list
    // // space: O(1)
    // public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
    //     if (list1 == null) return list2;
    //     if (list2 == null) return list1;
    //     ListNode result = new ListNode(0);
    //     ListNode curr = result;
    //     while (list1 != null && list2 != null) {
    //         if (list1.val <= list2.val) {
    //             curr.next = list1;
    //             list1 = list1.next;
    //         } else {
    //             curr.next = list2;
    //             list2 = list2.next;
    //         }
    //         curr = curr.next;
    //     }
    //     if (list1 == null) {
    //         curr.next = list2;
    //     } else {
    //         curr.next = list1;
    //     }
    //     return result.next;
    // }

    // recursive
    // time: O(n)
    // space: O(n)
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) return list2;
        if (list2 == null) return list1;
        
        if (list1.val <= list2.val) {
            list1.next = mergeTwoLists(list1.next, list2);
            return list1;
        } else {
            list2.next = mergeTwoLists(list1, list2.next);
            return list2;
        }
    }
}