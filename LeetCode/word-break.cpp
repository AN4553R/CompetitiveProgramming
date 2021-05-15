class Solution {
public:
    unordered_map<string, bool>used;
    
    bool dfs(string s, set<string>dict) {
        
        if((int)s.size() == 0)
            return true;
        if(used.count(s))return used[s];
        
        for(int i = 1; i <= (int)s.size(); i++) {
            string str = s.substr(0, i);
            if(dict.find(str) != dict.end() && dfs(s.substr(i, s.size()), dict)){
                used[str] = true;
                return true;
            }
        }
        used[s] = false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>dict;
        for(string i:wordDict)dict.insert(i);
        // return dfs(s, dict);
        
        vector<bool>dp(s.size() + 5);
        
        dp[0] = 1;
        
        for(int i = 1; i <= s.size(); i++) {
            for(int j = 0; j  < i; j++) {
             string word = s.substr(j , i - j);
                dp[i]=dp[j] && dict.find(word)!=dict.end() || dp[i];
            }
        }
        return dp[s.size()];
    }
};
