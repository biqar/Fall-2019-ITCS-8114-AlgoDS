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

struct comp {
    bool operator() (const pii &a, const pii &b) {
        return a.ss > b.ss;
    }
};

priority_queue< pii, vector< pii >, comp > pq;
vector<pii> graph[MAX];
int dist[MAX], nodes, edges, st, parent[MAX];
bool vis[MAX], is_directed;

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

        graph[u].push_back(pii(v, w));
        if(!is_directed) graph[v].push_back(pii(u, w));
    }

    getline(cin, line);
    stringstream ss_source(line);
    ss_source >> u_str;
    st = u_str[0] - 'A';

    /*for(int i=0; i<nodes; i+=1) {
        int sz = graph[i].size();
        for(int j=0; j<sz; j+=1) {
            cout << i << " " << graph[i][j].ff << " " << graph[i][j].ss << endl;
        }
    }
    cout << "starting node: " << st << endl;*/
}

void run_dijkstra () {
    int u, v, w, sz;
    for(int i=0; i<nodes; i+=1) {
        dist[i] = inf;
        vis[i] = false;
    }
    dist[st] = 0;
    parent[st] = -1;
    pq.push(pii(st, 0));

    while(!pq.empty()) {
        u = pq.top().ff;
        pq.pop();
        if(vis[u]) continue;
        sz = graph[u].size();
        for(int i=0; i<sz; i+=1) {
            v = graph[u][i].ff;
            w = graph[u][i].ss;
            if(!vis[v] && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push(pii(v, dist[v]));
            }
        }
        vis[u] = true;
    }
}

void print_path_recursive(int u) {
    // base case!
    if(parent[u] == -1) return;
    print_path_recursive(parent[u]);
    cout << u << " <- ";
}

void print_shortest_paths() {
    for(int i=0; i<nodes; i++) {
        cout << "from [" << st << "] to [" << i << "], min weight to reach: ";

        if(dist[i] >= inf) {
            cout << "unreachable" << endl;
        }
        else {
            cout << dist[i] << endl;
            cout << "path: ";
            print_path_recursive(i);
            cout << st << endl;
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int i, j, k;
    int test, t = 0, kase = 0;

    //load input after this line
    double st = clock();

    get_input();
    run_dijkstra();
    print_shortest_paths();

    cerr << "Execution time: " << (clock() - st) / CLOCKS_PER_SEC << endl;

    return 0;
}
