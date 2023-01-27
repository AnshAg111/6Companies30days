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
    void inorder(TreeNode*root, vector<int>&w){
        if(root!=NULL){
            inorder(root->left, w);
            w.push_back(root->val);
            inorder(root->right, w);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans, u, v;
        inorder(root1, u);
        inorder(root2, v);
        int x=u.size(), y=v.size(), i=0, j=0;
        while(i<x and j<y){
            if(u[i]<v[j]){
                ans.push_back(u[i]);
                i++;
            }
            else if(u[i]>v[j]){
                ans.push_back(v[j]);
                j++;
            }
            else{
                ans.push_back(u[i]);
                ans.push_back(v[j]);
                i++;
                j++;
            }
        }
        while(i<x){
            ans.push_back(u[i]);
            i++;
        }
        while(j<y){
            ans.push_back(v[j]);
            j++;
        }
        return ans;
    }
};