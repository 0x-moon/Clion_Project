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
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
typedef long long ll;typedef pair<int,int> PII;typedef priority_queue<int,vector<int>,greater<int>> pqIG;
const int INF=0x3f3f3f3f;const int MOD=1e9+7;const int N=1e5+10;


string s;
int dp[N];
int h[26]={0};
void solve() {
    cin>>s;
    int n=s.size();
    dp[0]=abs((s[1]-s[0])%26);
    h1[dp[0]]++;
    for (int i=1;i<n;++i) {
        dp[i]=abs((s[i]-s[i-1])%26);
        h1[dp[i]]++;
    }
    int ret=-1;
    for (int i=0;i<26;++i) {
        ret=max(ret,h1[i]);
    }
    cout<<ret<<endl;



}

int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

