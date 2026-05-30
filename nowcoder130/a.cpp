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
const int INF=0x3f3f3f3f;const int mod=1e9+7;const int N=2e5+10;




void solve() {
    string s;
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;++i){
        if(s[i]=='0'&&i<=n-1)continue;
        else{
            for(int j=i;j<n;++j){
                cout<<s[j];
            }
            break;
        }
    }

}

int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

