#include "../random/xorshift.hpp"

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

auto system_now = std::chrono::system_clock::now();
int checktime() {
	auto now = std::chrono::system_clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(now - system_now).count();
}

inline double get_temp(double start_temp, double end_temp, int elapsed_time, int total_time) {
    return end_temp + (start_temp - end_temp) * elapsed_time / total_time;
};

int main(){
    int start_time = checktime();
    int end_time = 1990;
    int total_time = end_time - start_time;
    double start_temp = 1e6;
    double end_temp = 1e1;
    const int inf_guard = 1000; // exp が発散するのを防ぐ
    ll cnt = 0;

    // 最小化の場合
    while(true){
        int now_time = checktime();
        if(now_time > end_time) break;
        int elapsed_time = now_time - start_time;
        int delta = 10;
        double temp = get_temp(start_temp, end_temp, elapsed_time, total_time);
        double probability = 0;
        if(delta > temp * inf_guard) probability = 0;
        else probability = std::exp(- delta / temp);
        double random_val = rand_double();

        if(delta <= 0 or (delta > 0 and random_val < probability)){
            cout << "update\n";
        }else{
            cout << "stay\n";
        }

        cnt++;
    }
    cerr << cnt << "\n";
    return 0;
}