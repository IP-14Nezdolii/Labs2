import class1

def input_m(mas):
	for i in range(len(mas)):
		print("Введіть кординати нового вектора номер "+str(i + 1))
		mas[i].input()

def output_m(mas):
	for i in range(len(mas)):
		print("Кординати вектора номер " + str(i + 1))
		print(mas[i])