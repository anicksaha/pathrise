#include <bits/stdc++.h>
using namespace std;


int minFallingPathSum(vector<vector<int>>& A) {
    int N = A.size();
    int dp[N][N];
    int ans = INT_MAX;
    
    for(int j=0;j<N;j++)
        dp[0][j] = A[0][j];
    
    for(int i=1;i<N;i++) {
        for(int j=0;j<N;j++) {
            int tmp_min = dp[i-1][j];
            if(j>0) tmp_min = min(tmp_min, dp[i-1][j-1]);
            if(j+1<N) tmp_min = min(tmp_min, dp[i-1][j+1]);
            dp[i][j] = A[i][j] + tmp_min;
        }
    }
    
    for(int j=0;j<N;j++)
        ans = min(ans, dp[N-1][j]);
    
    return ans;
}
    
int main() {
    
    vector<vector<int>> A = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    vector<vector<int>> B = {{-10, 5, 2},{-1,  -2, 3}};
    cout<<minFallingPathSum(A)<<endl;
    cout<<minFallingPathSum(B)<<endl;
    
    return 0;
}


