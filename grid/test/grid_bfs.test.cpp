#define PROBLEM "https://atcoder.jp/contests/abc007/tasks/abc007_3"
#include "../grid_template.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){

    int H, W, sx, sy, tx, ty;
    cin >> H >> W >> sx >> sy >> tx >> ty;
    sx--, sy--, tx--, ty--;
    vector<string> S(H);
    for(int i=0;i<H;i++) cin >> S[i];

    grid_map<int> G(H, W);
    for(int i=0;i<H;i++){
        for(int j=0;j<H;j++){
            if(S[i][j] == '#') continue;
            for(int k=0;k<(int)G.num_dirs;k++){
                int nx = i + G.dx[k];
                int ny = j + G.dy[k];
                if(nx >= 0 and nx < H and ny >= 0 and ny < W and S[nx][ny] != '#'){
                    G.access[i][j][k] = 1;
                }
            }
        }
    }

    auto dist = G.bfs(sx, sy);
    cout << dist[tx][ty] << endl;

    // ルート復元
    // auto [dist, route] = G.bfs_reconstruction(sx, sy, tx, ty);
    // cout << route << endl;

    return 0;
}