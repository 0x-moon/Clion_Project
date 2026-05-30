//https://www.lanqiao.cn/problems/20541/learning/?page=1
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N=2e5+10;
int primes[N];
int st[N],cnt=0;
int h_pri[N];
int a[N];
int b[N];
bool h[N];
int n,m;
int main(){
    ll ret=0;
    cin>>n>>m;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<m;++i) cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    int limt=m+n;
    for(int i=2;i<=limt;++i){
        if(!st[i]) {
            primes[cnt++]=i;
            h_pri[i]=1;
        }
        for(int j=0;j<cnt&&primes[j]<=limt/i;++j){
            st[primes[j]*i]=true;
            if(i%primes[j]==0)break;
        }
    }

    for (int i=0;i<n;++i) {
        if (a[i]>limt)break;
        for (int j=0;j<m;++j) {
            if (a[i]+b[j]>limt)break;
            if (h_pri[a[i]+b[j]]&&!h[a[i]+b[j]]) {
                h[a[i]+b[j]]=true;
                ret++;
            }

        }
    }
    cout<<ret<<endl;
    return 0;
}