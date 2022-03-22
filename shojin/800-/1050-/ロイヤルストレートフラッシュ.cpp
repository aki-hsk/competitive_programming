#include<iostream>
#include<map>
using namespace std;

int main() {
    char mark[4] = {'S', 'H', 'D', 'C'};
    string s; cin >> s;
    int n = s.size();
    string ans = "";
    int ans_cnt = (1<<30);

    for(int i=0; i<4; i++) {
        char C = mark[i];
        string t;
        int cnt = 0, royal_cnt = 0;
        for(int j=0; j<n; j += 2) {
            if(royal_cnt == 5) break;
            if(s[j] == C && (s[j+1] == '1' || s[j+1] == 'J' || s[j+1] == 'Q' || s[j+1] == 'K' || s[j+1] == 'A')) {
                if(s[j+1] == '1') j++;
                royal_cnt++;
                continue;
            }
            string str = s.substr(j, 2);
            if(s[j+1] == '1') {
                str.push_back(s[j+2]);
                j++;
            }
            t += str;
            cnt++;
        }
        if(ans_cnt > cnt) {
            ans = t;
            ans_cnt = cnt;
        }
    }
    if(ans.size() == 0) ans = '0';
    cout << ans << endl;
}