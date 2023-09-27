/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next =  NULL;
        random =  NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

    if (head ==  NULL) {
      return   NULL;
    }

    
     Node* p = head;

    while (p !=  NULL) {

      Node* t = new Node(p.val);

      t->next = p->next;
      p->next = t;
      p = t->next;
    }

    p = head;

    while (p !=  NULL) {
      p.next.random = (p->random !=  NULL) ? p->random->next :  NULL;
      p = p->next->next;
    }

    Node *old = head; // A->B->C
    Node *nw = head->next; // A'->B'->C'
    Node *old_head= head->next;
    while (old !=  NULL) {
      old->next = old->next->next;
      nw->next = (nw->next !=  NULL) ? nw->next->next :  NULL;
      old = old->next;
      nw = nw->next;
    }
    return old_head;

    }
};