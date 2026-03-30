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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode*head = new ListNode(0);
        ListNode*curr = head;
        while(true){
            ListNode* currmin = nullptr; 
            ListNode* min = nullptr;
            int index = -1;
            for(int i=0; i<lists.size(); i++){
                if(lists[i]!=nullptr){
                    currmin = lists[i];
                    if(min==nullptr||min->val>currmin->val){
                        min = currmin;
                        index = i; 
                    }
                    //we see the elments value and compare it to the thing we save the index of its head; 
                } 
            }
            if(index==-1) break;
            lists[index] = lists[index]->next;
            curr->next = min;
            curr = curr->next;
            curr->next = nullptr; 
            // using the index of our min we add and increment that head 
            // if min was never set then we now that we are done and we can break the loop 
        }
        return head->next; 
        
    }
};
