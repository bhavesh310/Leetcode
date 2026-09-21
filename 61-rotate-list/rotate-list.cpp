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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)
        return head;
        
        ListNode *temp=head;
        int count=0;
        //Count total nodes in linked lists
        while(temp){
            count++;
            temp=temp->next;
        }
        k=k%count;

        if(k==0)
        return head;

        count-=k;
        ListNode *curr=head,*prev=NULL;

        while(count--){
            prev=curr;
            curr=curr->next;
        }

        prev->next=NULL;
        ListNode *tail=curr;

        while(tail->next)
        tail=tail->next;

        tail->next=head;
        head=curr;

        return head;
    }
};