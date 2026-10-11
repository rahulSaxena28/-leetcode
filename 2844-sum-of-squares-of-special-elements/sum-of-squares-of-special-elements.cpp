class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=1;i<=nums.size();i++){
            if(n%i) continue;
            else ans=ans+nums[i-1]*nums[i-1];
        }
        return ans;
    }
};