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
    typedef pair<int, pair<int, ListNode*>> node;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        priority_queue< node, vector<node>, greater<node> > pq;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* head = lists[i];
            if (head != NULL)
                pq.push({head->val, {i, head}});
        }
        ListNode* result = new ListNode();
        while (!pq.empty()) {
            node current = pq.top();
            pq.pop();
            int listIndex = current.second.first;
            ListNode* listNode = current.second.second;
            ListNode* element = new ListNode(current.first);
            ListNode* tail = result;
            while (tail->next != NULL) {
                tail = tail -> next;
            }
            tail->next = element;
            
            if (listNode->next != NULL) {
                pq.push(make_pair(listNode->next->val, make_pair(listIndex, listNode->next)));
            }
        }
        return result->next;
    }
};