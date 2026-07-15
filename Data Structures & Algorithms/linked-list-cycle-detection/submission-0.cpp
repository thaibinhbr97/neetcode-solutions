/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // // slow + fast pointers
    // // time: O(n)
    // // space: O(1)
    // bool hasCycle(ListNode* head) {
    //     if (!head) return true;
    //     ListNode* slow = head;
    //     ListNode* fast = head;
    //     while (fast && fast->next) {
    //         slow = slow->next;
    //         fast = fast->next->next;
    //         if (slow == fast) return true;
    //     }
    //     return false;
    // }
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> visited;
        ListNode* curr = head;
        while (curr) {
            if (visited.contains(curr)) return true;
            visited.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};
