#include<cstdio>
int n, k, e[101], a, b, dp[101][4][2];
int f(int x, int y, int z) {
    if (e[x] && e[x] ^ y) return 0;
    if (x == n) return 1;
    if (dp[x][y][z]) return dp[x][y][z];
    int ret = z ? 0 : f(x + 1, y, 1);
    for (int i = 1; i <= 3; i++) if (y^i) ret = (ret + f(x + 1, i, 0)) % 10000;
    return dp[x][y][z] = ret;
}
int main() {
    for (scanf("%d%d", &n, &k); k--;) {
        scanf("%d%d", &a, &b);
        e[a] = b;
    }
    printf("%d", f(0, 0, 1));
    return 0;
}
