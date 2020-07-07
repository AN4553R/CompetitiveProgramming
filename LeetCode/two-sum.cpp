class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int>ret;
        map<int, int>idx;
        for(int i = 0; i < nums.size(); i++)
            idx[nums[i]] = i;
        for(int i = 0; i < nums.size(); i++)
            if(idx[target - nums[i]] && idx[target - nums[i]] != i)
            {
                ret.push_back(min(i, idx[target - nums[i]]));
                ret.push_back(max(i, idx[target - nums[i]]));
                break;
            }
        return ret;
    }
};
