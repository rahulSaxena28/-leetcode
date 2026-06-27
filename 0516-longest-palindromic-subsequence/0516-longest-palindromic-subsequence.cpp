class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        int dp[n+1][n+1];
        string s1="";
        for(int j=n-1;j>=0;j--){
            s1+=s[j];
        }
        for(int i=0;i<n+1;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0) dp[i][j]=0;
            }
        }
         for(int i=1;i<n+1;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]!=s1[j-1]){
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }else{
                    dp[i][j]=1+dp[i-1][j-1];
                }
            }
        }
        return dp[n][n];
    }
};