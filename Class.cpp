#include <iostream>

class Clock
{
    // default destructor
private:
    int hour;
    int minute;
    int second;
    Clock(const Clock&); // copy constructor disabled

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

    Clock& operator=(const Clock& clock)
    {
        if (this == &clock) // Identity test
        {
            std::cout << "\nWarning: Self-assignment attempted!\n\a";
            return *this;
        }

        // Override every attribute
        hour = clock.hour;
        minute = clock.minute;
        second = clock.second;

        // Return reference to this
        return *this;
    }
};

int main()
{
    Clock clock1(157, 0, 0);
    // Clock clock2(clock1); // cannot create instance based on clock1 (copy constructor is disabled)
    Clock clock3(14, 0, 0);

    std::cout << clock1.getHour() << ":" << clock1.getMinute() << ":" << clock1.getSecond() << '\n';

    return 0;
}