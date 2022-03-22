#include<iostream>
#include<algorithm>
using namespace std;

// topcoderのパーの回数をpとする
// atcoderが全部グーを出すと -p点
// 一回パーを出すごとに +1される
// n/2回パーを出せるので n/2-p
int main() {
    string s; cin >> s;
    int p_cnt = count(s.begin(), s.end(), 'p');
    cout << s.size()/2-p_cnt << endl;
}
