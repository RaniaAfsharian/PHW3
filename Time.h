#ifndef TIME_H
#define TIME_H

class Time {
private:
    int hour;
    int minute;

public:
    Time(int h = 0, int m = 0);

    bool operator<(const Time& other) const;
    bool operator==(const Time& other) const;
    int operator-(const Time& other) const; 

    void Show() const; 
};

#endif
