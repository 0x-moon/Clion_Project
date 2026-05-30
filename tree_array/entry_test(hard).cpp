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
const int N=(4e5 + 10)*3;


int n;
int a[N],b[N],tr[N],idx=0,gre[N],low[N];
unordered_map<int,int> h;
//tr[i]表示a[i-lowbit(x)+1,i]的区间和;
int Greater[N],lower[N];
int lowbit(int x) {
    return x&(-x);
}
void add(int tr[], int x, int c, int max_m) {
    for (int i = x; i <= max_m; i += lowbit(i)) tr[i] += c;
}
int sum(int tr[],int x) {
    int res=0;
    for (int i=x;i;i-=lowbit(i))res+=tr[i];
    return res;
}

void solve() {
        cin >> n;
        vector<int> alls;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i];
            alls.push_back(a[i]);
            alls.push_back(a[i] + b[i]);
            alls.push_back(a[i] - b[i]);
        }


        sort(alls.begin(), alls.end());
        alls.erase(unique(alls.begin(), alls.end()), alls.end());
         //去重
        int m = alls.size();
        memset(tr, 0, sizeof(tr));

        for (int i = 1; i <= n; ++i) {

            int L = lower_bound(alls.begin(), alls.end(), a[i] - b[i]) - alls.begin() + 1;
            int R = lower_bound(alls.begin(), alls.end(), a[i] + b[i]) - alls.begin() + 1;
            int pos = lower_bound(alls.begin(), alls.end(), a[i]) - alls.begin() + 1;


            int res = sum(tr, R) - sum(tr, L - 1);
            cout << res << (i == n ? "" : " ");


            add(tr, pos, 1,m);
        }
        cout << endl;
}





int main() {
    js;
    int T=1;
    //cin>>T;
    while (T--) {solve();}
    return 0;
}

