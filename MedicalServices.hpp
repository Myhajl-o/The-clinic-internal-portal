#pragma once
#include <iostream>
#include <string>
#include <memory>
using namespace std;
class MedicalServices{
    private:
    string typeServices;
    string nameServices;
    string diagnosis;
    string doctor;
    int time;
    double price;
string getType(){
        return typeServices;
    }
    string getName(){
        return nameServices;
    }
    string getDiagnosis(){
        return diagnosis;
    }
    string getDoctor(){
        return doctor;
    }
    int getTime(){
        return time;
    }

    public:
    
    MedicalServices(string type,string name,
        string diagn,string doc,int time,double price):typeServices(type),
        nameServices(name),diagnosis(diagn),doctor(doc),
        time(time),price(price){}
    
    double getPrice(){
        return price;
    }

    
    void setType(string type){
        typeServices=type;
    }
    void setName(string name){
        nameServices=name;
    }
    void setDiagnosis(string diag){
        diagnosis=diag;
    }
    void setDoctor(string doc){
        doctor=doc;
    }
    void setTime(int Time){
        time=Time;
    }
    void setPrice(double Price){
        price=Price;
    }
    void changeType(){
        cout<<"\nНовий тип: ";
        string type;
        cin>>type;
        setType(type);
    }
    void changeName(){
        cout<<"\nНова назва: ";
        string name;
        cin>>name;
        setName(name);
    }
    void changeDiagnosis(){
        cout<<"\nІнший діагноз: ";
        string diagnosis;
        cin>>diagnosis;
        setDiagnosis(diagnosis);
    }
    void changeDoctor(){
        cout<<"\nНовий лікар: ";
        string doctor;
        cin>>doctor;
        setDoctor(doctor);
    }
    void changeTime(){
        cout<<"\nНовий час: ";
        int time;
        cin>>time;
        setTime(time);
    }
    void changePrice(){
        cout<<"\nНова ціна: ";
        double price;
        cin>>price;
        setPrice(price);
    }
    void printService(){
        cout<<"1. Тип послуги:            "<<getType()<<" ;"<<endl;
        cout<<"2. Назва:                  "<<getName()<<" ;"<<endl;
        cout<<"3. Пробема:                "<<getDiagnosis()<<" ;"<<endl;
        cout<<"4. Лікар/спеціаліст:       "<<getDoctor()<<" ;"<<endl;
        cout<<"5. Процедура триває:       "<<getTime()<<"  хв ;"<<endl;
        cout<<"6. Ціна:                   "<<getPrice()<<"  грн ;"<<endl;
    }
    void printServices(){
        cout<<"\n\n";
        printService();
        cout<<"7. назад"<<endl;
    }
    int checkNumber(){
        cout<<"\nВведіть число: ";
        int number;
        cin >> number;
        if(cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
            return 10;
        }
        return number;
    }
    bool switchServices(){
        switch (checkNumber()) {
            case 1:
                changeType();
                return false;
            case 2:
                changeName();
                return false;
            case 3:
                changeDiagnosis();
                return false;
            case 4:
                changeDoctor();
                return false;
            case 5:
                changeTime();
                return false;
            case 6:
                changePrice();
                return false;
            case 7:
                return true;
            default:
                cout << "Не коректно введене значення" << endl;
                return false;
        }
    }
    void editingServices(){
        while(true){
            printServices();
            if(switchServices()){
                return;
            }
        }
    }
    unique_ptr<MedicalServices> clone() const {
        return make_unique<MedicalServices>(
            typeServices, 
            nameServices, 
            diagnosis, 
            doctor, 
            time, 
            price
        );
    }
};