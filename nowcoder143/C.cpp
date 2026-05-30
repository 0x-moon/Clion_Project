#include <bits/stdc++.h>

using namespace std;
#define int long long
#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl '\n'
typedef long long ll;typedef pair<int,int> PII;
const int inf=0x3f3f3f3f;const int mod=1e9+7;
const int N=1e5+10;


int n,m,x,y,a,b;
vector<int> v,k1,k2;
map<int,int> mp1,mp2;
int qpow(int x,int y) {
    int ans=1;
    x%=mod;
    while (y) {
        if (y%2!=0) {
            ans=(ans*x)%mod;
        }
        x=(x*x)%mod;
        y>>=1;
    }
    return ans;
}

void solve() {
    cin>>a>>b;
    for (int i=1;i<=a/i;++i) {
        if (a%i==0) {
            if (mp1.find(i)==mp1.end()) {
                k1.push_back(i);
                if (i!=a/i)k1.push_back(a/i);
                mp1[i]=1;
                mp1[a/i]=1;
            }
        }
    }
    for (int i=1;i<=b/i;++i) {
        if (b%i==0) {
            if (mp2.find(i)==mp2.end()) {
                k2.push_back(i);
                if (i!=b/i)k2.push_back(b/i);
                mp2[i]=1;
                mp2[b/i]=1;
            }
        }
    }
    set<int> res;
    res.insert(1);
    for (int i=0;i<k1.size();++i) {
        res.insert(k1[i]);
    }
    for (int i=0;i<k2.size();++i) {
        res.insert(k2[i]);
    }
    for (int i=0;i<k1.size();++i) {
        for (int j=0;j<k2.size();++j) {
            res.insert(k1[i]*k2[j]);
        }
    }
    int ans=0;
    while (!res.empty()) {
        int t=*res.begin();
        ans=(ans+qpow(t,t))%mod;
        res.erase(t);
    }
    cout<<ans<<endl;

}

signed main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

