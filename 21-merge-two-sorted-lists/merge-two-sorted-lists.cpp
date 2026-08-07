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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        //Add dummy node to avoid extra condition check
        ListNode*head=new ListNode(0);
        ListNode *tail=head;
        //Main Loop
        ListNode*head1=list1,*head2=list2;
        while(head1 && head2){
            if(head1->val<=head2->val){
                tail->next=head1;
                head1=head1->next;
                tail=tail->next;
                tail->next=NULL;
            }else{
                tail->next=head2;
                head2=head2->next;
                tail=tail->next;
                tail->next=NULL;
            }
        }
        //If linked list's still exists
        if(head1)
        tail->next=head1;
        else
        tail->next=head2;

        return head->next;
    }
};