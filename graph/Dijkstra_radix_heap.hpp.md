---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structures/radix_heap.hpp
    title: data_structures/radix_heap.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/test/Dijkstra_radix_heap.test.cpp
    title: graph/test/Dijkstra_radix_heap.test.cpp
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
    \ 2 \"graph/Dijkstra_radix_heap.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n\n// T \u306F\u8FBA\u306E\u30B3\u30B9\u30C8\u306E\
    \u578B\ntemplate <typename T> using weighted_graph = vector<vector<pair<int, T>>>;\n\
    \ntemplate <typename T> \ntuple<T, vector<pair<int, int>>> Dijkstra(const weighted_graph<T>\
    \ &G, int s, int t, bool reconstruction){\n    const T T_INF = numeric_limits<T>::max()\
    \ / 2;\n    int V = G.size();\n    assert(0 <= s and s < V);\n    assert(0 <=\
    \ t and t < V);\n    vector<T> dist(V, T_INF);\n    vector<T> prev(V, -1);\n \
    \   dist[s] = 0;\n    radix_heap<typename std::make_unsigned<T>::type, int> pq;\n\
    \    pq.emplace(0, s);\n    while(!pq.empty()){\n        auto [d, v] = pq.top();\n\
    \        pq.pop();\n        if(t == v) break;\n        if(dist[v] < d) continue;\n\
    \        for(const auto &e: G[v]){\n            T dnx = d + e.second;\n      \
    \      if(dist[e.first] <= dnx) continue;\n            dist[e.first] = dnx;\n\
    \            prev[e.first] = v;\n            pq.emplace(dnx, e.first);\n     \
    \   }\n    }\n\n    // \u6700\u77ED\u8DEF\u306E\u5FA9\u5143\n    vector<pair<int,\
    \ int>> shortest_path;\n    if(reconstruction and dist[t] != T_INF){\n       \
    \ int v2 = t;\n        int v1 = prev[v2];\n        while(v2 != s){\n         \
    \   shortest_path.emplace_back(v1, v2);\n            v2 = v1;\n            v1\
    \ = prev[v1];\n        }\n        reverse(shortest_path.begin(), shortest_path.end());\n\
    \    }\n\n    return {(dist[t] == T_INF ? -1 : dist[t]), shortest_path};\n}\n"
  code: "#include \"../data_structures/radix_heap.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\n// T \u306F\u8FBA\u306E\u30B3\u30B9\
    \u30C8\u306E\u578B\ntemplate <typename T> using weighted_graph = vector<vector<pair<int,\
    \ T>>>;\n\ntemplate <typename T> \ntuple<T, vector<pair<int, int>>> Dijkstra(const\
    \ weighted_graph<T> &G, int s, int t, bool reconstruction){\n    const T T_INF\
    \ = numeric_limits<T>::max() / 2;\n    int V = G.size();\n    assert(0 <= s and\
    \ s < V);\n    assert(0 <= t and t < V);\n    vector<T> dist(V, T_INF);\n    vector<T>\
    \ prev(V, -1);\n    dist[s] = 0;\n    radix_heap<typename std::make_unsigned<T>::type,\
    \ int> pq;\n    pq.emplace(0, s);\n    while(!pq.empty()){\n        auto [d, v]\
    \ = pq.top();\n        pq.pop();\n        if(t == v) break;\n        if(dist[v]\
    \ < d) continue;\n        for(const auto &e: G[v]){\n            T dnx = d + e.second;\n\
    \            if(dist[e.first] <= dnx) continue;\n            dist[e.first] = dnx;\n\
    \            prev[e.first] = v;\n            pq.emplace(dnx, e.first);\n     \
    \   }\n    }\n\n    // \u6700\u77ED\u8DEF\u306E\u5FA9\u5143\n    vector<pair<int,\
    \ int>> shortest_path;\n    if(reconstruction and dist[t] != T_INF){\n       \
    \ int v2 = t;\n        int v1 = prev[v2];\n        while(v2 != s){\n         \
    \   shortest_path.emplace_back(v1, v2);\n            v2 = v1;\n            v1\
    \ = prev[v1];\n        }\n        reverse(shortest_path.begin(), shortest_path.end());\n\
    \    }\n\n    return {(dist[t] == T_INF ? -1 : dist[t]), shortest_path};\n}"
  dependsOn:
  - data_structures/radix_heap.hpp
  isVerificationFile: false
  path: graph/Dijkstra_radix_heap.hpp
  requiredBy: []
  timestamp: '2023-06-14 22:06:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/test/Dijkstra_radix_heap.test.cpp
documentation_of: graph/Dijkstra_radix_heap.hpp
layout: document
redirect_from:
- /library/graph/Dijkstra_radix_heap.hpp
- /library/graph/Dijkstra_radix_heap.hpp.html
title: graph/Dijkstra_radix_heap.hpp
---
