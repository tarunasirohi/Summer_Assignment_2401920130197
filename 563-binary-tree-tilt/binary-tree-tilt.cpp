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

    
    int result = 0;
   void sum(TreeNode* root,int& s){
    if(!root)
     return;
     s += root->val;
     sum(root->left,s);
     sum(root->right,s);
       return;
   }
    int findTilt(TreeNode* root) {
         if(!root)
           return 0;
        int l = 0,r = 0;
        if(root->left)
        sum(root->left,l);
         if(root->right)
        sum(root->right,r);
        result += abs(l - r);
        findTilt(root->left);
        findTilt(root->right);
         return result;
    }
};