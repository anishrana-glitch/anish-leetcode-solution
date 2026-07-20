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
    class Node {
    public:
        ListNode* value;
        Node(ListNode* v) {
            value = v;
        }
    };
    struct cmp {
        bool operator()(const Node &a, const Node &b) {
            return a.value->val > b.value->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node, vector<Node>, cmp> pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr)
                pq.push(Node(lists[i]));
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        while (!pq.empty()) {
            Node n = pq.top();
            pq.pop();
            ListNode* temp = n.value;
            tail->next = temp;
            tail = tail->next;
            if (temp->next != nullptr) {
                pq.push(Node(temp->next));
            }
        }
        return dummy->next;
    }
};