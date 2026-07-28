class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        if(n==1) return s;
        map<char,int> mp;
        for(auto it : s){
            mp[it]++;
        }
        string s3="";
        string s1="";
        string s2="";
        for(auto it :mp){
           int f =it.second;
           char c =it.first;
           if(f%2){
            s3+=c;
            f--;
           }
            while(f){
                if(f>0){
                    s1+=c;
                    f--;
                }
                if(f>0){
                    s2+=c;
                    f--;
                }

            }
        }
        int st=0;
        int end=s2.length()-1;
        while(st<end){
            swap(s2[st],s2[end]);
            st++;
            end--;
        }
        
        return s1+s3+s2;

    }
};