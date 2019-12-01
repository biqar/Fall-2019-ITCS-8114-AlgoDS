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
int shift_table[30];

void build_shift_table() {
    for(int i=0; i<30; i+=1) shift_table[i] = pattern_len;
    for(int j=1,i=pattern_len-2; i>=0; j+=1,i-=1) {
        if(shift_table[scale(pattern[i])] == pattern_len) shift_table[scale(pattern[i])] = j;
    }
}

void print_shift_table() {
    for(int i=0; i<26; i+=1) {
        printf("%c:%d ", rev_scale(i), shift_table[i]);
    }
    printf("\n");
}

int horspool_matching() {
    build_shift_table();

    int i = pattern_len - 1;
    while(i < text_len) {
        int j = 0;
        while(j<pattern_len && pattern[pattern_len-1-j] == text[i-j]) j+= 1;
        if(j == pattern_len) return (i - pattern_len + 1);
        i += shift_table[scale(text[i])];
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
    int match_found = horspool_matching();
    cerr << (clock() - st) / CLOCKS_PER_SEC << endl;

    if(match_found == -1) printf("pattern not matched in the text\n");
    else printf("pattern matched in the text at text position: %d\n", match_found);

    return 0;
}
