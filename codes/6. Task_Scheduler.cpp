#include <bits/stdc++.h>
using namespace std;

/*
* Problem: Task Scheduler
* 
* We have scheduler performs tasks. Task types are identified with an integer id. 
* Each task takes 1 interval to complete and once it’s complete we take a cooldown of X intervals before another task of the same type can be run.
* We can still run other tasks with different ids. The cooldown is the same for all task types.
* 
* @Return: An integer representing the minimum intervals needed to process all tasks.
*/


int taskScheduler(vector<int>& tasks, int cooldown) {
    priority_queue<pair<int,int> > PQ;
    
}

int main() {
    vector<int> tasks = {3,3,1,3}; // [3 _ _ 3 1 _ 3] ans = 7
    int cooldown = 2;
    
    cout<<taskScheduler(tasks,cooldown)<<endl;
    
    return 0;
}
