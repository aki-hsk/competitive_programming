#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  deque<int> dq;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    dq.push_back(x);
  }

  for(int qi=0; qi<q; qi++) {
    int t, x, y;
    cin >> t >> x >> y;
    x--; y--;
    if(t == 1) {
      swap(dq[x], dq[y]);
    }
    else if(t == 2) {
      int a = dq.back();
      dq.pop_back();
      dq.push_front(a);
    }
    else {
      printf("%d\n", dq[x]);
    }
  }
}
