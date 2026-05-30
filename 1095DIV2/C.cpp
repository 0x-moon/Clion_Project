#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl '\n'
typedef long long ll;typedef pair<int,int> PII;
const int inf=0x3f3f3f3f;const int mod=1e9+7;
const int N=2e5+10,M=1e6+10;



int n;
int a[N];
int h[M];

void solve() {
    cin>>n;
    memset(h,0,sizeof(h));
    int r=0;
    for (int i=0;i<n;++i) {
        cin>>a[i];
        h[a[i]]++;
        r=max(r,a[i]);
    }
    int l=0;
    int ans;
    while (l<=r) {
        int mid=l+r>>1;
        if (f(mid)) {
            ans=l;
            l=mid+1;
        }else {
            r=mid-1;
        }
    }







}

int main() {
    js;
    int T=1;
    cin>>T;
    while (T--) {solve();}
    return 0;
}

