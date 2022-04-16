/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<int> ans;
    int index = 0;
    unordered_map<int, int> m;
    void inorder(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left);
        m[root->val] = index;
        index++;
        ans.push_back(root->val);
        inorder(root->right);
    }

    // this is where the actual conversion happens
    void convertBSTUtil(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        int gg = m[root->val];
        root->val = root->val + ans[ans.size() - 1] - ans[gg];

        convertBSTUtil(root->right);
        convertBSTUtil(root->left);
    }
    TreeNode* convertBST(TreeNode *root)
    {

        inorder(root);
        // now making prefix array
        for (int i = 1; i < ans.size(); i++)
        {
            ans[i] = ans[i] + ans[i - 1];
        }
        convertBSTUtil(root);
        return root;
    }
};