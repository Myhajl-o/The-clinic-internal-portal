#include "choiceServices.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <memory>
#include <ctime>
using namespace std;

double choiceServices::checkNumber(){
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
string choiceServices::newType(){
    while(true){
        cout<<"Введіть тип послуги: ";
        string type;
        getline(cin, type);
        if(type.size()>3&&type.size()<40){
            return type;
        }else{
            cout<<"НЕ корректно введений тип;"<<endl;
        }        
    }
}
string choiceServices::newName(){
    while(true){
        cout<<"Введіть назву послуги: ";
        string name;
        getline(cin,name);
        if(name.size()>3&&name.size()<60){
            return name;
        }else{
            cout<<"НЕ корректно введена назва"<<endl;
        }
    }
}
string choiceServices::newDiagnosis(){
    while(true){
        cout<<"Введіть обгрунтування процедури (діагноз): ";
        string diagnosis;
        getline(cin, diagnosis);
        if(diagnosis.size()>3&&diagnosis.size()<60){
            return diagnosis;
        }else{
            cout<<"НЕ корректно введений діагноз"<<endl;
        }
    }
}
string choiceServices::newDoctor(){
    while(true){
        cout<<"Введіть прізвище та ініціали лікаря: ";
        string doctor;
        getline(cin,doctor);
        if(doctor.size()>3&&doctor.size()<60){
            return doctor;
        }else{
            cout<<"НЕ корректно введено Прізвище та ініціали лікаря"<<endl;
        }
    }
}
int choiceServices::newTime(){
    while(true){
        cout<<"Введіть час проведення процедури: ";
        if(int time=checkNumber();time>4&&time<120){
            return time;
        }else{
            cout<<"НЕ корректно введений час"<<endl;
        }
    }
}
double choiceServices::newPrice(){
    while(true){
        cout<<"Введіть ціну послуги: ";
        if(double price=checkNumber();price>100&&price<1000000){
            return price;
        }else{
            cout<<"Не корректно введена ціна"<<endl;
        }
    }
}
void choiceServices::createS(string type, string name, string diag, string doc, int time, double price) {
    medic.push_back(make_unique<MedicalServices>(type, name, diag, doc, time, price));
}
void choiceServices::createService(){
    createS(newType(),newName(),newDiagnosis(),newDoctor(),newTime(),newPrice());
    cout<<"Нову послугу успішно створено"<<endl;
    medic[medic.size()-1]->printService();
}
void choiceServices::printSelectService(){
    for(int i=0;i<medic.size();i++){
        cout<<"\tПОСЛУГА "<<i+1<<endl;
        medic[i]->printService();
    }
    cout<<"\n0. Назад\n";
}
void choiceServices::editServices(){
    printSelectService();
    while(true){
        cout<<"Введіть число: ";
        if(int index=checkNumber();index==0){
            return;
        }else if(index>0&&index<=medic.size()){
            medic[index-1]->editingServices();
            return;
        }else{
            cout<<"НЕ корректно введене число"<<endl;
        }
    }
}
void choiceServices::eraseService(int index){
    medic.erase(medic.begin()+index);
}
void choiceServices::delateService(){
    printSelectService();
    while(true){
        cout<<"Введіть число: ";
        if(int index=checkNumber();index==0){
            return;
        }else if(index>0&&index<=medic.size()){
            eraseService(index-1);
            cout<<"\nПослугу успішно видалено"<<endl;
            return;
        }else{
            cout<<"НЕ корректно введене число"<<endl;
        }
    }
}
int choiceServices::newService(){
    printSelectService();
    while(true){
        cout<<"Введіть число: ";
        if(int index=checkNumber();index>=0&&index<=medic.size()){
            return index;
        }else{
            cout<<"НЕ корректно введене число"<<endl;
        }
    }
}
string choiceServices::newPatient(){
    while(true){
        cout<<"Введіть прізвище та ініціали пацієнта: ";
        string patient;
        getline(cin,patient);
        if(patient.size()>3&&patient.size()<60){
            return patient;
        }else{
            cout<<"НЕ корректно введено Прізвище та ініціали пацієнта"<<endl;
        }
    }
}
int choiceServices::newYear(){
    while(true){
        cout<<"Введіть рік: ";
        if(int year=checkNumber();year>2020&&year<=now->tm_year+1900){
            tempYear=year;
            return year;
        }else{
            cout<<"НЕ корректно введене число"<<endl;
        }
    }
}
int choiceServices::getMonth(){
    if(tempYear!=now->tm_year+1900){
        return 12;
    }else{
        return now->tm_mon + 1;
    }
}
int choiceServices::newMonth(){
    while(true){
        cout<<"Введіть місяць: ";
        if(int month=checkNumber();month>0&&month<=getMonth()){
            tempMonth=month;
            return month;
        }else{
            cout<<"НЕ корректно введене число"<<endl;
        }
    }
}
int choiceServices::getDay(){
    if(tempYear!=now->tm_year+1900){
        if(tempMonth==4||tempMonth==6||tempMonth==9||tempMonth==11){
            return 30;
        }else if(tempMonth==2){
            return 28;
        }else{
            return 31;
        }
    }else{
        if(tempMonth!=now->tm_mon+1){
            if(tempMonth==4||tempMonth==6||tempMonth==9||tempMonth==11){
                return 30;
            }else if(tempMonth==2){
                return 28;
            }else{
                return 31;
            }
        }else{
            return now->tm_mday;
        }
    }
}
int choiceServices::newDay(){
    while(true){
        cout<<"Введіть число: ";
        if(int day=checkNumber();day>0&&day<=getDay()){
            tempDay=day;
            return day;
        }else{
            cout<<"НЕ корректно введене число"<<endl;
        }
    }
}
int choiceServices::getHour(){
    if(tempYear==now->tm_year+1900&&tempMonth==now->tm_mon+1&&tempDay==now->tm_mday){
        return now->tm_hour; 
    }else{
        return 17;
    }
}
int choiceServices::newHour(){
    while(true){
        cout<<"Введіть годину: ";
        if(int hour=checkNumber();hour>=8&&hour<=getHour()){
            tempHour=hour;
            return hour;
        }else{
            cout<<"НЕ корректно введене число"<<endl;
        }
    }
}
int choiceServices::getMinute(){
    if(tempYear==now->tm_year+1900&&tempMonth==now->tm_mon+1&&tempDay==now->tm_mday&&tempHour==now->tm_hour){
        return now->tm_min;
    }else{
        return 59;
    }
}
int choiceServices::newMinute(){
    while(true){
        cout<<"Введіть хвилину: ";
        if(int minute=checkNumber();minute>0&&minute<=getMinute()){
            return minute;
        }else{
            cout<<"НЕ корректно введене число"<<endl;
        }
    }
}
void choiceServices::createHS(string pat, int y, int m, int d, int h, int mi, int index){
    if(index>=0&&medic.size()>0){
        history.push_back(make_unique<History>(pat, y, m, d, h, mi,index,move(medic[index - 1]->clone())));
    }
}
void choiceServices::createHistoryService(){
    t = time(nullptr);
    now = localtime(&t);
    if(now->tm_hour>=8&&now->tm_hour<=17){
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
        createHS(patient,year,month,day,hour,minute,index);
    }else{
        cout<<"Функція створення запису працює з 8:00 до 17:00"<<endl;
    }
}
void choiceServices::printFullHistory(){
    for(int index=0;index<history.size();index++){
        cout<<"\n"<<index+1<<"."<<endl;
        history[index]->printHistory();
        cout<<"\n";
    }
    cout<<"\n0. Назад\n";
}
bool choiceServices::sortingLogic(int index){
    if (history[index - 1]->getYear() < history[index]->getYear()) return true;
    if (history[index - 1]->getYear() > history[index]->getYear()) {
        swap(history[index - 1], history[index]);
        return false;
    }
    if (history[index - 1]->getMonth() < history[index]->getMonth()) return true;
    if (history[index - 1]->getMonth() > history[index]->getMonth()) {
        swap(history[index - 1], history[index]);
        return false;
    }
    if (history[index - 1]->getDay() < history[index]->getDay()) return true;
    if (history[index - 1]->getDay() > history[index]->getDay()) {
        swap(history[index - 1], history[index]);
        return false;
    }
    if (history[index - 1]->getHour() < history[index]->getHour()) return true;
    if (history[index - 1]->getHour() > history[index]->getHour()) {
        swap(history[index - 1], history[index]);
        return false;
    }
    if (history[index - 1]->getMinute() <= history[index]->getMinute()) {
        return true;
    } else {
        swap(history[index - 1], history[index]);
        return false;
    }
}
void choiceServices::sortingHictory(){
    if (history.size() < 2) {
            return;
        }
    int index=1;
    while(index<history.size()){
        if(sortingLogic(index)){
            index++;
        }else{
            index=1;
        }
    }
}
pair<double,double> choiceServices::AllProfit(){
    double fsum=0,sum=0;
    t = time(nullptr);
    now = localtime(&t);
    for(unique_ptr<History>& h:history){
        fsum+=h->getProfit();
        if(h->getMonth()==now->tm_mon+1&&h->getYear()==now->tm_year+1900){
            sum+=h->getProfit();
        }
    }
    return {fsum,sum};
}
void choiceServices::Profit(){
    pair<double,double> result=AllProfit();
    cout<<"Прибуток за весь період без врахування НДФЛ: "<<result.first<<endl;
    cout<<"Прибуток за весь період з врахуванням НДФЛ: "<<result.first-(result.first*0.22)<<endl;
    cout<<"Прибуток за місяць без врахування НДФЛ: "<<result.second<<endl;
    cout<<"Прибуток за місяць з врахуванням НДФЛ: "<<result.second-(result.second*0.22)<<endl;
}
void choiceServices::FinancialStatement(){
    sortingHictory();
    Profit();
    printFullHistory();
}
void choiceServices::printAction(){
    cout<<"\n\n1. Перегляд активних послуг;"<<endl;
    cout<<"2. Додати послугу;"<<endl;
    cout<<"3. Редагувати активну послугу;"<<endl;
    cout<<"4. Видалити послугу;"<<endl;
    cout<<"5. Див. бухгалтерський звіт;"<<endl;
    cout<<"6. Додати виконану послугу"<<endl;
    cout<<"0. Вихід"<<endl;
}
bool choiceServices::switchAction(){
    printAction();
    switch(static_cast<int>(checkNumber())){
        case 0:
            system("cls");
            return true;
        case 1:
            system("cls");
            printSelectService();
            return false;
        case 2:
            system("cls");
            createService();
            return false;
        case 3:
            system("cls");
            editServices();
            return false;
        case 4:
            system("cls");
            delateService();
            return false;
        case 5:
            system("cls");
            FinancialStatement();
            return false;
        case 6:
            system("cls");
            createHistoryService();
            return false;
        default:
            system("cls");
            cout<<"НЕ корректно введена дія"<<endl;
            return false;
    }
}
void choiceServices::choiceAction(){
    while(true){
        if(switchAction()){
            return;
        }
    }
}
vector<unique_ptr<MedicalServices>>& choiceServices::getMedic(){
    return medic;
}
vector<unique_ptr<History>>& choiceServices::getHistory() {
    return history;
}