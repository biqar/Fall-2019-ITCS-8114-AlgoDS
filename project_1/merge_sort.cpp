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
const int MAX = 1005;
int* ioArray = NULL;

int merge(int n, int start, int mid, int end){
    int n1= mid - start +1;
    int n2= end-mid;
    int leftArray[n1];
    int rightArray[n2];
    int i,j,k;
    for(i=0; i<n1; i++){
        leftArray[i]=ioArray[start+i];
    }
    for(j=0; j<n2; j++){
        rightArray[j]=ioArray[mid+1+j];
    }
    i=0, j=0, k=start;
    while(i<n1 && j<n2){
        if(leftArray[i]<=rightArray[j]){
            ioArray[k++]=leftArray[i++];
        }else{
            ioArray[k++]=rightArray[j++];
        }
    }
    while(i<n1){
        ioArray[k++]=leftArray[i++];
    }
    while(j<n2){
        ioArray[k++]=rightArray[j++];
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

    //load input after this line
    int x, n;
    ifstream inFile;
    inFile.open("input\\random\\in_50k.txt"); // put the input file path here
    if (!inFile){
        cerr<< "Error!"<<endl;
        exit(1);
    }
    int index=0;
    while (inFile >> x){
        if (!index){
            n=x;
            ioArray = new int[n];
        }else{
            ioArray[index-1]=x;
        }
        index+= 1;
    }
    inFile.close();
    //note: implement your algorithm here ... execution time will be printed automatically!
    double st = clock();
    int start =0;
    int end = n-1;
    mergeSort(n, start, end);
    cerr << (clock() - st) / CLOCKS_PER_SEC << endl;
    // load output here
    ofstream outfile ("output\\merge_sort\\out_50k.txt");
    if (outfile.is_open()){
        for(i=0; i < n; i++){
            outfile << ioArray[i] << endl ;
        }
        outfile.close();
    }
    return 0;
}
