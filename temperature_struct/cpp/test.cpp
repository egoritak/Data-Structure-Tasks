void TemperatureTest()
{
    const int N = 20;
    std::vector<int> temps(N);
 
    srand(time(0));
    for (auto& i_ : temps)
        i_ = rand() % 25 + 15; //from 15 to 40 degrees;
 
    for (auto i_ : temps)
    std::cout << i_ << "\n";
 
    TemperatureEx first_(temps.size() / 2);
 
    for (auto i_ : temps)
    {
        first_.push(i_);
    }
 
    std::cout << "max val = " << first_.max() << "\n";
    std::cout << "min val = " << first_.min() << "\n";
    std::cout << "size = " << first_.size() << "\n";
}

