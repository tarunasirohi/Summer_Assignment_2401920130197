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
    bool helper(TreeNode* root,long long low,long long high){

        if(root == NULL)
            return true;

        // BST condition
        if(root->val <= low || root->val >= high)
            return false;

        // left subtree
        bool left = helper(root->left, low, root->val);

        // right subtree
        bool right = helper(root->right, root->val, high);

        return left && right;
   }

    bool isValidBST(TreeNode* root) {

        return helper(root,LLONG_MIN,LLONG_MAX);

    }
};