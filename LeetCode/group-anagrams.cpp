class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int>>play;
        
        for(int i = 0; i < strs.size(); i++)play.push_back({strs[i], i});
        
        for(auto &i:play){
            sort(i.first.begin(), i.first.end());
        }
        sort(play.begin(), play.end());
        vector<vector<string>> result;
        
        vector<pair<string, int>> tmp = {play.back()};
    
        play.pop_back();
        
        while(!play.empty() || !tmp.empty())
        {
            if(play.empty())
            {
                vector<string>group;
                for(auto i:tmp)group.push_back(strs[i.second]);
                result.push_back(group);
                break;
            }
            if(play.back().first == tmp.back().first)
            {
                tmp.push_back(play.back());
                play.pop_back();
            }
            else {
                vector<string>group;
                for(auto i:tmp)group.push_back(strs[i.second]);
                result.push_back(group);
                tmp.clear();
                tmp.push_back(play.back());
                play.pop_back();
            }
        }
        return result;
        
    }
};
