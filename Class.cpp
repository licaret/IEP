#include <iostream>

class Clock
{
private:
    int hour;
    int minute;
    int second;
    Clock(const Clock&);
    Clock& operator=(const Clock&);

public:
    Clock(int hour, int minute, int second)
        : hour(hour),
          minute(minute),
          second(second)
    {}
};

int main()
{

    return 0;
}