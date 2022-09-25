/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        ListNode* findmid(ListNode *A)
        {
            if (!A || !A->next)
            {
                return A;
            }
            ListNode *slow = A;
            ListNode *fast = A;
            while (fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
    TreeNode* sortedListToBST(ListNode *A)
    {
        if (!A)
        {
            TreeNode *root = NULL;
            return root;
        }
        else if (!A->next)
        {
            TreeNode *root = new TreeNode(A->val);
            return root;
        }
        ListNode *midnode = findmid(A);
        ListNode *temp = A;
        while (temp->next != midnode)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        TreeNode *root = new TreeNode(midnode->val);
        root->left = sortedListToBST(A);
        root->right = sortedListToBST(midnode->next);

        return root;
    }
};