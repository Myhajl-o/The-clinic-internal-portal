#pragma once
#include "MedicalServices.hpp"
#include "Date.hpp"
#include <string>
#include <memory>
class History{
    private:
    std::string patient;
    std::unique_ptr<Date>date;
    std::unique_ptr<MedicalServices>service; 
    public:
    History(std::string pat, int y, int m, int d, int h, int mi,
        std::unique_ptr<MedicalServices> s) : 
        patient(pat){
        date = std::make_unique<Date>(y, m, d, h, mi);
        service = std::move(s); 
    }
    void printHistory();
    std::string getPatient();
    double getProfit();
    int getYear();
    int getMonth();
    int getDay();
    int getHour();
    int getMinute();
};
