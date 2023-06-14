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
  code: "import sys\nimport os\nimport subprocess\nimport time\n\nstart_time=time.perf_counter()\n\
    program_name = sys.argv[1]\nprint(program_name)\nscore_file = f\"../score/{program_name}.txt\"\
    \n\nsubprocess.run(\"g++ -O3 -std=c++17 -I $HOME/Work/procon/lib/ac-library -DONLINE_JUDGE\
    \ ../src/{0}.cpp -o ../src/{0}\".format(program_name), shell=True, check=True)\n\
    \noutput_dir_name = f\"../output/{program_name}\"\nif not os.path.exists(output_dir_name):\n\
    \    os.makedirs(output_dir_name)\n\nin_list = os.listdir(\"in/\")\nin_list.sort()\n\
    total_score = 0\ntest_ids = []\nscores = []\nfor test in in_list:\n    test_id\
    \ = test.split(\".\")[0]\n    res = subprocess.run(f\"cargo run --release --bin\
    \ tester ../src/{program_name} < in/{test_id}.txt > ../output/{program_name}/{test_id}.txt\"\
    , shell=True, check=False, capture_output=True)\n    score = int(res.stderr.decode().split(\"\
    =\")[1].split(' ')[1].split(\"\\n\")[0])\n    test_ids.append(test_id)\n    scores.append(score)\n\
    \    print(test_id, score)\n    total_score += score\nprint(total_score)\n\nend_time=time.perf_counter()\n\
    print(f\"elapsed time: {end_time - start_time}\")\n\nwith open(score_file, mode\
    \ = \"w\") as f:\n    for i in range(len(test_ids)):\n        print(test_ids[i],\
    \ scores[i], file=f)"
  dependsOn: []
  isVerificationFile: false
  path: score/interactive/calc_score.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: score/interactive/calc_score.py
layout: document
redirect_from:
- /library/score/interactive/calc_score.py
- /library/score/interactive/calc_score.py.html
title: score/interactive/calc_score.py
---
