/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> mp;
        Node* curr = head;
        Node* newHead = new Node(curr->val);
        Node* newCurr = newHead;

        mp[curr] = newCurr;

        while (curr->next) {
            curr = curr->next;

            Node* node = new Node(curr->val);
            newCurr->next = node;
            newCurr = node;

            mp[curr] = newCurr;
        }

        newCurr = newHead;
        while (head) {
            newCurr->random = mp[head->random];
            head = head->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};
