class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        
        int idx = 0;
        for(int i = 1; i < intervals.size(); i++) {
            auto a = intervals[idx];
            auto b = intervals[i];
            if(!(a[1] < b[0] || b[1] < a[0])) {
                intervals[idx][0] = min(intervals[idx][0], intervals[i][0]);
                intervals[idx][1] = max(intervals[idx][1], intervals[i][1]);
                intervals[i][0] = -1, intervals[i][1] = -1;
            }
           else {
               idx = i;
           }
        }
        for(auto i:intervals) {
            if(~i[0] && ~i[1]) {
                res.push_back(i);
            }
        }
        return res;
    }
};
