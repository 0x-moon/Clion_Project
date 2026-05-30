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
#define int long long
#define all(x) (x).begin(), (x).end()
#define js ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define endl '\n'
typedef long long ll;typedef pair<int,int> PII;
const int inf=0x3f3f3f3f;const int mod=1e9+7;
const int N=1e5+10;


int n,m,x;
int a[N];

void solve() {
    cin>>n>>m>>x;
    unordered_map<int,int> h;
    for (int i=0;i<n;++i) {
        cin>>a[i];
        if (h.find(a[i])==h.end()) {
            h[a[i]]=1;
        }else  h[a[i]]++;
    }
    int cnt=0;
    for (auto t:h) {
        if (t.second>x)cnt++;
    }
    cout<<m-cnt<<endl;



}

signed main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

