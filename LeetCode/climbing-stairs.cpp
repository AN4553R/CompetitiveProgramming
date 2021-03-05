class Solution {
    int dp[100005];
    int solve(int idx, int n) {
        if(idx > n) return 0;
        if(idx == n) return 1;
        
        int & ret = dp[idx];
        if(~ret)return ret;
        ret = 0;
        ret+=solve(idx + 1, n ) + solve(idx + 2, n);
        
        return ret;
    }
public:
    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        
        return solve(0, n);
    }
};
