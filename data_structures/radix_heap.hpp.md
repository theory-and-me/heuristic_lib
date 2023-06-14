---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: grid/grid_template.hpp
    title: grid/grid_template.hpp
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
    links:
    - https://github.com/iwiwi/radix-heap
    - https://hitonanode.github.io/cplib-cpp/data_structure/radix_heap.hpp
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
    \  std::swap(sz, a.sz), std::swap(last, a.last), v.swap(a.v);\n    }\n};\n"
  code: "#pragma once\n#include <array>\n#include <cstddef>\n#include <limits>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\n//\
    \ Radix heap for unsigned integer\n// https://github.com/iwiwi/radix-heap\n//\
    \ hitonanode \u3055\u3093\u306E radix heap. https://hitonanode.github.io/cplib-cpp/data_structure/radix_heap.hpp\n\
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
    \  std::swap(sz, a.sz), std::swap(last, a.last), v.swap(a.v);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data_structures/radix_heap.hpp
  requiredBy:
  - grid/grid_template.hpp
  timestamp: '2023-06-14 00:05:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - grid/test/grid_bfs.test.cpp
  - grid/test/grid_Dijkstra.test.cpp
documentation_of: data_structures/radix_heap.hpp
layout: document
redirect_from:
- /library/data_structures/radix_heap.hpp
- /library/data_structures/radix_heap.hpp.html
title: data_structures/radix_heap.hpp
---
