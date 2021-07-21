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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *cur = head, *prev = NULL;
        while (m > 1) {
            prev = cur;
            cur = cur->next;
            m--;
            n--;
        }
        ListNode *con = prev, *tail = cur;

        ListNode *third = NULL;
        while (n > 0) {
            third = cur->next;
            cur->next = prev;
            prev = cur;
            cur = third;
            n--;
        }
        if (con != NULL) {
            con->next = prev;
        } else {
            head = prev;
        }

        tail->next = cur;
        return head;
    }
};