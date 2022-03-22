#include <bits/stdc++.h>
using namespace std;

int N,M;
string board[60];
string pattern[60];

bool match(int x, int y) {
  int i,j;
  for(i=0; i<M; i++) {
    for(j=0; j<M; j++) {
      if(board[x+i][y+j] != pattern[i][j])
        return false;
    }
  }
  return true;
}


int main() {
  cin >> N >> M;
  int i, j;
  for(i=0; i<N; i++) cin >> board[i];
  for(i=0; i<M; i++) cin >> pattern[i];

  bool found = false;
  for(i=0; i<=N-M; i++) {
      for(j=0; j<=N-M; j++) {
          if(match(i,j)) found = true;
      }
  }
  cout << (found ? "Yes" : "No") << endl;
}