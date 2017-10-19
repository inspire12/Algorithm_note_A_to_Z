#define _CRT_SECURE_NO_WARNINGS // visual
#include <stdio.h>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>

using namespace std;

#define MEMSET(x, WITH) memset(x, (WITH), sizeof(x))
#define FOR(i, E) for(int i=0; i<(E); i++)
#define SCAN(n,k) scanf("%d%d",&n,&k)
typedef long long ll;
//const ll MOD = 100000000000007;
//const double PI = atan(1) *4;

int tree[50005];
int visit[50005];
int main(){
  int N; cin >> N;
  int a,b;
  visit[1] = 1;
  for(int i=0; i<N-1; i++){
    scanf("%d%d", &a, &b);
    if(visit[b] == 1) {tree[a] = b; visit[a] = 1;}
    else {tree[b] = a; visit[b] = 1;}
  }
  int k; cin >> k;
  //visit[1] = 1;
  for(int i=0; i<=N+2; i++){
    visit[i] = 0;
  }
  for(int i=0;i<k; i++){
    scanf("%d%d", &a, &b);
    int tmp = a;
    tree[0] = 1; visit[0] = 1;
    while(a!=
      0){
      visit[a] = 1;
      a = tree[a];
    //  cout << a << " " ;
    }
    //cout << endl;
    while(visit[b] == 0 ){
      b  = tree[b];
    //  cout << b <<" ";
    }
    printf("%d\n", b);

    for(int i=0; i<=N+2; i++){
      visit[i] = 0;
    }

  }
}
