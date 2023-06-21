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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import sys\nimport os\nimport subprocess\n\nprogram_name = sys.argv[1]\n\
    test_name = sys.argv[2]\nprint(program_name)\n\nsubprocess.run(\"g++ -O3 -std=c++17\
    \  -I $HOME/Work/procon/lib/ac-library ../src/{0}.cpp -o ../src/{0}\".format(program_name),\
    \ shell=True, check=True)\n\noutput_dir_name = f\"../output/{program_name}\"\n\
    if not os.path.exists(output_dir_name):\n    os.makedirs(output_dir_name)\n\n\
    res = subprocess.run(f\"cargo run --release --bin tester ../src/{program_name}\
    \ < in/{test_name}.txt > ../output/{program_name}/{test_name}.txt\", shell=True,\
    \ check=False, capture_output=True)\n# print(res)\nresults = int(res.stderr.decode().split(\"\
    =\")[1].split(' ')[1].split(\"\\n\")[0])\nprint(results)\n# score = int(results.split('\
    \ ')[2])\n# print(score)"
  dependsOn: []
  isVerificationFile: false
  path: score/interactive/single_run.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: score/interactive/single_run.py
layout: document
redirect_from:
- /library/score/interactive/single_run.py
- /library/score/interactive/single_run.py.html
title: score/interactive/single_run.py
---
