/* #include<stdio.h>
#include<iostream>

using namespace std;

int main(){
   int dp[1000][3] = {0,};
   int house[1000][3] = {0, };
   int n = 0;

   cin >> n;

   for(int i=0; i<n; i++){
      for(int j=0; j<3; j++){
         cin >> house[i][j];
      }
   }

   dp[0][0] = house[0][0];
   dp[0][1] = house[0][1];
   dp[0][2] = house[0][2];

   for(int i=1; i<n; i++){

      if(dp[i-1][0] < dp[i-1][1])
         dp[i][2] = dp[i-1][0] + house[i][2];
      else
         dp[i][2] = dp[i-1][1] + house[i][2];

      if(dp[i-1][1] < dp[i-1][2])
         dp[i][0] = dp[i-1][1] + house[i][0];
      else
         dp[i][0] = dp[i-1][2] + house[i][0];

      if(dp[i-1][0] < dp[i-1][2])
         dp[i][1] = dp[i-1][0] + house[i][1];
      else
         dp[i][1] = dp[i-1][2] + house[i][1];

   }

   int result = dp[n-1][0] < dp[n-1][1] ? dp[n-1][0] : dp[n-1][1];
   result = result < dp[n-1][2] ? result : dp[n-1][2];

   cout << result;
   return 0;
}
*/

#include <stdio.h>
#include <iostream>
using namespace std;
int table[1005][3] = {0, };
int cost[1005][3] = {0, };

int get_min(int a, int b){
   return a < b ? a : b;
}
int main(){
   int n = 0;
   scanf("%d", &n);

   for(int i=0; i < n; i++){
      for(int j=0; j < 3; j++){
         scanf(" %d", &cost[i][j]);
      }
   }

   for(int i=0; i < n; i++){
      cout << table[i-1][1];
      table[i][0] = get_min(table[i-1][1], table[i-1][2]) + cost[i][0];
      table[i][1] = get_min(table[i-1][0], table[i-1][2]) + cost[i][1];
      table[i][2] = get_min(table[i-1][0], table[i-1][1]) + cost[i][2];
   }

   printf("%d", get_min(table[n-1][0], get_min(table[n-1][1], table[n-1][2])));

   return 0;
}
