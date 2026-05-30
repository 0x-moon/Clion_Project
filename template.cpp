#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl '\n'
typedef long long ll;typedef pair<int,int> PII;
const int inf=0x3f3f3f3f;const int mod=1e9+7;
const int N=1e5+10;



void solve() {
    int n; cin>>n;
    vector<int> a(n+2),b(n+2),c(n+2);
    int _s=0;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        _s+=a[i];
    }
    if (_s%n!=0) {
        cout<<-1<<endl;
        return ;
    }
    int tar=_s/n;
    for (int i=1;i<=n;++i) {
        b[i]=a[i]-tar;
        if (i%2==0) {
            b[i]=-b[i];
        }
    }
    int ans=0;
    c[1]=b[1];
    b[n+1]=0;
    c[n+1]=0;
    for (int i = 1; i <= n + 1; ++i) {
        c[i] = b[i] - b[i - 1];
        ans += abs(c[i]);
    }
    int sum1=0,sum0=0;
    for (int i=1;i<=n+1;++i) {
        if (i % 2 == 1) {
            sum1 += c[i];
            if (sum1 > 0) { cout << -1 << endl; return; }
        } else {
            sum0 += c[i];
            if (sum0 < 0) { cout << -1 << endl; return; }
        }
    }
    cout<<ans/2<<endl;
}

signed main() {
    js;
    int T=1;
    cin>>T;
    while (T--) {solve();}
    return 0;
}


