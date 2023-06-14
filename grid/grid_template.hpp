#include "../data_structures/radix_heap.hpp" 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<typename T> // T は辺のコストの型
struct grid_template{
    const T T_INF = numeric_limits<T>::max() / 2;
    const int num_dirs =  4;
    const vector<int> dx = {0, -1, 0, 1};
    const vector<int> dy = {-1, 0, 1, 0};
    const vector<char> dc = {'L', 'U', 'R', 'D'};

    // H: 縦の長さ W: 横の長さ
    // access: 移動コストを表現する3次元配列．access[x][y][dir] はマス(x, y)から方向dirに進むときのコストを表す．-1の場合は移動不可能．
    int H, W;
    vector<vector<vector<T>>> access;
    vector<T> access_array;
    bool array_flag = false;

    grid_template(int H, int W): H(H), W(W){
        access.resize(H);
        for(int i=0;i<H;i++) access[i].resize(W);
        for(int i=0;i<H;i++) for(int j=0;j<W;j++) access[i][j].resize(num_dirs);
        for(int i=0;i<H;i++) for(int j=0;j<W;j++) for(int k=0;k<num_dirs;k++) access[i][j][k] = -1;
        access_array.resize(H * W * num_dirs);
    }

    int encode_access(int x, int y, int z){
        return x * W * num_dirs + y * num_dirs + z;
    }

    int encode_grid(int x, int y){
        return x * W + y;
    }

    pair<int, int> decode_grid(int x){
        return {x / W, x % W};
    }

