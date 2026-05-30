#include<bits/stdc++.h>

using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl '\n'
typedef long long ll;typedef pair<int,int> PII;
const int inf=0x3f3f3f3f;const int mod=1e9+7;
const int N=2e5+10;


int n;
int a[N];

void solve() {
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    int cnt=0;
    if (a[n]>0)cnt++;
    for (int i=n-1;i>0;--i) {
        a[i]+=max(a[i+1],(int)0);
        if (a[i]>0)cnt++;
    }
    cout<<cnt<<endl;

}

signed main() {
    js;
    int T=1;
    cin>>T;
    while (T--) {solve();}
    return 0;
}

