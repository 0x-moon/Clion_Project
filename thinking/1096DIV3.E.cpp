#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_map>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl '\n'
typedef long long ll;typedef pair<int,int> PII;
const int inf=0x3f3f3f3f;const int mod=1e9+7;
const int N=1e5+10;


int n;
int a[N];
int b[N];
int psum[N];
void solve() {
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>a[i];
    }
    int idx=-1,mina=-inf;
    psum[n-1]=a[n-1];
    for (int i=n-2;i>=0;--i) {
        psum[i]=psum[i+1]+a[i];
    }



}

int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

