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
    void reorderList(ListNode* head) {

        //find mid point
        ListNode*slow =head;
        ListNode*fast = head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }

        // split in half 
        ListNode*tail = slow->next;
        slow->next = nullptr;

        //reverse second half

        ListNode*currlist2 = tail;
        ListNode*prevlist2 = nullptr;
        ListNode*templist2 = nullptr;

        while(currlist2!=nullptr){
            templist2 = currlist2->next;
            currlist2->next = prevlist2;
            prevlist2 = currlist2;
            currlist2 = templist2;
        }
        ListNode* list1 = head;
        ListNode* list2 = prevlist2;
        ListNode* list1temp = nullptr;
        ListNode* list2temp = nullptr;
        while(list2!=nullptr){
            list1temp = list1->next;
            list2temp = list2->next;
            list1->next = list2;
            list2->next = list1temp;
            list1 = list1temp;
            list2 = list2temp;
        }

    
        
    }
};
