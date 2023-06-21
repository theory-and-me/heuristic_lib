---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: random/xorshift.hpp
    title: random/xorshift.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/xorshift.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n\nuint32_t rand_int() // XorShift random integer\
    \ generator\n{\n    static uint32_t x = 123456789, y = 362436069, z = 521288629,\
    \ w = 88675123;\n    uint32_t t = x ^ (x << 11);\n    x = y;\n    y = z;\n   \
    \ z = w;\n    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n}\ndouble rand_double()\
    \ { return (double)rand_int() / UINT32_MAX; }\n#line 2 \"utils/annealing.cpp\"\
    \n\n#line 4 \"utils/annealing.cpp\"\n\nusing namespace std;\nusing ll = long long;\n\
    \nauto system_now = std::chrono::system_clock::now();\nint checktime() {\n\tauto\
    \ now = std::chrono::system_clock::now();\n\treturn std::chrono::duration_cast<std::chrono::milliseconds>(now\
    \ - system_now).count();\n}\n\ninline double get_temp(double start_temp, double\
    \ end_temp, int elapsed_time, int total_time) {\n    return end_temp + (start_temp\
    \ - end_temp) * elapsed_time / total_time;\n};\n\nint main(){\n    int start_time\
    \ = checktime();\n    int end_time = 1990;\n    int total_time = end_time - start_time;\n\
    \    double start_temp = 1e6;\n    double end_temp = 1e1;\n    const int inf_guard\
    \ = 1000; // exp \u304C\u767A\u6563\u3059\u308B\u306E\u3092\u9632\u3050\n    ll\
    \ cnt = 0;\n\n    // \u6700\u5C0F\u5316\u306E\u5834\u5408\n    while(true){\n\
    \        int now_time = checktime();\n        if(now_time > end_time) break;\n\
    \        int elapsed_time = now_time - start_time;\n        int delta = 10;\n\
    \        double temp = get_temp(start_temp, end_temp, elapsed_time, total_time);\n\
    \        double probability = 0;\n        if(delta > temp * inf_guard) probability\
    \ = 0;\n        else probability = std::exp(- delta / temp);\n        double random_val\
    \ = rand_double();\n\n        if(delta <= 0 or (delta > 0 and random_val < probability)){\n\
    \            cout << \"update\\n\";\n        }else{\n            cout << \"stay\\\
    n\";\n        }\n\n        cnt++;\n    }\n    cerr << cnt << \"\\n\";\n    return\
    \ 0;\n}\n"
  code: "#include \"../random/xorshift.hpp\"\n\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\nusing ll = long long;\n\nauto system_now = std::chrono::system_clock::now();\n\
    int checktime() {\n\tauto now = std::chrono::system_clock::now();\n\treturn std::chrono::duration_cast<std::chrono::milliseconds>(now\
    \ - system_now).count();\n}\n\ninline double get_temp(double start_temp, double\
    \ end_temp, int elapsed_time, int total_time) {\n    return end_temp + (start_temp\
    \ - end_temp) * elapsed_time / total_time;\n};\n\nint main(){\n    int start_time\
    \ = checktime();\n    int end_time = 1990;\n    int total_time = end_time - start_time;\n\
    \    double start_temp = 1e6;\n    double end_temp = 1e1;\n    const int inf_guard\
    \ = 1000; // exp \u304C\u767A\u6563\u3059\u308B\u306E\u3092\u9632\u3050\n    ll\
    \ cnt = 0;\n\n    // \u6700\u5C0F\u5316\u306E\u5834\u5408\n    while(true){\n\
    \        int now_time = checktime();\n        if(now_time > end_time) break;\n\
    \        int elapsed_time = now_time - start_time;\n        int delta = 10;\n\
    \        double temp = get_temp(start_temp, end_temp, elapsed_time, total_time);\n\
    \        double probability = 0;\n        if(delta > temp * inf_guard) probability\
    \ = 0;\n        else probability = std::exp(- delta / temp);\n        double random_val\
    \ = rand_double();\n\n        if(delta <= 0 or (delta > 0 and random_val < probability)){\n\
    \            cout << \"update\\n\";\n        }else{\n            cout << \"stay\\\
    n\";\n        }\n\n        cnt++;\n    }\n    cerr << cnt << \"\\n\";\n    return\
    \ 0;\n}"
  dependsOn:
  - random/xorshift.hpp
  isVerificationFile: false
  path: utils/annealing.cpp
  requiredBy: []
  timestamp: '2023-06-22 00:16:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/annealing.cpp
layout: document
redirect_from:
- /library/utils/annealing.cpp
- /library/utils/annealing.cpp.html
title: utils/annealing.cpp
---
