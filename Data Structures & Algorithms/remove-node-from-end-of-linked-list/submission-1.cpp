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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr){
            head = nullptr;
            return head;
        }
        ListNode* headhead = head; 
        ListNode* curr = head; 
        ListNode* prev = nullptr; 
        ListNode* temp = nullptr; 
        while(curr !=nullptr){
            temp = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = temp;
        }
        // reverse the list 
        curr = prev;
        headhead = prev;
        prev = nullptr;

        int index = 1;
        while(index!=n){
            index++;
            prev = curr;
            curr = curr->next;
        }
        if(prev!=nullptr){
        prev->next = curr->next;
        curr->next = nullptr;
        }
        else {
            prev = curr;
            curr = curr->next;
            prev->next = nullptr;
            headhead = curr;
        }
 
        // go through it and remove the offending elment 

        curr = headhead;
        prev = nullptr; 
        temp = nullptr;
        while(curr!=nullptr){
            temp = curr->next;
            curr->next = prev; 
            prev = curr;
            curr = temp;

        }
        // reverse again 
        headhead = prev;
        return headhead;
    }
};
