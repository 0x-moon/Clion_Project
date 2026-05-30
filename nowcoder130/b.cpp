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



char g[21][21];
int n;
bool jud(int x,int y) {
    return x>=0&&x<n&&y>=0&&y<n;
}
void solve() {
    cin>>n;
    rep(i,0,n)
        rep(j,0,n) cin>>g[i][j];

    rep(i,0,n) {
        rep(j,0,n) {
            if (g[i][j]=='*') {
                if (jud(i,j-1)&&jud(i,j+1)&&g[i][j-1]=='*'&&g[i][j+1]=='*') {
                    if ((jud(i+1,j)&&g[i+1][j]=='*')||(jud(i-1,j)&&g[i-1][j]=='*')) {
                        cout<<'T'<<endl;
                    }else {
                        cout<<'L'<<endl;
                    }
                }
                if (jud(i-1,j)&&jud(i+1,j)&&g[i-1][j]=='*'&&g[i+1][j]=='*') {
                    if ((jud(i,j+1)&&g[i][j+1]=='*')||(jud(i,j-1)&&g[i][j-1]=='*')) {
                        cout<<'T'<<endl;
                    }else {
                        cout<<'L'<<endl;
                    }
                }
            }

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

