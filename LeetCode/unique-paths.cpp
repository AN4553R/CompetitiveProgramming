class Solution {
    int dp[101][101];
    int solve(int i, int j, int n, int m) {
        
        if(i > n || j > m) return 0;
        if(i == n && j == m) return 1;
        
        int & ret = dp[i][j];
        
        if(~ret)return ret;
        ret = 0;
        
        ret+=solve(i, j + 1, n, m) + solve(i + 1, j, n, m);
        return ret;
    }
public:
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(1, 1, n, m);
        
    }
};
