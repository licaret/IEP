#include <iostream>

class Clock
{
    // default destructor
private:
    int hour;
    int minute;
    int second;
    Clock(const Clock&); // copy constructor disabled
    Clock& operator=(const Clock&); // copy assignment disabled

public:
    Clock(int hour, int minute, int second) // initialize all fields
        : hour(hour % 24),
          minute(minute % 60),
          second(second % 60)
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
    Clock clock1(157, 0, 0);
    // Clock clock2(clock1); // cannot create instance based on clock1 (copy constructor is disabled)
    Clock clock3(14, 0, 0);

    // clock3 = clock1; // copy assignment is disabled

    std::cout << clock1.getHour() << ":" << clock1.getMinute() << ":" << clock1.getSecond() << '\n';

    return 0;
}