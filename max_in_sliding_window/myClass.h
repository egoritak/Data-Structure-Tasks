#include <deque>

struct myClass {
    std::deque<std::pair<int, int>> d;
    int l, r;

    myClass() {
        l = r = 0;
    }

    void insert(int x) {
        while (!d.empty() && d.back().first <= x)
            d.pop_back();
        d.emplace_back(x, r);
        ++r;
    }

    void pop_front() {
        if (d.front().second == l)
            d.pop_front();
        ++l;
    }

    int extract_max() {
        return d.front().first;
    }
};
