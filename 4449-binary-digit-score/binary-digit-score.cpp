class Solution {
public:
    int cntbit(int n){
        int cnt=0;
        while(n){
            if(n%2) cnt++;
            n=n/2;
        }
        return cnt;
    }
    int calculateScore(int a, int b) {
        int n1=cntbit(a);
        int n2=cntbit(b);
        if(n1>=n2) return n1*n2;
        return n2/n1;
    }
};