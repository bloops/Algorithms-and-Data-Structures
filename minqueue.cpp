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
#define foreach(it, c) for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

typedef long long int lli;
typedef pair<int,int> ii;
typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;

template <typename T, class C = std::less<T> > 
class minque {
private: 
    typedef pair<T,int> Ti;
    int time, _size;
    deque<Ti> M, Q;
    C cmp;
public:    
    minque() : time(0), _size(0) {}
    void push(T a){
        Q.push_back(Ti(a,++time));
        while(!M.empty() and !cmp(M.back().first,a)){
            M.pop_back();
        }
        M.push_back(Ti(a, time));
        _size++;
    }
    void pop(){
        if(M.front() == Q.front())
            M.pop_front();
        Q.pop_front();
        _size--;
    }
    T min(){ return M.front().first; }
    T front(){ return Q.front().first; }
    T back(){ return Q.back().first; }
    int size() { return _size; }
    bool empty() { return _size == 0; }
    T operator[](int i) { return Q[i].first; }
};

template <typename T, class C = std::less<T> > 
class minstack {
private: 
    typedef pair<T,int> Ti;
    int time, _size;
    deque<Ti> M, Q;
    C cmp;
public:    
    minstack() : time(0), _size(0) {}
    void push(T a){
        Q.push_back(Ti(a,++time));
        if(M.empty() or cmp(a,M.back().first)){
            M.push_back(Ti(a, time));
        }
        _size++;
    }
    void pop(){
        if(M.back() == Q.back())
            M.pop_back();
        Q.pop_back();
        _size--;
    }
    void clear() { while(!empty()) pop(); }
    T min(){ return M.back().first; }
    T front(){ return Q.front().first; }
    T back(){ return Q.back().first; }
    int size() { return _size; }
    bool empty() { return _size == 0; }
    T operator[](int i) { return Q[i].first; }
};

template <typename T, class C = std::less<T> >
class mindeque {
private:
    int _size;
    C cmp;
    minstack<T,C> A,B;
    void rebuild(){
        vector<T> v(_size);
        for(int i = 0;i < _size;i++)
            v[i] = (*this)[i];
        A.clear(), B.clear();
        for (int i = 0; i < _size/2; i++)
            A.push(v[(_size/2)-1-i]);
        for (int i = _size/2; i < _size; i++)
            B.push(v[i]);
    }
public:
    mindeque() : _size(0) {}
    int size() { return _size; }
    bool empty() { return _size == 0; }
    void push_back(T a) { B.push(a), _size++; }
    void push_front(T a) { A.push(a), _size++; }
    void pop_front() { 
        A.pop(), _size--;
        if(A.size() == 0 and _size > 1) 
            rebuild();
    }
    void pop_back() {
        B.pop(), _size--;
        if(B.size() == 0 and _size > 0)
            rebuild();
    }
    T min(){
        if(A.empty()) return B.min();
        T a = A.min(), b = B.min();
        return cmp(a,b) ? a : b;
    }
    T operator[](int i){ 
        if(i < A.size()) return A[A.size()-1-i];
        return B[i - A.size()];
    }
};


struct cmp{
    bool operator()(int a, int b){ return b < a;};
};

int main()
{
    ios::sync_with_stdio(false);

    mindeque<int,cmp> q;
    string s; 
    int a;
    while(cin >> s){
        if(s == "m") cout << "Min: " << q.min() << endl;
        else if(s == "pb") {
            cin >> a;
            q.push_back(a);
        }
        else if(s == "pf") {
            cin >> a;
            q.push_front(a);
        }
        else if(s == "rb") q.pop_back();
        else if(s == "rf") q.pop_front();
        else if(s == "s") {
            cout << "Q: "; FOR(i,q.size()) cout << q[i] << ' '; cout << endl;
        }
    }
    return 0;
}

