#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m = -1; // 組の数
    for(long long i=1; i<=1000; i++) {
        if(i*i-i == 2*n) {
            m = i;
            break;
        }
    }
    if(m == -1) {
        cout << "No" << endl;
        return 0;
    }

    int cnt = 2*n/m;
    vector<vector<int>> s(m);
    vector<int> a(100005);
    int num = 1;
    for(int i=0; i<m; i++) {
        int j = i+1;
        while(s[i].size() < cnt) {
            s[i].push_back(num);
            s[j].push_back(num);
            num++;
            j++;
        }
    }
    cout << "Yes" << endl;
    cout << m << endl;
    for(int i=0; i<m; i++) {
        cout << s[i].size() << " ";
        for(int j=0; j<cnt; j++) cout << s[i][j] << " ";
        cout << endl;
    }
    return 0;
}