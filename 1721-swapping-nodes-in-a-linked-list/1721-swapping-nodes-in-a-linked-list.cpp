/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* swapNodes(ListNode *head, int k)
        {
            ListNode *kfromstart = head, *kfromend = head, *temp = head;
            int x = k - 1;
            while (x)	// find the kth element from start
            {
                kfromstart = kfromstart->next;
                temp = temp->next;
                x--;
            }

            while (temp->next)	// now go till end to find kth element from end
            {
                temp = temp->next;
                kfromend = kfromend->next;
            }
           	//swap kth element from start &kth element from end
            swap(kfromend->val, kfromstart->val);
            return head;
        }
};