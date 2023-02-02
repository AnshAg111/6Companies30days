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
    int SumOfSubtree(TreeNode*root){
        int sum=0;
        if(root!=NULL){
            sum+=root->val;
            sum+=SumOfSubtree(root->left);
            sum+=SumOfSubtree(root->right);
        }
        return sum;
    }
    int no_of_children(TreeNode*root){
        int c=0;
        if(root!=NULL){
            c++;
            c+=no_of_children(root->left);
            c+=no_of_children(root->right);
        }
        return c;
    }
    int preorder(TreeNode*root){
        int ans=0;
        if(root!=NULL){
            if(root->val==SumOfSubtree(root)/no_of_children(root)) ans++;
            ans+=preorder(root->left);
            ans+=preorder(root->right);
        }
        return ans;
    }
    int averageOfSubtree(TreeNode* root) {
        return preorder(root);
    }
};