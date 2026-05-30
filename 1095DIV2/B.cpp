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
const int inf=0x3f3f3f3f;const int mod=1e9+7;
const int N=2e5+10;


int n;
int a[N];
int jud(int x,int y) {
    if (x<y)return jud(y,x);
    int dif=x-y;
    if (x%dif==0&&y%dif==0)return 1;
    return 0;
}

void solve() {
    cin>>n;
    for (int i=0;i<n;++i) {
        cin>>a[i];
    }
    int cnt=0;
    for (int i=1;i<n;++i) {
        cnt+=jud(a[i],a[i-1]);
    }
    cout<<cnt<<endl;



}

int main() {
    js;
    int T=1;
    cin>>T;
    while (T--) {solve();}
    return 0;
}

