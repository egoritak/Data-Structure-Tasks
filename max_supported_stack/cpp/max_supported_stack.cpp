#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstring>
#include <cassert>

template <typename T>
class Stack
{
public:
    Stack() : data_{ nullptr }, size_{ 0 }, capacity_{ 0 }
    {
    }

    Stack(const Stack& other)
    {
        size_ = other.size();
        capacity_ = other.capacity();
        data_ = new T[capacity_];
        std::copy(other.data(), other.data() + size_, data_);
    }

    const Stack& operator=(const Stack& other)
    {
        if (data_ == other.data())
            return *this;

        delete[] data_;
        size_ = other.size();
        capacity_ = other.capacity();
        data_ = new T[capacity_];
        std::copy(other.data(), other.data() + size_, data_);

        return *this;
    }

    ~Stack()
    {
        delete[] data_;
    }

    bool isFull() const
    {
        return size_ == capacity_;
    }

    const T* data() const
    {
        return data_;
    }

    T& top()
    {
        if (size_ == 0)
            std::runtime_error("stack is empty");

        return data_[size_ - 1];
    }

    bool empty() const
    {
        return size_ == 0;
    }

    size_t size() const
    {
        return size_;
    }

    size_t capacity() const
    {
        return capacity_;
    }

    void push(T val)
    {
        if (isFull())
        {
            int COEFF = 2;
            if (capacity_ == 0)
                capacity_ = 1;
            else
                capacity_ *= COEFF;

            T* temp = new T[capacity_];

            for (int i = 0; i < size_; i++)
                temp[i] = data_[i];

            delete[] data_;

            data_ = temp;
        }

        data_[size_++] = val;
    }

    T pop()
    {
        if (empty())
        {
            std::runtime_error("popping empty stack");
        }

        return data_[--size_];
    }

private:
    T* data_;
    size_t size_;
    size_t capacity_;
};

template <typename Out>
void split(const std::string& s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

std::string StackTask(std::vector<std::string> s)
{
    Stack<std::pair<int, int>> st;
    std::string result = "";
    for (int i = 0; i < s.size(); i++)
    {
        std::vector<std::string> x = split(s[i], ' ');

        if (x[0] == "push")
        {
            int new_element = std::stoi(x[1]);
            int minima = st.empty() ? new_element : std::max(new_element, st.top().second);
            st.push(std::make_pair(new_element, minima));
        }
        else if (x[0] == "pop")
            st.pop();
        else
        {
            int temp = st.top().second;
            result += std::to_string(temp) + " ";
        }

    }

    return result;
}

void MaxSupportStackTest()
{
    std::string answer = "3 7 ";
    assert(StackTask({
        "push 5", "pop", "push 3",
        "max", "push 9", "pop",
        "push 7", "max" }) == answer);

    answer = "2 2 ";
    assert(StackTask({
        "push 2", "push 1", "max",
        "pop", "max" }) == answer);

    answer = "2 1 ";
    assert(StackTask({
        "push 1", "push 2", "max",
        "pop", "max" }) == answer);

    answer = "9 9 9 9 ";
    assert(StackTask({
        "push 2", "push 3", "push 9",
        "push 7", "push 2", "max",
        "max", "max", "pop", "max" }) == answer);

}
