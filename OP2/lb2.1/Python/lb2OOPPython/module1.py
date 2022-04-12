def outList(fileName):       #функція запису/перезапису списку автомобілів у файлі; якщо файл відсутній, то він створюється                          
    outFile = open(fileName,'wb')
    n = int(input("Введіть кількість автомобілів: "))
    for i in range (n):
        name = input("Введіть назву автомобіля: ")
        releaseD = input("Введіть дату випуску: ")
        saleD = input("Введіть дату початку продажу: ")
        string = name + " " + releaseD + " " + saleD
        outFile.write((string + '\n').encode())
    outFile.close()

def inList(fileName):                #функція виведення списку автомобілів із файлу
    inFile = open(fileName,'rb')
    print("\nСписок автомобілів:")
    for string in inFile:            #поки не закінчаться рядки
        print((string.decode()).strip())
    inFile.close()

def newList(fileName1, fileName2):     #функція створення нового бінарного файлу на основі першого бінарного файлу з урахуванням умов завдання
    inFile = open(fileName1,'rb')
    outFile = open(fileName2,'wb')

    for string in inFile:
        string = (string.decode()).strip()
        d = data(string)
        dif = (d[1][2]- d[0][2])*365 + (d[1][1] - d[0][1])*30 + (d[1][0] - d[0][0]);
        if (dif <= 60):
            outFile.write((string + '\n').encode())

    inFile.close()
    outFile.close()

def appList(fileName):      #функція додання елементів списку у бінарний файл
    outFile = open(fileName,'ab')
    n = int(input("Введіть як кількість автомобілів ви хочете додати: "))
    for i in range (0,n):
        name = input("Введіть назву автомобіля: ")
        releaseD = input("Введіть дату випуску: ")
        saleD = input("Введіть дату початку продажу: ")
        string = name + " " + releaseD + " " + saleD
        outFile.write((string + '\n').encode())
    outFile.close()

def inList2(fileName):
    inFile = open(fileName,'rb')
    year = int(input("Введіть рік: "))
    print("\nСписок автомобілів, які були випущені не раніше вказаного року:")
    for string in inFile:
        string = (string.decode()).strip()
        d = data(string)
        if (d[0][2] >= year):
            print(string)
    inFile.close()

def data(string):               #функція заповнення масиву даними зі списку
    releaseD = []
    saleD = []

    for i in range(len(string)):
        if string[i].isdigit() == True : break

    releaseD.append(string[i:i+2])
    releaseD.append(string[i+3:i+5])
    releaseD.append(string[i+6:i+10])
    saleD.append(string[i+11:i+13])
    saleD.append(string[i+14:i+16])
    saleD.append(string[i+17:i+23])

    releaseD = [int(item) for item in releaseD]
    saleD = [int(item) for item in saleD]

    return releaseD, saleD

