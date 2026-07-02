class Solution {
public:
    int bs(vector<int> &nums,int target,bool f,bool l){
        int s=0;
        int e=nums.size()-1;
        int res=-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(target==nums[m]){
                res=m;
                if(f){
                    e=m-1;
                }
                if(l){
                    s=m+1;
                }
            }else if(target<nums[m]){
                e=m-1;
            }else{
                s=m+1;
            }
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int f=bs(nums,target,1,0);
        if(f==-1) return {-1,-1};
        int l=bs(nums,target,0,1);
        return {f,l};
    }
};