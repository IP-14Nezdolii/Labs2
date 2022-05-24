#include <iostream>
#include "Poly.h"
#include "Windows.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    float num,
            a,
            b,
            c,
            d;

    std::cout << "Введіть перший коефіцієнт другого полінома: ";
    std::cin >> a;
    std::cout << "Введіть другий коефіцієнт другого полінома: ";
    std::cin >> b;
    std::cout << "Введіть третій коефіцієнт другого полінома: ";
    std::cin >> c;
    std::cout << "Введіть четвертий коефіцієнт другого полінома: ";
    std::cin >> d;
    std::cout << std::endl;

    Poly_4 P1;
    Poly_4 P2(a, b, c, d);
    Poly_4 P3(P2);

    std::cout << "Перший поліном: ";
    output_Poly(P1);    
    std::cout << "Другий поліном: ";
    output_Poly(P2);   
    std::cout << "Третій поліном: ";
    output_Poly(P3);
    std::cout << std::endl;
   
    std::cout << "Введінь число на яке будуть збільшені коефіцієнти першого полінома: ";
    std::cin >> num;
    P1 += num;

    std::cout << "Введінь число на яке будуть зменшені коефіцієнти другого полінома: ";
    std::cin >> num;
    P2 -= num;
    std::cout << std::endl;
    
    std::cout << "Перший поліном: ";
    output_Poly(P1);
    std::cout << "Другий поліном: ";
    output_Poly(P2);
    std::cout << std::endl;

    if(P2 == P1)
    {
         std::cout << "Всі коефіцієнти першого та другого полінома рівні\n";
    }
    else std::cout << "Не всі коефіцієнти першого та другого полінома рівні\n";

    std::cout << "Введінь значення точки для обчислення значення третього полінома: ";
    std::cin >> num;
    std::cout << "Значення полінома у точці "<<num<<" : "<< P3.count(num);
}
