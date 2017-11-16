/*icpc.me/1167 */
/*
 트리의 지름은 각 정점끼리의 거리를 다 따지는 O(n^2)이 바로 떠오리즈미나
 dfs 를 두 번 돌려 O(n)으로도 풀수 있다.
 트리는 어느 부분인든 루트로 정할 수 있다.
*/
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#define max(a,b) a>b?a:b;
#define lld long long int
vector<pair<int ,lld> > tree[100004];
int start2;
lld maxV = -1;
int visit[100004];
int dfs(int a,lld v){
  for(int i=0; i<tree[a].size(); i++){
    int to = tree[a][i].first;
    if(visit[to] == 0){
      visit[to] = 1;
      dfs(to,v+tree[a][i].second);
    }else{
//      cout << maxV << endl;
      if(maxV < v){
          maxV = v;
          start2 = a;
      }
    }
  }
}
int main(){
  int n; cin>>n;
  int loc, to, w;
  for(int i=1; i<=n; i++){
    scanf("%d",&loc);
    scanf("%d",&to);
    while(to != -1){
        scanf("%d",&w);
        tree[loc].push_back(make_pair(to,w));
        scanf("%d",&to);
    }
  }
  visit[1] =1;
  dfs(1,0);
  for(int i=1;i<=n;i++)visit[i] = 0;
  visit[start2] = 1;
  dfs(start2,0);
  cout << maxV;
}
