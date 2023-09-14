#pragma once
#include <cassert>
#include <vector>

// [0, n) の集合を管理するデータ構造．
// 値の追加・削除・存在確認 が時間 O(1)，空間O(n)でできる
// https://topcoder-tomerun.hatenablog.jp/entry/2021/06/12/134643
// hari さんの実装に倣っている
// https://github.com/hari64boli64/MarathonTemplate/blob/main/src/cpp/main.cpp

template <int sz>
struct IndexSet {
    vector<int> vec;
    IndexSet() {
        for (int i = 0; i < sz; i++) _pos[i] = -1;
    }
    void insert(int v) {
        assert(0 <= v && v < sz);
        if (contains(v)) return;
        _pos[v] = vec.size();
        vec.push_back(v);
    }
    void remove(int v) {
        assert(contains(v));
        int p = _pos[v], b = vec.back();
        vec[p] = b;
        vec.pop_back();
        _pos[b] = p;
        _pos[v] = -1;
    }
    int random_pop() {
        assert(!vec.empty());
        int v = myrand.choice(vec);
        remove(v);
        return v;
    }
    bool contains(int v) const {
        return _pos[v] != -1;
    }
    bool empty() const {
        return vec.empty();
    }
    size_t size() const {
        return vec.size();
    }
    friend ostream& operator<<(ostream& os, const IndexSet& is) {
        vector<int> v = is.vec;
        sort(v.begin(), v.end());
        for (auto& e : v) os << e << " ";
        return os << endl;
    }

   private:
    int _pos[sz];
};