#include <bits/stdc++.h>
using namespace std;

vector<int> getIntersection(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    vector<int> ANS;
    int idx1 = 0, idx2 = 0;
    while(idx1<A.size() && idx2<B.size()) {
        if(A[idx1]==B[idx2]) {
            ANS.push_back(A[idx1]);
            idx1++,idx2++;
        } else if(A[idx1]<B[idx2]) {
            idx1++;
        } else {
            idx2++;
        }
    }
    return ANS;
}

int main() {
    int arrA[] = {0, 1, 3, 3, 3, 4};
    int arrB[] = {2, 3, 3, 5};
    
    vector<int> A(arrA, arrA + 6);
    vector<int> B(arrB, arrB + 4);
    
    vector<int> ANS = getIntersection(A,B);
    
    for(int i=0;i<ANS.size();i++)
        cout<<ANS[i]<<" ";
    
    return 0;
}
