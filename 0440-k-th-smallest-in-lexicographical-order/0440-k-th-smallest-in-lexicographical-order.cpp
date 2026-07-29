class Solution {
public:
    long long count(long long curr,long long next,long long n){
        long long cnt=0;
        while(curr<=n){
            cnt+=next-curr;
            curr*=10;
            next=min(next*10,n+1);
        }
        return cnt;
    }
    int findKthNumber(int n, int k) {
        int curr=1;
        k--;
        while(k>0){
            long long cnt=count(curr,curr+1,n);
            if(cnt<=k){
                k-=cnt;
                curr++;
            }else{
                k--;
                curr*=10;
            }
        }
        return curr;
    }
};