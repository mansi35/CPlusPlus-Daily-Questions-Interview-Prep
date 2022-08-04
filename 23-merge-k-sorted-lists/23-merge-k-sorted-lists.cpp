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
    typedef pair<int, ListNode*> node;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return NULL;
        
        priority_queue<node, vector<node>, greater<node>> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL)
                pq.push({ lists[i]->val, lists[i] });
        }
        
        ListNode* result = new ListNode();
        ListNode* tail = result;
        while (!pq.empty()) {
            node current = pq.top();
            pq.pop();
            tail->next = new ListNode(current.first);
            tail = tail->next;
            
            if (current.second->next != NULL) {
                pq.push({ current.second->next->val, current.second->next });
            }
        }
        return result->next;
    }
};