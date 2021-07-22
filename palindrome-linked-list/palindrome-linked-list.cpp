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
    ListNode* reverseLinkedList(ListNode* &head) {
        if (head == NULL or head->next == NULL)
            return head;
        ListNode *prev = NULL, *nextNode, *current = head;
        while (current != NULL) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        ListNode *slow = head,*fast = head,*prev = slow;
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        slow = reverseLinkedList(slow);
        while (slow and head) {
            cout << head->val << " ";
            if (head->val != slow->val) 
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};