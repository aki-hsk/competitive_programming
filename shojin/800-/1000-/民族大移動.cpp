#include<iostream>
#include<vector>
using namespace std;

int main() {
    // n:街の数, d:移動の日数, k: 民族の数
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> l(d), r(d);
    for(int i=0; i<d; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        l[i] = a;
        r[i] = b;
    }

    // s:始めに住んでいる街, t:目的の街
    vector<int> s(k), t(k);
    for(int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        s[i] = a;
        t[i] = b;
    }

    for(int i=0; i<k; i++) {
        int a = s[i], b = s[i];
        for(int j=0; j<d; j++) {
            if(a <= r[j] && b >= l[j]) {
                a = min(a, l[j]);
                b = max(b, r[j]);
            }
            if(t[i] >= a && t[i] <= b) {
                cout << j+1 << endl;
                break;
            }
        }
    }
}