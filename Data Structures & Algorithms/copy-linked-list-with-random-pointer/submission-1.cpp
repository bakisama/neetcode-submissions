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
        unordered_map<Node*, Node*> deeper;
        deeper[NULL] = NULL;
        Node* curr = head;
        while(curr!=NULL){
            Node* copy = new Node(curr->val);
            deeper[curr] = copy;
            curr = curr->next;
        }
        curr = head;
        while(curr!=NULL){
            Node* copy = deeper[curr];
            copy-> next = deeper[curr->next];
            copy->random = deeper[curr->random];
            curr = curr->next;
        }
        return deeper[head];

    }
};
