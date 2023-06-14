---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# \u30D5\u30A1\u30A4\u30EB\u51FA\u529B\u3092\u63A1\u70B9\u3059\u308B\u30BF\
    \u30A4\u30D7\u306E\u554F\u984C\u306E\uFF0C\u5358\u4E00\u30C6\u30B9\u30C8\u30B1\
    \u30FC\u30B9\u306E\u30B9\u30B3\u30A2\u8A08\u7B97\u30B9\u30AF\u30EA\u30D7\u30C8\
    \n\nimport sys\nimport os\nimport subprocess\n\nprogram_name = sys.argv[1]\ntest_name\
    \ = sys.argv[2]\nprint(program_name)\n\nsubprocess.run(\"g++ -O3 -std=c++17  -I\
    \ $HOME/Work/procon/lib/ac-library ../src/{0}.cpp -o ../src/{0}\".format(program_name),\
    \ shell=True, check=True)\nfilename = \"../score/{}.txt\".format(program_name)\n\
    \nsubprocess.run(\"rm {}\".format(filename), shell=True, check=False)\nsubprocess.run(\"\
    mkdir ../output/{}\".format(program_name), shell=True, check=False)\n\nsubprocess.run(\"\
    ../src/{0} < in/{1}.txt > ../output/{0}/{1}.txt \".format(program_name, test_name),\
    \ shell=True, check=False)\nres = subprocess.run(\"cargo run --release --bin vis\
    \ in/{0}.txt ../output/{1}/{0}.txt\".format(test_name, program_name), shell=True,\
    \ check=False, capture_output=True)\n# print(res)\nscore = int(res.stdout.decode().split('\\\
    n')[0].split(' ')[2])\nprint(score)"
  dependsOn: []
  isVerificationFile: false
  path: score/non_interactive/single_run.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: score/non_interactive/single_run.py
layout: document
redirect_from:
- /library/score/non_interactive/single_run.py
- /library/score/non_interactive/single_run.py.html
title: score/non_interactive/single_run.py
---
