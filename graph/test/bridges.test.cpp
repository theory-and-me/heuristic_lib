#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"
#include <bits/stdc++.h>

#include "../low_link.hpp"
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    vector<int> s(E), t(E);
    for (int i = 0; i < E; i++) {
        cin >> s[i] >> t[i];
    }

    low_link lk(V);
    for (int i = 0; i < E; i++) {
        lk.add_edge(s[i], t[i]);
    }
    lk.build();
    for (int i = 0; i < (int)lk.bridges.size(); i++) {
        cout << lk.bridges[i].first << " " << lk.bridges[i].second << "\n";
    }
}