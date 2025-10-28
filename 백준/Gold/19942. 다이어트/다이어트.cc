#include <bits/stdc++.h>
using namespace std;

int n, mp, mf, ms, mv;
int ret = 1e9;
vector<int> best;
struct Food {
    int p, f, s, v, c;
} a[16];

void dfs(int idx, int tp, int tf, int ts, int tv, int cost, vector<int>& picked) {
    if (tp >= mp && tf >= mf && ts >= ms && tv >= mv) {
        if (cost < ret) {
            ret = cost;
            best = picked;
        } else if (cost == ret && picked < best) {
            best = picked;
        }
    }
    if (idx == n) return;

    // 1️⃣ 현재 재료 선택하지 않기
    dfs(idx + 1, tp, tf, ts, tv, cost, picked);

    // 2️⃣ 현재 재료 선택하기
    picked.push_back(idx + 1);
    dfs(idx + 1,
        tp + a[idx].p,
        tf + a[idx].f,
        ts + a[idx].s,
        tv + a[idx].v,
        cost + a[idx].c,
        picked);
    picked.pop_back();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++)
        cin >> a[i].p >> a[i].f >> a[i].s >> a[i].v >> a[i].c;

    vector<int> picked;
    dfs(0, 0, 0, 0, 0, 0, picked);

    if (ret == 1e9) cout << -1;
    else {
        cout << ret << "\n";
        for (int x : best) cout << x << " ";
    }
}
