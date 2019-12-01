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

const int inf = (1 << 28);

string text, pattern;
int text_len, pattern_len;
int number_of_comparison;

int brute_force_matching() {
    number_of_comparison = 0;
    for(int i=0; i<=(text_len-pattern_len); i+=1) {
        int j = 0;
        while(j<pattern_len && text[i+j] == pattern[j]) {
            j+=1;
            number_of_comparison += 1;
        }
        if(j == pattern_len) return i;

        number_of_comparison += 1;  //for failed match
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
    int match_found = brute_force_matching();
    cerr << (clock() - st) / CLOCKS_PER_SEC << endl;

    if(match_found == -1) printf("pattern not matched in the text; # of comparison required: %d\n", number_of_comparison);
    else printf("pattern matched in the text at text position: %d; # of comparison required: %d\n", match_found, number_of_comparison);

    return 0;
}
