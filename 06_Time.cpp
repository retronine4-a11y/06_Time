#include <iostream>
#include <iomanip>
using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

    int toSeconds() const
    {
        return hours * 3600 + minutes * 60 + seconds;
    }

public:
    Time()
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    Time(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }

    explicit Time(int s)
    {
        hours = s / 3600;
        minutes = s / 60 % 60;
        seconds = s % 60;
    }

    void Show() const
    {
        cout << setfill('0')
            << setw(2) << hours << ":"
            << setw(2) << minutes << ":"
            << setw(2) << seconds << endl;
    }

    Time& operator++()
    {
        seconds++;

        if (seconds >= 60)
        {
            seconds = 0;
            minutes++;
        }

        if (minutes >= 60)
        {
            minutes = 0;
            hours++;
        }

        return *this;
    }

    Time operator+(const Time& t) const
    {
        return Time(toSeconds() + t.toSeconds());
    }

    Time operator-(const Time& t) const
    {
        int result = toSeconds() - t.toSeconds();

        if (result < 0)
            result = 0;

        return Time(result);
    }

    Time operator*(const Time& t) const
    {
        return Time(toSeconds() * t.toSeconds());
    }

    Time operator/(const Time& t) const
    {
        if (t.toSeconds() == 0)
            return Time();

        return Time(toSeconds() / t.toSeconds());
    }

    bool operator>(const Time& t) const
    {
        return toSeconds() > t.toSeconds();
    }

    bool operator<(const Time& t) const
    {
        return toSeconds() < t.toSeconds();
    }

    bool operator>=(const Time& t) const
    {
        return toSeconds() >= t.toSeconds();
    }

    bool operator<=(const Time& t) const
    {
        return toSeconds() <= t.toSeconds();
    }

    bool operator==(const Time& t) const
    {
        return toSeconds() == t.toSeconds();
    }

    bool operator!=(const Time& t) const
    {
        return toSeconds() != t.toSeconds();
    }
};

int main()
{
    Time t1;
    Time t2(11, 59, 59);
    Time t3(5555);
    Time t4(1, 30, 0);

    cout << "Default time: ";
    t1.Show();

    cout << "Time t2: ";
    t2.Show();

    cout << "5555 seconds: ";
    t3.Show();

    cout << "\nt2 + t4: ";
    (t2 + t4).Show();

    cout << "t2 - t4: ";
    (t2 - t4).Show();

    cout << "t2 * t4: ";
    (t2 * t4).Show();

    cout << "t2 / t4: ";
    (t2 / t4).Show();

    cout << "\nIncrement t2: ";
    ++t2;
    t2.Show();

    cout << "\nComparisons:" << endl;
    cout << boolalpha;
    cout << "t2 > t4: " << (t2 > t4) << endl;
    cout << "t2 < t4: " << (t2 < t4) << endl;
    cout << "t2 >= t4: " << (t2 >= t4) << endl;
    cout << "t2 <= t4: " << (t2 <= t4) << endl;
    cout << "t2 == t4: " << (t2 == t4) << endl;
    cout << "t2 != t4: " << (t2 != t4) << endl;


}