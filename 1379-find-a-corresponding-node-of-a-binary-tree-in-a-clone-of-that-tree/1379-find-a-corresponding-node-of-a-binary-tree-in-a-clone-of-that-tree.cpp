/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */

class Solution
{
    public:
        void dfs(TreeNode *original, TreeNode *cloned, TreeNode *target, TreeNode* &ans)
        {
            if (!original)
            {
                return;
            }
            if (original == target)
            {
                ans = cloned;
            }
            dfs(original->left, cloned->left, target, ans);
            dfs(original->right, cloned->right, target, ans);
            return;
        }
    TreeNode* getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        TreeNode *ans = nullptr;
        dfs(original, cloned, target, ans);
        return ans;
    }
};