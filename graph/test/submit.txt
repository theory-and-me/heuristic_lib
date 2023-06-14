#line 1 "Dijkstra.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#line 1 "/Users/akagiyasunori/Work/procon/lib/heuristic_lib/graph/Dijkstra.hpp"
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
    using Pi = pair<T, int>;
    priority_queue<Pi, vector<Pi>, greater<Pi>> pq;
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
#line 3 "Dijkstra.test.cpp"

#line 5 "Dijkstra.test.cpp"
using namespace std;
using ll = long long;

int main(){
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    vector<ll> a(M), b(M), c(M);
    for(int i=0;i<M;i++){
        cin >> a[i] >> b[i] >> c[i];
    }

    weighted_graph<ll> G(N);
    for(int i=0;i<M;i++){
        G[a[i]].emplace_back(b[i], c[i]);
    }

    auto [dist, sp] = Dijkstra(G, s, t, true);
    
    if(dist == -1){
        cout << -1 << "\n";
    }else{
        cout << dist << " " << sp.size() << "\n";
        for(auto [a, b]: sp) cout << a << " " << b << "\n";
    }
}
