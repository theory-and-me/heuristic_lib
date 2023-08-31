---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/low_link.hpp
    title: graph/low_link.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "#line 1 \"graph/test/bridges.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n#include <bits/stdc++.h>\n\n#line 2 \"graph/low_link.hpp\"\nusing namespace\
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
    \        sort(bridges.begin(), bridges.end());\n        return;\n    }\n};\n#line\
    \ 5 \"graph/test/bridges.test.cpp\"\nusing namespace std;\n\nint main() {\n  \
    \  int V, E;\n    cin >> V >> E;\n    vector<int> s(E), t(E);\n    for (int i\
    \ = 0; i < E; i++) {\n        cin >> s[i] >> t[i];\n    }\n\n    low_link lk(V);\n\
    \    for (int i = 0; i < E; i++) {\n        lk.add_edge(s[i], t[i]);\n    }\n\
    \    lk.build();\n    for (int i = 0; i < (int)lk.bridges.size(); i++) {\n   \
    \     cout << lk.bridges[i].first << \" \" << lk.bridges[i].second << \"\\n\"\
    ;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n#include <bits/stdc++.h>\n\n#include \"../low_link.hpp\"\nusing namespace std;\n\
    \nint main() {\n    int V, E;\n    cin >> V >> E;\n    vector<int> s(E), t(E);\n\
    \    for (int i = 0; i < E; i++) {\n        cin >> s[i] >> t[i];\n    }\n\n  \
    \  low_link lk(V);\n    for (int i = 0; i < E; i++) {\n        lk.add_edge(s[i],\
    \ t[i]);\n    }\n    lk.build();\n    for (int i = 0; i < (int)lk.bridges.size();\
    \ i++) {\n        cout << lk.bridges[i].first << \" \" << lk.bridges[i].second\
    \ << \"\\n\";\n    }\n}"
  dependsOn:
  - graph/low_link.hpp
  isVerificationFile: true
  path: graph/test/bridges.test.cpp
  requiredBy: []
  timestamp: '2023-08-31 22:50:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: graph/test/bridges.test.cpp
layout: document
redirect_from:
- /verify/graph/test/bridges.test.cpp
- /verify/graph/test/bridges.test.cpp.html
title: graph/test/bridges.test.cpp
---
