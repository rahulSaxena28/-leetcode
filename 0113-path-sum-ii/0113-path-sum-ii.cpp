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
    void solve(int &sum,TreeNode* root,int target,vector<int> &temp){
         if(!root ){
            return;
         }
         temp.push_back(root->val);
         sum=sum+root->val;
         if(root->left==nullptr && root->right==nullptr){
            if(sum==target) ans.push_back(temp);
         }else{
            solve(sum,root->left,target,temp);
            solve(sum,root->right,target,temp);
         }
         sum=sum-root->val;
         temp.pop_back();
         

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ans.clear();
        vector<int> temp;
        int sum=0;
        solve(sum,root,targetSum,temp);
        return ans;
    }
};