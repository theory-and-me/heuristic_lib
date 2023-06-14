---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structures/radix_heap.hpp
    title: data_structures/radix_heap.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: grid/test/grid_Dijkstra.test.cpp
    title: grid/test/grid_Dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: grid/test/grid_bfs.test.cpp
    title: grid/test/grid_bfs.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structures/radix_heap.hpp\"\n#include <array>\n#include\
    \ <cstddef>\n#include <limits>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <utility>\n#include <vector>\n\n// Radix heap for unsigned integer\n// https://github.com/iwiwi/radix-heap\n\
    // hitonanode \u3055\u3093\u306E radix heap. https://hitonanode.github.io/cplib-cpp/data_structure/radix_heap.hpp\n\
    template <class Uint, class Label, typename std::enable_if<std::is_unsigned<Uint>::value>::type\
    \ * = nullptr>\nclass radix_heap {\n    int sz;\n    Uint last;\n    std::array<std::vector<std::pair<Uint,\
    \ Label>>, std::numeric_limits<Uint>::digits + 1> v;\n\n    template <class U,\
    \ typename std::enable_if<sizeof(U) == 4>::type * = nullptr>\n    static inline\
    \ int bucket(U x) noexcept {\n        return x ? 32 - __builtin_clz(x) : 0;\n\
    \    }\n    template <class U, typename std::enable_if<sizeof(U) == 8>::type *\
    \ = nullptr>\n    static inline int bucket(U x) noexcept {\n        return x ?\
    \ 64 - __builtin_clzll(x) : 0;\n    }\n\n    void pull() {\n        if (!v[0].empty())\
    \ return;\n        int i = 1;\n        while (v[i].empty()) ++i;\n        last\
    \ = v[i].back().first;\n        for (int j = 0; j < int(v[i].size()); j++) last\
    \ = std::min(last, v[i][j].first);\n        for (int j = 0; j < int(v[i].size());\
    \ j++) {\n            v[bucket(v[i][j].first ^ last)].emplace_back(std::move(v[i][j]));\n\
    \        }\n        v[i].clear();\n    }\n\npublic:\n    radix_heap() : sz(0),\
    \ last(0) {\n        static_assert(std::numeric_limits<Uint>::digits > 0, \"Invalid\
    \ type.\");\n    }\n    std::size_t size() const noexcept { return sz; }\n   \
    \ bool empty() const noexcept { return sz == 0; }\n    void push(Uint x, const\
    \ Label &val) { ++sz, v[bucket(x ^ last)].emplace_back(x, val); }\n    void push(Uint\
    \ x, Label &&val) { ++sz, v[bucket(x ^ last)].emplace_back(x, std::move(val));\
    \ }\n    template <class... Args> void emplace(Uint x, Args &&...args) {\n   \
    \     ++sz, v[bucket(x ^ last)].emplace_back(std::piecewise_construct, std::forward_as_tuple(x),\n\
    \                                               std::forward_as_tuple(args...));\n\
    \    }\n    void pop() { pull(), --sz, v[0].pop_back(); }\n    std::pair<Uint,\
    \ Label> top() { return pull(), v[0].back(); }\n    Uint top_key() { return pull(),\
    \ last; }\n    Label &top_label() { return pull(), v[0].back().second; }\n   \
    \ void clear() noexcept {\n        sz = 0, last = 0;\n        for (auto &vec :\
    \ v) vec.clear();\n    }\n    void swap(radix_heap<Uint, Label> &a) {\n      \
    \  std::swap(sz, a.sz), std::swap(last, a.last), v.swap(a.v);\n    }\n};\n#line\
    \ 2 \"grid/grid_template.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\n\ntemplate<typename T> // T \u306F\u8FBA\u306E\u30B3\u30B9\
    \u30C8\u306E\u578B\nstruct grid_template{\n    const T T_INF = numeric_limits<T>::max();\n\
    \    const int num_dirs =  4;\n    const vector<int> dx = {0, -1, 0, 1};\n   \
    \ const vector<int> dy = {-1, 0, 1, 0};\n    const vector<char> dc = {'L', 'U',\
    \ 'R', 'D'};\n\n    // H: \u7E26\u306E\u9577\u3055 W: \u6A2A\u306E\u9577\u3055\
    \n    // access: \u79FB\u52D5\u30B3\u30B9\u30C8\u3092\u8868\u73FE\u3059\u308B\
    3\u6B21\u5143\u914D\u5217\uFF0Eaccess[x][y][dir] \u306F\u30DE\u30B9(x, y)\u304B\
    \u3089\u65B9\u5411dir\u306B\u9032\u3080\u3068\u304D\u306E\u30B3\u30B9\u30C8\u3092\
    \u8868\u3059\uFF0E-1\u306E\u5834\u5408\u306F\u79FB\u52D5\u4E0D\u53EF\u80FD\uFF0E\
    \n    int H, W;\n    vector<vector<vector<T>>> access;\n    vector<T> access_array;\n\
    \    bool array_flag = false;\n\n    grid_template(int H, int W): H(H), W(W){\n\
    \        access.resize(H);\n        for(int i=0;i<H;i++) access[i].resize(W);\n\
    \        for(int i=0;i<H;i++) for(int j=0;j<W;j++) access[i][j].resize(num_dirs);\n\
    \        for(int i=0;i<H;i++) for(int j=0;j<W;j++) for(int k=0;k<num_dirs;k++)\
    \ access[i][j][k] = -1;\n        access_array.resize(H * W * num_dirs);\n    }\n\
    \n    int encode_access(int x, int y, int z){\n        return x * W * num_dirs\
    \ + y * num_dirs + z;\n    }\n\n    int encode_grid(int x, int y){\n        return\
    \ x * W + y;\n    }\n\n    pair<int, int> decode_grid(int x){\n        return\
    \ {x / W, x % W};\n    }\n\n    void make_access_array(){\n        for(int i=0;i<H;i++){\n\
    \            for(int j=0;j<W;j++){\n                for(int k=0;k<num_dirs;k++){\n\
    \                    access_array[encode_access(i, j, k)] = access[i][j][k];\n\
    \                }\n            }\n        }\n        array_flag = true;\n   \
    \ }\n\n    // BFS\b. \u8FBA\u91CD\u307F\u304C1\u306E\u307F\u306E\u5834\u5408\u3057\
    \u304B\u4F7F\u3048\u306A\u3044\n    vector<vector<T>> bfs(int sx, int sy){\n\n\
    \        if(!array_flag) make_access_array();\n\n        vector<T> dist(H * W,\
    \ -1);\n        queue<int> qu;\n\n        int s = encode_grid(sx, sy);\n     \
    \   dist[s] = 0;\n        qu.emplace(s);\n\n        while(!qu.empty()){\n    \
    \        auto v_cur = qu.front();qu.pop();\n            auto [cx, cy] = decode_grid(v_cur);\n\
    \            for(int i=0;i<num_dirs;i++){\n                int nx = cx + dx[i];\n\
    \                int ny = cy + dy[i];\n                int v_next = encode_grid(nx,\
    \ ny);\n                if(access_array[encode_access(cx, cy, i)] == -1) continue;\n\
    \                if(dist[v_next] != -1) continue;\n                \n        \
    \        dist[encode_grid(nx, ny)] = dist[v_cur] + access_array[encode_access(cx,\
    \ cy, i)];\n                qu.emplace(v_next);\n            }\n        }\n  \
    \      \n        vector<vector<T>> dist_grid(H, vector<T>(W));\n        for(int\
    \ i=0;i<H;i++){\n            for(int j=0;j<W;j++){\n                dist_grid[i][j]\
    \ = dist[encode_grid(i, j)];\n            }\n        }\n\n        return dist_grid;\n\
    \    }\n\n    // \u7D4C\u8DEF\u5FA9\u5143\u4ED8\u304DBFS\b. \u8FBA\u91CD\u307F\
    \u304C1\u306E\u307F\u306E\u5834\u5408\u3057\u304B\u4F7F\u3048\u306A\u3044\n  \
    \  tuple<T, string> bfs_reconstruction(int sx, int sy, int tx, int ty){\n\n  \
    \      if(!array_flag) make_access_array();\n\n        vector<T> dist(H * W, -1);\n\
    \        vector<T> pre_v(H * W, -1);\n        queue<int> qu;\n\n        int s\
    \ = encode_grid(sx, sy);\n        dist[s] = 0;\n        qu.emplace(s);\n\n   \
    \     while(!qu.empty()){\n            auto v_cur = qu.front();qu.pop();\n   \
    \         auto [cx, cy] = decode_grid(v_cur);\n            for(int i=0;i<num_dirs;i++){\n\
    \                int nx = cx + dx[i];\n                int ny = cy + dy[i];\n\
    \                int v_next = encode_grid(nx, ny);\n                if(access_array[encode_access(cx,\
    \ cy, i)] == -1) continue;\n                if(dist[v_next] != -1) continue;\n\
    \                \n                dist[encode_grid(nx, ny)] = dist[v_cur] + access_array[encode_access(cx,\
    \ cy, i)];\n                pre_v[v_next] = v_cur;\n                qu.emplace(v_next);\n\
    \            }\n        }\n\n        string route = \"\";\n\n        if(dist[encode_grid(tx,\
    \ ty)] == -1){\n            return {-1, route};\n        }\n\n        int v_cur\
    \ = encode_grid(tx, ty);\n        while(v_cur != s){\n            int v_pre =\
    \ pre_v[v_cur];\n            auto [cx, cy] = decode_grid(v_cur);\n           \
    \ auto [px, py] = decode_grid(v_pre);\n            for(int i=0;i<4;i++){\n   \
    \             if(dx[i] == cx - px and dy[i] == cy - py){\n                   \
    \ route.push_back(dc[i]);\n                }\n            }\n            v_cur\
    \ = v_pre;\n        }\n        reverse(route.begin(), route.end());\n        return\
    \ {dist[encode_grid(tx, ty)], route};\n    }\n\n    // Dijkstra\u6CD5\u306B\u3088\
    \u308B\u6700\u77ED\u7D4C\u8DEF\uFF0E\u8CA0\u8FBA\u306F\u6271\u3048\u306A\u3044\
    \n    vector<vector<T>> Dijkstra(int sx, int sy){\n\n        if(!array_flag) make_access_array();\n\
    \n        int s = encode_grid(sx, sy);\n        vector<T> dist(H * W, T_INF);\n\
    \        vector<int> pre_v(H * W, T_INF);\n\n        using Pi = pair<T, int>;\n\
    \        priority_queue<Pi, vector<Pi>, greater<Pi>> pq;\n        // radix_heap<typename\
    \ std::make_unsigned<T>::type, int> pq; // \u7B26\u53F7\u306A\u3057\u6574\u6570\
    \u306B\u3057\u304B\u4F7F\u3048\u306A\u3044\u304C\uFF0C\u5B9A\u6570\u500D\u304C\
    \u9AD8\u901F\n\n        dist[s] = 0;\n        pq.emplace(0, s);\n\n        while(!pq.empty()){\n\
    \            auto [cost, v_cur] = pq.top();pq.pop();\n            auto [x_cur,\
    \ y_cur] = decode_grid(v_cur);\n            if(dist[v_cur] < cost) continue;\n\
    \            for(int i=0;i<num_dirs;i++){\n                if(access_array[v_cur\
    \ * num_dirs + i] == -1) continue;\n                auto cost_next = cost + access_array[v_cur\
    \ * num_dirs + i];\n                int x_next = x_cur + dx[i];\n            \
    \    int y_next = y_cur + dy[i];\n                int v_next = encode_grid(x_next,\
    \ y_next);\n                if(dist[v_next] <= cost_next) continue;\n        \
    \        dist[v_next] = cost_next;\n                pq.emplace(dist[v_next], v_next);\n\
    \            }\n        }\n\n        vector<vector<T>> dist_grid(H, vector<T>(W));\n\
    \        for(int i=0;i<H;i++){\n            for(int j=0;j<W;j++){\n          \
    \      dist_grid[i][j] = dist[encode_grid(i, j)];\n            }\n        }\n\n\
    \        return dist_grid;\n    }\n\n    // Dijkstra\u6CD5\u306B\u3088\u308B\u7D4C\
    \u8DEF\u5FA9\u5143\u4ED8\u304D\u6700\u77ED\u7D4C\u8DEF\uFF0E\u8CA0\u8FBA\u306F\
    \u6271\u3048\u306A\u3044\n    tuple<T, string> Dijkstra_reconstruction(int sx,\
    \ int sy, int tx, int ty){\n\n        if(!array_flag) make_access_array();\n\n\
    \        int s = encode_grid(sx, sy);\n        vector<T> dist(H * W, T_INF);\n\
    \        vector<int> pre_v(H * W, T_INF);\n\n        using Pi = pair<T, int>;\n\
    \        priority_queue<Pi, vector<Pi>, greater<Pi>> pq;\n        // radix_heap<typename\
    \ std::make_unsigned<T>::type, int> pq; // \u7B26\u53F7\u306A\u3057\u6574\u6570\
    \u306B\u3057\u304B\u4F7F\u3048\u306A\u3044\u304C\uFF0C\u5B9A\u6570\u500D\u304C\
    \u9AD8\u901F\n\n        dist[s] = 0;\n        pq.emplace(0, s);\n\n        while(!pq.empty()){\n\
    \            auto [cost, v_cur] = pq.top();pq.pop();\n            auto [x_cur,\
    \ y_cur] = decode_grid(v_cur);\n            if(dist[v_cur] < cost) continue;\n\
    \            for(int i=0;i<num_dirs;i++){\n                if(access_array[v_cur\
    \ * num_dirs + i] == -1) continue;\n                auto cost_next = cost + access_array[v_cur\
    \ * num_dirs + i];\n                int x_next = x_cur + dx[i];\n            \
    \    int y_next = y_cur + dy[i];\n                int v_next = encode_grid(x_next,\
    \ y_next);\n                if(dist[v_next] <= cost_next) continue;\n        \
    \        dist[v_next] = cost_next;\n                pre_v[v_next] = v_cur;\n \
    \               pq.emplace(dist[v_next], v_next);\n            }\n        }\n\n\
    \        string route = \"\";\n\n        if(dist[encode_grid(tx, ty)] == T_INF){\n\
    \            return {dist[encode_grid(tx, ty)], route};\n        }\n\n       \
    \ int v_cur = encode_grid(tx, ty);\n        while(v_cur != s){\n            int\
    \ v_pre = pre_v[v_cur];\n            auto [cx, cy] = decode_grid(v_cur);\n   \
    \         auto [px, py] = decode_grid(v_pre);\n            for(int i=0;i<4;i++){\n\
    \                if(dx[i] == cx - px and dy[i] == cy - py){\n                \
    \    route.push_back(dc[i]);\n                    break;\n                }\n\
    \            }\n            v_cur = v_pre;\n        }\n        reverse(route.begin(),\
    \ route.end());\n\n        return {dist[encode_grid(tx, ty)], route};\n    }\n\
    };\n"
  code: "#include \"../data_structures/radix_heap.hpp\" \n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\ntemplate<typename T> // T \u306F\
    \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u578B\nstruct grid_template{\n    const T\
    \ T_INF = numeric_limits<T>::max();\n    const int num_dirs =  4;\n    const vector<int>\
    \ dx = {0, -1, 0, 1};\n    const vector<int> dy = {-1, 0, 1, 0};\n    const vector<char>\
    \ dc = {'L', 'U', 'R', 'D'};\n\n    // H: \u7E26\u306E\u9577\u3055 W: \u6A2A\u306E\
    \u9577\u3055\n    // access: \u79FB\u52D5\u30B3\u30B9\u30C8\u3092\u8868\u73FE\u3059\
    \u308B3\u6B21\u5143\u914D\u5217\uFF0Eaccess[x][y][dir] \u306F\u30DE\u30B9(x, y)\u304B\
    \u3089\u65B9\u5411dir\u306B\u9032\u3080\u3068\u304D\u306E\u30B3\u30B9\u30C8\u3092\
    \u8868\u3059\uFF0E-1\u306E\u5834\u5408\u306F\u79FB\u52D5\u4E0D\u53EF\u80FD\uFF0E\
    \n    int H, W;\n    vector<vector<vector<T>>> access;\n    vector<T> access_array;\n\
    \    bool array_flag = false;\n\n    grid_template(int H, int W): H(H), W(W){\n\
    \        access.resize(H);\n        for(int i=0;i<H;i++) access[i].resize(W);\n\
    \        for(int i=0;i<H;i++) for(int j=0;j<W;j++) access[i][j].resize(num_dirs);\n\
    \        for(int i=0;i<H;i++) for(int j=0;j<W;j++) for(int k=0;k<num_dirs;k++)\
    \ access[i][j][k] = -1;\n        access_array.resize(H * W * num_dirs);\n    }\n\
    \n    int encode_access(int x, int y, int z){\n        return x * W * num_dirs\
    \ + y * num_dirs + z;\n    }\n\n    int encode_grid(int x, int y){\n        return\
    \ x * W + y;\n    }\n\n    pair<int, int> decode_grid(int x){\n        return\
    \ {x / W, x % W};\n    }\n\n    void make_access_array(){\n        for(int i=0;i<H;i++){\n\
    \            for(int j=0;j<W;j++){\n                for(int k=0;k<num_dirs;k++){\n\
    \                    access_array[encode_access(i, j, k)] = access[i][j][k];\n\
    \                }\n            }\n        }\n        array_flag = true;\n   \
    \ }\n\n    // BFS\b. \u8FBA\u91CD\u307F\u304C1\u306E\u307F\u306E\u5834\u5408\u3057\
    \u304B\u4F7F\u3048\u306A\u3044\n    vector<vector<T>> bfs(int sx, int sy){\n\n\
    \        if(!array_flag) make_access_array();\n\n        vector<T> dist(H * W,\
    \ -1);\n        queue<int> qu;\n\n        int s = encode_grid(sx, sy);\n     \
    \   dist[s] = 0;\n        qu.emplace(s);\n\n        while(!qu.empty()){\n    \
    \        auto v_cur = qu.front();qu.pop();\n            auto [cx, cy] = decode_grid(v_cur);\n\
    \            for(int i=0;i<num_dirs;i++){\n                int nx = cx + dx[i];\n\
    \                int ny = cy + dy[i];\n                int v_next = encode_grid(nx,\
    \ ny);\n                if(access_array[encode_access(cx, cy, i)] == -1) continue;\n\
    \                if(dist[v_next] != -1) continue;\n                \n        \
    \        dist[encode_grid(nx, ny)] = dist[v_cur] + access_array[encode_access(cx,\
    \ cy, i)];\n                qu.emplace(v_next);\n            }\n        }\n  \
    \      \n        vector<vector<T>> dist_grid(H, vector<T>(W));\n        for(int\
    \ i=0;i<H;i++){\n            for(int j=0;j<W;j++){\n                dist_grid[i][j]\
    \ = dist[encode_grid(i, j)];\n            }\n        }\n\n        return dist_grid;\n\
    \    }\n\n    // \u7D4C\u8DEF\u5FA9\u5143\u4ED8\u304DBFS\b. \u8FBA\u91CD\u307F\
    \u304C1\u306E\u307F\u306E\u5834\u5408\u3057\u304B\u4F7F\u3048\u306A\u3044\n  \
    \  tuple<T, string> bfs_reconstruction(int sx, int sy, int tx, int ty){\n\n  \
    \      if(!array_flag) make_access_array();\n\n        vector<T> dist(H * W, -1);\n\
    \        vector<T> pre_v(H * W, -1);\n        queue<int> qu;\n\n        int s\
    \ = encode_grid(sx, sy);\n        dist[s] = 0;\n        qu.emplace(s);\n\n   \
    \     while(!qu.empty()){\n            auto v_cur = qu.front();qu.pop();\n   \
    \         auto [cx, cy] = decode_grid(v_cur);\n            for(int i=0;i<num_dirs;i++){\n\
    \                int nx = cx + dx[i];\n                int ny = cy + dy[i];\n\
    \                int v_next = encode_grid(nx, ny);\n                if(access_array[encode_access(cx,\
    \ cy, i)] == -1) continue;\n                if(dist[v_next] != -1) continue;\n\
    \                \n                dist[encode_grid(nx, ny)] = dist[v_cur] + access_array[encode_access(cx,\
    \ cy, i)];\n                pre_v[v_next] = v_cur;\n                qu.emplace(v_next);\n\
    \            }\n        }\n\n        string route = \"\";\n\n        if(dist[encode_grid(tx,\
    \ ty)] == -1){\n            return {-1, route};\n        }\n\n        int v_cur\
    \ = encode_grid(tx, ty);\n        while(v_cur != s){\n            int v_pre =\
    \ pre_v[v_cur];\n            auto [cx, cy] = decode_grid(v_cur);\n           \
    \ auto [px, py] = decode_grid(v_pre);\n            for(int i=0;i<4;i++){\n   \
    \             if(dx[i] == cx - px and dy[i] == cy - py){\n                   \
    \ route.push_back(dc[i]);\n                }\n            }\n            v_cur\
    \ = v_pre;\n        }\n        reverse(route.begin(), route.end());\n        return\
    \ {dist[encode_grid(tx, ty)], route};\n    }\n\n    // Dijkstra\u6CD5\u306B\u3088\
    \u308B\u6700\u77ED\u7D4C\u8DEF\uFF0E\u8CA0\u8FBA\u306F\u6271\u3048\u306A\u3044\
    \n    vector<vector<T>> Dijkstra(int sx, int sy){\n\n        if(!array_flag) make_access_array();\n\
    \n        int s = encode_grid(sx, sy);\n        vector<T> dist(H * W, T_INF);\n\
    \        vector<int> pre_v(H * W, T_INF);\n\n        using Pi = pair<T, int>;\n\
    \        priority_queue<Pi, vector<Pi>, greater<Pi>> pq;\n        // radix_heap<typename\
    \ std::make_unsigned<T>::type, int> pq; // \u7B26\u53F7\u306A\u3057\u6574\u6570\
    \u306B\u3057\u304B\u4F7F\u3048\u306A\u3044\u304C\uFF0C\u5B9A\u6570\u500D\u304C\
    \u9AD8\u901F\n\n        dist[s] = 0;\n        pq.emplace(0, s);\n\n        while(!pq.empty()){\n\
    \            auto [cost, v_cur] = pq.top();pq.pop();\n            auto [x_cur,\
    \ y_cur] = decode_grid(v_cur);\n            if(dist[v_cur] < cost) continue;\n\
    \            for(int i=0;i<num_dirs;i++){\n                if(access_array[v_cur\
    \ * num_dirs + i] == -1) continue;\n                auto cost_next = cost + access_array[v_cur\
    \ * num_dirs + i];\n                int x_next = x_cur + dx[i];\n            \
    \    int y_next = y_cur + dy[i];\n                int v_next = encode_grid(x_next,\
    \ y_next);\n                if(dist[v_next] <= cost_next) continue;\n        \
    \        dist[v_next] = cost_next;\n                pq.emplace(dist[v_next], v_next);\n\
    \            }\n        }\n\n        vector<vector<T>> dist_grid(H, vector<T>(W));\n\
    \        for(int i=0;i<H;i++){\n            for(int j=0;j<W;j++){\n          \
    \      dist_grid[i][j] = dist[encode_grid(i, j)];\n            }\n        }\n\n\
    \        return dist_grid;\n    }\n\n    // Dijkstra\u6CD5\u306B\u3088\u308B\u7D4C\
    \u8DEF\u5FA9\u5143\u4ED8\u304D\u6700\u77ED\u7D4C\u8DEF\uFF0E\u8CA0\u8FBA\u306F\
    \u6271\u3048\u306A\u3044\n    tuple<T, string> Dijkstra_reconstruction(int sx,\
    \ int sy, int tx, int ty){\n\n        if(!array_flag) make_access_array();\n\n\
    \        int s = encode_grid(sx, sy);\n        vector<T> dist(H * W, T_INF);\n\
    \        vector<int> pre_v(H * W, T_INF);\n\n        using Pi = pair<T, int>;\n\
    \        priority_queue<Pi, vector<Pi>, greater<Pi>> pq;\n        // radix_heap<typename\
    \ std::make_unsigned<T>::type, int> pq; // \u7B26\u53F7\u306A\u3057\u6574\u6570\
    \u306B\u3057\u304B\u4F7F\u3048\u306A\u3044\u304C\uFF0C\u5B9A\u6570\u500D\u304C\
    \u9AD8\u901F\n\n        dist[s] = 0;\n        pq.emplace(0, s);\n\n        while(!pq.empty()){\n\
    \            auto [cost, v_cur] = pq.top();pq.pop();\n            auto [x_cur,\
    \ y_cur] = decode_grid(v_cur);\n            if(dist[v_cur] < cost) continue;\n\
    \            for(int i=0;i<num_dirs;i++){\n                if(access_array[v_cur\
    \ * num_dirs + i] == -1) continue;\n                auto cost_next = cost + access_array[v_cur\
    \ * num_dirs + i];\n                int x_next = x_cur + dx[i];\n            \
    \    int y_next = y_cur + dy[i];\n                int v_next = encode_grid(x_next,\
    \ y_next);\n                if(dist[v_next] <= cost_next) continue;\n        \
    \        dist[v_next] = cost_next;\n                pre_v[v_next] = v_cur;\n \
    \               pq.emplace(dist[v_next], v_next);\n            }\n        }\n\n\
    \        string route = \"\";\n\n        if(dist[encode_grid(tx, ty)] == T_INF){\n\
    \            return {dist[encode_grid(tx, ty)], route};\n        }\n\n       \
    \ int v_cur = encode_grid(tx, ty);\n        while(v_cur != s){\n            int\
    \ v_pre = pre_v[v_cur];\n            auto [cx, cy] = decode_grid(v_cur);\n   \
    \         auto [px, py] = decode_grid(v_pre);\n            for(int i=0;i<4;i++){\n\
    \                if(dx[i] == cx - px and dy[i] == cy - py){\n                \
    \    route.push_back(dc[i]);\n                    break;\n                }\n\
    \            }\n            v_cur = v_pre;\n        }\n        reverse(route.begin(),\
    \ route.end());\n\n        return {dist[encode_grid(tx, ty)], route};\n    }\n\
    };"
  dependsOn:
  - data_structures/radix_heap.hpp
  isVerificationFile: false
  path: grid/grid_template.hpp
  requiredBy: []
  timestamp: '2023-06-14 01:33:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - grid/test/grid_Dijkstra.test.cpp
  - grid/test/grid_bfs.test.cpp
documentation_of: grid/grid_template.hpp
layout: document
redirect_from:
- /library/grid/grid_template.hpp
- /library/grid/grid_template.hpp.html
title: grid/grid_template.hpp
---
