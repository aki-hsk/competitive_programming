#include<iostream>
#include<vector>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  vector<vector<int>> b(h, vector<int>(w));

  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) cin >> a[i][j];
  }
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) cin >> b[i][j];
  }

  long long ans = 0;
  for(int i=0; i<h-1; i++) {
    for(int j=0; j<w-1; j++) {
      int div = b[i][j] - a[i][j];
      ans += abs(div);
      for(int y=0; y<=1; y++) {
        for(int x=0; x<=1; x++) {
          a[i+y][j+x] += div;
        }
      }
    }
  }

  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      if(a[i][j] != b[i][j]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  cout << ans << endl;
  return 0;
}