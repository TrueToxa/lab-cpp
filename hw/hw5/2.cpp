#include <iostream>
#include <string>

struct Time {
    int hours = 0, minutes = 0, seconds = 0;
};

Time time_add(Time start, Time interval) {
    Time ans;
    ans.seconds = (start.seconds + interval.seconds)%60;
    ans.minutes = (start.minutes + interval.minutes + (start.seconds+interval.seconds)/60)%60;
    ans.hours = (start.hours + interval.hours + ((start.minutes + interval.minutes + (start.seconds+interval.seconds)/60)/60))%24;
    return ans;
}