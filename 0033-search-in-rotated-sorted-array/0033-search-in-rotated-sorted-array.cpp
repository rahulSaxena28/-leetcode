class Solution {
public:
    int bs(vector<int>& nums, int s, int e, int target) {
        while (s <= e) {
            int m = s + (e - s) / 2;

            if (nums[m] == target)
                return m;
            else if (nums[m] < target)
                s = m + 1;
            else
                e = m - 1;
        }
        return -1;
    }

   int rotatedBs(vector<int>& nums) {
    int s = 0;
    int e = nums.size() - 1;

    while (s < e) {
        int m = s + (e - s) / 2;

        if (nums[m] > nums[e])
            s = m + 1;
        else
            e = m;
    }

    return s;
}

    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;

        int pivot = rotatedBs(nums);

        int ans = bs(nums, 0, pivot - 1, target);
        if (ans != -1)
            return ans;

        return bs(nums, pivot, nums.size() - 1, target);
    }
};