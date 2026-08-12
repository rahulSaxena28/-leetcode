class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int s = 0;
        int e = 0;
        int ans = 0;
        int n = nums.size();

        while (e < n) {

            if (mp.find(nums[e]) != mp.end()) {

                if (mp[nums[e]] < k) {
                    mp[nums[e]]++;
                    e++;

                    ans = max(ans, e - s);
                }
                else {
                    // Remove elements from left
                    // until one occurrence of nums[e] is removed
                    while (nums[s] != nums[e]) {
                        mp[nums[s]]--;
                        s++;
                    }

                    // Remove the matching nums[e]
                    mp[nums[s]]--;
                    s++;
                }
            }
            else {
                mp[nums[e]]++;
                e++;

                ans = max(ans, e - s);
            }
        }

        return ans;
    }
};