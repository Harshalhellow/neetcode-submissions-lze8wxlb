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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode*prev = nullptr;
    ListNode * temp = nullptr;
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;
    ListNode* head = list1;

    while(list2 !=nullptr){

        if(list2->val<=list1->val&&prev!=nullptr){
            prev->next = list2;
            temp = list2->next;
            list2->next = list1;
            list2 = temp;
            prev = prev->next;
            
        }
        else if(list2->val>list1->val&&list1->next ==nullptr){
            list1->next = list2;
            temp = list2->next;
            list2->next = nullptr;
            list2 = temp;
            prev = list1;
            list1 = list1->next;
        }
        else if(list2->val<=list1->val&&prev==nullptr){
            temp = list2->next;
            list2->next = list1;
            list1 = list2;
            list2 = temp;
            head = list1;
        }
        else {
            prev = list1;
            list1 = list1->next;
        }

    }

    return head;
    }
};
