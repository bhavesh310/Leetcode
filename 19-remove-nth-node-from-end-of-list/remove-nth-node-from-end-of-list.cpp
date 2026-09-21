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
        int count=0;
        ListNode *temp=head;
        //Count total nodes in linked lists
        while(temp){
            count++;
            temp=temp->next;
        }
        //From start find position of node that has to be deleted
        count=count-n;

        if(count==0){
            head=head->next;
            return head;
        }
        
        ListNode *prev=NULL,*curr=head;
        while(count--){
            prev=curr;
            curr=curr->next;
        }

        prev->next=curr->next;

        delete curr;

        return head;
    }
};