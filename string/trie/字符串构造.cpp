#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int N=2e5+10;


string a[N];
int n,k;
ll qpow(ll a,ll b,ll mod) {
    ll ans=1;
    a%=mod;
    while (b) {
        if (b&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
struct Trie {
    int trie[N*32][2];
    int cnt[N*32],idx;
    Trie() {
        idx=0;
    }
    void insert(string &s) {
        int p=0;
        for (int i=0;i<s.size();++i) {
            if (!trie[p][s[i]-'0']) trie[p][s[i]-'0']=++idx;
            p=trie[p][s[i]-'0'];
        }
        cnt[p]++;
    }
    string find(string &s) {
        int p=0,sum=0;
        for (int i=0;i<s.size();++i){
            if (!trie[p][s[i]-'0']) return "-1";
            p=trie[p][s[i]-'0'];
            sum+=cnt[p];
            if (sum==k) {
                return s.substr(0, i + 1);
            }
        }
        return "-1";
    }
};
Trie ti;
void solve() {
    cin>>n>>k;
    rep(i,0,n) {
        cin>>a[i];
        ti.insert(a[i]);
    }
    rep(i,0,n) {
        string ret=ti.find(a[i]);
        if (ret!="-1") {
            cout<<ret<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

