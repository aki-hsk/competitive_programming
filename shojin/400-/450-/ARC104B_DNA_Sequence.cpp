#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int cnt = 0;
    for(int i=0; i<N; i++) {
        int cnt_1 = 0, cnt_2 = 0;
        for(int j=i; j<N; j++) {
            if(S[j] == 'A') cnt_1++;
            else if(S[j] == 'T') cnt_1--;
            else if(S[j] == 'C') cnt_2++;
            else if(S[j] == 'G') cnt_2--;
            if(cnt_1 == 0 && cnt_2 == 0) cnt++;
        }
    }
    cout << cnt << endl;
}
