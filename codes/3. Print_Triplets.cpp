#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

/*
Find all 3 integers in the array sum to 0.
[-3,3,0,2,-2,1] -> [[-3, 3, 0], [0, 2, -2], … ]

Examples
[-3,3,0,2] -> [[-3,3,0], …, ]
[1,2,3,4] -> []

Assuming repetitions is allowed
[0, -1, 2] -> [[0, 0, 0], [-1, -1, 2]]
*/


void printTriplets(vector<int>& arr) {  
    int i,j,k;
    int n = arr.size();
    
    if(n==0) {
        return;
    }
    
    sort(arr.begin(), arr.end());
    
    for(i=0;i<n;i++) {
        j = i;
        k = n-1;
        
        int target = (-arr[i]);
        
        while(j<=k) {
            if(arr[j] + arr[k] > target) k--;
            else if(arr[j] + arr[k] < target) j++; 
            else {
                cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                j++,k--;
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    //vector<int> arr = {0};
    vector<int> arr = {-2,-1, 0, 1, 2};
    // {-2, 1, 1}
    
    printTriplets(arr);
    
    return 0;
}
