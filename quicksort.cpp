#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;


void quicksort(vector<int>& A, int a, int b){
    if(a >= b) return;
    int pi = a + (rand() % (b-a));
    swap(A[a], A[pi]);
    int p = A[a]; 
    int i = a+1, j = b-1;
    // invariant: [a+1,i) is <= p, [j+1,b) is > p
    while(i < j){
        if(A[i] <= p) i++;
        else if(A[j] > p) j--;
        else swap(A[i++], A[j--]);
    }
    swap(A[a], A[i]);
    cout << p << endl;
    for(int i = 0; i < A.size(); i++)
        cout << A[i] << ' ';
    cout << endl;

    quicksort(A,a,a+i);
    quicksort(A,a+i+1,j);
}

int main(){

    int n = 10;
    vector<int> A(n);
    for(int i = 0; i < n; i++)
        A[i] = i;

    random_shuffle(A.begin(), A.end());

    quicksort(A,0,10);

    for(int i = 0; i < n; i++)
        cout << A[i] << ' ';
    cout << endl;


}
