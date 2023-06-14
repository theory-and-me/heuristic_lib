import sys
import os
import subprocess

program_name = sys.argv[1]
test_name = sys.argv[2]
print(program_name)

subprocess.run("g++ -O3 -std=c++17  -I $HOME/Work/procon/lib/ac-library ../src/{0}.cpp -o ../src/{0}".format(program_name), shell=True, check=True)

output_dir_name = f"../output/{program_name}"
if not os.path.exists(output_dir_name):
    os.makedirs(output_dir_name)

res = subprocess.run(f"cargo run --release --bin tester ../src/{program_name} < in/{test_name}.txt > ../output/{program_name}/{test_name}.txt", shell=True, check=False, capture_output=True)
# print(res)
results = int(res.stderr.decode().split("=")[1].split(' ')[1].split("\n")[0])
print(results)
# score = int(results.split(' ')[2])
# print(score)