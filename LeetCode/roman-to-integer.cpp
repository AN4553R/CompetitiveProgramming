#include<bits/stdc++.h>
class Solution {

int lst[7] = {1, 5, 10, 50, 100, 500, 1000};
    
public:
    int romanToInt(string s) {
        unordered_map<char, int>mp;
        mp['I'] = 1, mp['V'] = 5, mp['X'] = 10, mp['L'] = 50, mp['C'] = 100, mp['D'] = 500, mp['M'] = 1000;
        
        int result = 0;
        
        for(int i = 0; i < s.size(); i++) {
            auto lim = lower_bound(lst, lst + 7, mp[s[i]]);
            int tmp = 0;
            if(
                (s[i] == 'I' && i + 1 < s.size() && (s[i + 1] == 'V' || s[i + 1] == 'X'))
                ||
                (s[i] == 'X' && i + 1 < s.size() && (s[i + 1] == 'L' || s[i + 1] == 'C'))
                ||
                (s[i] == 'C' && i + 1 < s.size() && (s[i + 1] == 'D' || s[i + 1] == 'M'))
              ) {
                tmp = -*lim;
            }
            else {
                tmp = *lim;
            }
            result+=tmp;
        }
        
        return result;
    }
};
