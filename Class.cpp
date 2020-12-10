#include <iostream>
#include <memory>

class Clock
{
    // default destructor
private:
    int hour;
    int minute;
    int second;

public:
    Clock(int hour, int minute, int second) : // initialize all fields
        hour(hour % 24),
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
    auto clock1 = std::make_shared<Clock>(12, 0, 0);
    std::auto_ptr<Clock> clock3(new Clock(14, 0, 0));

    std::cout << "\nThe initial clocks:\n";
    std::cout << "\tClock1 - " << clock1.get()->getHour() << ":" << clock1.get()->getMinute() << ":" << clock1.get()->getSecond() << '\n';
    std::cout << "\tClock3 - " << clock3.get()->getHour() << ":" << clock3.get()->getMinute() << ":" << clock3.get()->getSecond() << '\n';

    auto clock2(clock1);

    std::cout << "\nNumber of references: " << clock1.use_count();

    auto clock4(clock3);

    if (!clock3.get())
    {
        std::cout << "\nclock3 is NULL";
    }

    return 0;
}
