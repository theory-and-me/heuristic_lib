#include "../data_structures/radix_heap.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// T は辺のコストの型
template <typename T> using weighted_graph = vector<vector<pair<int, T>>>;

template <typename T> 
tuple<T, vector<pair<int, int>>> Dijkstra(const weighted_graph<T> &G, int s, int t, bool reconstruction){
    const T T_INF = numeric_limits<T>::max() / 2;
    int V = G.size();
    assert(0 <= s and s < V);
    assert(0 <= t and t < V);
    vector<T> dist(V, T_INF);
    vector<T> prev(V, -1);
    dist[s] = 0;
    radix_heap<typename std::make_unsigned<T>::type, int> pq;
    pq.emplace(0, s);
    while(!pq.empty()){
        auto [d, v] = pq.top();
        pq.pop();
        if(t == v) break;
        if(dist[v] < d) continue;
        for(const auto &e: G[v]){
            T dnx = d + e.second;
            if(dist[e.first] <= dnx) continue;
            dist[e.first] = dnx;
            prev[e.first] = v;
            pq.emplace(dnx, e.first);
        }
    }

    // 最短路の復元
    vector<pair<int, int>> shortest_path;
    if(reconstruction and dist[t] != T_INF){
        int v2 = t;
        int v1 = prev[v2];
        while(v2 != s){
            shortest_path.emplace_back(v1, v2);
            v2 = v1;
            v1 = prev[v1];
        }
        reverse(shortest_path.begin(), shortest_path.end());
    }

    return {(dist[t] == T_INF ? -1 : dist[t]), shortest_path};
}