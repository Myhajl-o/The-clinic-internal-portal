#include "choiceServices.hpp"
using namespace std;
int main () {
    choiceServices clinic;

    clinic.addTestService("Стоматологія", "Лікування карієсу", "Карієс середнього ступеня", "Лобанов С.В.", 45, 1200.00);
    clinic.addTestService("Діагностика", "УЗД черевної порожнини", "Біль у животі", "Купітман І.Н.", 20, 650.50);
    clinic.addTestService("Терапія", "Первинна консультація", "ГРВІ, температура", "Биков А.Є.", 15, 400.00);
    clinic.addTestHistory("Шевченко О.М.", 2026, 4, 15, 10, 9, 2);
    clinic.addTestHistory("Коваленко І.І.", 2026, 4, 10, 14, 00, 1);
    clinic.addTestHistory("Ткачук В.П.", 2026, 2, 28, 9, 15, 3);
    clinic.choiceAction();
    return 0;
}