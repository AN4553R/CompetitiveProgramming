class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>used;
        int prefixSum = 0;
        used[prefixSum] = 1;
        int result = 0;
        for(int num = 0; num < nums.size(); num++) {
            prefixSum+=nums[num];
            result+=used[prefixSum - k];
            used[prefixSum]++;
        }
        return result;
    }
};
