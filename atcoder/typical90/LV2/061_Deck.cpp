#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
  int q;
  cin >> q;
  deque<int> dq;
  for(int i=0; i<q; i++) {
    int t, x;
    cin >> t >> x;
    if(t == 1) {
      dq.push_front(x);
    }
    else if(t == 2) {
      dq.push_back(x);
    }
    else {
      printf("%d\n", dq[x-1]);
    }
  }
}