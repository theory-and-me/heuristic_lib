import sys
import os
import subprocess
import time

start_time=time.perf_counter()
program_name = sys.argv[1]
print(program_name)
score_file = f"../score/{program_name}.txt"

subprocess.run("g++ -O3 -std=c++17 -I $HOME/Work/procon/lib/ac-library -DONLINE_JUDGE ../src/{0}.cpp -o ../src/{0}".format(program_name), shell=True, check=True)

output_dir_name = f"../output/{program_name}"
if not os.path.exists(output_dir_name):
    os.makedirs(output_dir_name)

in_list = os.listdir("in/")
in_list.sort()
total_score = 0
test_ids = []
scores = []
for test in in_list:
    test_id = test.split(".")[0]
    res = subprocess.run(f"cargo run --release --bin tester ../src/{program_name} < in/{test_id}.txt > ../output/{program_name}/{test_id}.txt", shell=True, check=False, capture_output=True)
    score = int(res.stderr.decode().split("=")[1].split(' ')[1].split("\n")[0])
    test_ids.append(test_id)
    scores.append(score)
    print(test_id, score)
    total_score += score
print(total_score)

end_time=time.perf_counter()
print(f"elapsed time: {end_time - start_time}")

with open(score_file, mode = "w") as f:
    for i in range(len(test_ids)):
        print(test_ids[i], scores[i], file=f)