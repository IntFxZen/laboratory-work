#include <stdio.h>
#include <locale.h>
#include <math.h>

void ex1(){
    int shelfs;
    float width, height, depth ;
    double shelfs_V, back_V, sidewall_V, cap_V, door_V,
    back_thickness = 0.005, sidewall_thickness = 0.015,
    cap_thickness = 0.015, door_thickness = 0.01, result,
    DVP_M, DSP_M, WOOD_M, DVP_p, DSP_p, WOOD_p;

    // Плотности ДВП, ДСП, дерева
    DVP_p = 820;
    DSP_p = 800;
    WOOD_p = 650;

    // Ввод данных
    printf("Введите высоту шкафа(180-220), ширину, глубину(50-90), :\n");
    scanf("%f %f %f", &height, &width, &depth);

    // Перевод в метры
    height /= 100;
    depth /= 100;
    width /= 100;

    // Полки
    shelfs = (int)(height / 0.4) - 1; // Количество полок
    shelfs_V = (width * depth * 0.015) * shelfs;
    // Задняя стенка
    back_V = height * width * back_thickness;
    // Боковина
    sidewall_V = (depth * height * sidewall_thickness) * 2;
    // Крышка
    cap_V = (depth * width * cap_thickness) * 2;
    // Дверь
    door_V = (width * height * door_thickness);
    // Подсчет масс
    DVP_M = back_V * DVP_p;
    DSP_M = (sidewall_V + cap_V + shelfs_V) * DSP_p;
    WOOD_M = door_V * WOOD_p;
    result = DSP_M+DVP_M+WOOD_M;

    printf("Масса шкафа равна %f кг", result);
}


void whoCan(int x1, int y1, int x2, int y2){
    if (((abs(x2-x1) <= 1) && (abs(y2-y1) <= 1))){
        printf("Король может перейти на эту клетку за один ход\n");
    }
    if((x2 == x1 ) || (y2 == y1) || (abs(x2 - x1)) == (abs(y2-y1))){
        printf("Ферзь может перейти на эту клетку за один ход\n");
    }
    if ((x2 == x1 ) || (y2 == y1)){
        printf("Ладья может перейти на эту клетку за один ход\n");
    }
    if ((abs(x2 - x1)) == (abs(y2-y1))){
        printf("Слон может перейти на эту клетку за один ход\n");
    }
    if (((abs(x2-x1) == 2) && (abs(y2 - y1) == 1) || (abs(y2-y1) == 2) && (abs(x2 - x1) == 1)) && (x2 != x1 && y2 != y1)){
        printf("Конь может перейти на эту клетку за один ход\n");
    }
}

void king(int x1, int y1, int x2, int y2){
    if ((abs(x2-x1) <= 1) && (abs(y2-y1) <= 1)){
        printf("Король может перейти на эту клетку за один ход");
    }
    else{
        printf("Выбранная Вами фигура не может перейти на эту клетку за один ход\n");
        whoCan(x1, y1, x2, y2);
    }
}

void queen(int x1, int y1, int x2, int y2){
    if ((x2 == x1 ) || (y2 == y1) || (abs(x2 - x1)) == (abs(y2-y1))){
        printf("Ферзь может перейти на эту клетку за один ход");
    } else {
        printf("Выбранная Вами фигура не может перейти на эту клетку за один ход\n");
        whoCan(x1, y1, x2, y2);
    }
}

void rook(int x1, int y1, int x2, int y2){
    if ((x2 == x1 ) || (y2 == y1)){
        printf("Ладья может перейти на эту клетку за один ход");
    } else{
        printf("Выбранная Вами фигура не может перейти на эту клетку за один ход\n");
        whoCan(x1, y1, x2, y2);
    }
}

void bishop(int x1, int y1, int x2, int y2){
    if ((abs(x2 - x1)) == (abs(y2-y1))){
        printf("Слон может перейти на эту клетку за один ход");
    } else{
        printf("Выбранная Вами фигура не может перейти на эту клетку за один ход\n");
        whoCan(x1, y1, x2, y2);
    }
}

void knight(int x1, int y1, int x2, int y2){
    if(((abs(x2-x1) == 2) && (abs(y2 - y1) == 1) || (abs(y2-y1) == 2) && (abs(x2 - x1) == 1)) && (x2 != x1 && y2 != y1)){
        printf("Конь может перейти на эту клетку за один ход");
    } else{
        printf("Выбранная Вами фигура не может перейти на эту клетку за один ход\n");
        whoCan(x1, y1, x2, y2);
    }
}


void ex2(){
    int x1, y1, x2, y2, f;
    printf("Введите координаты первой клетки:\n");
    scanf("%d %d", &x1, &y1);
    printf("Введите координаты второй клетки:\n");
    scanf("%d %d", &x2, &y2);
    printf("Выберите фигуру (король(1), ферзь(2), ладья(3), слон(4), конь(5)):\n");
    scanf("%d", &f);
    switch (f) {
        case 1: king(x1, y1, x2, y2); break;
        case 2: queen(x1, y1, x2, y2); break;
        case 3: rook(x1, y1, x2, y2); break;
        case 4: bishop(x1, y1, x2, y2); break;
        case 5: knight(x1, y1, x2, y2); break;
    }
}

// Функция для выбора задачи
void select(){
    int number;
    printf("Введите номер задачи(1, 2):\n");
    scanf("%d", &number);
    switch (number) {
        case 1: ex1(); break;
        case 2: ex2();
    }
}

int main(){
    setlocale(LC_ALL, "Russian");
    select();
    return 0;
}
