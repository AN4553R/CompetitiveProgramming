class Solution {
public:
    void solve(int idx, int target, vector<vector<int>>&res,vector<int>&sub_res, vector<int>&can) {
        if(target < 0 || idx == can.size())
            return;
        if(target  == 0) {
            res.push_back(sub_res);
            return;
        }
        // include
        sub_res.push_back(can[idx]);
        solve(idx, target - can[idx], res, sub_res, can);
        sub_res.pop_back();
        // exclude
        solve(idx + 1, target, res, sub_res, can);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>result;
        vector<int>sub_result;
        
        solve(0, target, result, sub_result, candidates);
        
        return result;
    }
};
