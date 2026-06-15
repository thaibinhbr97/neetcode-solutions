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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* resultList = new ListNode(numeric_limits<double>::infinity());
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* lr = resultList;
        while (l1 || l2) {
            if (!l1) {
                lr->next = l2;
                break;
            }
            if (!l2) {
                lr->next = l1;
                break;
            }
            if (l1->val >= l2->val) {
                lr->next = l2;
                l2 = l2->next;
            } else {
                lr->next = l1;
                l1 = l1->next;
            }
            lr = lr->next;
        }
        return resultList->next;
    }
};
