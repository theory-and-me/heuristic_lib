#include <bits/stdc++.h>
using namespace std;

struct low_link {
    int V, cnt;
    vector<vector<int>> graph;
    vector<int> ord, low;
    vector<int> articulation_points;
    vector<pair<int, int>> bridges;
    low_link(int V)
        : V(V), cnt(0), graph(V), ord(V, -1), low(V, -1) {
    }

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void dfs(int v, int par) {
        ord[v] = cnt;
        low[v] = cnt;
        cnt++;
        bool is_articulation_point = false;
        int num_of_child = 0;
        for (auto u : graph[v]) {
            if (ord[u] == -1) {
                num_of_child++;
                dfs(u, v);
                if (low[v] > low[u]) {
                    low[v] = low[u];
                }
                if (par != -1 and ord[v] <= low[u]) is_articulation_point = true;
                if (ord[v] < low[u]) bridges.emplace_back(min(u, v), max(u, v));
            } else if (u != par) {
                low[v] = min(low[v], ord[u]);
            }
        }
        if (par == -1 and num_of_child >= 2) is_articulation_point = true;
        if (is_articulation_point) articulation_points.push_back(v);
        return;
    }

    void build() {
        for (int i = 0; i < V; i++) {
            ord[i] = -1;
            low[i] = -1;
        }
        for (int i = 0; i < V; i++) {
            if (ord[i] == -1) {
                dfs(i, -1);
            }
        }
        sort(articulation_points.begin(), articulation_points.end());
        sort(bridges.begin(), bridges.end());
        return;
    }
};