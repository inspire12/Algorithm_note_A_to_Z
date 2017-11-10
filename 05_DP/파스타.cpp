//
//
#include <cstdio>
int n, k, input[101], a, b, dp[101][4][2]; //날짜, 전에 먹은 맛, 가능여부


int recur(int loc, int tas, int preTas){
  if(loc == 0) return 1;
  if(dp[loc][tas][preTas]>0) return 0;
  if(input[loc] > 0)
    if(input[loc] == tas)
    return dp[loc][tas][preTas] = f(loc-1, input[loc], tas);
  for(int i=0; i<3; i++){
    if((i == tas) &&(tas == preTas)) continue;
    dp[loc][tas][preTas] += f(loc-1, i, tas);
  }
}


int main() {
    scanf("%d%d", &n, &k);
    while(k--) {
        scanf("%d%d", &a, &b);
        input[a] = b;
    }
    printf("%d", f(0, 0, 1));
    printf("\n");
    for(int i=1; i<=n; i++){
      for(int j=1; j<=3; j++){
        printf("%d", dp[i][j][0]);
      }
      printf("\n");
    }
    return 0;
}
