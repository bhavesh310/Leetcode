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
        ListNode* prev=NULL;    //Intialisation
        ListNode* curr=head;
        ListNode* next=NULL;

        while(curr!=NULL){
            next=curr->next;    //Preserve next node address
            curr->next=prev;    //otherwise list will break and address would be lost
            prev=curr;          //Establish connection with previous
            curr=next;
        } 
        return prev;
    }
};