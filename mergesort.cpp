
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

int scratch[100010];

void mergesort(vector<int>& A, int a, int b){
    if(b - a <= 1) return;
    int m = (a + b)/2;
    mergesort(A,a,m);
    mergesort(A,m,b);

    int k = a;
    int i = a, j = m;
    while(i < m or j < b){
        if(j >= b or (i < m and A[i] <= A[j]))
            scratch[k++] = A[i++];
        else
            scratch[k++] = A[j++];
    }
    for(int l = a; l < b; l++)
        A[l] = scratch[l];
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    REP(i,n){ cin >> A[i]; }

    mergesort(A,0,n);
    REP(i,n){ cout << A[i] << ' ';}
}

