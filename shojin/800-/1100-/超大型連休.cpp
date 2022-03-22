#include<iostream>
#include<map>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int day_per_month[13] = {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
map<pair<int, int>, bool> holiday;

bool weekend(int month, int day) {
    int sum = day;
    for(int i=1; i<month; i++) {
        sum += day_per_month[i];
    }
    if(sum % 7 == 0 || sum % 7 == 1) return true;
    else return false;
}

pair<int, int> next_weekday(int m, int d) {
    for(int i=m; i<=12; i++) {
        int day = 1;
        if(i == m) day = d;
        for(int j=day; j<=day_per_month[i]; j++) {
            if(weekend(i, j) || holiday[{i, j}]) continue;
            return make_pair(i, j);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        int m, d;
        if(s[1] == '/') {
            m = stoi(s.substr(0, 1));
            d = stoi(s.substr(2));
        }
        else {
            m = stoi(s.substr(0, 2));
            d = stoi(s.substr(3));
        }
        holiday[next_weekday(m, d)] = true;
    }

    int ans = 0, cnt = 0;
    for(int i=1; i<=12; i++) {
        for(int j=1; j<=day_per_month[i]; j++) {
            if(weekend(i, j) || holiday[{i, j}]) cnt++;
            else cnt = 0;
            chmax(ans, cnt);
        }
    }
    cout << ans << endl;
}