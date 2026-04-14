#pragma once
class Date{
    private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    public:
    Date(int y,int m,int d,int h,int mi):year(y),
        month(m),day(d),hour(h),minute(mi){}

    int getYear(){
        return year;
    }
    int getMonth(){
        return month;
    }
    int getDay(){
        return day;
    }
    int getHour(){
        return hour;
    }
    int getMinute(){
        return minute;
    }
};