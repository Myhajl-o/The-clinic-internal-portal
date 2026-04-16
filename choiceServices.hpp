#pragma once
#include "MedicalServices.hpp"
#include "History.hpp"
#include <utility>
#include <string>
#include <vector>
#include <memory>
#include <ctime>
class choiceServices{
    private:
    std::vector<std::unique_ptr<MedicalServices>>medic;
    std::vector<std::unique_ptr<History>>history;
    time_t t;
    tm* now;
    int tempYear;
    int tempMonth;
    int tempDay;
    int tempHour;
    int getMonth();
    int getDay();
    int getHour();
    int getMinute();
    double checkNumber();
    std::string newType();
    std::string newName();
    std::string newDiagnosis();
    std::string newDoctor();
    int newTime();
    double newPrice();
    void createService();
    void printSelectService();
    void editServices();
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
    void choiceAction();
    std::vector<std::unique_ptr<MedicalServices>>& getMedic();
    std::vector<std::unique_ptr<History>>& getHistory();
    void createS(std::string type, std::string name, std::string diag, std::string doc, int time, double price);
    void createHS(std::string pat, int y, int m, int d, int h, int mi, int index);
};