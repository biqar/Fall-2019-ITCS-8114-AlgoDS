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
const int MAX = 1005;

struct disjoint_set {
    int parent, rank;
};

int total_mst_cost, nodes, edges;
bool is_directed;

vector< pair< int, pii > > edge_list, mst;
struct disjoint_set dset[MAX];

void init_dsd() {
    for(int i=0; i<nodes; i+=1) {
        dset[i].parent = i;
        dset[i].rank = 0;
    }
}

void get_input() {
    string line, dir, u_str, v_str;
    int u, v, w;

    getline(cin, line);
    stringstream ss(line);
    ss >> nodes;
    ss >> edges;
    ss >> dir;

    if(dir[0] == 'U') is_directed = false;
    else is_directed = true;

    for(int i=0; i<edges; i+=1) {
        getline(cin, line);
        stringstream ss(line);
        ss >> u_str;
        ss >> v_str;
        ss >> w;
        u = u_str[0] - 'A';
        v = v_str[0] - 'A';

        edge_list.push_back(make_pair(w, pii(u, v)));
    }

    if(is_directed) {
        cout << "Kruskal's algorithm for finding MST can't work on directed graph." << endl;
        exit(0);
    }

    /*for(int i=0; i<edges; i+=1) {
        cout << edge_list[i].ss.ff << " " << edge_list[i].ss.ss << " " << edge_list[i].ff << endl;
    }*/
}

/*find root of the disjoint set with path compression*/
int find_set(int x) {
    if(x != dset[x].parent) dset[x].parent = find_set(dset[x].parent);
    return dset[x].parent;
}

/*union disjoint sets by rank*/
void union_by_rank(int px, int py) {
    if(dset[px].rank < dset[py].rank) {
        dset[px].parent = py;
    }
    else if(dset[px].rank > dset[py].rank) {
        dset[py].parent = px;
    }
    else {
        dset[py].parent = px;
        dset[px].rank += 1;
    }
}

void calculate_mst() {
    int u, v, pu, pv;

    //sort edges by increasing order
    sort(edge_list.begin(), edge_list.end());

    for(int i=0; i<edges; i+=1) {
        u = edge_list[i].ss.ff;
        v = edge_list[i].ss.ss;

        pu = find_set(u);
        pv = find_set(v);

        /*u and v are not in same set, connect them by this edge and add a link among them*/
        if(pu != pv) {
            mst.push_back(edge_list[i]);
            total_mst_cost += edge_list[i].ff;
            union_by_rank(pu, pv);
        }
    }
}

void print_mst() {
    int sz = mst.size();

    cout << "Cost for building mst: " << total_mst_cost << endl;
    for(int i=0; i<sz; i+=1) {
        cout << (char) (mst[i].ss.ff + 'A') << " " << (char) (mst[i].ss.ss + 'A') << " -> " << mst[i].ff << endl;
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int i, j, k;
    int test, t = 0, kase = 0;

    //load input after this line
    double st = clock();

    //take input
    get_input();

    //initialize disjoint set data-structure
    init_dsd();

    //apply kruskal algorithm on the input graph to calculate mst
    calculate_mst();

    //print mst edges with weight
    print_mst();

    cerr << "Execution time: " << (clock() - st) / CLOCKS_PER_SEC << endl;

    return 0;
}
