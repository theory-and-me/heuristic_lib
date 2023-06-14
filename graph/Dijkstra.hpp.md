---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/test/Dijkstra.test.cpp
    title: graph/test/Dijkstra.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/Dijkstra.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n\n// T \u306F\u8FBA\u306E\u30B3\u30B9\u30C8\u306E\
    \u578B\ntemplate <typename T> using weighted_graph = vector<vector<pair<int, T>>>;\n\
    \ntemplate <typename T> \ntuple<T, vector<pair<int, int>>> Dijkstra(const weighted_graph<T>\
    \ &G, int s, int t, bool reconstruction){\n    const T T_INF = numeric_limits<T>::max()\
    \ / 2;\n    int V = G.size();\n    assert(0 <= s and s < V);\n    assert(0 <=\
    \ t and t < V);\n    vector<T> dist(V, T_INF);\n    vector<T> prev(V, -1);\n \
    \   dist[s] = 0;\n    using Pi = pair<T, int>;\n    priority_queue<Pi, vector<Pi>,\
    \ greater<Pi>> pq;\n    pq.emplace(0, s);\n    while(!pq.empty()){\n        auto\
    \ [d, v] = pq.top();\n        pq.pop();\n        if(t == v) break;\n        if(dist[v]\
    \ < d) continue;\n        for(const auto &e: G[v]){\n            T dnx = d + e.second;\n\
    \            if(dist[e.first] <= dnx) continue;\n            dist[e.first] = dnx;\n\
    \            prev[e.first] = v;\n            pq.emplace(dnx, e.first);\n     \
    \   }\n    }\n\n    // \u6700\u77ED\u8DEF\u306E\u5FA9\u5143\n    vector<pair<int,\
    \ int>> shortest_path;\n    if(reconstruction and dist[t] != T_INF){\n       \
    \ int v2 = t;\n        int v1 = prev[v2];\n        while(v2 != s){\n         \
    \   shortest_path.emplace_back(v1, v2);\n            v2 = v1;\n            v1\
    \ = prev[v1];\n        }\n        reverse(shortest_path.begin(), shortest_path.end());\n\
    \    }\n\n    return {(dist[t] == T_INF ? -1 : dist[t]), shortest_path};\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    // T \u306F\u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u578B\ntemplate <typename T> using\
    \ weighted_graph = vector<vector<pair<int, T>>>;\n\ntemplate <typename T> \ntuple<T,\
    \ vector<pair<int, int>>> Dijkstra(const weighted_graph<T> &G, int s, int t, bool\
    \ reconstruction){\n    const T T_INF = numeric_limits<T>::max() / 2;\n    int\
    \ V = G.size();\n    assert(0 <= s and s < V);\n    assert(0 <= t and t < V);\n\
    \    vector<T> dist(V, T_INF);\n    vector<T> prev(V, -1);\n    dist[s] = 0;\n\
    \    using Pi = pair<T, int>;\n    priority_queue<Pi, vector<Pi>, greater<Pi>>\
    \ pq;\n    pq.emplace(0, s);\n    while(!pq.empty()){\n        auto [d, v] = pq.top();\n\
    \        pq.pop();\n        if(t == v) break;\n        if(dist[v] < d) continue;\n\
    \        for(const auto &e: G[v]){\n            T dnx = d + e.second;\n      \
    \      if(dist[e.first] <= dnx) continue;\n            dist[e.first] = dnx;\n\
    \            prev[e.first] = v;\n            pq.emplace(dnx, e.first);\n     \
    \   }\n    }\n\n    // \u6700\u77ED\u8DEF\u306E\u5FA9\u5143\n    vector<pair<int,\
    \ int>> shortest_path;\n    if(reconstruction and dist[t] != T_INF){\n       \
    \ int v2 = t;\n        int v1 = prev[v2];\n        while(v2 != s){\n         \
    \   shortest_path.emplace_back(v1, v2);\n            v2 = v1;\n            v1\
    \ = prev[v1];\n        }\n        reverse(shortest_path.begin(), shortest_path.end());\n\
    \    }\n\n    return {(dist[t] == T_INF ? -1 : dist[t]), shortest_path};\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2023-06-14 21:52:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/test/Dijkstra.test.cpp
documentation_of: graph/Dijkstra.hpp
layout: document
redirect_from:
- /library/graph/Dijkstra.hpp
- /library/graph/Dijkstra.hpp.html
title: graph/Dijkstra.hpp
---
