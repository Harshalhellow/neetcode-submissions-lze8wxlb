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
    ListNode* reverseList(ListNode* head) {
        // defining curr prev and temp 
        ListNode*curr = head; 
        ListNode*prev = nullptr;
        ListNode*temp = nullptr; 
        while(curr!=nullptr){
            temp = curr->next; 
            curr->next = prev;
            prev = curr; 
            curr = temp;
        }
        return prev; 
        // while loop with curr not nullptr yet
        // save curr next in temp
        // curr next becomes prev
        // prev becomes curr
        // curr becomes temp
    }
};

/*
i want the curr to point at previous so i must break the link of each node and attach it mannually backwards i must save curr next so i can reassign curr later
*/