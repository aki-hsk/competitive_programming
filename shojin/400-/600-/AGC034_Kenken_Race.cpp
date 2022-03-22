#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int N, A, B, C, D;
string S;

bool solve() {
    if(C < D) {
        for(int i=A; i<D; i++) {
            if(S[i] == '#' && S[i+1] == '#') return false;
        }
        return true;
    }

    for(int i=A; i<C; i++) {
        if(S[i] == '#' && S[i+1] == '#') return false;
    }
    for(int i=B; i<=D; i++) {
        if(S[i] == '#') continue;
        if(S[i-1] == '.' && S[i+1] == '.') return true;
    }
    return false;

}

int main() {
    // N:マスの数
    // A:すぬけくんの位置, B:ふぬけくんの位置
    // C:すぬけくんの後の位置, D:ふぬけくんの後の位置
    cin >> N >> A >> B >> C >> D;
    A--; B--; C--; D--;
    cin >> S;

    cout << (solve() ? "Yes" : "No") << endl;

}
