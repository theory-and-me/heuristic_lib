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
  code: "from genericpath import isfile\nimport sys\nimport os\nimport shutil\nimport\
    \ subprocess\nimport shutil\nimport time\nimport multiprocessing\nimport re\n\
    from turtle import width\n\nnum_processes = 48\nprogram_name = sys.argv[1]\nnum_test_case\
    \ = 0\nnum_of_run = 0\nnum_of_evaluate = 0\n\ndef init():\n    if not os.path.exists(f\"\
    ../output/{program_name}\"):\n        os.makedirs(f\"../output/{program_name}\"\
    )\n    if not os.path.exists(f\"../score/{program_name}\"):\n        os.makedirs(f\"\
    ../score/{program_name}\")\n\n    subprocess.run(\"g++ -O3 -std=c++17 -I $HOME/Work/procon/lib/ac-library\
    \ -DONLINE_JUDGE ../src/{0}.cpp -o ../src/{0}\".format(program_name), shell=True,\
    \ check=True)\n    return\n\ndef get_txt_list():\n    files = os.listdir(\"in/\"\
    )\n    txt_files = [f for f in files if f.endswith(\".txt\")]\n    txt_files.sort()\n\
    \    return txt_files\n\ndef run_test_case(file_name):\n    run_time = 0.0\n \
    \   with open(\"in/\" + file_name, \"r\") as f_in:\n        with open(f\"../output/{program_name}/\"\
    \ + file_name, \"w\") as f_out:\n            start_time=time.perf_counter()\n\
    \            subprocess.run([f\"../src/{program_name}\"], stdin=f_in, stdout=f_out)\n\
    \            end_time=time.perf_counter()\n            run_time=end_time-start_time\n\
    \    print(file_name)\n    return    \n\ndef evaluate_all(txt_files):\n    for\
    \ file_name in txt_files:\n\n        output_dir = f\"../score/{program_name}/\"\
    \n        if not os.path.exists(output_dir):\n            os.makedirs(output_dir)\n\
    \        output_file = output_dir + file_name\n\n        #\u516C\u5F0F\u914D\u5E03\
    \u306ERust\u3092\u5B9F\u884C&\u7D50\u679C\u306E\u66F8\u304D\u8FBC\u307F\n    \
    \    with open(output_file, \"w\") as f_out:\n            subprocess.run([\"cargo\"\
    , \"run\", \"--release\", \"--bin\", \"vis\", \"in/\" + file_name, f\"../output/{program_name}/\"\
    \ + file_name], stdout=f_out)\n\n        #\u30D3\u30B8\u30E5\u30A2\u30E9\u30A4\
    \u30BA\u7D50\u679C\u3092\u30B3\u30D4\u30FC\u3057\u3066\u79FB\u52D5\u3059\u308B\
    \u51E6\u7406\n        # if os.path.exists(\"vis.html\"):\n        #     shutil.copy(\"\
    vis.html\",\"result/visualizer/vis\"+file_name+\".html\")\n\ndef evaluate_test_case(file_name):\n\
    \n    output_dir = f\"../score/{program_name}/\"\n    if not os.path.exists(output_dir):\n\
    \        os.makedirs(output_dir)\n    output_file = output_dir + file_name\n\n\
    \    #\u516C\u5F0F\u914D\u5E03\u306ERust\u3092\u5B9F\u884C&\u7D50\u679C\u306E\u66F8\
    \u304D\u8FBC\u307F\n    res = subprocess.run([\"cargo\", \"run\", \"--release\"\
    , \"--bin\", \"vis\", \"in/\" + file_name, f\"../output/{program_name}/\" + file_name],\
    \ capture_output=True)\n    with open(output_file, \"w\") as f_out:\n        f_out.write(res.stdout.decode())\n\
    \n    #\u30D3\u30B8\u30E5\u30A2\u30E9\u30A4\u30BA\u7D50\u679C\u3092\u30B3\u30D4\
    \u30FC\u3057\u3066\u79FB\u52D5\u3059\u308B\u51E6\u7406\n    # if os.path.exists(\"\
    vis.html\"):\n    #     shutil.copy(\"vis.html\",\"result/visualizer/vis\"+file_name+\"\
    .html\")\n\n    print(file_name)\n\ndef show_scores(txt_files):\n    output_file_name\
    \ = f\"compare_scores/{program_name}.txt\"\n    if(os.path.isfile(output_file_name)):\n\
    \        os.remove(output_file_name)\n    for file_name in txt_files:\n      \
    \  with open(f\"../score/{program_name}/{file_name}\", 'r') as f:\n          \
    \  test_case = file_name.split(\".\")[0]\n            score = (re.split(\"[ \\\
    n]\", f.readline()))[2]\n            print(test_case, score)\n            with\
    \ open(output_file_name, \"a\") as f:\n                print(test_case, score,\
    \ file = f)\n\ndef main():\n    start_time=time.perf_counter()\n    filename =\
    \ \"../score/{}.txt\".format(program_name)\n    print(program_name)\n\n    init()\n\
    \    txt_files = get_txt_list()\n    num_test_case = len(txt_files)\n\n    print(\"\
    --START RUN--\")\n    with multiprocessing.Pool(processes = num_processes)as p:\n\
    \        p.map(run_test_case, txt_files)\n\n    print(\"\\n--START EVALUATION--\"\
    )\n    with multiprocessing.Pool(processes = num_processes)as p:\n        p.map(evaluate_test_case,\
    \ txt_files)\n\n    show_scores(txt_files)\n    end_time=time.perf_counter()\n\
    \    print(f\"elapsed time: {end_time - start_time}\")\n\n    return\n\n\nif __name__\
    \ == \"__main__\":\n    main()"
  dependsOn: []
  isVerificationFile: false
  path: score/interactive/parallel_score.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: score/interactive/parallel_score.py
layout: document
redirect_from:
- /library/score/interactive/parallel_score.py
- /library/score/interactive/parallel_score.py.html
title: score/interactive/parallel_score.py
---
