def outText(name):                                                                                      ##функція запису/перезапису тексту у файлі; якщо файл відсутній, то він створюється                          
    outFile = open(name,'w')
    works = True
    while works:
        string = input()                                                                                ##допоміжний "буферний" рядок
        if (string.rfind(chr(25)) == (len(string)-1)):                                                  ##якщо заданий символ буде в кінці рядка
            string = string[0:len(string)-1]                                                            ##зменшити рядок на 1 символ
            outFile.write(string + '\n')                                                                ##записати рядок у файл
            works = False
        else: outFile.write(string + '\n')
    outFile.close()

def inText(name):                                                                                       ##функція виведення тексту із файлу
    inFile = open(name,'r')
    for string in inFile:                                                                               ##поки не закінчаться рядки
        print(string.strip())
    inFile.close()

def newText(name1, name2):                                                                              ##функція створення нового текстового файлу на основі першого текстового файлу з урахуванням умов завдання
    inFile = open(name1,'r')
    outFile = open(name2,'w')
    for string in inFile:                                                                               ##поки не закінчаться рядки
        a = len(string)-2                                                                               ##позиція останнього символу
        if ((string.rfind(' ') != a) and (string.rfind(',') != a) and (string.rfind('.') != a)):        ##якщо в кінці рядка відсустні пробіл, крапка чи кома
           string = "-" +'\n'
        outFile.write(string)
    inFile.close()
    outFile.close()

def appText(name):                                                                                      ##функція додання тексту у файл
    outFile = open(name,'a')
    while True:
        string = input()                                                                                ##допоміжний "буферний" рядок
        if (string.rfind(chr(25)) == (len(string)-1)):                                                  ##якщо заданий символ буде в кінці рядка
            string = string[0:len(string)-1]                                                            ##зменшити рядок на 1 символ
            outFile.write(string + '\n')                                                                ##записати рядок у файл
            break
        outFile.write(string + '\n')
    outFile.close()
