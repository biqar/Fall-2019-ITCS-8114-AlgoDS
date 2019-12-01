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

typedef long double ld;

const int MAX = 1000005;
const int inf = (1 << 28);

string text, pattern;
int text_len, pattern_len;
int pi[MAX];
int number_of_comparison;

void kmp_failure_function_naive() {
    for(int i=0; i<pattern_len; i+=1) {
        for(int j=i; j>=0; j-=1) {
            if(pattern.substr(0, j) == pattern.substr(i-j+1, j)) {
                pi[i] = j;
                break;
            }
        }
    }
}

void kmp_failure_function_fast() {
    pi[0] = 0;
    for(int i=1; i<pattern_len; i+=1) {
        int j = pi[i-1];

        while(j>0 && pattern[i] != pattern[j]) j = pi[j-1];
        if(pattern[i] == pattern[j]) j += 1;
        pi[i] = j;
    }
}

void print_kmp_failure_table() {
    for(int i=0; i<pattern_len; i+=1) printf("%d ", pi[i]);
    printf("\n");
}

int kmp_matching() {
    kmp_failure_function_fast();

    number_of_comparison = 0;
    int i = 0, j = 0;
    while(i < text_len) {
        number_of_comparison += 1;
        if(text[i] == pattern[j]) {
            if(j == pattern_len-1) return i - j;
            else {
                i += 1;
                j += 1;
            }
        }
        else {
            if(j > 0) j = pi[j - 1];
            else i += 1;
        }
    }
    return -1;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int i, j, k;
    int test, t = 0, kase = 0;

    //load input after this line
    getline(cin, text);
    getline(cin, pattern);
    text_len = text.length();
    pattern_len = pattern.length();

    double st = clock();
    int match_found = kmp_matching();
    cerr << (clock() - st) / CLOCKS_PER_SEC << endl;

    if(match_found == -1) printf("pattern not matched in the text; # of comparison required: %d\n", number_of_comparison);
    else printf("pattern matched in the text at text position: %d; # of comparison required: %d\n", match_found, number_of_comparison);

    return 0;
}
