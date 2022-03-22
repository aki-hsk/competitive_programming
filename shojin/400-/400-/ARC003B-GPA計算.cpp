#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string s;
    cin >> N >> s;

    double score = 0;
    rep(i, N) {
        if(s[i] == 'A') score += 4;
        else if(s[i] == 'B') score += 3;
        else if(s[i] == 'C') score += 2;
        else if(s[i] == 'D') score += 1;
    }

    printf("%1.20f\n", score/N);
}