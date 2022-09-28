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
    int length(ListNode* head)
    {
        int c=0;
        while(head!=NULL)
        {
            c++;
            head=head->next;
        }
        return c;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*q=NULL;
         ListNode*p=head;
        
        int a=length(head)-n+1;
        if(a==1)
        {
          q=head;
            head=head->next;
            delete q;
            return head;
        }
        else{
            for(int i=0;i<a-1;i++)
            {
                q=p;
                p=p->next;
            }
            q->next=p->next;
            delete p;
            return head;
        }
        
        
        
        
    }
};