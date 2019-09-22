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


int insertionSort(int n, int start, int end) {
    int i,j,k;
    for(j=start+1; j<=end; j++){
        k=input_arr[j];
        i=j-1;
        while(i>=0 && input_arr[i]>k){
            input_arr[i+1]=input_arr[i];
            i--;
        }
        input_arr[i+1]=k;
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
    insertionSort(n, start, end);
    for(i=0; i<n; i+=1) {
        printf("%d\n", input_arr[i]);
    }
    cerr << (clock() - st) / CLOCKS_PER_SEC << endl;
    //
    return 0;
}
