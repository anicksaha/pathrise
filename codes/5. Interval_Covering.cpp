#include <bits/stdc++.h>
using namespace std;

/*
* Problem: Interval Covering
* You are given a set of closed intervals. 
* Design an efficient algorithm for finding a minimum sized set of numbers that cover all the intervals.
* @Return: Actual times (the smallest sized set) that covers all the intervals.

// 
// Like: [1,2], [3,6], [2,6] -> (2,6)
      vs [1,2], [2,6], [3,6] -> (2,6)
*/

struct Interval {
    int start, end;
};

bool comp(Interval X, Interval Y) {
    if(X.end!=Y.end)
        return X.end < Y.end;
    else 
        return X.start < Y.start;
}

vector<int> IntervalCovering(vector<Interval>& intervals) {
    vector<int> timeStamps;
    sort(intervals.begin(), intervals.end(), comp);
    
    timeStamps.push_back(intervals[0].end);
    int curr = intervals[0].end;
    
    for(int i=1;i<intervals.size();i++) {
        if(curr<intervals[i].start) {
            curr = intervals[i].end;
            timeStamps.push_back(curr);
        }
    }
    
    return timeStamps;
}

int main() {
    vector<Interval> intervals_1 = { {1,2}, {2,3}, {3,4}, {2,3}, {3,4}, {4,5} };
    vector<Interval> intervals_2 = { {0,3}, {2,6}, {3,4}, {6,9} };
    
    vector<int> timeStamps = IntervalCovering(intervals_2);
    
    for(int i=0;i<timeStamps.size();i++) {
        cout<<timeStamps[i]<<" ";    
    }
    cout<<endl;
    
    return 0;
}
