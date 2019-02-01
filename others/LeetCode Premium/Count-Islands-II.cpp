class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    char h[5] = {'D','U','R','L','T'};
        
    void dfs(vector<vector<int>>& grid, int x, int y, string& hash, int N , int M) {
        grid[x][y] = 0;
        for(int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M) {
                if(grid[nx][ny]==1) {
                    hash+=h[i];
                    dfs(grid,nx,ny,hash,N,M);
                }
            }
        }
        hash+=h[4];
    }
    
    int numDistinctIslands(vector<vector<int>>& grid) {
        set<string> s;
        int N = (int)grid.size();
        int M = (int)grid[0].size();
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1){
                    string hash = "S";
                    dfs(grid,i,j,hash,N,M);
                    s.insert(hash);
                }
            }
            
        return s.size();
    }
};