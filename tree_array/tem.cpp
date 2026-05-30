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
typedef long long ll;typedef pair<int,int> PII;typedef priority_queue<int,vector<int>,greater<int>> pq;
const int inf=0x3f3f3f3f;const int mod=1e9+7;
const int N=4e5+10;


int n;
int a[N],tr[N];
//tr[i]表示a[i-lowbit(x)+1,i]的区间和;
int Greater[N],lower[N];
int lowbit(int x) {
    return x&(-x);
}
void add(int x,int c) {
    for (int i=x;i<=n;i+=lowbit(i))tr[i]+=c;
}
int sum(int x) {
    int res=0;
    for (int i=x;i;i-=lowbit(i))res+=tr[i];
    return res;
}
void solve() {
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    memset(tr,0,sizeof(tr));
    for (int i=1;i<=n;++i){
        int y=a[i];
        Greater[i]=sum(n)-sum(y);
        lower[i]=sum(y-1);
        add(y,1);
    }
    memset(tr,0,sizeof(tr));
    ll ans1=0,ans2=0;
    for (int i=n;i;--i) {
        int y=a[i];
        ans1+=Greater[i]*(ll)(sum(n)-sum(y));
        ans2+=lower[i]*(ll)(sum(y-1));
        add(y,1);
    }
    cout<<ans1<<' '<<ans2<<endl;

}

int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

