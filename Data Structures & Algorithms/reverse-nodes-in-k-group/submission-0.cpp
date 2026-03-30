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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head; 
        int count = 0; 
        while(curr!=nullptr){
            count++;
            curr = curr->next;
        }
        // go through it once get a size of the list 
        int numberofks = count/k; 
        int index = 0; 
        ListNode* currhead = head;
        ListNode* nexthead = head;
        ListNode* ender = head;
        ListNode* oldtail = nullptr; 
        ListNode* lasttail = nullptr; 
        ListNode*newtail = nullptr;
        for(int i=0; i<numberofks; i++){
            while(index!=k-1){
                ender = ender->next; 
                index++;
            }
            nexthead = ender->next; 
            if(i==numberofks-1) lasttail = ender->next; 
            ender->next = nullptr; 
            // go through it again wiht a counter ever k times stop and terminate the list. 


            // reverse the list 
            ListNode*curr = currhead; 
            ListNode*prev = nullptr; 
            ListNode*temp = nullptr; 
            while(curr!=nullptr){
                temp = curr->next; 
                curr->next = prev; 
                prev = curr;
                curr = temp; 
            }


            // reattach it 
            newtail= prev; 
            if(i==0){
                head = prev; 
                while(newtail->next!=nullptr){
                    newtail = newtail->next; 
                }
                oldtail = newtail; 
            }
            else{
                 while(newtail->next!=nullptr){
                    newtail = newtail->next; 
                }
                oldtail->next = prev; 
                oldtail = newtail; 
            }
    
            currhead = nexthead;
            ender = currhead;  
            index = 0; 
        }
        newtail->next = lasttail; 

        return head; 
        
    }
};




// using this terminated lsit go through and reverse it 
// reattach then set the head of the next starting point as the thing 
// repeat until there are too few elments in teh list. 
