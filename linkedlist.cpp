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

struct node{
    int val;
    node *next;
};

node *head = NULL;

void append(int x){
    if(head == NULL){
        head = new node;
        head->val = x;
        head->next = NULL;
    }
    else{
        node *p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = new node;
        p->next->val = x;
        p->next->next = NULL;
    }
}

void print(){
    node *p = head;
    while(p != NULL){
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;
}

void rev(){
    if(head -> next == NULL) return;
    node *a = head, *b = head -> next;
    a -> next = NULL;
    while(b != NULL){
        node *c = b -> next;
        b -> next = a;
        a = b;
        b = c;
    }
    head = a;
}

int main() {
    int n = 10;
    REP(i,n) append(i);
    print();
    rev();
    print();
}
