#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>
using namespace std;

#define FOR(i, n) for(int i=0;i<int(n);i++)
#define FOR1(i, n) for(int i=1;i<=int(n);i++)
#define FORA(i, a, n) for(int i=a;i<int(n);i++)
#define FORR(i, n) for(int i=n-1;i>=0;i--)
#define foreach(it, c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define all(c) c.begin(), c.end()

typedef long long int lli;
typedef pair<int,int> ii;
typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;

int main()
{
    ios::sync_with_stdio(false);
    
    vector<int> E[N];

    vector<int> topo;
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    FOR(i,n) if(indegree[i] == 0) q.push(i);

    while(!q.empty()){
        int p = q.front();
        q.pop();
        if(visited[p]) continue;
        visited[p] = 1;
        topo.push_back(p);
        FOR(j,children[p].size()) {
            indegree[children[p][j]]--;
            if(indegree[children[p][j]] == 0)
                q.push(children[p][j]);
        }
    }

    return 0;
}

