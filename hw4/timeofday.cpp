#include "timeofday.h"
#include <iostream>
using std::cout;
using std::endl;

TimeOfDay::TimeOfDay(int h, int m, int s) {
    // Initialize data members with default values
    hour = 0;
    minute = 0;
    second = 0;

    // Set data members if arguments are valid
    SetHour(h);
    SetMinute(m);
    SetSecond(s);
}

void TimeOfDay::SetHour(int h) {
    // Set hour if it is valid (0-23)
    if (h >= 0 && h <= 23)
        hour = h;
}

void TimeOfDay::SetMinute(int m) {
    // Set minute if it is valid (0-59)
    if (m >= 0 && m <= 59)
        minute = m;
}

void TimeOfDay::SetSecond(int s) {
    // Set second if it is valid (0-59)
    if (s >= 0 && s <= 59)
        second = s;
}

int TimeOfDay::GetHour() const {
    return hour;
}

int TimeOfDay::GetMinute() const {
    return minute;
}

int TimeOfDay::GetSecond() const {
    return second;
}

void TimeOfDay::Print(bool militaryTime, bool displaySeconds) const {
    // Output time based on format parameters
    if (militaryTime) {
        cout << (hour < 10 ? "0" : "") << hour << ":" << (minute < 10 ? "0" : "") << minute;
        if (displaySeconds) {
            cout << ":" << (second < 10 ? "0" : "") << second;
        }
    } else {
        int displayHour = (hour % 12 == 0) ? 12 : hour % 12;
        cout << (displayHour < 10 ? "0" : "") << displayHour << ":" << (minute < 10 ? "0" : "") << minute;
        if (displaySeconds) {
            cout << ":" << (second < 10 ? "0" : "") << second;
        }
        cout << (hour < 12 ? " a.m." : " p.m.");
    }

    cout << endl;
}