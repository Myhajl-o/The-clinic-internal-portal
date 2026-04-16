# The Clinic Internal Portal (Medical Services Accounting)
## language: EN

## Project Overview
A C++ console application for accounting medical services and managing patient history. The project is developed with a strong focus on robust architecture (MVC pattern), safe memory management, and complex business logic for data validation. The program simulates the operation of a real-world medical CRM system.

## Technical Mechanics & Architecture

### 1. Memory Management (Smart Pointers)
* Complete elimination of raw pointers and manual memory management (`new`/`delete`).
* Utilization of `std::unique_ptr` combined with `std::vector` to store the services database and transaction history.

### 2. Cascading Time Validation
* Integration with the OS system time via the `<ctime>` library.
* Implemented a date input validation algorithm: users are physically prevented from entering dates from the "future". The logic dynamically restricts available months, days (accounting for 28/30/31 days), and hours based on the current real-time.
* Built-in business logic: record creation is restricted to clinic working hours (08:00 - 17:00).

### 3. Application of OOP Principles
* **Encapsulation & Decomposition:** The program's logic is strictly divided into independent classes (`MedicalServices`, `Date`, `History`, `choiceServices`), each responsible for its own data domain.
* **Composition over Inheritance:** The `History` class does not inherit from services but contains them as objects, adhering to relational database design principles.
* **Prototype Pattern:** Implemented a deep cloning mechanism (`clone()`). When adding a record to the history, an independent "snapshot" of the service is created. This ensures that future price changes in the catalog do not alter historical accounting receipts.

### 4. Input Stream Protection (Defensive Programming)
* Robust handling of user input errors. The use of `std::cin.fail()`, `std::cin.clear()`, and `std::cin.ignore()` prevents input stream breakage (cin failure) and infinite loops when characters are entered instead of numbers.

### 5. Custom Sorting Algorithm (Gnome Sort Variant)
* Developed a custom multi-level sorting algorithm for patient history based on date and time (from year down to minute).
* The algorithm correctly handles nested date equality conditions without relying on the standard `<algorithm>` library.

### 6. Data Persistence (File I/O)
* Saving and loading the program's state to local `.hms` format files.
* Use of custom delimiters (`|`) for accurate parsing of strings containing spaces using `std::getline`.

## Tech Stack
* Language: C++ (C++14/17)
* Architecture: OOP, MVC, Prototype Pattern
* Libraries: `<iostream>`, `<vector>`, `<memory>`, `<string>`, `<fstream>`, `<ctime>`




# The Clinic Internal Portal (Medical Services Accounting)
## language: UA

## Опис проєкту
Консольний додаток на C++ для обліку медичних послуг та ведення історії пацієнтів. Проєкт розроблено з акцентом на надійну архітектуру (MVC-патерн), безпечне управління пам'яттю та складну бізнес-логіку валідації даних. Програма імітує роботу реальної медичної CRM-системи.

## Технічні механіки та архітектура

### 1. Управління пам'яттю (Smart Pointers)
* Повна відмова від сирих вказівників (`raw pointers`) та ручного управління пам'яттю (`new`/`delete`).
* Використання `std::unique_ptr` у комбінації з `std::vector` для зберігання бази послуг та історії транзакцій.

### 2. Каскадна валідація часу (Cascading Time Validation)
* Інтеграція з системним часом ОС через бібліотеку `<ctime>`.
* Реалізовано алгоритм перевірки вводу дати: користувач фізично не може ввести дату з "майбутнього". Логіка динамічно обмежує доступні місяці, дні (з урахуванням 28/30/31 днів) та години залежно від поточного реального часу.
* Вбудована бізнес-логіка: створення записів можливе лише в робочі години клініки (08:00 - 17:00).

### 3. Використання принципів ООП
* **Інкапсуляція та Декомпозиція:** Логіка програми строго розділена на незалежні класи (`MedicalServices`, `Date`, `History`, `choiceServices`), кожен з яких відповідає за свою частину даних.
* **Композиція замість Спадкування:** Клас `History` не успадковує послуги, а містить їх як об'єкти, що відповідає правилам побудови реляційних баз даних.
* **Патерн "Прототип" (Prototype):** Реалізовано механізм глибокого клонування об'єктів (`clone()`). При додаванні запису в історію створюється незалежний "зліпок" послуги. Це гарантує, що майбутні зміни цін у прайс-листі не вплинуть на старі бухгалтерські чеки.

### 4. Захист потоку вводу (Defensive Programming)
* Надійна обробка помилок вводу користувача. Використання `std::cin.fail()`, `std::cin.clear()` та `std::cin.ignore()` запобігає "зламу" потоку вводу (cin failure) та нескінченним циклам при введенні символів замість чисел.

### 5. Кастомний алгоритм сортування (Gnome Sort Variant)
* Написано власний алгоритм багаторівневого сортування історії пацієнтів за датою та часом (від року до хвилини).
* Алгоритм коректно обробляє вкладені умови рівності дат без використання стандартної бібліотеки `<algorithm>`.

### 6. Персистентність даних (File I/O)
* Збереження та завантаження стану програми у локальні файли формату `.hms`.
* Використання кастомних роздільників (`|`) для коректного парсингу рядків, що містять пробіли, за допомогою `std::getline`.

## Стек технологій
* Мова: C++ (C++14/17)
* Архітектура: OOP, MVC, Prototype Pattern
* Бібліотеки: `<iostream>`, `<vector>`, `<memory>`, `<string>`, `<fstream>`, `<ctime>`
