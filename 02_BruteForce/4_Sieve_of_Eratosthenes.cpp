#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1000000
bool isPrime[MAX+1];
int prime[MAX+1], cnt, num, testcase, T;

void sieve_Of_Eratosthenes(int N) {
    for (int i = 2; i <= N; i++) {
        isPrime[i] = 1;    // initialize isPrime[] array
    }
    int sqrtn=sqrt(N);
    for (int i = 2; i <= sqrtn; i++) {
        if (!isPrime[i]) continue;
        for (int j = i + i; j <= N; j += i) {
            isPrime[j] = 0;
        }
    }
}

int main() {
    sieve_Of_Eratosthenes(MAX);
    for(int i=0; i<20; i++){
      cout << prime[i];
    }
    return 0;
}
