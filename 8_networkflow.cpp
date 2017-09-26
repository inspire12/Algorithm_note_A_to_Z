#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct network_edge {
    int to, capacity, flow, residual_idx;
    network_edge() {}
    network_edge(int t, int c, int f, int r) {
        to = t;
        capacity = c;
        flow = f;
        residual_idx = r;
    }
};
int min(int a, int b){
  return a < b ? a:b;
}
int src, sink;
bool chk[101];
vector<network_edge> adj[101];

//edge를 보는 알고리즘
int find_path(int cur, int added_flow){
  if(cur == sink) return added_flow;
  chk[cur] = 1;
//연결된 것들 확인
  for(int i=0; i<adj[cur].size(); i++ ){
    network_edge& next_edge = adj[cur][i];
    if(chk[next_edge.to]  |  next_edge.capacity - next_edge.flow == 0)  continue;//dfs
    int added = find_path(next_edge.to, min(added_flow, next_edge.capacity));
    if(added){
      next_edge.flow += added;
      adj[next_edge.to][next_edge.residual_idx].flow -= added;
      return added;
    }
  }


}


int main() {
    int v, e;
    scanf("%d %d", &v, &e);
    scanf("%d %d", &src, &sink);

    for(int i = 0; i < e; i++) {
        int from, to, capacity;
        scanf("%d %d %d", &from, &to, &capacity);
        adj[from].push_back(network_edge(to, capacity, 0, adj[to].size()));
        adj[to].push_back(network_edge(from, 0, 0, adj[from].size() - 1));
    }

    int ans = 0, added_flow;
    while(added_flow = find_path(src, 101)) {
        ans += added_flow;
        for(int i = 1; i <= v; i++) {
            chk[i] = 0;
        }
    }

    printf("%d\n", ans);
    return 0;
}
