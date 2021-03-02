class Solution {
    int max_dp[100005], min_dp[100005];
public:
    int maxProduct(vector<int>& nums) {
       // max_dp[i] = maximum subarray ends at that point
       // min_dp[i] = minimum subarray ends at that point, we need it becuase the signed values can maximize the  result (- * - = +)
        min_dp[0] = nums[0];
        max_dp[0] = nums[0];
        int result = nums[0];
     
        for(int i = 1; i < nums.size(); i++) {
            max_dp[i] = max({nums[i], max_dp[i - 1] * nums[i], min_dp[i - 1] * nums[i]});
            result = max(result, max_dp[i]);
            min_dp[i] = min({nums[i], max_dp[i - 1] * nums[i], min_dp[i - 1] * nums[i]});
        }
        
        return result;
    }
};

// We can reduce space complexity to O(1) because we only need the value of  the dp[i - 1]
