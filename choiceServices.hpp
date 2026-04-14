#pragma once
#include "MedicalServices.hpp"
#include "History.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;
class choiceServices{
    private:
    vector<unique_ptr<MedicalServices>>medic;
    vector<unique_ptr<History>>history;
    double checkNumber(){
        double number;
        cin>>number;
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
            return -1;
        }
        cin.ignore(10000, '\n');
        return number; 
    }
    string newType(){
        while(true){
            cout<<"Введіть тип послуги: ";
            string type;
            getline(cin, type);
            if(type.size()>3&&type.size()<20){
                return type;
            }else{
                cout<<"НЕ корректно введений тип;"<<endl;
            }        
        }
    }
    string newName(){
        while(true){
            cout<<"Введіть назву послуги: ";
            string name;
            getline(cin,name);
            if(name.size()>3&&name.size()<30){
                return name;
            }else{
                cout<<"НЕ корректно введена назва"<<endl;
            }
        }
    }
    string newDiagnosis(){
        while(true){
            cout<<"Введіть обгрунтування процедури (діагноз): ";
            string diagnosis;
            getline(cin, diagnosis);
            if(diagnosis.size()>3&&diagnosis.size()<30){
                return diagnosis;
            }else{
                cout<<"НЕ корректно введений діагноз"<<endl;
            }
        }
    }
    string newDoctor(){
        while(true){
            cout<<"Введіть прізвище та ініціали лікаря: ";
            string doctor;
            getline(cin,doctor);
            if(doctor.size()>3&&doctor.size()<30){
                return doctor;
            }else{
                cout<<"НЕ корректно введено Прізвище та ініціали лікаря"<<endl;
            }
        }
    }
    int newTime(){
        while(true){
            cout<<"Введіть час проведення процедури: ";
            if(int time=checkNumber();time>0&&time<120){
                return time;
            }else{
                cout<<"НЕ корректно введений час"<<endl;
            }
        }
    }
    double newPrice(){
        while(true){
            cout<<"Введіть ціну послуги: ";
            if(double price=checkNumber();price>100&&price<1000000){
                return price;
            }else{
                cout<<"Не корректно введена ціна"<<endl;
            }
        }
    }
    void createService(){
        medic.push_back(make_unique<MedicalServices>(newType(),
        newName(),newDiagnosis(),newDoctor(),newTime(),newPrice()));
        cout<<"Нову послугу успішно створено"<<endl;
        medic[medic.size()-1]->printService();
    }
    void SelectService(){
        for(int i=0;i<medic.size();i++){
            cout<<"\tПОСЛУГА "<<i+1<<endl;
            medic[i]->printService();
        }
        cout<<"\n0. Вихід\n";
    }
    void eraseService(int index){
        medic.erase(medic.begin()+index);
    }
    void delateService(){
        SelectService();
        while(true){
            cout<<"Введіть число: ";
            if(int index=checkNumber();index==0){
                return;
            }else if(index>0&&index<medic.size()){
                eraseService(index-1);
                cout<<"\nПослугу успішно видалено"<<endl;
                return;
            }else{
                cout<<"НЕ корректно введене число"<<endl;
            }
        }
    }
    int newService(){
        SelectService();
        while(true){
            cout<<"Введіть число: ";
            if(int index=checkNumber();index>=0&&index<medic.size()){
                return index;
            }else{
                cout<<"НЕ корректно введене число"<<endl;
            }
        }
    }
    string newPatient(){
        while(true){
            cout<<"Введіть прізвище та ініціали пацієнта: ";
            string patient;
            getline(cin,patient);
            if(patient.size()>3&&patient.size()<30){
                return patient;
            }else{
                cout<<"НЕ корректно введено Прізвище та ініціали пацієнта"<<endl;
            }
        }
    }
    int newYear(){
        while(true){
            cout<<"Введіть рік: ";
            if(int year=checkNumber();year>2020&&year<2027){
                return year;
            }else{
                cout<<"НЕ корректно введене число"<<endl;
            }
        }
    }
    int newMonth(){
        while(true){
            cout<<"Введіть місяць: ";
            if(int month=checkNumber();month>0&&month<13){
                return month;
            }else{
                cout<<"НЕ корректно введене число"<<endl;
            }
        }
    }
    int newDay(){
        while(true){
            cout<<"Введіть число: ";
            if(int day=checkNumber();day>0&&day<31){
                return day;
            }else{
                cout<<"НЕ корректно введене число"<<endl;
            }
        }
    }
    int newHour(){
        while(true){
            cout<<"Введіть годину: ";
            if(int hour=checkNumber();hour>8&&hour<17){
                return hour;
            }else{
                cout<<"НЕ корректно введене число"<<endl;
            }
        }
    }
    int newMinute(){
        while(true){
            cout<<"Введіть хвилину: ";
            if(int minute=checkNumber();minute>0&&minute<60){
                return minute;
            }else{
                cout<<"НЕ корректно введене число"<<endl;
            }
        }
    }
    void createHistoryService(){
        string patient=newPatient();
        int year=newYear();
        int month=newMonth();
        int day=newDay();
        int hour=newHour();
        int minute=newMinute();
        int index=newService();
        if(index==0){
            return;
        }
        history.push_back(make_unique<History>(patient,year,month,day,hour,minute,medic[index-1]->clone()));
    }
    public:
    void printFullHistory(){
        for(int index=0;index<history.size();index++){
            cout<<"\n"<<index+1<<"."<<endl;
            history[index]->printHistory();
            cout<<"\n";
        }
        cout<<"\n0. Вихід\n";
    }
    bool sortingLogic(int index){
        if(history[index]->getYear()<=history[index+1]->getYear()){
            if(history[index]->getMonth()<=history[index+1]->getMonth()){
                if(history[index]->getDay()<=history[index+1]->getDay()){
                    if(history[index]->getHour()<=history[index+1]->getHour()){
                        if(history[index]->getMinute()<=history[index+1]->getMinute()){
                            return true;
                        }else{
                            swap(history[index], history[index+1]);
                            return false;
                        }
                    }else{
                        swap(history[index], history[index+1]);
                        return false;
                    }
                }else{
                    swap(history[index], history[index+1]);
                    return false;
                }
            }else{
                swap(history[index], history[index+1]);
                return false;
            }
        }else{
            swap(history[index], history[index+1]);
            return false;
        }

    }
    void sortingHictory(){
        int index=0;
        while(index<history.size()){
            if(sortingLogic(index)){
                index=0;
            }else{
                index++;
            }
        }
    }
    pair<double,double> AllProfit(){
        double fsum=0,sum=0;
        for(unique_ptr<History>& h:history){
            fsum+=h->getProfit();
            if(h->getMonth()==4&&h->getYear()==2026){
                sum+=h->getProfit();
            }
        }
        return {fsum,sum};
    }
    void Profit(){
        pair<double,double> result=AllProfit();
        cout<<"Прибуток за весь період без врахування НДФЛ: "<<result.first<<endl;
        cout<<"Прибуток за весь період з врахуванням НДФЛ: "<<result.first-(result.first*0.22)<<endl;
        cout<<"Прибуток за місяць без врахування НДФЛ: "<<result.second<<endl;
        cout<<"Прибуток за місяць з врахуванням НДФЛ: "<<result.second-(result.second*0.22)<<endl;
    }
    void FinancialStatement(){
        sortingHictory();
        Profit();
        printFullHistory();
    }
};
//spy.erase(spy.begin()+index);