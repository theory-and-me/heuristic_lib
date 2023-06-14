#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include "../Dijkstra_radix_heap.hpp"

#include <bits/stdc++.h>
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