#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dx[2] = {0,1};
int dy[2] = {1,0};

void dfs(vector<vector<int>>& grid, int x, int y, vector<pair<int,int>>& path, bool& found) {
    if(found) {
        return;
    }
    
    path.push_back({x,y});
    if(x==grid.size()-1 && y==grid[0].size()-1) {
        found = true;
        return;
    }
    
    for(int dir = 0; dir < 2; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]!=1) {
            dfs(grid,nx,ny,path,found);
            if(found) {
                return;
            }
        }
    }
    path.pop_back(); 
}



int main() {
    
    vector<vector<int>> grid = {{0,0,0,1,0},
                                {0,0,0,0,0},
                                {0,1,0,1,0},
                                {1,1,0,1,0}};
    
    bool found = false;
    
    vector<pair<int,int>> path;
    
    dfs(grid,0,0,path,found);
    
    cout<<path.size()<<endl;
    for(auto P:path) {
        cout<<P.first<<" "<<P.second<<endl;
    }
    
    return 0;
}
