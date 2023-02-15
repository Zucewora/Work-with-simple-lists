#include <cmath>
#include <algorithm>
#include <Windows.h>
#include <iostream>
#include <string>

#pragma warning (disable :4996)
using namespace std;

int proverka(int x) {
    if (x > 0) {
        return x;
    }
    else {
        while (x <= 0) {
            cout << "Неверное числовое значение" << endl;
            cout << "Введите числовое значение" << endl;
            cin >> x;
        }
        return x;
    }
}
int proverka_Menu(int x) {
    if (((x > 0) && (x <= 7)) || (x == 8)) {
        return x;
    }
    else {
        while (((x <= 0) || (x >= 7))) {
            if (x == 8) {
                break;
            }
            cout << "Неверный пункт меню" << endl;
            cout << "Введите пункт меню" << endl;
            cin >> x;
        }
        return x;
    }
}

void Menu() {
    //Карандаши (жёсткость (строка: HB, 2H,..), цвет, цена)
    cout << endl;
    cout << "ПУНКТЫ МЕНЮ" << endl;
    cout << "1. Ввести структуру " << endl;
    cout << "2. Вывести структуру " << endl;
    cout << "3. Сортировка по цвету карандаша " << endl;
    cout << "4. Сортировка по цене карандаша " << endl;
    cout << "5. двойной сортировки -- цена совпадает, то сортировка по цвету " << endl;
    cout << "6. Самая большая жесткость из введенных" << endl;
    cout << "7. Вывод количества пар разных цветов карандашей " << endl;
    cout << "8. Выход" << endl;
    cout << "Введите номер пункта, который вам нужен" << endl;
}

struct Pen {
    double price; // цена для карандаша
    char color[10]; //цвет карандаша 
};
struct Hardness {
    int nPens;
    string hardness; //HB B B2 жесткость карандаша 
    int count_of_pair;
    struct Pen Pens[100]; // количество карандашей
};

