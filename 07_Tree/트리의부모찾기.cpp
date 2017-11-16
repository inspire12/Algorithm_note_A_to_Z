/* icpc.me/11725 */

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

//그래프를 만든다음 루트부터 bfs 탐색
using namespace std;
vector<int> tree[100003];
int parent[100003];
int visit[100003];

int main(){
  int n; cin >> n;
  int t,s,start;
  for(int i=0; i<n-1; i++){
    scanf("%d%d",&t,&s);
    tree[t].push_back(s);
    tree[s].push_back(t);
  }
  queue<int> q;
  q.push(1); //start

  while(!q.empty()){
    int cur = q.front(); q.pop();
    visit[cur] = 1;
    int size = tree[cur].size();
    sort(tree[cur].begin(), tree[cur].end());
    for(int i=0; i< size; i++){
      int next = tree[cur][i];
      if(visit[next] == 0){
        q.push(next);
        visit[next] = 1;
        parent[next] = cur;
      }
    }
  }
  for(int i=2;i<=n; i++){
    printf("%d\n",parent[i]);
  }
}
