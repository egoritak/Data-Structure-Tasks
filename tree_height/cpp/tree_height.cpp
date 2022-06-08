#include <vector>
#include <unordered_map>
#include <cassert>

int treeHeight(std::vector<int> r)
{
    std::unordered_map<int, std::vector<int>> spis_smezh;

    for (int i = 0; i < r.size(); i++)
    {
        spis_smezh[r[i]].push_back(i);
    }

    std::vector<int> root = spis_smezh[-1];
    int step = 0;

    while (root.size())
    {
        std::vector<int> temp = root;
        root = {};
        for (int val : temp)
            for (int i : spis_smezh[val])
                root.push_back(i);
        step++;
    }

    return step;
}

void TreeHeightTest()
{
    assert(treeHeight({ 4, -1, 4, 1, 1 }) == 3);
    assert(treeHeight({ -1, 0, 4, 0, 3 }) == 4);
    assert(treeHeight({ 9, 7, 5, 5, 2, 9, 9, 9, 2, -1 }) == 4);
}