class Solution {
public:
   int dp[100005];
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int result = nums[0];
        // dp[i] = maximum subarray ends at index i
        // dp[i] = max(nums[i], dp[i - 1] + nums[i])
    
        dp[0] = nums[0];
        
        for(int i = 1; i < n; i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            result = max(result, dp[i]);
        }
        
        return result;
    }
};
