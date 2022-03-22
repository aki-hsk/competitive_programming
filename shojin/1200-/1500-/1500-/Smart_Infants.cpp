#include<iostream>
#include<vector>
#include<set>
using namespace std;

// 平衡二分探索木
// iteratorの説明
// https://www.youtube.com/watch?v=IhnlLGb-rzg

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    vector<multiset<int>> s(200005);
    multiset<int> maxs;

    // 幼稚園iの最強園児のrating
    auto getMax = [&](int i) {
        if(s[i].size() == 0) return -1;
        return *s[i].rbegin();
    };
    auto addSchool = [&](int i) {
        int x = getMax(i);
        if(x == -1) return;
        maxs.insert(x);
    };
    auto delSchool = [&](int i) {
        int x = getMax(i);
        if(x == -1) return;
        maxs.erase(maxs.find(x));
    };
    auto addStudent = [&](int i, int x) {
        delSchool(i);
        s[i].insert(x);
        addSchool(i);
    };
    auto delStudent = [&](int i, int x) {
        delSchool(i);
        s[i].erase(s[i].find(x));
        addSchool(i);
    };

    for(int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
        addStudent(b[i], a[i]);
    }

    for(int qi=0; qi<q; qi++) {
        int c, d;
        cin >> c >> d;
        c--;
        delStudent(b[c], a[c]);
        b[c] = d;
        addStudent(b[c], a[c]);
        int ans = *maxs.begin();
        printf("%d\n", ans);
    }
    return 0;
}