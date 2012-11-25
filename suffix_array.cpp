#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cstdio>
using namespace std;

#define FOR(i,n) for(int i=0;i<(int)n;i++)
#define FORA(i,a,n) for(int i=a;i<(int)n;i++)
#define FORD(i,a) for(int i=a;i>=0;i--)

typedef pair<int,int> ii;

const int N = 500010, logN = 20;
int A[logN+1][N];
int SA[N];

int lcp(int x, int y){
    if(x == y) return -1;
    int lcp = 0;
    FORD(k,logN) if(A[k][x] == A[k][y])
            lcp += (1<<k), x += (1<<k), y += (1<<k);
    return lcp;
}

pair<ii,int> P[N];

void constructSuffixArray(string s){ 
    int n = s.length();
    FOR(i,n) A[0][i] = s[i]-'a';

    FOR(k,logN){
        int p = 1 << k;
        FOR(i,n){
            ii rank = ii(A[k][i], -1);
            if(i + p < n) rank.second = A[k][i+p];
            P[i] = make_pair(rank, i);
        }
        sort(P,P+n);
        int cur = 0;
        FOR(i,n) {
            if(i > 0 and P[i].first > P[i-1].first) cur++;
            A[k+1][P[i].second] = cur;
        }
    }
    FOR(i,n) SA[A[logN][i]] = i;

    //FOR(i,n) cout << A[logN][i] << ' '; cout << endl;

}


int longestCommonSubstring(string s, string t){
    string r = s + '#' + t;
    constructSuffixArray(r);
    int n = s.size();
    int longest = 0;
    FOR(i,r.size()-1) 
        if((SA[i] < n and SA[i+1] > n) or (SA[i] > n and SA[i+1] < n))
            longest = max(lcp(SA[i],SA[i+1]), longest);
    return longest;
}
int main()
{
    ios::sync_with_stdio(false);
    string s, t;
    // {
    //     int n = 100000;
    //     s = string(n,'a'), t = string(n,'a');
    //     srand(time(0));
    //     FOR(i,n) s[i] = (rand()%26) + 'a';
    //     FOR(i,n) t[i] = (rand()%26) + 'a';
    // }
    // cout << s << endl;
    // cout << t << endl;
    cin >> s >> t;
    //constructSuffixArray(s);
    cout << longestCommonSubstring(s,t) << endl;

    return 0;
}

