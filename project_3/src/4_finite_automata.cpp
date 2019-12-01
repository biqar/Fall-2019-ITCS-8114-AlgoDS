#pragma warning ( disable : 4786 )

#include <iostream>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

#define scale(x) (x-'A')
#define rev_scale(x) (x+'A')

typedef long double ld;

const int MAX = 1000005;
const int inf = (1 << 28);

string text, pattern;
int text_len, pattern_len;
int dfa[30][MAX], pi[MAX];

//kmp_failure_function_fast
void prefix_function() {
    pi[0] = 0;
    for(int i=1; i<pattern_len; i+=1) {
        int j = pi[i-1];

        while(j>0 && pattern[i] != pattern[j]) j = pi[j-1];
        if(pattern[i] == pattern[j]) j += 1;
        pi[i] = j;
    }
}

void calculate_dfa_table() {
    prefix_function();
    for (int i = 0; i < pattern_len; i+=1) {
        for (int c = 0; c < 26; c+=1) {
            if (i > 0 && rev_scale(c) != pattern[i]) dfa[c][i] = dfa[c][pi[i-1]];
            else dfa[c][i] = i + (rev_scale(c) == pattern[i]);
        }
    }
}

void print_dfa_table() {
    for(int i=0; i<26; i+=1) {
        for(int j=0; j<pattern_len; j+=1) {
            printf("%d ", dfa[i][j]);
        }
        printf("\n");
    }
}

int dfa_matching() {
    calculate_dfa_table();

    int current_state = 0;
    for(int i=0; i<text_len; i+=1) {
        current_state = dfa[scale(text[i])][current_state];
        if(current_state == pattern_len) return (i - pattern_len + 1);
    }
    return -1;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int i, j, k;
    int test, t = 0, kase = 0;

    getline(cin, text);
    getline(cin, pattern);
    text_len = text.length();
    pattern_len = pattern.length();

    double st = clock();
    int match_found = dfa_matching();
    cerr << (clock() - st) / CLOCKS_PER_SEC << endl;

    if(match_found == -1) printf("pattern not matched in the text\n");
    else printf("pattern matched in the text at text position: %d\n", match_found);

    return 0;
}
