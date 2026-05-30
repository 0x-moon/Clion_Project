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
typedef long long ll;typedef pair<int,int> PII;typedef priority_queue<int,vector<int>,greater<int>> pq;
const int INF=0x3f3f3f3f;const int mod=1e9+7;
const int N=2e5+10;


int n;
int a[N],b[N];
int gcd(int x,int y) {
    return y==0?x:gcd(y,x%y);
}
void solve() {
    cin>>n;
    for (int i=0;i<n;++i) cin>>a[i];
    for (int i=0;i<n;++i) cin>>b[i];
    int op_cnt=0;


    for (int i=1;i<n;++i) {
        int min_t=min(a[i],a[i-1]);
        if(gcd(a[i],a[i-1])<min_t){
            op_cnt++;
        }
    }
    
    cout<<op_cnt<<endl;




}

int main() {
    js;
    int T=1;
    cin>>T;
    while (T--) {solve();}
    return 0;
}

