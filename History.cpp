#include "History.hpp"
#include <iostream>
#include <string>
using namespace std;

void History::printHistory(){
        cout<<"Час та дата проведення послуги"<<endl;
        cout<<date->getHour()<<" : "<<date->getMinute()<<"   "<<
        date->getDay()<<"/"<<date->getMonth()<<"/"<<date->getYear()<<endl<<endl;
        cout<<"Паціент:                   "<<getPatient()<<" ;"<<endl;
        service->printService();
    }
    string History::getPatient(){
        return patient;
    }
    double History::getProfit(){
        return service->getPrice();
    }
    int History::getYear(){
        return date->getYear();
    }
    int History::getMonth(){
        return date->getMonth();
    }
    int History::getDay(){
        return date->getDay();
    }
    int History::getHour(){
        return date->getHour();
    }
    int History::getMinute(){
        return date->getMinute();
    }