#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;

/* 
* You’re an avid pet owner and have a group of hungry dogs. 
* Each dog must be assigned two meals. 
* However, you don’t want to feed them too much. 
* We want to assign meals to the dogs so as to minimize the largest meal pair. 
*/

// Nice you'll want to explain why this works?
// We want to pair the max value with the min value so as to minimize the total pair sum.

vector<PII> dietAssignment(vector<int>& diets) {
    sort(diets.begin(), diets.end());
    vector<PII> ANS;
    int i=0, j = diets.size()-1;
    while(i<j) {
        ANS.push_back({diets[i],diets[j]});
        i++,j--;
    }
    return ANS;
}

int main() {
    vector<int> diets = {5, 2, 1, 4, 6, 4}; 
    
    vector<PII> ans = dietAssignment(diets);
    int res = INT_MIN;
    PII resPair;
    for(int i=0;i<ans.size();i++) {
        //cout<<ans[i].first<<" "<<ans[i].second<<endl;
        if(ans[i].first + ans[i].second > res) {
            resPair = {ans[i].first, ans[i].second};
            res = ans[i].first + ans[i].second;
        }
    }
    cout<<resPair.first<<" "<<resPair.second<<endl;
    return 0;
}
