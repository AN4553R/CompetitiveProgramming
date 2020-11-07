class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        bool vis[500005];
        int ans = 1;
        
        for(int i = 0; i < (int)s.size() - 1; i++){
            memset(vis, 0, sizeof(vis));
            vis[s[i]] = true;
            for(int j = i + 1; j < s.size(); j++){
                if(!vis[s[j]]){
                    ans = max(ans, j - i + 1);
                    vis[s[j]] = 1;
                }
                else
                    break;
            }
        }
        return min(ans, (int)s.size());
    }
};
