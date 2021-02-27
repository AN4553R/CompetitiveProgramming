class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0, r = (int)nums.size() - 1;
        
        while(l < r)
        {
            int mid = (l + r) / 2;
            
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] > nums[l])
                l = mid;
            else r = mid;
        }
        auto first_half = lower_bound(nums.begin(), nums.begin() + l, target);
        auto second_half = lower_bound(nums.begin() + l + 1, nums.end(), target);
        if(first_half != nums.end() && nums[first_half - nums.begin()] == target)
            return first_half - nums.begin();
        if(second_half != nums.end() && nums[second_half - nums.begin()] == target)
            return second_half - nums.begin();
        return -1;
    }
};
