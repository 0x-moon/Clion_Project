#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
typedef long long ll;typedef pair<int,int> PII;typedef priority_queue<int> pq;
const int inf=0x3f3f3f3f;const int mod=1e9+7;const int N=1e6+10;

int n;
int a[N];
int b[N];
int c[N];
int s=0,tar;

void solve() {
    cin>>n;
    s=0;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        s+=a[i];
    }
    if (s%n!=0) {
        cout<<-1<<endl;
        return ;
    }
    tar=s/n;
    int op=0;
    for (int i=1;i<=n;++i) {
        b[i]=a[i]-tar;
        if (i%2)b[i]=-b[i];
    }
    c[1]=b[1];
    b[n+1]=0;
    c[n+1]=0;
    for (int i=1;i<=n+1;++i) {
        c[i]=b[i]-b[i-1];
    }
    for (int i=1;i<=n+1;++i) {
        op+=abs(c[i]);
    }
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 1; i <= n + 1; ++i) {

        if (i % 2 == 1) {
            sum1 += c[i];
            if (sum1 < 0) { cout << -1 << endl; return; }
        } else {
            sum2 += c[i];
            if (sum2 > 0) { cout << -1 << endl; return; }
        }
    }
    cout<<op/2<<endl;
}

signed main() {
    js;
    int T=1;
    cin>>T;
    while (T--) {solve();}
    return 0;
}

