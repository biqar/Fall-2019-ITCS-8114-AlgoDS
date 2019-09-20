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

int n;
int input_arr[MAX];

int median_of_three(int a, int b, int c) {
    if((b <= a && a <= c) || (c <= a && a <= b)) return a;
    if((a <= b && b <= c) || (c <= b && b <= a)) return b;
    return c;
}

int get_pivot(int left, int right) {
    int mid = (left + right) / 2;
    return median_of_three(input_arr[left], input_arr[mid], input_arr[right]);
}

void inplace_quick_sort(int left, int right) {
    //base case
    if(left+10 <= right) {
        int pivot = get_pivot(left, right);
        int i = left, j = right;

        while(true) {
            while(input_arr[i] < pivot) i+=1;
            while(pivot < input_arr[j]) j -= 1;
            if(i < j) {
                swap(input_arr[i], input_arr[j]);
                i += 1;
                j -= 1;
            }
            else break;
        }
        inplace_quick_sort(left, i-1);
        inplace_quick_sort(j+1, right);
    }
    else {
        //todo: @Jawad please insert the code of insertion sort
        insertion_sort(left, right);
    }
}

int main() {
	//freopen("input/random/in_40k.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int i, j, k;
	int test, t = 0, kase=0;

	scanf("%d", &n);
    for(i=0; i<n; i+=1) {
        scanf("%d", &input_arr[i]);
    }

    double st=clock();

    inplace_quick_sort(0, n-1);

    for(i=0; i<n; i+=1) {
        printf("%d\n", input_arr[i]);
    }

    cerr << (clock()-st)/CLOCKS_PER_SEC << endl;

	return 0;
}
