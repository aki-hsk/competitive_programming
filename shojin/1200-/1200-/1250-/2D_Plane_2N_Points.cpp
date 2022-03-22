#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int INF = (1<<30);

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> red(n), blue(n);
    for(int i=0; i<2*n; i++) {
        int y, x;
        cin >> y >> x;
        if(i < n) red[i] = {x, y};
        else blue[i%n] = {x, y};
    }
    // blueはxで昇順ソート, redはyで降順ソート
    sort(blue.begin(), blue.end());
    sort(red.rbegin(), red.rend(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second;});

    int ans = 0;
    for(int j=0; j<n; j++) {
        for(int i=0; i<n; i++) {
            if(red[i].first < blue[j].first && red[i].second < blue[j].second) {
                red[i].first = red[i].second = INF;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}