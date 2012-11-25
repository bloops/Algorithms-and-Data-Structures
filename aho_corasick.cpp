
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

const int K = 2;
vector< map<char,int> > T, A;

void insertTrie(const string p, int i = 0, int x = 0){
   if(i >= p.size()) return; 
   if(!T[x].count(p[i])){
       T[x][p[i]] = T.size();
       T.push_back(map<char,int>());
   }
   insertTrie(p,i+1,T[x][p[i]]);
}

void makeSuffixAutomaton(){
    A = vector< map<char,int> >(T.size());
    REP(j,K) A[0]['a'+j] = 0;
    
    /*cout << T.size() << endl;

    REP(i,T.size()){
        printf("%d ", i + 1);
        FORE(it,T[i])
            printf("(%c %d) ", it->first, it->second + 1);
        printf("\n");
    }
    return;
    */
    vector<int> q;
    q.push_back(0);
    REP(i,q.size()){
        int p = q[i];
        FORE(it, T[p]){
            int x = A[p][it->first];
            A[p][it->first] = it->second;
            REP(j,K){
                A[it->second]['a'+j] = T[x].count('a'+j) ? T[x]['a'+j] : A[x]['a'+j];
            }
            q.push_back(it->second);
        }
    }

    printf("\n");
    REP(i,A.size()){
        printf("%d ", i+1);
        FORE(it,A[i])
            printf("(%c,%d) ", it->first, it->second+1);
        printf("\n");
    }
}

int main() {
    T.push_back(map<char,int>());

    int n;
    cin >> n;

    string p;
    REP(i,n){
        cin >> p;
        insertTrie(p);
    }

    makeSuffixAutomaton();
}
