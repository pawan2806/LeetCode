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
    ListNode* rev(ListNode* root){
        ListNode* curr=root, *prev=NULL, *nex=NULL;
        while(curr){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        ListNode* curr=head;
        int i=0;
        ListNode* newhead=head;
        for(;i<k-1;i++){
            if(!newhead){
                break;
            }
            newhead=newhead->next;
        }
        if(i<k-1){
            return head;
        }
        if(!newhead){
            return curr;
        }
        ListNode* nextnode=newhead->next;
        newhead->next=NULL;

        newhead=rev(curr);
        curr->next=reverseKGroup(nextnode, k);
        
        return newhead;
        
        
    }
};