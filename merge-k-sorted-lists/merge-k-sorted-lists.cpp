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
        priority_queue< node, vector<node>, greater<node> > pq;
        for (int i = 0; i < lists.size(); i++) {
            ListNode* head = lists[i];
            if (head != NULL)
                pq.push({head->val, head});
        }
        ListNode* result = new ListNode();
        ListNode* tail = result;
        while (!pq.empty()) {
            node current = pq.top();
            pq.pop();
            ListNode* listNode = current.second;
            ListNode* element = new ListNode(current.first);
            tail->next = element;
            tail = tail->next;
            
            if (listNode->next != NULL) {
                pq.push(make_pair(listNode->next->val, listNode->next));
            }
        }
        return result->next;
    }
};