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
    TreeNode* tree(vector<int>& preorder, vector<int>& inorder,int st,int end,int idx){
          if(st > end)
            return NULL;
        TreeNode* root = new TreeNode(preorder[idx]);
        int pos = find(inorder,preorder[idx],st,end);
        root->left = tree(preorder,inorder,st,pos-1,idx+1);
         root->right = tree(preorder, inorder,pos+1,end,idx+(pos-st)+1);
         return root;

   }
   int find(vector<int>& inorder,int target,int st,int end){
       for(int i = st;i<=end;i++){
        if(inorder[i] == target)
          return i;
       }
          return -1; 
   }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* res = tree(preorder,inorder,0,inorder.size()-1,0);
        return res;

        
    }

};