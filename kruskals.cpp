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
vector<pair<int, ii> > E;

int parent[N];
int rank[N];

void init(int n){
    REP(i,n) {
        parent[i] = i;
        rank[i] = 1;
    }
}

int find(int i){
    if(parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

int join(int i, int j){
    i = find(i), j = find(j);
    if(rank[i] < rank[j])
        swap(i,j);
    parent[j] = i;
    rank[i] += rank[j];
}

int main() {
    int n, m;
    cin >> n >> m;

    int u, v;
    int cost;

    REP(i,m){
        cin >> u >> v >> cost;
        E.push_back(make_pair(cost, ii(u,v)));
    }

    sort(ALL(E));

    int total = 0;
    init(n);
    REP(i,m){
        int u = E[i].second.first, v = E[i].second.second;
        int cost = E[i].first;
        if(find(u) != find(v)){
            total += cost;
            join(u,v);
        }
    }

    cout << total << endl;
}
