class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return 0;
        string num="";
        while(x){
            num+=char(x%10);
            x=x/10;
        }
        int start=0;
        int end=num.length()-1;
        while(start<end){
            if(num[start]!=num[end])return 0;
            start++;
            end--;
        }
        return 1;

    }
};