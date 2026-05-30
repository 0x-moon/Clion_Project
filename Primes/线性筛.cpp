#include<iostream>
using namespace std;
const int N=10000;

int p[N],idx;
bool st[N];

int main() {
    for (int i=2;i<N;++i) {
        if (!st[i]) p[idx++]=i;
        for (int j=0;p[j]<=N/i;++j) {
            st[i*p[j]]=true;
            if (i%p[j]==0)break;
        }
    }
    for (int i=0;i<10;++i) {
        cout<<p[i]<<' ';
    }
    return 0;
}