class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sz = INT_MAX;
        string base = "";
        
        for(int i = 0;i < strs.size(); i++){
            if(strs[i].size() < sz){
                base = strs[i];
                sz = base.size();
            }
        }
        for(int i = 0; i < strs.size(); i++)
        {
            string cbase = base, cur = strs[i];
            while(cur.size() > cbase.size()){
                cur.pop_back();
            }
            int j = 0;
            for(; j < cbase.size(); j++)
            {
                if(cbase[j] !=cur[j])
                    break;
            }          
            base=cbase.substr(0, j);
    
        }
        return base;
    }
    
};
