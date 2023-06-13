#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0558"
#include "../grid_template.hpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int H, W, N;
    cin >> H >> W >> N;
    vector<string> S(H);
    for(int i=0;i<H;i++) cin >> S[i];

    grid_template<int> G(H, W);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j] == 'X') continue;
            for(int k=0;k<(int)G.num_dirs;k++){
                int nx = i + G.dx[k];
                int ny = j + G.dy[k];
                if(nx >= 0 and nx < H and ny >= 0 and ny < W and S[nx][ny] != 'X'){
                    G.access[i][j][k] = 1;
                }
            }
        }
    }

    vector<int> xs(N+1), ys(N+1);
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j] == 'S'){
                xs[0] = i;
                ys[0] = j;
            }else if(S[i][j] != 'X' and S[i][j] != '.'){
                xs[S[i][j] - '0'] = i;
                ys[S[i][j] - '0'] = j;
            }
        }
    }

    int res = 0;
    for(int i=0;i<N;i++){
        auto dist = G.bfs(xs[i], ys[i]);
        res += dist[xs[i+1]][ys[i+1]];
    }

    cout << res << endl;

    return 0;
}