int main() {
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N = 1;
    int Punkt_menu;
    struct Pen buff;
    struct Hardness* M = new struct Hardness[N];
    
    do {
        cout << "Введите пункт меню" << endl;
        Menu();

        cin >> Punkt_menu;
        Punkt_menu = proverka_Menu(Punkt_menu);
        
        switch (Punkt_menu) {
        case 1: {
            cout << "Введите количество типов твердости карандашей" << endl;
            cin >> N;
            N = proverka(N);

            delete[] M;
            M = new struct Hardness[N];

            for (int i = 0; i < N; i++) {
                cout << "Введите твердость карандаша  " << endl;
                cin >> M[i].hardness;
                cout << "Введите количество карандашей для твердости ->" << M[i].hardness << endl;
                cin >> M[i].nPens;
                M[i].nPens = proverka(M[i].nPens);
                
                for (int j = 0; j < M[i].nPens; j++) {
                    cout << "Введите цвет для карандаша" << endl;
                    cin >> M[i].Pens[j].color;
                    cout << "Введите цену для карандаша -> " << M[i].Pens[j].color << endl;
                    cin >> M[i].Pens[j].price;
                    M[i].Pens[j].price = proverka(M[i].Pens[j].price);
                }
            }
            break;
        }
        case 2: {
            for (int i = 0; i < N; i++) {
                cout << "Жесткость - " << M[i].hardness << endl;
                for (int j = 0; j < M[i].nPens; j++) {
                    cout << "Цвет карандаша -> " << M[i].Pens[j].color << endl;;
                    cout << "Цена за карандаш цвет ->  " << M[i].Pens[j].color << " это " << M[i].Pens[j].price << endl;
                }
            }

            break;
        }
        case 3: {
            //Сортировка по цвету карандаша
            for (int d = 0; d < N; d++) {
                for (int i = 0; i < M[d].nPens - 1; i++) {
                    for (int j = i + 1; j < M[d].nPens; j++) {
                        strupr(M[d].Pens[i].color);
                        strupr(M[d].Pens[j].color);
                        if (strcmp(M[d].Pens[i].color, M[d].Pens[j].color) > 0) {
                            buff = M[d].Pens[i];
                            M[d].Pens[i] = M[d].Pens[j];
                            M[d].Pens[j] = buff;
                        }
                    }
                }
            }
            break;
        }
        case 4: {
            cout << "4. Сортировка по цене карандаша " << endl;
            for (int d = 0; d < N; d++) {
                for (int i = 0; i < M[d].nPens - 1; i++) {
                    for (int j = i + 1; j < M[d].nPens; j++) {
                        if (M[d].Pens[i].price > M[d].Pens[j].price) {
                            buff = M[d].Pens[i];
                            M[d].Pens[i] = M[d].Pens[j];
                            M[d].Pens[j] = buff;
                        }
                    }
                }
            }
            break;

        }
        case 5: {
            //сортировка по двум признакам 
            // 
            for (int d = 0; d < N; d++) {
                for (int i = 0; i < M[d].nPens - 1; i++) {
                    for (int j = i + 1; j < M[d].nPens; j++) {
                        if (M[d].Pens[i].price == M[d].Pens[j].price) {
                            strupr(M[d].Pens[i].color);
                            strupr(M[d].Pens[j].color);
                            if (strcmp(M[d].Pens[i].color, M[d].Pens[j].color) > 0) {
                                buff = M[d].Pens[i];
                                M[d].Pens[i] = M[d].Pens[j];
                                M[d].Pens[j] = buff;
                            }
                        }
                        else
                        {
                            if (M[d].Pens[i].price > M[d].Pens[j].price) {
                                buff = M[d].Pens[i];
                                M[d].Pens[i] = M[d].Pens[j];
                                M[d].Pens[j] = buff;
                            }
                        }
                    }
                }
            }
            break;

        }
        case 6: {
            const int nPens = 24;
            string hardness_of_pens[nPens] = { "11B", "10B", "9B", "8B","7B", "6B", "5B","4B", "3B", "2B","B","HB", "F", "H", "2H", "3H","4H", "5H","6H","7H", "8H","9H","10H", "11H", };
            //  составили строчку жесткостей карандаша по овзрастанию, если найдет совпадающий то запомнит самый последний элемент в строчке 
            // 11B 10B 9B 8B 7B 6B 5B 4B 3B 2B B F H 2H 3H 4H 5H 6H 7H 8H 9H 10H 11H 
            int X;
            int index_of_last_elem;
            for (int i = 0; i < 24; i++) {
                for (int k = 0; k < N; k++) {
                    transform(M[k].hardness.begin(), M[k].hardness.end(), M[k].hardness.begin(), toupper); // делаем буквы заглавными 
                    if (hardness_of_pens[i] == M[k].hardness) {
                        X = M[k].nPens - 1;
                        index_of_last_elem = k;
                    }
                }
            }
            cout << "the_last_hardest_pen  ->" << M[index_of_last_elem].hardness << " ->>  ";
            cout << M[index_of_last_elem].Pens[X].color << " price -> " << M[index_of_last_elem].Pens[X].price << endl;
            break;
        }
        case 7: {
            for (int d = 0; d < N; d++) {
                M[d].count_of_pair = 0;
                cout << "Количество карандашей для жесткости " << M[d].hardness << " это " << M[d].nPens;
                for (int i = 0; i < M[d].nPens - 1; i++) {
                    for (int j = i + 1; j < M[d].nPens; j++) {
                        strupr(M[d].Pens[i].color);
                        strupr(M[d].Pens[j].color);
                        if ((strcmp(M[d].Pens[i].color, M[d].Pens[j].color) > 0)) {
                            M[d].count_of_pair++;
                        }
                        else {
                            if (strcmp(M[d].Pens[i].color, M[d].Pens[j].color) < 0) {
                                M[d].count_of_pair++;
                            }
                            else {
                                j = M[d].nPens;
                            }
                        }
                    }
                }
                cout << "Количество пар разных цветов " << M[d].count_of_pair << endl;
            }


            break;
        }

                // примеры для ввода:
              // 11B 10B 9B 8B 7B 6B 5B 4B 3B 2B B F H 2H 3H 4H 5H 6H 7H 8H 9H 10H 11H 

              // 3 HB 2 Красный 30 Зеленый 80 B 3 Синий 89 Зеленый 5 Красный 145 4B 4 Зеленый 87 Красный 40 Желтый 8 Синий 1
              // 3 8H 2 Красный 30 Зеленый 30 B 4 Синий 89 Синий 89 Зеленый 5 Красный 145 4B 5 Зеленый 87 Красный 87 Желтый 8 Синий 1 Ораньжевый 8
        //3 8H 2 Красный 30 Зеленый 30 11h 4 Синий 89 Синий 89 Зеленый 5 Красный 145 4B 5 Зеленый 87 Красный 87 Желтый 8 Синий 1 Ораньжевый 8
        //3 8H 2 Красный 30 красный 30 11h 4 Синий 89 Синий 89 Синий 5 Синий 145 4B 5 Зеленый 87 зеленый 87 зеленый 8 зеленый 1 зеленый 8

        } //switch

    } while (Punkt_menu != 8);


    system("pause");
    return 0;




}
