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
    int getDecimalValue(ListNode* head) {
        ListNode* start = head;
        int length = 0, ans = 0;
        while (start != NULL) {
            start = start->next;
            length++;
        }
        start = head;
        while (start != NULL) {
            ans += start->val * pow(2, --length);
            start = start->next;
        }
        return ans;
    }
};