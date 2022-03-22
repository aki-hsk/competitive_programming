#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
	cin >> s;
	cout << s;
	// 入力Xがきたら ",X" の形式で出力
	// 入力が続く限りループは続く
	while(cin >> s) cout << ',' << s;
    cout << endl;
	return 0;
}