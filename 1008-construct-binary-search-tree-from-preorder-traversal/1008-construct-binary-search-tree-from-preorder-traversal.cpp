/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>&p, int s, int e){
        TreeNode *root = new TreeNode(p[s]);
        int m;
        for(m=s+1; m<=e; ++m)
            if(p[m]>p[s]) break;
        if(m<=e)
            root->right = solve(p,m,e);
        if(s<e and p[s+1]<p[s])
            root->left = solve(p,s+1,m-1);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder,0,preorder.size()-1);
    }
};