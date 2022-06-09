#include <stack>
#include <unordered_map>
#include <string>
#include <cassert>

std::unordered_map<char, char> brackets = {
                            {')', '('},
                            {']', '['},
                            {'}', '{'}
};

bool isOpened(char i)
{
    return i == '(' || i == '[' || i == '{';
}

bool isClosed(char i)
{
    return i == ')' || i == ']' || i == '}';
}

int check_brackets(std::string s)
{
    std::stack<std::pair<char, int>> myStack;
    int it = 1;
    for (char i : s)
    {
        if (isOpened(i))
            myStack.push({ i, it });
        else if (isClosed(i))
            if (!myStack.empty() && myStack.top().first == brackets[i])
                myStack.pop();
            else
                return it;

        it++;
    }

    if (myStack.size() == 0)
        return 0;
    else
        return myStack.top().second;
}

void BracketsTest()
{
    assert(check_brackets("([](){([])})") == 0);
    assert(check_brackets("()[]}") == 5);
    assert(check_brackets("{{[()]]") == 7);
    assert(check_brackets("{{{[][][]") == 3);
    assert(check_brackets("{*{{}") == 3);
    assert(check_brackets("[[*") == 2);
    assert(check_brackets("{*}") == 0);
    assert(check_brackets("{{") == 2);
    assert(check_brackets("{}") == 0);
    assert(check_brackets("") == 0);
    assert(check_brackets("}") == 1);
    assert(check_brackets("*{}") == 0);
    assert(check_brackets("{{{**[][][]") == 3);
    assert(check_brackets("[]([];") == 3);
}
