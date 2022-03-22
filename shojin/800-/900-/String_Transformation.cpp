#include<iostream>
#include<vector>
using namespace std;

// https://scrapbox.io/esaka-sandbox/AtCoder_Beginner_Contest_110_-_C_-_String_Transformation

int main() {
    string s, t;
    cin >> s >> t;
    vector<int> start(26, -1), goal(26, -1);
    for(int i=0; i<s.size(); i++) {
        int a = s[i] - 'a';
        int b = t[i] - 'a';

        if(start[a] != -1 || goal[b] != -1) {
            if(start[a] != b || goal[b] != a) {
                cout << "No" << endl;
                return 0;
            }
        }
        start[a] = b;
        goal[b] = a;
    }
    cout << "Yes" << endl;
}