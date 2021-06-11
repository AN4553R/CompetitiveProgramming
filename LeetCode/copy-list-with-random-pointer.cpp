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
// O(n) time | O(n) space | where n is the number of nodes in the list
map<Node*, Node*>cpy;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* tmp = head;
        
        while(tmp != nullptr) {
            cpy[tmp] = new Node(tmp->val);
            tmp = tmp->next;
        }
        
        tmp = head;
         while(tmp != nullptr) {
            cpy[tmp]->next = cpy[tmp->next];
            cpy[tmp]->random = cpy[tmp->random];
            tmp = tmp->next;
        }
        
        return cpy[head];
    }
};



// O(n) time | O(1) space | where n is the number of nodes in the list

unordered_map<Node*, Node*>cpy;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL)return NULL;
        
        Node* tmp = head;
        
        while(tmp != NULL) {
            // Cloned node with same val as head
            Node* newNode = new Node(tmp->val);
            // Insert the cloned node next to the original node
            // If A->B->C is the original linked list,
            // Linked list after weaving cloned nodes would be
            // A->A'->B->B'->C->C'
            newNode->next = tmp->next;
            tmp->next = newNode;
            tmp = newNode->next;
        }
        
        tmp = head;
        
        // Link random pointers of the newly created nodes
        // and iterate through the newly created list and
        // use original node's random pointers
        while(tmp != NULL) {
        // For the cloned node I should make it to point the temp->random->next
        // because temp->random is the original node
        // and temp->random->next is the cloned node of temp->random.
        //eg;
        //A->A'->B->B'->C->C'->D->D'->E->E'->NULL
            tmp->next->random = (tmp->random)?tmp->random->next:NULL;
            tmp = tmp->next->next;
        }
         // Unweave the current linked list to get back the 
        // original linked list and the cloned one.
        
        // A->B->C
        Node* original = head;
        // A'->B'->C'
        Node* cpy = head->next;
        // Result is used for returning
        Node* result=head->next;
        
        while(original != NULL) {
            original->next = original->next->next;
            cpy->next = (cpy->next)?cpy->next->next:NULL;
            
            original = original->next;
            cpy = cpy->next;
        }
        
        return result;
        
    }
};
