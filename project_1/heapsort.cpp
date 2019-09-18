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
using namespace std;

//#define _rep( i, a, b, x ) for( __typeof(b) i = ( a ); i <= ( b ); i += x )
#define _rep( i, a, b, x ) for( i = ( a ); i <= ( b ); i += x )
#define rep( i, n ) _rep( i, 0, n - 1, 1 )

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
const int inf = (1<<28);
const int MAX = 50005;

int heap[MAX];
int input_arr[MAX];
int n;

void heap_insert(int key, int pos) {
    heap[pos] = key;
    int i = pos;
    while(i>1 && heap[i/2] > heap[i]) {
        swap(heap[i], heap[i/2]);
        i = i / 2;
    }
}

int heap_remove_min() {
    int j, i = 1, tmp = heap[1];
    heap[1] = heap[n];
    n -= 1;

    while(i < n) {
        if(2*i+1 <= n) {    //heap node has 2 child
            if(heap[i] <= heap[2*i] && heap[i] <= heap[2*i+1]) {
                return tmp;
            }
            else {
                if(heap[2*i] < heap[2*i+1]) j = 2*i;
                else j = 2*i+1;

                swap(heap[i], heap[j]);
                i = j;
            }
        }
        else {  //heap node has 0 or 1 child
            if(2*i <= n && heap[i] > heap[2*i]) {
                swap(heap[i], heap[2*i]);
            }
            return tmp;
        }
    }
    return tmp;
}

int main() {
    //freopen("input/in_50k.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int i, j, k;
    int test, t = 0, kase=0;
    int key, _n;

    scanf("%d", &n);
    _n = n;
    //printf("%d\n", n);
    for(i=1; i<=_n; i+=1) {
        scanf("%d", &input_arr[i]);
    }

    double st=clock();

    for(i=1; i<=_n; i+=1) {
        heap_insert(input_arr[i], i);
    }

    for(i=0; i<_n; i+=1) {
        //if(i) printf(" ");
        printf("%d\n", heap_remove_min());
    }
    //printf("\n");
    cerr << (clock()-st)/CLOCKS_PER_SEC << endl;

    return 0;
}
