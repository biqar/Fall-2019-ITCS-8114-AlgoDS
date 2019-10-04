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
const int MAX = 1000005;

int max_heap[MAX], min_heap[MAX];
int max_heap_sz, min_heap_sz;

void min_heap_insert(int key, int pos) {
    min_heap[pos] = key;
    int i = pos;
    while(i>1 && min_heap[i/2] > min_heap[i]) {
        swap(min_heap[i], min_heap[i/2]);
        i = i / 2;
    }
}

int heap_remove_min() {
    int j, i = 1, tmp = min_heap[1];
    min_heap[1] = min_heap[min_heap_sz];
    min_heap_sz -= 1;

    while(i < min_heap_sz) {
        if(2*i+1 <= min_heap_sz) {    //min_heap node has 2 child
            if(min_heap[i] <= min_heap[2*i] && min_heap[i] <= min_heap[2*i+1]) {
                return tmp;
            }
            else {
                if(min_heap[2*i] < min_heap[2*i+1]) j = 2*i;
                else j = 2*i+1;

                swap(min_heap[i], min_heap[j]);
                i = j;
            }
        }
        else {  //min_heap node has 0 or 1 child
            if(2*i <= min_heap_sz && min_heap[i] > min_heap[2*i]) {
                swap(min_heap[i], min_heap[2*i]);
            }
            return tmp;
        }
    }
    return tmp;
}

int peek_min_heap() {
    return min_heap[1];
}

void max_heap_insert(int key, int pos) {
    max_heap[pos] = key;
    int i = pos;
    while(i>1 && max_heap[i/2] < max_heap[i]) {
        swap(max_heap[i], max_heap[i/2]);
        i = i / 2;
    }
}

int heap_remove_max() {
    int j, i = 1, tmp = max_heap[1];
    max_heap[1] = max_heap[max_heap_sz];
    max_heap_sz -= 1;

    while(i < max_heap_sz) {
        if(2*i+1 <= max_heap_sz) {    //max_heap node has 2 child
            if(max_heap[i] >= max_heap[2*i] && max_heap[i] >= max_heap[2*i+1]) {
                return tmp;
            }
            else {
                if(max_heap[2*i] > max_heap[2*i+1]) j = 2*i;
                else j = 2*i+1;

                swap(max_heap[i], max_heap[j]);
                i = j;
            }
        }
        else {  //max_heap node has 0 or 1 child
            if(2*i <= max_heap_sz && max_heap[i] < max_heap[2*i]) {
                swap(max_heap[i], max_heap[2*i]);
            }
            return tmp;
        }
    }
    return tmp;
}

int peek_max_heap() {
    return max_heap[1];
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int i, j, k;
    int test, t = 0, kase = 0;
    int n, data;

    //load input after this line

    double st = clock();

    min_heap_sz = min_heap_sz = 0;
    scanf("%d", &n);
    for(i=1; i<=n; i+=1) {
        scanf("%d", &data);
        min_heap_insert(data, i);
        min_heap_sz += 1;

        max_heap_insert(heap_remove_min(), i);
        max_heap_sz += 1;

        if(min_heap_sz < max_heap_sz) {
            min_heap_insert(heap_remove_max(), i);
            min_heap_sz += 1;
        }

        //printf("sz of min: %d, sz of max: %d\n", min_heap_sz, max_heap_sz);
        //printf("peek of min: %d, peek of max: %d\n", peek_min_heap(), peek_max_heap());

        if(min_heap_sz > max_heap_sz) {
            printf("median of first %d numbers => %d\n", i, peek_min_heap());
        }
        else {
            printf("median of first %d numbers => %lf\n", i, (peek_min_heap() + peek_max_heap())/2.0);
        }
    }

    //note: implement your algorithm here ... execution time will be printed automatically!

    cerr << (clock() - st) / CLOCKS_PER_SEC << endl;

    return 0;
}
