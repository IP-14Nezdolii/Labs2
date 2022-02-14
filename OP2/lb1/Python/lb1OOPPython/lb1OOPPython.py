import module1

print ("Для введення тексту у файл з нового рядка натисніть Enter.\n"
        "Для завершення введення тексту у файл в кінці введеного рядка натисніть Ctrl+y, а потім Enter.\n")

fileName = input("Введіть ім'я файлу: ")
print ("Введіть текст: ")
module1.outText(fileName)

newfileName = input("\nВведіть ім'я другого файлу: ")
module1.newText(fileName,newfileName)

print ("\nТекст у першому файлі: ")
module1.inText(fileName)
print ("\nТекст у другому файлі: ")
module1.inText(newfileName)

print ("\nДодати текст у перший файл: ")
module1.appText(fileName)
print ("\nТекст у першому файлі: ")
module1.inText(fileName)
