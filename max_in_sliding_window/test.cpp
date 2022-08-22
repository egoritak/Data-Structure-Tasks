#include <cassert>
#include <vector>

#include "myClass.h"

std::vector<std::pair<std::pair<std::vector<int>, int>, std::vector<int>>>
    testcases = {
        {{{2, 7, 3, 1, 5, 2, 6, 2}, 4}, {7, 7, 5, 6, 6}},
        {{{2, 1, 5}, 1}, {2, 1, 5}},
        {{{73, 65, 24, 14, 44, 20, 65, 97, 27, 6, 42, 1, 6, 41, 16}, 7},
         {73, 97, 97, 97, 97, 97, 97, 97, 42}},
        {{{28, 7, 64, 40, 68, 86, 80, 93, 4, 53, 32, 56, 68, 18, 59}, 12},
         {93, 93, 93, 93}},
        {{{16, 79, 20, 19, 43, 72, 78, 33, 40, 52, 70, 79, 66, 43, 60}, 12},
         {79, 79, 79, 79}},
        {{{34, 51, 61, 90, 26, 84, 2, 25, 7, 8, 25, 78, 21, 47, 25}, 3},
         {61, 90, 90, 90, 84, 84, 25, 25, 25, 78, 78, 78, 47}},
        {{{27, 83, 29, 77, 6, 3, 48, 2, 16, 72, 46, 38, 55, 2, 58}, 5},
         {83, 83, 77, 77, 48, 72, 72, 72, 72, 72, 58}}

};

std::vector<int> calc(std::vector<int> nums, int k) {
    std::vector<int> ans;
    myClass res;
    for (int i = 0; i < k; ++i)
        res.insert(nums[i]);

    for (int i = k; i < nums.size(); ++i) {
        ans.push_back(res.extract_max());

        res.pop_front();

        res.insert(nums[i]);
    }
    ans.push_back(res.extract_max());

    return ans;
}

void TEST() {
    std::vector<int> nums;
    std::vector<int> ans;
    int k;

    for (auto case_ : testcases) {
        nums = case_.first.first;
        k = case_.first.second;
        ans = case_.second;
        assert(calc(nums, k) == ans);
    }
}
