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
    vector<vector<int>> ans;
    unordered_map<int, vector<int>> m;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return ans;
        }
        queue<pair<TreeNode* , int >> q;
        TreeNode* temp=root;
        q.push({temp, 0});
        while(!q.empty()){
            pair<TreeNode* , int > gg=q.front(); q.pop();
            temp=gg.first;
            m[gg.second].push_back(temp->val);
            if(temp->left){
                 q.push({temp->left, gg.second+1});
            }
            if(temp->right){
                 q.push({temp->right, gg.second+1});
            }
            
        }
        unordered_map<int, vector<int>>::iterator itr;
        int level=0;
        while(m[level].size()>0){
            ans.push_back(m[level]);
            level++;
        }
        
        
        
        
        return ans;
    }
};