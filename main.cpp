#include "MedicalServices.hpp"
#include "History.hpp"
#include "choiceServices.hpp"
#include <memory>
using namespace std;
int main () {
    unique_ptr<MedicalServices> medic1 = make_unique<MedicalServices>
    ("massage", "gavai", "pain", "Darvin", 30, 550.50);
    unique_ptr<History> his =
    make_unique<History>("Galya", 2026, 3, 17, 12, 50, move(medic1));

    choiceServices d; 
    d.FinancialStatement();



    return 0;
}