/*
icpc.me/6068
>input 1
4
3 5
8 14
5 20
1 16
>output 1
2
 
*/

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int> > v;
bool comp(pair<int,int> i, pair<int,int> j){
    return i.second < j.second;
}
int main(){
    int n,a,b; scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%d%d",&a,&b);
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end(),comp);
    int maxTime = 999999;
    while(n--){
        if(maxTime > v[n].second){
            maxTime = v[n].second;
        }
        maxTime -=v[n].first;
        if(maxTime<0){break;}
    }
    printf("%d",maxTime<0?-1:maxTime);
}