    void make_access_array(){
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                for(int k=0;k<num_dirs;k++){
                    access_array[encode_access(i, j, k)] = access[i][j][k];
                }
            }
        }
        array_flag = true;
    }

    // BFS. 辺重みが1のみの場合しか使えない
    vector<vector<T>> bfs(int sx, int sy){

        if(!array_flag) make_access_array();

        vector<T> dist(H * W, -1);
        queue<int> qu;

        int s = encode_grid(sx, sy);
        dist[s] = 0;
        qu.emplace(s);

        while(!qu.empty()){
            auto v_cur = qu.front();qu.pop();
            auto [cx, cy] = decode_grid(v_cur);
            for(int i=0;i<num_dirs;i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                int v_next = encode_grid(nx, ny);
                if(access_array[encode_access(cx, cy, i)] == -1) continue;
                if(dist[v_next] != -1) continue;
                
                dist[encode_grid(nx, ny)] = dist[v_cur] + access_array[encode_access(cx, cy, i)];
                qu.emplace(v_next);
            }
        }
        
        vector<vector<T>> dist_grid(H, vector<T>(W));
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                dist_grid[i][j] = dist[encode_grid(i, j)];
            }
        }

        return dist_grid;
    }

    // 経路復元付きBFS. 辺重みが1のみの場合しか使えない
    tuple<T, string> bfs_reconstruction(int sx, int sy, int tx, int ty){

        if(!array_flag) make_access_array();

        vector<T> dist(H * W, -1);
        vector<T> pre_v(H * W, -1);
        queue<int> qu;

        int s = encode_grid(sx, sy);
        dist[s] = 0;
        qu.emplace(s);

        while(!qu.empty()){
            auto v_cur = qu.front();qu.pop();
            auto [cx, cy] = decode_grid(v_cur);
            for(int i=0;i<num_dirs;i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                int v_next = encode_grid(nx, ny);
                if(access_array[encode_access(cx, cy, i)] == -1) continue;
                if(dist[v_next] != -1) continue;
                
                dist[encode_grid(nx, ny)] = dist[v_cur] + access_array[encode_access(cx, cy, i)];
                pre_v[v_next] = v_cur;
                qu.emplace(v_next);
            }
        }

        string route = "";

        if(dist[encode_grid(tx, ty)] == -1){
            return {-1, route};
        }

        int v_cur = encode_grid(tx, ty);
        while(v_cur != s){
            int v_pre = pre_v[v_cur];
            auto [cx, cy] = decode_grid(v_cur);
            auto [px, py] = decode_grid(v_pre);
            for(int i=0;i<4;i++){
                if(dx[i] == cx - px and dy[i] == cy - py){
                    route.push_back(dc[i]);
                }
            }
            v_cur = v_pre;
        }
        reverse(route.begin(), route.end());
        return {dist[encode_grid(tx, ty)], route};
    }

    // Dijkstra法による最短経路．負辺は扱えない
    vector<vector<T>> Dijkstra(int sx, int sy){

        if(!array_flag) make_access_array();

        int s = encode_grid(sx, sy);
        vector<T> dist(H * W, T_INF);
        vector<int> pre_v(H * W, T_INF);

        using Pi = pair<T, int>;
        priority_queue<Pi, vector<Pi>, greater<Pi>> pq;
        // radix_heap<typename std::make_unsigned<T>::type, int> pq; // 符号なし整数にしか使えないが，定数倍が高速

        dist[s] = 0;
        pq.emplace(0, s);

        while(!pq.empty()){
            auto [cost, v_cur] = pq.top();pq.pop();
            auto [x_cur, y_cur] = decode_grid(v_cur);
            if(dist[v_cur] < cost) continue;
            for(int i=0;i<num_dirs;i++){
                if(access_array[v_cur * num_dirs + i] == -1) continue;
                auto cost_next = cost + access_array[v_cur * num_dirs + i];
                int x_next = x_cur + dx[i];
                int y_next = y_cur + dy[i];
                int v_next = encode_grid(x_next, y_next);
                if(dist[v_next] <= cost_next) continue;
                dist[v_next] = cost_next;
                pq.emplace(dist[v_next], v_next);
            }
        }

        vector<vector<T>> dist_grid(H, vector<T>(W));
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                dist_grid[i][j] = dist[encode_grid(i, j)];
            }
        }

        return dist_grid;
    }

    // Dijkstra法による経路復元付き最短経路．負辺は扱えない
    tuple<T, string> Dijkstra_reconstruction(int sx, int sy, int tx, int ty){

        if(!array_flag) make_access_array();

        int s = encode_grid(sx, sy);
        vector<T> dist(H * W, T_INF);
        vector<int> pre_v(H * W, T_INF);

        using Pi = pair<T, int>;
        priority_queue<Pi, vector<Pi>, greater<Pi>> pq;
        // radix_heap<typename std::make_unsigned<T>::type, int> pq; // 符号なし整数にしか使えないが，定数倍が高速

        dist[s] = 0;
        pq.emplace(0, s);

        while(!pq.empty()){
            auto [cost, v_cur] = pq.top();pq.pop();
            auto [x_cur, y_cur] = decode_grid(v_cur);
            if(dist[v_cur] < cost) continue;
            for(int i=0;i<num_dirs;i++){
                if(access_array[v_cur * num_dirs + i] == -1) continue;
                auto cost_next = cost + access_array[v_cur * num_dirs + i];
                int x_next = x_cur + dx[i];
                int y_next = y_cur + dy[i];
                int v_next = encode_grid(x_next, y_next);
                if(dist[v_next] <= cost_next) continue;
                dist[v_next] = cost_next;
                pre_v[v_next] = v_cur;
                pq.emplace(dist[v_next], v_next);
            }
        }

        string route = "";

        if(dist[encode_grid(tx, ty)] == T_INF){
            return {dist[encode_grid(tx, ty)], route};
        }

        int v_cur = encode_grid(tx, ty);
        while(v_cur != s){
            int v_pre = pre_v[v_cur];
            auto [cx, cy] = decode_grid(v_cur);
            auto [px, py] = decode_grid(v_pre);
            for(int i=0;i<4;i++){
                if(dx[i] == cx - px and dy[i] == cy - py){
                    route.push_back(dc[i]);
                    break;
                }
            }
            v_cur = v_pre;
        }
        reverse(route.begin(), route.end());

        return {dist[encode_grid(tx, ty)], route};
    }
};