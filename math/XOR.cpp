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
typedef long long ll;
typedef pair<int, int> PII;
typedef priority_queue<int, vector<int>, greater<int> > pq;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e7+10;



int n;
int a[N];

void solve() {
    cin >> n ;
    for (int i=1;i<=n;++i) {
        a[i]=i;
    }
    swap(a[1],a[n]);
    for (int i=2;i<n-1;i+=2) {
        swap(a[i],a[i+1]);
    }
    for (int i=1;i<=n;++i) {
        cout<<a[i]<<' ';
    }
    cout<<'\n';
}

int main() {
    js;

    int T = 1;
    cin>>T;
    while (T--) { solve(); }
    return 0;
}
