class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
        {
            vector<vector<int>>v;
            return v;
        }
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int> >st;
        for(int i  = 0; i < n - 2; i++)
        {
            int l = i + 1, r = n - 1;
            
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0)
                    r--;
                else if(sum < 0)
                    l++;
                else {
                    vector<int>v = {nums[i], nums[l], nums[r]};
                    sort(v.begin(), v.end());
                    st.insert(v);
                    l++, r--;
                }
            }
            
        }
       for(auto i:st)result.push_back(i);
    
       return result;
    }
};
