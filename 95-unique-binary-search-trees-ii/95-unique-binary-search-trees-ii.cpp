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
     vector<TreeNode*> build(int n,int val){
        //base case
        if(n==0){return {nullptr};}
        
        vector<TreeNode*>ans;
        TreeNode* root;
        
        for(int i=0;i<n;i++){
            
            vector<TreeNode*>l=build(i,val);
            vector<TreeNode*>r=build(n-i-1,val+i+1);
            
            for(int j=0;j<l.size();j++){
                for(int k=0;k<r.size();k++){
                    root=new TreeNode(val+i);
                    root->left=l[j];
                    root->right=r[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return build(n,1);
    }
};