#define PROBLEM "https://yukicoder.me/problems/no/1638"
#include "../grid_template.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int H, W;
    cin >> H >> W;
    vector<ll> C(4);
    cin >> C[1] >> C[3] >> C[2] >> C[0];
    ll K, P;
    cin >> K >> P;
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    sx--, sy--, tx--, ty--;
    vector<string> S(H);
    for(int i=0;i<H;i++){
        cin >> S[i];
    }

    grid_template<ll> G(H, W);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            for(int k=0;k<(int)G.num_dirs;k++){
                int nx = i + G.dx[k];
                int ny = j + G.dy[k];
                if(nx >= 0 and nx < H and ny >= 0 and ny < W and S[nx][ny] != '#'){
                    G.access[i][j][k] = C[k];
                    if(S[nx][ny] == '@') G.access[i][j][k] += P;
                }
            }
        }
    }

    auto dist = G.Dijkstra(sx, sy);
    cout << (dist[tx][ty] <= K ? "Yes" : "No") << endl;
}