class Solution {
public:

    int solve(int l, int r, vector<int>& nums,
              vector<vector<int>>& dp,
              vector<int>& pref) {

        if(l == r)
            return 0;

        if(dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        for(int k = l; k < r; k++) {

            // Sum [l ... k]
            int ls = pref[k + 1] - pref[l];

            // Sum [k+1 ... r]
            int rs = pref[r + 1] - pref[k + 1];

            if(ls < rs) {

                ans = max(
                    ans,
                    ls + solve(l, k, nums, dp, pref)
                );

            }
            else if(rs < ls) {

                ans = max(
                    ans,
                    rs + solve(k + 1, r, nums, dp, pref)
                );

            }
            else {

                ans = max({
                    ans,
                    ls + solve(l, k, nums, dp, pref),
                    rs + solve(k + 1, r, nums, dp, pref)
                });
            }
        }

        return dp[l][r] = ans;
    }


    int stoneGameV(vector<int>& s) {

        int n = s.size();

        // prefix[i] = sum of first i elements
        vector<int> pref(n + 1, 0);

        for(int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + s[i];
        }

        vector<vector<int>> dp(
            n,
            vector<int>(n, -1)
        );

        return solve(0, n - 1, s, dp, pref);
    }
};