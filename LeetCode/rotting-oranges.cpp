int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

class Solution {
public:
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int fresh = 0;
        
        vector<vector<int>> vis(grid.size(), vector<int> (grid[0].size(), 0));

        queue<vector<int> >turns; // x, y
        
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                fresh+=grid[i][j] == 1;
                if(grid[i][j] == 2){
                    turns.push({i, j});             
                    vis[i][j] = true;
                }
            }
        }
        
        int seconds = -1;
        
        while(!turns.empty()) {
            seconds++;
            
            if(!fresh) {
                return seconds;
            }
            
            int n = turns.size();
            
            for(int i = 0; i < n; i++){
                auto orange = turns.front();
                turns.pop();
                
                for(int dir = 0; dir < 4; dir++) {
                    int nxt_x = orange[0] + dx[dir];
                    int nxt_y = orange[1] + dy[dir];    
                    if(nxt_x >= 0 && nxt_x < grid.size() && nxt_y >= 0 && nxt_y < grid[nxt_x].size()) {
                        if(grid[nxt_x][nxt_y] == 1 && !vis[nxt_x][nxt_y]){
                            grid[nxt_x][nxt_y] = 2;
                            fresh--;
                            vis[nxt_x][nxt_y] = true;
                            turns.push({nxt_x, nxt_y});
                        }
                    }
                }
            }
        }
        if(fresh) return -1;
        return 0;
    }
};
