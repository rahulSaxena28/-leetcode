class Solution {
public:
    double minPrice(vector<int>& p, vector<int>& d) {
        double ans=0;
        sort(p.begin(),p.end());
        sort(d.begin(),d.end());
        int n=p.size(),j=d.size()-1;
        for(int i=n-1;i>=0;i--){
            if(j>=0){
               double rem=double(100-d[j])/double(100);
               double price=double(p[i]*rem);
               ans+=price;
               j--;
            }
            else ans+=double(p[i]);
   
        }
        return ans;
    }
};