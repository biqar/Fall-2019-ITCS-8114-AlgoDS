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
int bs_shift_table[30], gs_shift_table[MAX], pos[MAX];
int number_of_comparison;

int _max(int a, int b) {
    return a > b ? a : b;
}

void build_bad_symbol_shift_table() {
    for(int i=0; i<30; i+=1) bs_shift_table[i] = pattern_len;
    for(int j=1,i=pattern_len-2; i>=0; j+=1,i-=1) {
        if(bs_shift_table[scale(pattern[i])] == pattern_len) bs_shift_table[scale(pattern[i])] = j;
    }
}

void full_suffix_match() {
    int i = pattern_len, j = pattern_len+1;
    pos[i] = j;
    while(i > 0) {
        while ((j <= pattern_len) && (pattern[i-1] != pattern[j-1])) {
            if(gs_shift_table[j] == 0) gs_shift_table[j] = j-i;
            j = pos[j];
        }
        i -= 1;
        j -= 1;
        pos[i] = j;
    }
}

void partial_suffix_match() {
    int i, j;
    j = pos[0];
    for(i=0; i <= pattern_len; i+=1) {
        if(gs_shift_table[i] == 0) gs_shift_table[i]=j;
        if(i == j) j = pos[j];
    }
}

void build_good_suffix_shift_table() {
    full_suffix_match();
    partial_suffix_match();
}

void print_good_suffix_shift_table() {
    for(int i=0; i<=pattern_len; i+=1) {
        printf("%d: %d\n", i, gs_shift_table[i]);
    }
}

void print_bad_symbol_shift_table() {
    for(int i=0; i<26; i+=1) {
        printf("%c:%d ", rev_scale(i), bs_shift_table[i]);
    }
    printf("\n");
}

int bm_matching() {
    build_bad_symbol_shift_table();
    build_good_suffix_shift_table();

    number_of_comparison = 0;
    int i = pattern_len - 1;
    while(i < text_len) {
        int j = 0;
        while(j<pattern_len && pattern[pattern_len-1-j] == text[i-j]) {
            j+= 1;
            number_of_comparison += 1;
        }
        if(j == pattern_len) return (i - pattern_len + 1);

        number_of_comparison += 1;  //for failed match
        i += _max(gs_shift_table[pattern_len-j], (bs_shift_table[scale(text[i-j])] - j));
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
    int match_found = bm_matching();
    cerr << (clock() - st) / CLOCKS_PER_SEC << endl;

    if(match_found == -1) printf("pattern not matched in the text; # of comparison required: %d\n", number_of_comparison);
    else printf("pattern matched in the text at text position: %d; # of comparison required: %d\n", match_found, number_of_comparison);

    return 0;
}
