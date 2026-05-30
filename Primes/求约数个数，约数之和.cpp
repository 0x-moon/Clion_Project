#include <iostream>
#include <vector>
using namespace std;
const int N = 10010;
int st[N];
//模板gcd
/*
 辗转相除法，来求a，b的最大公约数、
 原理：（a,b）的最大公约数就是（b,a%b）的最大公约数
 */
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

//分解质因数
vector<int> primes(N);
void  solve(int n) {
    for (int i=2;i<=n/i;++i) {
        int s=0;
        while (n%i==0) {
            n/=i;
            s++;
        }
        if (s) {
            primes[i]=s;
        }
    }
    if (n>1) {
        primes[n]=1;
    }
}
/*数学推导
 1.欧拉函数
 */

int main() {
    solve(10068);
    bool flag=false;
    for (int i=0;i<N;++i) {
        if (primes[i]) {
            if (flag)cout<<'*';
            flag=true;
            cout<<i<<'^'<<primes[i];
        }
    }
    cout<<endl;
    cout<<gcd(10,gcd(100,5));
    return 0;
}