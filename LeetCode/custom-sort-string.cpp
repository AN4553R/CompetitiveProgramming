class Solution {
public:
    string customSortString(string S, string T) {
       map<char, int>idx;
        for(int i = 0; i < S.size(); i++)
            idx[S[i]] = i;
        sort(T.begin(), T.end(), [&](char & a, char & b){return  idx[a] < idx[b];});
        return T;
    }
};
