from genericpath import isfile
import sys
import os
import shutil
import subprocess
import shutil
import time
import multiprocessing
import re
from turtle import width

num_processes = 48
program_name = sys.argv[1]
num_test_case = 0
num_of_run = 0
num_of_evaluate = 0

def init():
    if not os.path.exists(f"../output/{program_name}"):
        os.makedirs(f"../output/{program_name}")
    if not os.path.exists(f"../score/{program_name}"):
        os.makedirs(f"../score/{program_name}")

    subprocess.run("g++ -O3 -std=c++17 -I $HOME/Work/procon/lib/ac-library -DONLINE_JUDGE ../src/{0}.cpp -o ../src/{0}".format(program_name), shell=True, check=True)
    return

def get_txt_list():
    files = os.listdir("in/")
    txt_files = [f for f in files if f.endswith(".txt")]
    txt_files.sort()
    return txt_files

def run_test_case(file_name):
    run_time = 0.0
    with open("in/" + file_name, "r") as f_in:
        with open(f"../output/{program_name}/" + file_name, "w") as f_out:
            start_time=time.perf_counter()
            subprocess.run([f"../src/{program_name}"], stdin=f_in, stdout=f_out)
            end_time=time.perf_counter()
            run_time=end_time-start_time
    print(file_name)
    return    

def evaluate_all(txt_files):
    for file_name in txt_files:

        output_dir = f"../score/{program_name}/"
        if not os.path.exists(output_dir):
            os.makedirs(output_dir)
        output_file = output_dir + file_name

        #公式配布のRustを実行&結果の書き込み
        with open(output_file, "w") as f_out:
            subprocess.run(["cargo", "run", "--release", "--bin", "vis", "in/" + file_name, f"../output/{program_name}/" + file_name], stdout=f_out)

        #ビジュアライズ結果をコピーして移動する処理
        # if os.path.exists("vis.html"):
        #     shutil.copy("vis.html","result/visualizer/vis"+file_name+".html")

def evaluate_test_case(file_name):

    output_dir = f"../score/{program_name}/"
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    output_file = output_dir + file_name

    #公式配布のRustを実行&結果の書き込み
    res = subprocess.run(["cargo", "run", "--release", "--bin", "vis", "in/" + file_name, f"../output/{program_name}/" + file_name], capture_output=True)
    with open(output_file, "w") as f_out:
        f_out.write(res.stdout.decode())

    #ビジュアライズ結果をコピーして移動する処理
    # if os.path.exists("vis.html"):
    #     shutil.copy("vis.html","result/visualizer/vis"+file_name+".html")

    print(file_name)

def show_scores(txt_files):
    output_file_name = f"compare_scores/{program_name}.txt"
    if(os.path.isfile(output_file_name)):
        os.remove(output_file_name)
    for file_name in txt_files:
        with open(f"../score/{program_name}/{file_name}", 'r') as f:
            test_case = file_name.split(".")[0]
            score = (re.split("[ \n]", f.readline()))[2]
            print(test_case, score)
            with open(output_file_name, "a") as f:
                print(test_case, score, file = f)

def main():
    start_time=time.perf_counter()
    filename = "../score/{}.txt".format(program_name)
    print(program_name)

    init()
    txt_files = get_txt_list()
    num_test_case = len(txt_files)

    print("--START RUN--")
    with multiprocessing.Pool(processes = num_processes)as p:
        p.map(run_test_case, txt_files)

    print("\n--START EVALUATION--")
    with multiprocessing.Pool(processes = num_processes)as p:
        p.map(evaluate_test_case, txt_files)

    show_scores(txt_files)
    end_time=time.perf_counter()
    print(f"elapsed time: {end_time - start_time}")

    return


if __name__ == "__main__":
    main()