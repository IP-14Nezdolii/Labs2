import class1 as c
import module1 as m

mas1 = [c.R2Vector() for i in range(3)]
mas2 = [c.R3Vector() for i in range(4)]

sum = float(0)

print("Введення трьох двовимірних векторів")
m.input_m(mas1)
print("Введення чотирьох тривимірних векторів")
m.input_m(mas2);

print("\nДвовимірні вектори :")
m.output_m(mas1);
print("\nТривимірні вектори :")
m.output_m(mas2);

print("")   
for i in range(1,3):
    if mas1[0].parall(mas1[i]) == True:
        print("Двовимірний вектор номер "+str(i+1)+" паралельний до вектора номер 1")
        sum += mas1[i].length()
print("Сума довжин векторів паралельних до вектора номер 1: " + str(sum) + "\n")

sum = 0;
for i in range(1,4):
    if mas2[0].perp(mas2[i]) == True:
        print("Тривимірний вектор номер " + str(i+1) + " перпендикулярний до вектора номер 1")
        sum += mas2[i].length()
print("Сума довжин векторів перпендикулярних до вектора номер 1: " + str(sum) + "\n")