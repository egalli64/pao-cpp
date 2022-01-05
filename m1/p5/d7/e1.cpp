#include <iostream>
using namespace std;

enum class Day { MON, TUE, WED, THU, FRI, SAT, SUN, SZ = 7 };

ostream& operator<<(ostream& os, const Day& day) {
    os << static_cast<int>(day);
    return os;
}

// prefix ++
Day& operator++(Day& day) {
    day = static_cast<Day>((static_cast<int>(day) + 1) % (static_cast<int>(Day::SZ)));
    return day;
}

// postfix ++
Day operator++(Day& day, int) {
    Day cur = day;
    day = static_cast<Day>((static_cast<int>(day) + 1) % (static_cast<int>(Day::SZ)));
    return cur;
}

// prefix --
Day& operator--(Day& day) {
    day = (day == Day::MON) ? Day::SUN : static_cast<Day>((static_cast<int>(day) - 1));
    return day;
}

// postfix --
Day operator--(Day& day, int) {
    Day cur = day;
    day = (day == Day::MON) ? Day::SUN : static_cast<Day>((static_cast<int>(day) - 1));
    return cur;
}

int main()
{
    Day cur{ Day::MON };

    cout << "Current day is " << cur << endl;
    cout << "Pre-decrement of current day " << --cur << endl;
    cout << "Pre-increment of current day " << ++cur << endl;
    cout << "Post-increment of current day " << cur++ << endl;
    cout << "Current day is " << cur << endl;
    cout << "Post-decrement of current day " << cur-- << endl;
    cout << "Post-decrement of current day " << cur-- << endl;
    cout << "Current day is " << cur << endl;
}
