// Define a TimeInterval class that has two TimeOfDay objects as private
// data members: one for the start time of the interval and one for the
// end time of the interval.
// Note: this class is only for time intervals where the start and end times
//       are contained within the confines of a single day
// The class should ensure that the value of the end TimeOfDay data member
// is not earlier in the day than the value of the start TimeOfDay data
// member.


// Add a default constructor that initializes the start time of day
// and end time of day to midnight (0 hour, 0 minute, 0 second)


// Add a constructor that takes two arguments:
//   a const TimeOfDay& for the beginning of the time interval and
//   a const TimeOfDay& for the end of the time interval
// If the values of the TimeOfDay arguments are out of order (if the value
// of the first TimeOfDay argument is later in the day than the value of the
// second TimeOfDay argument) then set both the start and end TimeOfDay
// data members to the first argument.


// Add a constructor that takes three arguments:
//  - a const TimeOfDay& for the the start time of day of the interval
//  - an integer for the length of the interval
//  - a string for the units of the length provided (must be either "seconds",
//    "minutes", or "hours")
// The constructor should set the start TimeOfDay data member to the value
// of the first argument.
// If the length and units can be used to create a valid TimeInterval, the
// constructor should set then end TimeOfDay data member to the value that
// corresponds to the end of the interval.
// If the length and units cannot be used to create a valid TimeInterval,
// the constructor should set the end TimeOfDay data member to the value
// of the start TimeOfDay data member.


// Add accessor functions to return the start and end data members


// Add a SetStartTime member function that takes a const TimeOfDay& as an
// argument.
// The function should update the start TimeOfDay data member if the value
// of the argument is not later in the day than the current value of the end
// TimeOfDay data member.
// If the value of the argument is later in the day than the current value
// of the end TimeOfDay data member, the function should leave the start
// TimeOfDay data member unchanged.


// Add a SetEndTime member function that takes a const TimeOfDay& as an
// argument.
// The function should update the end TimeOfDay data member if the value
// of the argument is not earlier in the day than the current value of the
// start TimeOfDay data member.
// If the value of the argument is earlier in the day than the current value
// of the start TimeOfDay data member, the function should leave the end
// TimeOfDay data member unchanged.


// Add a SetEndTime member function that takes an integer for the length of
// the interval and a string for the units of the length (must be either
// "hours", "minutes", or "seconds") as its two arguments.
// The function should update the end TimeOfDay data member if the values
// of the arguments can be used to create a valid interval.
// If the values of the arguments cannot be used to create a valid interval,
// the function should leave the end TimeOfDay data member unchanged.
// Examples:
//  - if the current start time of day is 10:59:00,
//    then x.SetEndTime(30, "seconds") should set the end time to 10:59:30
//  - if the current start time of day is 10:59:00
//    then x.SetEndTime(14, "minutes") should set the end time to 11:13:00
//  - if the current start time of day is 10:59:00
//    then x.SetEndTime(90, "minutes") should set the end time to 12:29:00
//  - if the current start time of day is 10:59:00
//    then x.SetEndTime(18, "hours") should leave the current end time
//    unchanged since 18 hours after 10:59:00 would be after the end of
//    the current day (the time interval must be contained in a single day)


// Add a Print function that prints the data members to the standard
// output device. The format of the output should be:
// "Start time: " followed by the start TimeOfDay on one line,
// and "End time: " followed by the end TimeOfDay on the next line.
// The function's first argument should be a bool, defaulting to false,
// that specifies whether or not the times should display in military time.
// The function's second argument should be a bool, defaulting to false,
// that specifies whether or not to display the seconds component of the
// TimeOfDay data members.

// timeinterval.h
#ifndef TIMEINTERVAL_H
#define TIMEINTERVAL_H
#include <string>
#include "timeofday.h"

class TimeInterval {
private:
    TimeOfDay startTime;
    TimeOfDay endTime;

public:
    // Default constructor
    TimeInterval();

    // Constructor with two TimeOfDay arguments
    TimeInterval(const TimeOfDay& start, const TimeOfDay& end);

    // Constructor with TimeOfDay, length, and units arguments
    TimeInterval(const TimeOfDay& start, int length, const std::string& units);

    // Accessor functions
    TimeOfDay GetStartTime() const;
    TimeOfDay GetEndTime() const;

    // Mutator functions
    void SetStartTime(const TimeOfDay& start);
    void SetEndTime(const TimeOfDay& end);
    void SetEndTime(int length, const std::string& units);

    // Print function
    void Print(bool militaryTime = false, bool displaySeconds = false) const;
};

#endif // TIMEINTERVAL_H


