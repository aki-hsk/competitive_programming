#include<iostream>
#include<vector>
using namespace std;

// N:タスクの数, M:人数, K:技能の数, R: 依存数
int N, M, K, R;

// タスク要求レベル
vector<vector<int>> d(1000, vector<int>(20));
vector<pair<int, int>> uv(3000);
vector<bool> task_status(1000);

void input() {
    cin >> N >> M >> K >> R;
    for(int i=0; i<N; i++) {
        for(int j=0; j<K; j++) cin >> d[i][j];
    }
    for(int i=0; i<R; i++) cin >> uv[i].first >> uv[i].second;
}

int main() {
    input();
    printf("%d", min(R, M));
    for(int i=0; i<min(R, M); i++) {
        printf(" %d %d", i+1, uv[i].first);
    }
    fflush(stdout);

    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int a;
        scanf("%d", &a);
        task_status[a] = true;
    }

    while(true) {
        printf("%d\n", 0);
        fflush(stdout);
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            int a;
            scanf("%d", &a);
            task_status[a] = true;
        }
        if(n == -1) break;
    }
}