#pragma once
#include <string>
#include <memory>
class MedicalServices{
    private:
    std::string typeServices;
    std::string nameServices;
    std::string diagnosis;
    std::string doctor;
    int time;
    double price;

    void setType(std::string type){
        typeServices=type;
    }
    void setName(std::string name){
        nameServices=name;
    }
    void setDiagnosis(std::string diag){
        diagnosis=diag;
    }
    void setDoctor(std::string doc){
        doctor=doc;
    }
    void setTime(int Time){
        time=Time;
    }
    void setPrice(double Price){
        price=Price;
    }

    void changeType();
    void changeName();
    void changeDiagnosis();
    void changeDoctor();
    void changeTime();
    void changePrice();
    void printServices();
    double checkNumber();
    bool checkTimeNumber(int number);
    bool checkPriceNumber(double number);
    public:
    
    MedicalServices(std::string type,std::string name,
        std::string diagn,std::string doc,int time,double price):typeServices(type),
        nameServices(name),diagnosis(diagn),doctor(doc),
        time(time),price(price){}
        
    std::string getType(){
        return typeServices;
    }
    std::string getName(){
        return nameServices;
    }
    std::string getDiagnosis(){
        return diagnosis;
    }
    std::string getDoctor(){
        return doctor;
    }
    int getTime(){
        return time;
    }
    double getPrice(){
        return price;
    }
    void printService();
    bool switchServices();
    void editingServices();
    std::unique_ptr<MedicalServices> clone() const ;
};