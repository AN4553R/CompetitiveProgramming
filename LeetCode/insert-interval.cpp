class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        
        int idx = 0;
        
        vector<int> b =  newInterval;
        while(idx < (int)intervals.size()) {
            vector<int> a =  intervals[idx];
            
            if(!(a[1] < b[0] || b[1] < a[0])) {
                    b[0] = min(a[0], b[0]);
                    b[1] = max(a[1], b[1]);
                idx++;
            }
            else {
                result.push_back(a);
                idx++;
            }
        }
        result.push_back(b);
        while(idx < (int)intervals.size()) {
            result.push_back(intervals[idx++]);
        }
        sort(result.begin(), result.end());
        return result;
        
    }
};
