#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-window-substring/description/

string minWindow(string S, string T) {
    if (S.size() == 0 || T.size() == 0) 
        return "";
    
    vector<int> freq(26, 0);
    
    int required = T.size();
    
    for (int i = 0; i < required; i++) 
        freq[T[i]]++;
    
    int min = INT_MAX;
    int left = 0;
    int i = 0, j = 0;
    
    while(j < S.size() && i<=j) {
        if(required > 0) {
            freq[S[j]]--;
            if(freq[S[j]] >= 0) required--;
            j++;
        } 
        
        if(required == 0) {
            if ((j - i) + 1 < min) {
                min = (j - i) + 1;
                left = i;
            }
            
            freq[S[i]]++;
            
            if(freq[S[i]] > 0) 
                required++;
            
            i++;
        }
    }
    
    return min == INT_MAX ? "" : S.substr(left, min);
}


int main() {
    
    string S = "ADOBECODEBANC";
    string T = "ABC";
    
    cout<<minWindow(S,T)<<endl;
    
    return 0;
}


