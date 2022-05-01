#include<iostream>
#include<vector>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  if(h == 1 || w == 1) cout << w * h << endl;
  else cout << (h+1) / 2 * ((w+1) / 2) << endl;
}