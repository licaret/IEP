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
    int getHour() {
        return hour;
    }
    int getMinute() {
        return minute;
    }
    int getSecond() {
        return second;
    }
};

int main()
{
    Clock clock1(12, 0, 0);
    // Clock clock2(clock1); // cannot create instance based on clock1 (copy constructor is disabled)
    Clock clock3(14, 0, 0);

    // clock3 = clock1; // copy assignment is disabled

    std::cout << clock1.getHour() << ":" << clock1.getMinute() << ":" << clock1.getSecond();

    return 0;
}