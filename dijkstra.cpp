
#include <iostream>
#include <sstream>
#include <fstream>
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

#define FOR(i,a,n) for(int i=int(a);i<int(n);i++)
#define REP(i,n) FOR(i,0,n)
#define FORE(it, c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define ALL(c) c.begin(), c.end()
#define CLEAR(c,v) memset(c,v,sizeof(c))

typedef long long int lli;
typedef pair<int,int> ii;

const int INF = 1<<29;
const int N = 100010;
vector<ii> E[N];

int D[N];
int n;

int dijkstra(int s, int t){
    REP(i,n) D[i] = INF;
    priority_queue <ii, vector<ii>, greater<ii> > Q;
    Q.push(ii(0,s));
    while(!Q.empty()){
        int dist = Q.top().first;
        int u = Q.top().second;
        if(u == t) return dist;
        Q.pop();
        if(dist > D[u]) continue;
        REP(j,E[u].size()){
            int v = E[u][j].second;
            int cost = E[u][j].first;
            if(dist + cost < D[v]){
                D[v] = dist + cost;
                Q.push(ii(D[v],v));
            }
        }
    }
    return INF;
}

int main() {
    int m;
    cin >> n >> m;

    int u, v;
    int cost;

    REP(i,m){
        cin >> u >> v >> cost;
        E[u].push_back(ii(cost,v));
        E[v].push_back(ii(cost,u));
    }

    cout << dijkstra(0,n-1) << endl;
}
