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
typedef long long ll;typedef pair<int,int> PII;
const int inf=0x3f3f3f3f;const int mod=676767677;
const int N=1e5+10;


int n;
int a[N];

void solve() {
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>a[i];
    }
    int ans=0;
    for (int i=0;i<n;++i) {
        if (a[i]==0) {
            cout<<0<<endl;
            return ;
        }
        if (a[i]==1)continue;
        ans+=a[i];
    }
    if (a[n-1]==1)ans++;
    cout<<ans<<endl;



}

int main() {
    js;
    int T=1;
    cin>>T;
    while (T--) {solve();}
    return 0;
}

