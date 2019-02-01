#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'segment' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER x
 *  2. INTEGER_ARRAY arr
 */

int segment(int x, vector<int> arr) {
    deque<int> Q;

    // Process first sub-array
    for(int i=0;i<x;i++) {
        while(!Q.empty() && arr[i]<=arr[Q.back()])
            Q.pop_back();
        Q.push_back(i);    
    }
    int ans = arr[Q.front()];

    for(int i=x;i<arr.size();i++) {
        ans = max(ans,arr[Q.front()]);

        while(!Q.empty() && Q.front()<=(i-x))
          Q.pop_front();

        while(!Q.empty() && arr[i] <= arr[Q.back()])
          Q.pop_back();
        Q.push_back(i);
    }

    return ans;
}

int main()