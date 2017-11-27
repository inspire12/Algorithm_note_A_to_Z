/*
icpc.me/1922
 Kruskal 알고리즘
 priority queue  class 이용하는 방법
 new 로 heap에 할당해서 써야지 main 에서 그냥 쓰면 런타임 오류
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;

#define pii pair<int, int>

class Edge{
  public:
    int to, from, weight;
    Edge(int t, int f, int w);

};
Edge::Edge(int t, int f, int w) :to(t),from(f),weight(w){}

class comp{
public:
  bool operator()(const Edge& e1, const Edge& e2 ) const{
    return e1.weight > e2.weight;
  }
};

class UnionFind{
public:
  vector<int> parents; //rank 는 음수로 처리
  UnionFind(int n){
    parents = vector<int>(n,-1);
  }
  int find(int from){
    if(parents[from] < 0){
      return from;
    }
    return find(parents[from]);
  }

  bool disjointSet(int a, int b){
    int root1 = find(a);
    int root2 = find(b);
    if(root1 == root2){
      return false;
    }
    int unionSize = parents[root1] + parents[root2];
    if(parents[root1] > parents[root2]){
        parents[root1] = root2;
        parents[root2] = unionSize;
    }else{
      parents[root2] = root1;
      parents[root1] = unionSize;
    }
    //cout << rank[root1] <<rank[root2] << endl;
    return true;
  }
};
int kruskal(priority_queue<Edge, vector<Edge>, comp> &edgeLists, int n){
  int reSum = 0;
  int edgeCount = 0;
  UnionFind* disjoint = new UnionFind(n+10);
  while(!edgeLists.empty() && edgeCount < n-1){
    Edge tmp = edgeLists.top();   edgeLists.pop();

    if(disjoint->disjointSet(tmp.to, tmp.from)){
      reSum += tmp.weight;
      edgeCount++;
    }
  }
  delete disjoint;
  return reSum;
}

int main(){
  int n,m, a,b,c; cin >> n >> m; //n은 vector //
  //vector<vector<pii> > graph(n) ;
  priority_queue<Edge, vector<Edge>, comp> edgeLists;

  for(int i=0; i<m ; i++){
    cin >> a >> b>> c;
    //graph[a].push_back(make_pair(b,c));
    edgeLists.push(Edge(a,b,c));
  }
  //sort(edgeLists.begin(), edgeLists.end(), greater<vector<Edge> >());
  cout << kruskal(edgeLists, n);
}
