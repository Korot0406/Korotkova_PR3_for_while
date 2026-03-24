// Короткова
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Функция проверки корректности ввода целого числа
bool IntUserInput(string input){
    if (input.empty())return false;

    try{
        size_t pos;
        stoi(input, &pos);
        return pos == input.length();
    }catch(...){
        return false;
    }
}

// Функция ввода целого числа с повторением запроса до корректного ввода
int IntEnterNumber(string label){
    string raw_input;
    cout << label;
    getline(cin, raw_input);
    while (!IntUserInput(raw_input)){
        cout << label;
        getline(cin, raw_input);
    }
    return stoi(raw_input);
}

// Функция проверки корректности ввода вещественного числа
bool DoubleUserInput(string input){
    if (input.empty())return false;

    try{
        size_t pos;
        stod(input, &pos);
        return pos == input.length();
    }catch(...){
        return false;
    }
}

// Функция ввода вещественного числа с повторением запроса до корректного ввода
double DoubleEnterNumber(string label){
    string raw_input;
    cout << label;
    getline(cin, raw_input);
    while (!DoubleUserInput(raw_input)){
        cout << label;
        getline(cin, raw_input);
    }
    return stod(raw_input);
}


// Задание 1. Составить программу, проверяющую, является ли последовательность из десяти целых чисел 
// «зигзагообразной» (элементы поочередно то строго больше, то строго меньше предыдущего).
// Решить с помощью цикла while или do...while.
void is_zigzag_sequence(){
    int i = 0;
    int k = 0;
    int n1 = IntEnterNumber("Введите целое число: ");
    while (i < 2 && i > -2 && k < 9){
        int n2 = IntEnterNumber("Введите целое число: ");
        if(n1 > n2){
            i--;
        }else{
            i++;
        }
        n1 = n2;
        k++;
    }
    cout << "Результат задания 1:\n";
    if (k == 9){
        cout << "Последовательность является \"зигзагообразной\".\n";
    }else{
        cout << "Последовательность не является \"зигзагообразной\".\n";
    }
}
// Задание 2. Вывести все четырехзначные числа, цифры которых образуют арифметическую
// прогрессию (например, 1357, 8642). Решить с помощью цикла for.
void is_arith_progression(){
    cout << "Результат задания 2:\n";
    for (int i = 1000; i < 10000; i++){
        int a1 = i / 1000;
        int a2 = (i % 1000) / 100;
        int a3 = ((i / 10) % 100) % 10;
        int a4 = i % 10;
        if (a2 - a1 == a3 - a2 && a3 - a2 == a4 - a3){
            cout << i << "\n";
        }
    }
}
// Задание 3. Написать программу для вычисления и вывода на экран таблицы значений
// функции
// 𝑦 = √(|𝑥 − 1|) + √(|𝑥 + 1|).
// Диапазон значений аргумента х и шаг вводятся. Вывод выполнить в два столбика: первый
// столбик – значения аргумента, второй – значения функции. При разработке программы
// следует учитывать область определения функции и в случае необходимости организовать
// во втором столбике печать сообщения – «функция не определена». Можно использовать
// любые операторы цикла.
void table_funcion(){
    double x1 = DoubleEnterNumber("Введите  x1: ");
    double x2 = DoubleEnterNumber("Введите  x2: ");
    double x0 = DoubleEnterNumber("Введите шаг: ");
    cout << x0 << endl;
    cout << "Результат задания 3:\n" << "      x        |        y        \n";
    cout << "--------------------------------\n";
    if (x1 == x2){
         double y = sqrt(abs(x1 - 1)) + sqrt(abs(x1 + 1));
        printf("%10.4f     | %10.4f\n", x1, y);
    }
    if (x1 < x2 && x0 > 0){
        for (double i = x1; i <= x2; i += x0){
            double y = sqrt(abs(i - 1)) + sqrt(abs(i + 1));
            printf("%10.4f     | %10.4f\n", i, y);
        }
    }else if (x1 > x2 && x0 > 0){
        for (double i = x2; i <= x1; i += x0){
            double y = sqrt(abs(i - 1)) + sqrt(abs(i + 1));
            printf("%10.4f     | %10.4f\n", i, y);
        }
    }else if (x1 < x2 && x0 < 0){
        for (double i = x2; i >= x1; i += x0){
            double y = sqrt(abs(i - 1)) + sqrt(abs(i + 1));
            printf("%10.4f     | %10.4f\n", i, y);
        }
    }else if (x1 > x2 && x0 > 0){
        for (double i = x2; i <= x1; i += x0){
            double y = sqrt(abs(i - 1)) + sqrt(abs(i + 1));
            printf("%10.4f     | %10.4f\n", i, y);
        }
    }
}
//Задание 4. Дано натуральное число n. Вычислить сумму ряда:
// 1/(1 · 2) + 1/(2 · 3) + . . . + 1/(𝑛 · (𝑛 + 1)).
void sum_line(){
    int n = IntEnterNumber("Введите натуральное число n: ");
    if (n < 1){
        n = IntEnterNumber("Введите натуральное число n: ");
    }
    double answer = 0;
    int sum = 0;
    for (int i = 1; i < n + 1; i++){
        sum += i * (i + 1);
    }
    answer = 1.0 / sum;
    cout << "Результат задания 5:\nСумма ряда: " <<  answer << ".\n";
}
// Задание 5. Найти количество натуральных чисел, меньших n, у которых сумма цифр является простым числом.
void find_count(){
    int n = IntEnterNumber("Введите натуральное число: ");
    if (n < 0){
        n = IntEnterNumber("Введите натуральное число: ");
    }else if (n == 1 || n == 2){
        cout << "Результат задания 5:\nКоличество натуральных чисел, меньших "<< n << ": " << 0 << ".\n";
    }else{
        int count = 0;
        for (int i = 2; i < n; i++){
            int i1 = i;
            int k = 0;
            int sum = 0;
            while (i1 > 9){
                sum += i1 % 10;
                i1 = i1 / 10;
            }
            sum += i1;
            for (int j = 1; j < sum / 2 + 1; j++){
                if (sum % j == 0){
                    k++;
                }
            }
            if (k == 1){
                count++;
            }
            
        }
        cout << "Результат задания 5:\nКоличество натуральных чисел, меньших "<< n << ": " << count << ".\n";
    }
}


int main(){
    setlocale(LC_ALL, "Russian");
    int funcSelect = 0;
    for(;;){
        cout << "\nTask 1. Проверить, является ли последовательность из десяти целых чисел «зигзагообразной»;\n";
        cout << "Task 2. Вывести все четырехзначные числа, цифры которых образуют арифметическую прогрессию;\n";
        cout << "Task 3. Вычисление и вывод на экран таблицы значений функции 𝑦 = √(|𝑥 − 1|) + √(|𝑥 + 1|);\n";
        cout << "Task 4. Поиск суммы ряда: 1/(1 · 2) + 1/(2 · 3) + ... + 1/(𝑛 · (𝑛 + 1));\n";
        cout << "Task 5. Поиск количества натуральных чисел, меньших n, у которых сумма цифр является простым числом.\n\n";
        cout << "Please the number of the desired function or 0 if you want to close the app: \n";
        funcSelect = IntEnterNumber("Введите вариант: ");
        switch (funcSelect){
            case 0:
                return 0;
            case 1:
                is_zigzag_sequence();
                break;
            case 2:
                is_arith_progression();
                break;
            case 3:
                table_funcion();
                break;
            case 4:
                sum_line();
                break;
            case 5:
                find_count();
                break;
        }
    }
    return 0;
}