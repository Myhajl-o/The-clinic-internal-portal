#include "MedicalServices.hpp"
#include <iostream>
#include <string>
#include <memory>
using namespace std;

    void MedicalServices::changeType(){
        while(true){
            cout<<"\nНовий тип: ";
            string type;
            getline(cin, type);
            if(type.size()>3&&type.size()<40){
                setType(type);
                return;
            }else{
                cout<<"НЕ корректно введений тип;"<<endl;
            }         
        }
    }
    void MedicalServices::changeName(){
        while(true){
            cout<<"\nНова назва: ";
            string name;
            getline(cin,name);
            if(name.size()>3&&name.size()<60){
                setName(name);
                return;
            }else{
                cout<<"НЕ корректно введена назва"<<endl;
            }
        }
    }
    void MedicalServices::changeDiagnosis(){
        while(true){
            cout<<"\nІнший діагноз: ";
            string diagnosis;
            getline(cin, diagnosis);
            if(diagnosis.size()>3&&diagnosis.size()<60){
                setDiagnosis(diagnosis);
                return;
            }else{
                cout<<"НЕ корректно введений діагноз"<<endl;
            }
        }
    }
    void MedicalServices::changeDoctor(){
        while(true){
            cout<<"\nНовий лікар: ";
            string doctor;
            getline(cin,doctor);
            if(doctor.size()>3&&doctor.size()<60){
                setDoctor(doctor);
                return;
            }else{
                cout<<"НЕ корректно введена назва"<<endl;
            }
        }
    }

    void MedicalServices::changeTime(){
        while(true){
            cout<<"\nНовий час";
            if(int number=checkNumber();checkTimeNumber(number)){
                setTime(number);
                return;
            }else{
                cout<<"НЕ корректно введене значення";
            }
        }
    }
    bool MedicalServices::checkTimeNumber(int number){
        if(number>4&&number<120){
            return true;
        }else{
            return false;
        }
    }
    void MedicalServices::changePrice(){
        while(true){
            cout<<"\nНова ціна";
            if(double number=checkNumber();checkPriceNumber(number)){
                setPrice(number);
                return;
            }else{
                cout<<"НЕ корректно введене значення";
            }
        }
    }
    bool MedicalServices::checkPriceNumber(double number){
        if(number>100&&number<1000000){
            return true;
        }else{
            return false;
        }
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
    double MedicalServices::checkNumber(){
        cout<<"\nВведіть число: ";
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
    bool MedicalServices::switchServices(){
        switch (static_cast<int>(checkNumber())) {
            case 1:
                system("cls");
                changeType();
                return false;
            case 2:
                system("cls");
                changeName();
                return false;
            case 3:
                system("cls");
                changeDiagnosis();
                return false;
            case 4:
                system("cls");
                changeDoctor();
                return false;
            case 5:
                system("cls");
                changeTime();
                return false;
            case 6:
                system("cls");
                changePrice();
                return false;
            case 7:
                system("cls");
                return true;
            default:
                system("cls");
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