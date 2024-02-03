#include <iostream>
#include <array>
#include <random>

using std::cout;
using std::endl;
using std::array;
using std::random_device;
using std::uniform_int_distribution;

constexpr size_t STICK_COUNT = 4;

array <short, STICK_COUNT> diceSticks;

void throw_sticks(array <short, STICK_COUNT> &diceSticks);
short assess_sticks(array <short, STICK_COUNT> &diceSticks);

int main(int argc, char *argv[])
{
        throw_sticks(diceSticks);
        short result =  assess_sticks(diceSticks);

        for (size_t i = 0; i < diceSticks.size(); ++i)
        {
                cout << diceSticks[i] << endl;
        }

        cout << result << endl;
}

void throw_sticks(array <short, STICK_COUNT> &diceSticks)
{
        uniform_int_distribution <int> dist(0, 1);
        random_device rd;

        for (size_t i = 0; i < diceSticks.size(); ++i)
                diceSticks[i] = dist(rd);
}

short assess_sticks(array <short, STICK_COUNT> &diceSticks)
{
        short flatCount = 0;

        for (size_t i = 0; i < diceSticks.size(); ++i)
        {
                if (diceSticks[i] == 1)
                        ++flatCount;
        }

        if (flatCount == 1)
                return 1;

        if (flatCount == 2)
                return 2;

        if (flatCount == 3)
                return 3;

        if (flatCount == 0)
                return 6;

        return 0;
}
