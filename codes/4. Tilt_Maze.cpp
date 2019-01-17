#include <bits/stdc++.h>
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

struct Node {
    int x,y,moves;
};

int canReach(pair<int,int> source, pair<int,int> destination, vector<vector<int>>& grid) {
    int N = grid.size();
    int M = grid[0].size();
    
    //cout<<N<<" "<<M<<endl;
    //bool visited[N][M];
    //memset(visited,false,sizeof(visited));
    
    vector<vector<bool>> visited(N,vector<bool>(M,false));

    queue<Node> Q;
    
    Q.push({source.first,source.second,0});
    visited[source.first][source.second] = 1;
    
    while(!Q.empty()) {
        Node front = Q.front();
        Q.pop();

        if(front.x == destination.first && front.y == destination.second)
            return front.moves;
        
        for(int i=0;i<4;i++) {
            int nx = front.x;
            int ny = front.y; 
            
            while(nx>=0 && ny>=0 && nx<N && ny<M && grid[nx][ny] == 0) {
                nx+=dx[i];
                ny+=dy[i];
            }
            
            if(!visited[nx-dx[i]][ny-dy[i]]) {
                Q.push({nx-dx[i], ny-dy[i],front.moves+1});
                visited[nx-dx[i]][ny-dy[i]] = 1;
            }
        }   
    }
    
    return -1; 
}

int main() {
    
    vector<vector<int>> grid = { { 0, 0, 1, 0, 0 },
                                 { 0, 1, 0, 0, 1 },
                                 { 0, 0, 0, 0, 0 }
                                };
                                
    cout<<canReach({0,4},{2,4},grid);
    
    return 0;
}
