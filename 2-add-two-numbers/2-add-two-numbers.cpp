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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp=l1;
        ListNode *temp2=l2;
        ListNode *prev=NULL;
        int carry=0;
        while(temp && temp2){
            int x=temp->val+temp2->val+carry;
            temp2->val=x%10;
            carry=x/10;
            temp=temp->next;
            prev=temp2;
            temp2=temp2->next;
        }
        if(temp){
            prev->next=temp;
            prev=prev->next;
            while(prev){
                int x=prev->val+carry;
                prev->val=x%10;
                carry=x/10;
                if(prev->next==NULL && carry){
                    prev->next=new ListNode(carry);
                    carry=0;
                    break;
                }
                prev=prev->next;
            }
            
        } else {
            while(temp2){
                int x=temp2->val+carry;
                temp2->val=x%10;
                carry=x/10;
                if(temp2->next==NULL && carry){
                    temp2->next=new ListNode(carry);
                     carry=0;
                    break;
                }
                temp2=temp2->next;
            }
        }
       if(carry){
           prev->next=new ListNode(carry);
           
       }
        return l2;
    }
};