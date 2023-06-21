---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: utils/annealing.cpp
    title: utils/annealing.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/xorshift.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n\nuint32_t rand_int() // XorShift random integer\
    \ generator\n{\n    static uint32_t x = 123456789, y = 362436069, z = 521288629,\
    \ w = 88675123;\n    uint32_t t = x ^ (x << 11);\n    x = y;\n    y = z;\n   \
    \ z = w;\n    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n}\ndouble rand_double()\
    \ { return (double)rand_int() / UINT32_MAX; }\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    uint32_t rand_int() // XorShift random integer generator\n{\n    static uint32_t\
    \ x = 123456789, y = 362436069, z = 521288629, w = 88675123;\n    uint32_t t =\
    \ x ^ (x << 11);\n    x = y;\n    y = z;\n    z = w;\n    return w = (w ^ (w >>\
    \ 19)) ^ (t ^ (t >> 8));\n}\ndouble rand_double() { return (double)rand_int()\
    \ / UINT32_MAX; }"
  dependsOn: []
  isVerificationFile: false
  path: random/xorshift.hpp
  requiredBy:
  - utils/annealing.cpp
  timestamp: '2023-06-22 00:16:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/xorshift.hpp
layout: document
redirect_from:
- /library/random/xorshift.hpp
- /library/random/xorshift.hpp.html
title: random/xorshift.hpp
---
