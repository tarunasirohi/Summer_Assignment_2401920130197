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
    TreeNode* tree(vector<int>& inorder, vector<int>& postorder,int st,int end,int idx){
          if(st > end)
            return NULL;
        TreeNode* root = new TreeNode(postorder[idx]);
        int pos = find(inorder,postorder[idx],st,end);
        root->right = tree(inorder,postorder,pos+1,end,idx-1);
         root->left = tree(inorder,postorder,st,pos-1,idx-(end-pos)-1);
         return root;

   }
   int find(vector<int>& inorder,int target,int st,int end){
       for(int i = st;i<=end;i++){
        if(inorder[i] == target)
          return i;
       }
          return -1; 
   }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         TreeNode* res = tree(inorder,postorder,0,inorder.size()-1,inorder.size()-1);
        return res;
        }
};