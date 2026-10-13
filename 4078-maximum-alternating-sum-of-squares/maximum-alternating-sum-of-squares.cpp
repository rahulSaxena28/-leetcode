
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = abs(nums[i]);
        }

        sort(nums.begin(), nums.end());

        long long ans = 0;
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            ans += 1LL * nums[end] * nums[end];
            ans -= 1LL * nums[start] * nums[start];

            start++;
            end--;
        }
        int n=nums.size();
        if(n%2){
            int x=n/2;
            ans=ans+1LL*nums[x]*nums[x];
        }

        return ans;
    }
};
