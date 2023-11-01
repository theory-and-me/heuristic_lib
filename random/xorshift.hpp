#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Xorshift {
    uint32_t x = 123456789, y = 362436069, z = 521288629, w = 88675123;

    uint32_t rand_int() {
        uint32_t t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }

    uint32_t rand_int(uint32_t mod) {
        return rand_int() % mod;
    }

    // l以上r以下の整数を乱択
    uint32_t rand_int(uint32_t l, uint32_t r) {
        return l + rand_int(r - l + 1);
    }

    double rand_double() {
        return (double)rand_int() / UINT32_MAX;
    }
};