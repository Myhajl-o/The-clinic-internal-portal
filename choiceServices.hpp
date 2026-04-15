#pragma once
#include "MedicalServices.hpp"
#include "History.hpp"
#include <utility>
#include <string>
#include <vector>
#include <memory>
class choiceServices{
    private:
    std::vector<std::unique_ptr<MedicalServices>>medic;
    std::vector<std::unique_ptr<History>>history;
    double checkNumber();
    std::string newType();
    std::string newName();
    std::string newDiagnosis();
    std::string newDoctor();
    int newTime();
    double newPrice();
    void createService();
    void printSelectService();
    void eraseService(int index);
    void delateService();
    int newService();
    std::string newPatient();
    int newYear();
    int newMonth();
    int newDay();
    int newHour();
    int newMinute();
    void createHistoryService();
    void printFullHistory();
    bool sortingLogic(int index);
    void sortingHictory();
    std::pair<double,double> AllProfit();
    void Profit();
    void FinancialStatement();
    void printAction();
    bool switchAction();
    public:
    void addTestService(std::string type, std::string name, std::string diag, std::string doc, int time, double price) {
        medic.push_back(std::make_unique<MedicalServices>(type, name, diag, doc, time, price));
    }
    void addTestHistory(std::string pat, int y, int m, int d, int h, int mi, int serviceIndex) {
        if (serviceIndex > 0 && serviceIndex <= medic.size()) {
            history.push_back(std::make_unique<History>(
                pat, y, m, d, h, mi, 
                std::move(medic[serviceIndex - 1]->clone())
            ));
        }
    }
    void choiceAction();

};
//spy.erase(spy.begin()+index);