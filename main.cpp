#include "choiceServices.hpp"
#include <string>
#include <fstream>
using namespace std;
void readingFile(choiceServices& med){
    ifstream file("Services.hms");
    if (!file.is_open()) return;
    string type, name, diagn, doc, timeStr, priceStr;
    while (getline(file, type, '|')) {
        getline(file, name, '|');
        getline(file, diagn, '|');
        getline(file, doc, '|');
        getline(file, timeStr, '|');
        getline(file, priceStr, '\n');

        if (!type.empty()) {
            med.createS(type, name, diagn, doc, stoi(timeStr), stod(priceStr));
        }
    }
    file.close();
}

void readHistoryFile(choiceServices& med) {
    ifstream file("HistoryServices.hms");
    if (!file.is_open()) return;

    string pat, yearStr, monthStr, dayStr, hourStr, minStr, indexStr;

    while (getline(file, pat, '|')) {
        getline(file, yearStr, '|');
        getline(file, monthStr, '|');
        getline(file, dayStr, '|');
        getline(file, hourStr, '|');
        getline(file, minStr, '|');
        getline(file, indexStr, '\n');

        if (!pat.empty()) {
            med.createHS(pat, stoi(yearStr), stoi(monthStr), stoi(dayStr), stoi(hourStr), stoi(minStr), stoi(indexStr));
        }
    }
    file.close();
}

void writeFile(vector<unique_ptr<MedicalServices>>& med){
    ofstream file("Services.hms");
    if (!file.is_open()) return;
    for (unique_ptr<MedicalServices>& m : med) {
        file << m->getType() << '|'
             << m->getName() << '|'
             << m->getDiagnosis() << '|'
             << m->getDoctor() << '|'
             << m->getTime() << '|'
             << m->getPrice() << '\n';
    }
    file.close();
}
void writeHiistoryFile(vector<unique_ptr<History>>& history){
    ofstream file("HistoryServices.hms");
    if (!file.is_open()) return;
    for(unique_ptr<History>& h:history){
        file<<h->getPatient()<<'|'
            <<h->getYear()<<'|'
            <<h->getMonth()<<'|'
            <<h->getDay()<<'|'
            <<h->getHour()<<'|'
            <<h->getMinute()<<'|'
            <<h->getIndex()<<'\n';
    }
    file.close();
}
int main () {
    choiceServices clinic;
    readingFile(clinic);
    readHistoryFile(clinic);
    clinic.choiceAction();
    writeFile(clinic.getMedic());
    writeHiistoryFile(clinic.getHistory());
    return 0;
}