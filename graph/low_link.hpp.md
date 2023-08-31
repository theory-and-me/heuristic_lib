---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: graph/test/articulation_points.test.cpp
    title: graph/test/articulation_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: graph/test/bridges.test.cpp
    title: graph/test/bridges.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/low_link.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct low_link {\n    int V, cnt;\n    vector<vector<int>> graph;\n\
    \    vector<int> ord, low;\n    vector<int> articulation_points;\n    vector<pair<int,\
    \ int>> bridges;\n    low_link(int V)\n        : V(V), cnt(0), graph(V), ord(V,\
    \ -1), low(V, -1) {\n    }\n\n    void add_edge(int u, int v) {\n        graph[u].push_back(v);\n\
    \        graph[v].push_back(u);\n    }\n\n    void dfs(int v, int par) {\n   \
    \     ord[v] = cnt;\n        low[v] = cnt;\n        cnt++;\n        bool is_articulation_point\
    \ = false;\n        int num_of_child = 0;\n        for (auto u : graph[v]) {\n\
    \            if (ord[u] == -1) {\n                num_of_child++;\n          \
    \      dfs(u, v);\n                if (low[v] > low[u]) {\n                  \
    \  low[v] = low[u];\n                }\n                if (par != -1 and ord[v]\
    \ <= low[u]) is_articulation_point = true;\n                if (ord[v] < low[u])\
    \ bridges.emplace_back(min(u, v), max(u, v));\n            } else if (u != par)\
    \ {\n                low[v] = min(low[v], ord[u]);\n            }\n        }\n\
    \        if (par == -1 and num_of_child >= 2) is_articulation_point = true;\n\
    \        if (is_articulation_point) articulation_points.push_back(v);\n      \
    \  return;\n    }\n\n    void build() {\n        for (int i = 0; i < V; i++) {\n\
    \            ord[i] = -1;\n            low[i] = -1;\n        }\n        for (int\
    \ i = 0; i < V; i++) {\n            if (ord[i] == -1) {\n                dfs(i,\
    \ -1);\n            }\n        }\n        sort(articulation_points.begin(), articulation_points.end());\n\
    \        sort(bridges.begin(), bridges.end());\n        return;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nstruct low_link {\n   \
    \ int V, cnt;\n    vector<vector<int>> graph;\n    vector<int> ord, low;\n   \
    \ vector<int> articulation_points;\n    vector<pair<int, int>> bridges;\n    low_link(int\
    \ V)\n        : V(V), cnt(0), graph(V), ord(V, -1), low(V, -1) {\n    }\n\n  \
    \  void add_edge(int u, int v) {\n        graph[u].push_back(v);\n        graph[v].push_back(u);\n\
    \    }\n\n    void dfs(int v, int par) {\n        ord[v] = cnt;\n        low[v]\
    \ = cnt;\n        cnt++;\n        bool is_articulation_point = false;\n      \
    \  int num_of_child = 0;\n        for (auto u : graph[v]) {\n            if (ord[u]\
    \ == -1) {\n                num_of_child++;\n                dfs(u, v);\n    \
    \            if (low[v] > low[u]) {\n                    low[v] = low[u];\n  \
    \              }\n                if (par != -1 and ord[v] <= low[u]) is_articulation_point\
    \ = true;\n                if (ord[v] < low[u]) bridges.emplace_back(min(u, v),\
    \ max(u, v));\n            } else if (u != par) {\n                low[v] = min(low[v],\
    \ ord[u]);\n            }\n        }\n        if (par == -1 and num_of_child >=\
    \ 2) is_articulation_point = true;\n        if (is_articulation_point) articulation_points.push_back(v);\n\
    \        return;\n    }\n\n    void build() {\n        for (int i = 0; i < V;\
    \ i++) {\n            ord[i] = -1;\n            low[i] = -1;\n        }\n    \
    \    for (int i = 0; i < V; i++) {\n            if (ord[i] == -1) {\n        \
    \        dfs(i, -1);\n            }\n        }\n        sort(articulation_points.begin(),\
    \ articulation_points.end());\n        sort(bridges.begin(), bridges.end());\n\
    \        return;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/low_link.hpp
  requiredBy: []
  timestamp: '2023-08-31 22:50:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - graph/test/bridges.test.cpp
  - graph/test/articulation_points.test.cpp
documentation_of: graph/low_link.hpp
layout: document
redirect_from:
- /library/graph/low_link.hpp
- /library/graph/low_link.hpp.html
title: graph/low_link.hpp
---
