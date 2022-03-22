#include<iostream>
#include<vector>
using namespace std;

// インタラクティブな問題
bool betemp(string sleft, string sright, int left, int right) {
    if(sleft == sright) return (right - left)%2 == 1;
    else return (right - left) % 2 == 0;
}

void solve(int n) {
    string vac = "Vacant";
    string sleft, sright, str;
    int left = 0, right = n/2;
    cout << left << endl;
    cin >> sleft;
    if(sleft == vac) return;
    cout << right << endl;
    cin >> sright;
    if(sright == vac) return;

    if(!betemp(sleft, sright, left, right)) {
        swap(sleft, sright), left = right, right = n;
    }
    while(right - left > 1) {
        int mid = (left + right)/2;
        cout << mid << endl;
        cin >> str;
        if(str == vac) return;
        if (betemp(sleft, str, left, mid)) sright = str, right = mid;
        else sleft = str, left = mid;
    }
}

int main() {
    int n;
    while(cin >> n) solve(n);
}