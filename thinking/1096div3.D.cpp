//https://codeforces.com/blog/entry/153099
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl '\n'
typedef long long ll;typedef pair<int,int> PII;
const int inf=0x3f3f3f3f;const int mod=1e9+7;
const int N=1e5+10;


int n;
int a[N*2];
int f(int l,int r) {
    set<int> s;
    for (int i=0;i<=n;++i) {
        s.insert(i);
    }
    while (l>=0&&r<n*2&&a[l]==a[r]) {
        s.erase(a[l]);
        l--,r++;
    }
    return *s.begin();
}
void solve() {
    cin>>n;
    int x=-1,y=-1;
    for (int i=0;i<2*n;++i) {
        cin>>a[i];
        if (a[i]==0) {
            if (x==-1) {
                x=i;
            }else {y=i;}
        }
    }
    int ans=-1;
    ans=max(f(x,x),f(y,y));
    ans=max(ans,f((x+y)/2,(x+y+1)/2));
    cout<<ans<<endl;
}

int main() {
    js;
    int T=1;
    cin>>T;
    while (T--) {solve();}
    return 0;
}

