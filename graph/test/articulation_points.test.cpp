#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"
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
    for (int i = 0; i < (int)lk.articulation_points.size(); i++) {
        cout << lk.articulation_points[i] << "\n";
    }
}