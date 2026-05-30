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
const int N=1e5+10;



void solve() {
    int n;
    string a,b;
    cin>>n;
    cin>>a>>b;
    int lcnt=0,rcnt=0;
    deque<int> pos;
    for (int i=0;i<n;++i) {
        if (a[i]=='(')lcnt++;
        if (b[i]=='(')lcnt++;
        if (a[i]==')')rcnt++;
        if (b[i]==')')rcnt++;
        if (a[i]!=b[i])pos.push_back(i);
    }
    if  (lcnt!=rcnt) {
        cout<<"No"<<endl;
        return;
    }
    int suma=0,sumb=0;
    for (int i=0;i<n;++i) {
        if (a[i]=='(')suma+=1;
        if (a[i]==')')suma-=1;
        if (b[i]=='(')sumb+=1;
        if (b[i]==')')sumb-=1;
        if (pos.front()==i) {
            pos.pop_front();
            if (suma<sumb&&sumb>2) {
                suma+=2;
                sumb-=2;
                swap(a[i],b[i]);
            }
            if (sumb<suma&&suma>2) {
                sumb+=2;
                suma-=2;
                swap(a[i],b[i]);
            }
        }
        if (suma<0||sumb<0) {
            cout<<"No"<<endl;
            return ;
        }

    }
    if (suma==0&&sumb==0) {
        cout<<"Yes"<<endl;
    } else cout<<"No"<<endl;
}

int main() {
    js;
    int T=1;
    cin>>T;
    while (T--) {solve();}
    return 0;
}

