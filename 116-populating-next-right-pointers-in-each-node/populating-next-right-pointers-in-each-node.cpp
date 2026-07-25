/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        if(root == NULL)
           return NULL;
         queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            queue<Node*> level;
            for(int i=0;i<n;i++){
                Node* node=q.front();
                q.pop();

                level.push(node);
                if(node->left != NULL){
                    q.push(node->left);
                }

                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            int s = level.size();
            while(s--){
                Node* t = level.front();
                  level.pop();
                  if(!level.empty())
                     t->next = level.front();
                     else
                       t->next = NULL;

            }
        }
        return root;



        
    }
};