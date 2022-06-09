#include <vector>
#include <queue>
#include <cassert>

std::vector<int> netPackages(int buff_size, std::vector<std::pair<int, int>> v)
{
    if (v.empty())
        return {};

    int time_ = v[0].first;
    std::queue<std::pair<int, int>> buff;
    std::queue<int> ids;
    std::queue<int> buff_arrive;
    std::vector<int> times_answer(v.size());

    for (int i = 0; i < buff_size; i++)
    {
        buff.push(v[i]);
        ids.push(i);
        buff_arrive.push(v[i].first);
    }

    buff.front().first = time_;

    for (int i = buff_size; i < v.size(); i++)
    {
        time_ += buff.front().second;

        times_answer[ids.front()] = buff.front().first;

        if (buff.front().first > time_)
            time_ = buff_arrive.front() + buff.front().second;

        buff.pop();
        ids.pop();
        buff_arrive.pop();

        if (!buff.empty())
        {
            if (buff.front().first > time_)
                time_ = buff.front().first;
            else
                buff.front().first = time_;
        }

        for (int j = i; j < v.size(); j++)
        {
            if (v[j].first < time_)
            {
                times_answer[j] = -1;
                i = j + 1;
            }
            else
            {
                if (!buff.empty())
                {
                    if (time_ < buff_arrive.front())
                    {
                        buff.front().second -= buff_arrive.front() - time_;
                        if (buff.front().second < 0)
                            buff.front().second = 0;
                    }
                    time_ = buff.front().first;
                }
                else
                    if (time_ < v[j].first)
                        time_ = v[j].first;

                buff.push(v[j]);
                ids.push(j);
                buff_arrive.push(v[j].first);

                break;
            }
        }

    }

    while (!buff.empty())
    {
        if (buff_arrive.front() > time_)
            time_ = buff_arrive.front();

        if (buff.front().first < time_)
            times_answer[ids.front()] = buff_arrive.front();
        else
            times_answer[ids.front()] = buff.front().first;

        time_ += buff.front().second;

        buff.pop();
        ids.pop();
        buff_arrive.pop();

        if (!buff.empty())
            buff.front().first = time_;
    }

    return times_answer;
}

void NetPackagesTest()
{
    std::vector<int> answer = { 0, 0, 0, 1, 1, 1, 2, -1 };

    assert(netPackages(2, { {0, 0}, {0, 0},
                                {0, 0}, {1, 0},
                                {1, 0}, {1, 1},
                                {1, 2}, {1, 3} }) == answer);

    answer = { 0 };
    assert(netPackages(1, { {0, 0} }) == answer);

    answer = {};
    assert(netPackages(1, { }) == answer);

    answer = { 2, 9, 125, 141, 160, 189, 244, 334, 999, 1149 };
    assert(netPackages(5, { {2, 4}, {9, 21}, {125, 16},
                                {126, 19}, {126, 29},
                                {126, 55},
                                {141, 90}, {141, 0},
                                {999, 150}, {999, 0} }) == answer);

    answer = { 0, -1, 5, -1, 12 };
    assert(netPackages(1, { {0, 5}, {0, 1},
                                {5, 7}, {6, 8},
                                {12, 3} }) == answer);

    answer = { 0, 0, 0, 1, 2, -1, -1, -1 };
    assert(netPackages(2, { {0, 0}, {0, 0},
                                {0, 0}, {1, 1},
                                {1, 0}, {1, 0},
                                {1, 2}, {1, 3} }) == answer);

    answer = { 999999, 1000000, 1000000, -1, -1 };
    assert(netPackages(1, { {999999, 1}, {1000000, 0},
                                {1000000, 1}, {1000000, 0},
                                {1000000, 0} }) == answer);

    answer = { 0, 7, 7, -1, -1, -1 };
    assert(netPackages(3, { {0, 7}, {0, 0},
                                {2, 0}, {3, 3},
                                {4, 0}, {5, 0} }) == answer);

    answer = { 2, 11, -1, 19, 21 };
    assert(netPackages(2, { {2, 9}, {4, 8},
                                {10, 9}, {15, 2},
                                {19, 1} }) == answer);

    answer = { 0, 2, 2, 3, 4, 5 };
    assert(netPackages(2, { {0, 2}, {0, 0},
                                {2, 0}, {3, 0},
                                {4, 0}, {5, 0} }) == answer);
}
