class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        int ans_sum = 0;
        for(int i = 0; i < (int)nums.size(); i++) {
            int l = i + 1, r = (int)nums.size() - 1;
            
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(ans > abs(sum - target))ans = abs(target - sum), ans_sum = sum;
                r-=sum > target;
                l+=sum<target;
                if(sum == target)break;
                
            }
        }
        return ans_sum;
    }
};
