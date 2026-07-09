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
    
    void helper(TreeNode* root,vector<TreeNode*>& ans)
    {
        if(!root)
           return;
           ans.push_back(root);
           helper(root->left,ans);
           helper(root->right,ans);
           return;
    }
    void flatten(TreeNode* root) {
        if(!root)
          return;
        vector<TreeNode*> ans;
        helper(root,ans);
        TreeNode* temp = root;
        for(int i = 1;i<ans.size();i++){
            
            
            temp->left = NULL;
            temp->right = ans[i];
            temp = temp->right;

        }
       
        temp->left = NULL;
        temp->right = NULL;
        return;

    }
};