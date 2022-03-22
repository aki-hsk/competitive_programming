#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    vector<ll> grade;

    int sum = 1;
    for(int i=0; i<K; i++) sum *= A[i];
    grade.push_back(sum);
    int start = 0;
    int last = K;


    for(int i=K; i<N; i++) {
        sum /= A[start];
        sum *= A[last];
        grade.push_back(sum);
        start++;
        last++;
    }

    for(int i=1; i<grade.size(); i++) {
        if(grade[i] <= grade[i-1]) {
            cout << "No" << endl;
        }
        if(grade[i] > grade[i-1]) {
            cout << "Yes" << endl;
        }
    }
}