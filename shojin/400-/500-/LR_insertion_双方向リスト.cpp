#include<iostream>
#include<list>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    list<int> a{0};
    auto it = a.end();

    for(int i=0; i<n; i++) {
        if(s[i] == 'L') --it;
        a.insert(it, i+1);
    }
    for(auto i:a) cout << i << endl;
    return 0;
}