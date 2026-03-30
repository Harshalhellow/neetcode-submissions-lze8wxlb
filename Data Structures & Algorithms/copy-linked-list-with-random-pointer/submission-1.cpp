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
        Node* nothing = NULL;
        if(head==NULL) return nothing;

        Node* head1 = head;
        Node* head2 = new Node(head1->val);
        Node* head2copy = head2;
        Node* head3copy = head2;
        unordered_map<Node*,int> hashmaporg;
        unordered_map<int,Node*> hashmapcopt;
        int index =0;
        while(head1->next!=NULL){
            head2->next = new Node(head1->next->val);
            hashmaporg[head1] = index;
            hashmapcopt[index] = head2;
            head2 = head2->next; 
            head1 = head1->next; 
            index++;
        }
        hashmaporg[head1] = index;
        hashmapcopt[index] = head2;

        head1 = head; 
        Node*head1prev = NULL;
        while(head1!=NULL){
            head1prev = head1; 
            head1 = head1->random; 
            if(head1== NULL) head2copy->random = NULL;
            else head2copy->random = hashmapcopt[hashmaporg[head1]];
            head2copy = head2copy->next; 
            head1 = head1prev;
            head1 = head1->next;
        }
        
        return head3copy;
    }
};
