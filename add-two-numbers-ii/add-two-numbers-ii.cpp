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
    void reverseLinkedList(ListNode* &head) {
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* nextOfCurrent;
        while (current != NULL) {
            nextOfCurrent = current->next;
            current->next = prev;
            prev = current;
            current = nextOfCurrent;
        }
        head = prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        reverseLinkedList(l1);
        reverseLinkedList(l2);
        ListNode* ans = new ListNode();
        ListNode* ansHead = ans;
        int carry = 0, sum;
        while(l1 != NULL or l2 != NULL or carry != 0) {
            sum = 0;
            sum += carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            ListNode* digit = new ListNode(sum % 10);
            carry = sum / 10;
            ans->next = digit;
            ans = ans->next;
        }
        reverseLinkedList(ansHead->next);
        return ansHead->next;
    }
};