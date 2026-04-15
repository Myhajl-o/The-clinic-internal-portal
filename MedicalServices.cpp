#include "MedicalServices.hpp"
#include <iostream>
#include <string>
#include <memory>
using namespace std;

void MedicalServices::changeType(){
        cout<<"\nНовий тип: ";
        string type;
        cin>>type;
        setType(type);
    }
    void MedicalServices::changeName(){
        cout<<"\nНова назва: ";
        string name;
        cin>>name;
        setName(name);
    }
    void MedicalServices::changeDiagnosis(){
        cout<<"\nІнший діагноз: ";
        string diagnosis;
        cin>>diagnosis;
        setDiagnosis(diagnosis);
    }
    void MedicalServices::changeDoctor(){
        cout<<"\nНовий лікар: ";
        string doctor;
        cin>>doctor;
        setDoctor(doctor);
    }
    void MedicalServices::changeTime(){
        cout<<"\nНовий час: ";
        int time;
        cin>>time;
        setTime(time);
    }
    void MedicalServices::changePrice(){
        cout<<"\nНова ціна: ";
        double price;
        cin>>price;
        setPrice(price);
    }
    void MedicalServices::printService(){
        cout<<"1. Тип послуги:            "<<getType()<<" ;"<<endl;
        cout<<"2. Назва:                  "<<getName()<<" ;"<<endl;
        cout<<"3. Пробема:                "<<getDiagnosis()<<" ;"<<endl;
        cout<<"4. Лікар/спеціаліст:       "<<getDoctor()<<" ;"<<endl;
        cout<<"5. Процедура триває:       "<<getTime()<<"  хв ;"<<endl;
        cout<<"6. Ціна:                   "<<getPrice()<<"  грн ;"<<endl;
    }
    void MedicalServices::printServices(){
        cout<<"\n\n";
        printService();
        cout<<"7. назад"<<endl;
    }
    int MedicalServices::checkNumber(){
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
    bool MedicalServices::switchServices(){
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
    void MedicalServices::editingServices(){
        while(true){
            printServices();
            if(switchServices()){
                return;
            }
        }
    }
    unique_ptr<MedicalServices> MedicalServices::clone() const {
        return make_unique<MedicalServices>(
            typeServices, 
            nameServices, 
            diagnosis, 
            doctor, 
            time, 
            price
        );
    }