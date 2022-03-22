#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {2, 1, 3};
    sort(v.begin(), v.end());
    do {
        for(int x : v) {
            cout << x << " ";
        }
        cout << endl;
    //順列の全列挙
    } while(next_permutation(v.begin(), v.end()));
}

/* sort(v.begin(), v.end())
do {
    //順列に対する操作
} while(next_permutation(v.begin(), v.end()));