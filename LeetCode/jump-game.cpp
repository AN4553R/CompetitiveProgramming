class Solution {
    
public:
    bool canJump(vector<int>& nums) {
    
        int n = nums.size();

        int left_most_good = n - 1;

        for(int i = n - 2; i >= 0; i--) {
            if(i + nums[i] >= left_most_good) {
                left_most_good = i;
            }
        }
        
        return !left_most_good;
    
    }
};
