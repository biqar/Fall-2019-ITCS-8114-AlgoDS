#pragma warning ( disable : 4786 )

#include <iostream>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>

#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <fstream>
#include <ctime>

using namespace std;

//#define _rep( i, a, b, x ) for( __typeof(b) i = ( a ); i <= ( b ); i += x )
#define _rep(i, a, b, x) for( i = ( a ); i <= ( b ); i += x )
#define rep(i, n) _rep( i, 0, n - 1, 1 )

#define ff first
#define ss second

#define pii pair< int, int >
#define psi pair< string, int >

#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define set(p) memset(p, -1, sizeof(p))
#define clr(p) memset(p, 0, sizeof(p))

//typedef long long i64;
//typedef __int64 i64;
typedef long double ld;

//const double pi = (2.0*acos(0.0));
const double pi = acos(-1.0);
const double eps = 1e-9;
const int inf = (1 << 28);
const int MAX = 50005;

int input_arr[MAX];
int x;

int merge(int n, int start, int mid, int end){
    int n1= mid - start +1;
    int n2= end-mid;
    int leftArray[n1];
    int rightArray[n2];
    int i,j,k;
    for(i=0; i<n1; i++){
        leftArray[i]=input_arr[start+i];
    }
    for(j=0; j<n2; j++){
        rightArray[j]=input_arr[mid+1+j];
    }
    i=0, j=0, k=start;
    while(i<n1 && j<n2){
        if(leftArray[i]<=rightArray[j]){
            input_arr[k++]=leftArray[i++];
        }else{
            input_arr[k++]=rightArray[j++];
        }
    }
    while(i<n1){
        input_arr[k++]=leftArray[i++];
    }
    while(j<n2){
        input_arr[k++]=rightArray[j++];
    }

    return 0;
}

int mergeSort(int n, int start, int end) {
    if (start < end){
        int mid = (end+start)/2;
        mergeSort(n, start, mid);
        mergeSort(n, mid+1, end);
        merge(n, start, mid, end);
    }
    return 0;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int i, j, k;
    int test, t = 0, kase = 0;
    //
    int n;
    scanf("%d", &x);
    n = x;
    for(i=0; i<n; i+=1) {
        scanf("%d", &input_arr[i]);
    }
    double st = clock();
    int start =0;
    int end = n-1;
    mergeSort(n, start, end);
    for(i=0; i<n; i+=1) {
        printf("%d\n", input_arr[i]);
    }
    cerr << (clock() - st) / CLOCKS_PER_SEC << endl;
    //
    return 0;
}
