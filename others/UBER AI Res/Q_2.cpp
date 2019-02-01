#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'connectedCities' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER g
 *  3. INTEGER_ARRAY originCities
 *  4. INTEGER_ARRAY destinationCities
 */

unordered_map<int, int> parent;

int Find(int x) {
  if (parent.find(x) == parent.end())
    parent[x] = x;

  if (parent[x] != x)
    parent[x] = Find(parent[x]);

  return parent[x];
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);

  if (x != y)
    parent[x] = y;
}

int areConnected(int x, int y) {
  x = Find(x);
  y = Find(y);

  if(x == y) return 1;
  else return 0;
}

vector<int> connectedCities(int n, int g, vector<int> originCities, vector<int> destinationCities) {
    for(int i=g+1;i<=n;i++) {
        for(int j=i;j<=n;j+=i)
            Union(i,j);
    }

    vector<int> ans;
    for(int i=0;i<originCities.size();i++) {
      ans.push_back(areConnected(originCities[i], destinationCities[i]));
    }
    return ans;
}

int main()