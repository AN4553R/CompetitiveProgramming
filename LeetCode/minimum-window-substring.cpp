class Solution {
public:
    string minWindow(string s, string t) {
        
        //frequency mapping
        int FP[256]={0};
        int FS[256]={0};
        int cnt=0;
        int start=0; //left contraction
        int start_idx=-1 ;//for best window
        int min_so_far=INT_MAX;
        
        for(int i = 0;i < t.size();i++){
            FP[t[i]]++;
        }
        
        //sliding window algo
        for(int i = 0; i < s.size();i++){
        //expand window by including current character
        
            char ch=s[i];
            FS[ch]++;
            //count how many characters have been matched till now
            if(FP[ch] && FS[ch] <= FP[ch]){
                cnt+=1;
            }
            //if all characters are found in current window then start contracting
            
            if(cnt == t.size()){
                
                //start contracting 
                while(FP[s[start]] == 0 || FS[s[start]] > FP[s[start]]){
                    FS[s[start]]--;
                    start++;
                }
            
                int window_size = i - start + 1;
                
                if(window_size < min_so_far){
                    min_so_far = window_size;
                    start_idx = start;
                }
            }
        
        }
        
        if(start_idx == -1){
            return "";
        }
        
        return s.substr(start_idx, min_so_far);
    }
};
