#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using Graph = vector<vector<int>>;
const long long INF = 1LL << 60;
const int SINF = 1LL << 29;
const ll mod = 1000000000+7;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool leap(int y) {
    if(y % 400 == 0) return true;
    else if(y % 100 == 0) return false;
    else if(y % 4 == 0) return true;
    else return false;
}

int day_per_month(int year, int month) {
    int d_per_m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(month == 2 && leap(year)) return 29;
    else return d_per_m[month];
}

int main() {
    string s;
    cin >> s;
    int year = stoi(s.substr(0, 4));
    int month = stoi(s.substr(5, 2));
    int day = stoi(s.substr(8, 2));

    for(int y=year; y<=3000; y++) {
        for(int m=1; m<=12; m++) {
            for(int d=1; d<=day_per_month(y, m); d++) {
                if(y==year && m==month && d<day) continue;
                if(y==year && m < month) continue;
                if(y%(m*d) == 0) {
                    printf("%04d/%02d/%02d\n", y, m, d);
                    return 0;
                }
            }
        }
    }
}