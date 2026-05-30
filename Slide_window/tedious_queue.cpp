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
const int inf=0x3f3f3f3f;const int mod=1e9+7;
const int N=1e6+10;

#define int long long
int n,k;
int a[N];
deque<int> q,minq;
vector<int> ans1,ans2;
void solve() {
    cin>>n>>k;
    for (int i=0;i<n;++i)cin>>a[i];
    for (int i=0;i<k;++i) {
        while (!q.empty()&&a[q.back()]<a[i])q.pop_back();
        q.push_back(i);
    }
    ans1.push_back(a[q.front()]);
    for (int i=k;i<n;++i) {
        if (!q.empty()&&q.front()<i-k+1)q.pop_front();
        while (!q.empty()&&a[q.back()]<a[i])q.pop_back();
        q.push_back(i);
        ans1.push_back(a[q.front()]);
    }
    for (int i=0;i<ans1.size();++i) {
        cout<<ans1[i]<<' ';
    }cout<<endl;


}

signed main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

