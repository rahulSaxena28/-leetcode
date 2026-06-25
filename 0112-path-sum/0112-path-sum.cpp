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
    bool yes=false;
    void solve(int &sum,TreeNode* root,int target){
        if(!root) return;
        sum+=root->val;
        if(root->left==nullptr && root->right==nullptr){
            if(sum==target){
                yes=true;
                return;
            }
        }else{
            solve(sum,root->left,target);
            solve(sum,root->right,target);
        }
        sum-=root->val;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        yes=false;
        solve(sum,root,targetSum);
        return yes;
    }
};