/*
Допустим, Вам нужно написать приложение, которое периодически получает значение 
температуры за окном, хранит не более N последних замеров в оперативной памяти и 
показывает пользователю минимальное и максимальное значения среди этих N. 
 
Какую структуру данных Вы бы организовали/использовали для решения этой задачи?
*/
 
class TemperatureEx
{
private:
    std::multiset<int> st_;
    std::queue<std::set<int>::iterator> q_;
    int size_ = 0;
 
    void pop_back()
    {
        auto it = q_.front();
        q_.pop();
        st_.erase(it);    
    }
public:
 
    TemperatureEx(int size) : size_ {size}
    {
    }
 
    int max()
    {
        return *(--st_.end());
    }
 
    int min()
    {
        return *st_.begin();
    }
 
    int size()
    {
        return st_.size();
    }
 
    void push(const int val)
    {
        if (q_.size() == size_)
            pop_back();
 
        auto it = st_.insert(val);
        q_.push(it);
    }
};
