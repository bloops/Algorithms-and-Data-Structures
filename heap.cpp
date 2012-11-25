#include <iostream> 
#include <algorithm> 
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<=n;i++)
#define P(i) cout << (i) << ' '
#define Pn cout << endl

const int N = 110;

class heap { 
public:
  int n, A[N];
  void heapup(int i) {
    if(i<=0) return;
    if(A[i]>A[i/2]) {
      swap(A[i],A[i/2]);
      heapup(i/2);
    }
  }
  
  void insert(int v) {
    A[++n]=v;
    heapup(n);
  }

  void heapdown(int i) {
    int k = i<<1; 
    if (k>n) return;
    if (k+1<=n)  
      if(A[k+1]>A[k])	
		k+=1;
    if (A[i]<A[k]) {
      swap(A[i],A[k]);
      heapdown(k);
    }
  }
    
  int deltop(){
    swap(A[1],A[n]);
    --n;
    heapdown(1);
    return A[n];
  }

  void makeheap(int m){
    n = m;
    make_heap(A+1,A+n+1);
  }

};



int main() { 
  int n; 
  heap h;
  cin >> n;
  FOR1(i,n) 
    cin >> h.A[i];
  h.makeheap(n);

  int c=0; 
  while(c!=-1) { 
    cin >> c; 
    if (c==1) {
      int v; cin >> v; h.insert(v);
    }
    else if (c==0) 
      h.deltop();

    FOR1(i,h.n)
      P(h.A[i]);
    Pn;
  }

}
