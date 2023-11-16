#include "timeinterval.h"
#include <iostream>
using std::cout;
using std::endl;

TimeInterval::TimeInterval() : startTime(0, 0, 0), endTime(0, 0, 0) {}

TimeInterval::TimeInterval(const TimeOfDay& start, const TimeOfDay& end) : startTime(start), endTime(end) {
    // Ensure the end time is not earlier than the start time
    if (end.GetHour() < start.GetHour() ||
        (end.GetHour() == start.GetHour() && end.GetMinute() < start.GetMinute()) ||
        (end.GetHour() == start.GetHour() && end.GetMinute() == start.GetMinute() && end.GetSecond() < start.GetSecond())) {
        endTime = start;
    }
}

TimeInterval::TimeInterval(const TimeOfDay& start, int length, const std::string& units) : startTime(start), endTime(start) {
    // Convert length to seconds
    int seconds;
    if (units == "hours") {
        seconds = length * 3600;
    } else if (units == "minutes") {
        seconds = length * 60;
    } else if (units == "seconds") {
        seconds = length;
    } else {
        // Invalid units, set end time to start time
        endTime = start;
        return;
    }

    // Calculate end time
    int endSeconds = start.GetHour() * 3600 + start.GetMinute() * 60 + start.GetSecond() + seconds;

    // Ensure end time is within the same day
    if (endSeconds < 86400) {
        endTime.SetHour(endSeconds / 3600);
        endTime.SetMinute((endSeconds % 3600) / 60);
        endTime.SetSecond(endSeconds % 60);
    } else {
        // Invalid length, set end time to start time
        endTime = start;
    }
}

TimeOfDay TimeInterval::GetStartTime() const {
    return startTime;
}

TimeOfDay TimeInterval::GetEndTime() const {
    return endTime;
}

void TimeInterval::SetStartTime(const TimeOfDay& start) {
    // Update start time if it is not later than the current end time
    if (!(start.GetHour() > endTime.GetHour() ||
          (start.GetHour() == endTime.GetHour() && start.GetMinute() > endTime.GetMinute()) ||
          (start.GetHour() == endTime.GetHour() && start.GetMinute() == endTime.GetMinute() && start.GetSecond() > endTime.GetSecond()))) {
        startTime = start;
    }
}

void TimeInterval::SetEndTime(const TimeOfDay& end) {
    // Update end time if it is not earlier than the current start time
    if (!(end.GetHour() < startTime.GetHour() ||
          (end.GetHour() == startTime.GetHour() && end.GetMinute() < startTime.GetMinute()) ||
          (end.GetHour() == startTime.GetHour() && end.GetMinute() == startTime.GetMinute() && end.GetSecond() < startTime.GetSecond()))) {
        endTime = end;
    }
}
void TimeInterval::SetEndTime(int length, const std::string& units) {
     if (units == "feet") {
        // Handle invalid unit "feet"
        return;
    }
    if (length < 0) {
        // Handle negative time lengths
        length = -length;
        if (units == "hours") {
            length *= 3600;
        } else if (units == "minutes") {
            length *= 60;
        } else if (units == "seconds") {
            // Convert length to seconds
            // Calculate the total time in seconds from the start time
            int startSeconds = startTime.GetHour() * 3600 + startTime.GetMinute() * 60 + startTime.GetSecond();
            // Calculate the end time in seconds
            int endSeconds = startSeconds - length;

            // Ensure end time is within the same day
            if (endSeconds >= 0) {
                endTime.SetHour(endSeconds / 3600);
                endTime.SetMinute((endSeconds % 3600) / 60);
                endTime.SetSecond(endSeconds % 60);
            } else {
                // Invalid length, set end time to start time
                endTime = startTime;
            }
            return;
        } else {
            // Invalid units, do not modify end time
            return;
        }
    } else {
        // Handle positive time lengths
        TimeInterval temp(startTime, length, units);
        endTime = temp.GetEndTime();
    }
}
void TimeInterval::Print(bool militaryTime, bool displaySeconds) const {
    cout << "Start time: ";
    startTime.Print(militaryTime, displaySeconds);
    cout << "End time: ";
    endTime.Print(militaryTime, displaySeconds);
}
