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
const int inf=0x3f3f3f3f;const int mod=1e9+7;const int N=3e4+10;


string op;
int p[N],s[N];
int d[N];
int find(int x) {
    if (p[x]!=x){
        p[x]=find(p[x]);
    }
    return p[x];
}


void solve() {
   


}

int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}


