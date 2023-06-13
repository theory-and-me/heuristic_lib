#define PROBLEM "https://atcoder.jp/contests/past201912-open/tasks/past201912_j"
#include "../grid_template.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W, 0)); 
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> A[i][j];
        }
    }

    grid_map<ll> G(H, W);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            for(int k=0;k<(int)G.num_dirs;k++){
                int nx = i + G.dx[k];
                int ny = j + G.dy[k];
                if(nx >= 0 and nx < H and ny >= 0 and ny < W){
                    G.access[i][j][k] = A[nx][ny];
                }
            }
        }
    }

    auto dist1 = G.Dijkstra(H-1, 0);
    auto dist2 = G.Dijkstra(0, W-1);
    auto dist3 = G.Dijkstra(H-1, W-1);

    ll res = G.T_INF;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            chmin(res, dist1[i][j] + dist2[i][j] + dist3[i][j] - 2 * A[i][j]);
        }
    }
    cout << res << endl;

    // ルート復元
    // auto [dist, route] = G.Dijkstra_reconstruction(0, W-1, H-1, 0);
    // cout << dist << endl;
    // cout << route << endl;
}