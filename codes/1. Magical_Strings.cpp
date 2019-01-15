#include <bits/stdc++.h>
using namespace std;

// Rules:
// "a" must only be followed by "e".
// "e" must only be followed by "a" or "i".
// "i" must only be followed by "a", "e", "i"

int magicalStrings(int N) {
    if(N==1) return 3;
    
    int dp[N+1][3]; // {len, charEnding}
    memset(dp,0,sizeof(dp));
    // 'a', 'e', 'i'
    dp[1][0] = 1, dp[1][1] = 1, dp[1][2] = 1; 

    for(int i=2;i<=N;i++) {
        dp[i][0]+=(dp[i-1][1] + dp[i-1][2]); // ending with 'a'
        dp[i][1]+=(dp[i-1][0] + dp[i-1][2]); // ending with 'e'
        dp[i][2]+=(dp[i-1][1] + dp[i-1][2]); // ending with 'i'
    }
    return dp[N][0] + dp[N][1] + dp[N][2];
}

int main() {
    
    cout<<magicalStrings(1)<<endl;
    cout<<magicalStrings(2)<<endl;
    cout<<magicalStrings(3)<<endl;
    cout<<magicalStrings(10)<<endl;
    cout<<magicalStrings(15)<<endl;
    
    return 0;
}
