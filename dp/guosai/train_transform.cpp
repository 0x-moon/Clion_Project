#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// 用安全的极小值，不溢出
const int MINF = -100000000;
// 题目n≤200，A≤200，数组开205足够，不浪费、不越界
const int MAXA = 205;

int n, A, B;
int w[MAXA];
int dp[MAXA]; // dp[j]：车厢1装j，车厢2最大重量

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> A >> B;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }

    // 1. 初始化：0~A全设为不可达，只有0可达
    for (int j = 0; j <= A; ++j) {
        dp[j] = MINF;
    }
    dp[0] = 0;

    // 2. 01背包，逐个物品，倒序j
    for (int i = 1; i <= n; ++i) {
        int now = w[i];
        // 倒序：避免重复选同一件
        for (int j = A; j >= 0; --j) {
            if (dp[j] == MINF) continue; // 不可达，跳过

            // 决策1：放车厢1 → 必须判j+w≤A，防越界
            if (j + now <= A) {
                dp[j + now] = max(dp[j + now], dp[j]);
            }
            // 决策2：放车厢2 → 不改变j，直接加重量
            dp[j] = max(dp[j], dp[j] + now);
        }
    }

    // 3. 统计答案：车厢2≤B，取j+dp[j]最大
    int ans = 0;
    for (int j = 0; j <= A; ++j) {
        if (dp[j] != MINF && dp[j] <= B) {
            ans = max(ans, j + dp[j]);
        }
    }

    cout << ans << endl;
    return 0;
}