class Solution {
public: // O(N^3)? cuz we call the algorithm for each prefix and there are O(N) prefixes and the substr takes O(N)
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
        return dfs(s, dict);
    }
};
