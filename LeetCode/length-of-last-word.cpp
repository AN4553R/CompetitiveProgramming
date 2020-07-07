class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0, start = (int)s.size() - 1;
        while(start >= 0 and s[start] == ' ')start--;
        for(int i = start; i >= 0; i--)
        {
            if(s[i] == ' ')break;
            ret++;
        }
        return ret;
    }
};
