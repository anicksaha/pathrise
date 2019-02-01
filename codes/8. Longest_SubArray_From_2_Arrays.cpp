#include<bits/stdc++.h>
using namespace std;

/*
 Pair Programming
 Longest Sub-Array from Two Arrays
*/

int main() {
    //vector<int> A = {2, 3, 4, 5, 6};
    //vector<int> B = {4, 5, 6, 1, 2, 1, 1};
    
    //vector<int> A = {2, 10, 11, 12, 6};
    //vector<int> B = {4, 5, 6, 1, 2, 1, 1};
    
    vector<int> A = {0,0,0,0,2,3,0};
    vector<int> B = {0,0,2,3,0,0,0,0};
    
    //vector<int> A = {2, 3, 4, 5, 6};
    //vector<int> B = {4, 5, 6, 1, 2, 1, 1};

    int ans = 0;
    vector<vector<int>> dp(A.size()+ 1,vector<int>(B.size()+1,0));
    
    for(int i=0;i<A.size();i++) {
        for(int j=0;j<B.size();j++) {
            if(A[i]==B[j]) {
                dp[i+1][j+1] = 1 + dp[i][j];
            }
            ans = max(dp[i+1][j+1],ans);
        }   
    }
    
    cout<<ans<<endl;
    return 0;
}