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

const int N = 55;
bool visited[N];
bool G[N][N];

// returns the size of vertex i's component
int dfs(int i){
    if(visited[i]) return 0;
    visited[i] = 1;
    int ret = 1;
    FOR(j,n) if(G[i][j]) ret += dfs(j);
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    
    return 0;
}

