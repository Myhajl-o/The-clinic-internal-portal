#pragma once
#include "MedicalServices.hpp"
#include "Date.hpp"
#include <iostream>
#include <string>
#include <memory>
using namespace std;
class History{
    private:
    string patient;
    unique_ptr<Date>date;
    unique_ptr<MedicalServices>service; 
    public:
    History(string pat, int y, int m, int d, int h, int mi,
        unique_ptr<MedicalServices> s) : 
        patient(pat){
        date = make_unique<Date>(y, m, d, h, mi);
        service = move(s); 
    }
    string getPatient(){
        return patient;
    }
    void printHistory(){
        cout<<"Час та дата проведення послуги"<<endl;
        cout<<date->getHour()<<" : "<<date->getMinute()<<"   "<<
        date->getDay()<<"/"<<date->getMonth()<<"/"<<date->getYear()<<endl<<endl;
        cout<<"Паціент:                   "<<getPatient()<<" ;"<<endl;
        service->printService();
    }
    double getProfit(){
        return service->getPrice();
    }

    int getYear(){
        return date->getYear();
    }
    int getMonth(){
        return date->getMonth();
    }
    int getDay(){
        return date->getDay();
    }
    int getHour(){
        return date->getHour();
    }
    int getMinute(){
        return date->getMinute();
    }
};
