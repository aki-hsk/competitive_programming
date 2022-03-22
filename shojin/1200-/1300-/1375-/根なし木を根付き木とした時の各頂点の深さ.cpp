#include<iostream>
#include<vector>
using namespace std;
using Graph = vector<vector<int>>;
vector<int> depth;

void dfs(const Graph &G, int v, int p = -1, int d = 0) {
    depth[v] = d;
    for(auto c:G[v]) {
        if(c == p) continue;
        dfs(G, c, v, d+1); // dを1増やして子頂点へ
    }
}
