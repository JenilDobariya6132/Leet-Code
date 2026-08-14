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
    ListNode* merge(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            }
            else {
                current->next = list2;
                list2 = list2->next;
            }

            current = current->next;
        }
        if (list1 != nullptr) {
            current->next = list1;
        }
        else {
            current->next = list2;
        }

        ListNode* result = dummy->next;

        delete dummy;

        return result;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(second);
        return merge(left, right);
    }
};