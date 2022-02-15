def write_file(filename, filemode):
     f = open(filename, filemode)#відкриття файлу
     us_str = ' '
     print("Enter text, double Enter to stop")
     while us_str:#умова введення рядків
         us_str = input()
         if us_str:
             f.write(us_str + "\n")
     f.close()


def file_out(filename):
    with open(filename, 'r+') as f:
        for line in f:
            print(line)#виведення файлу


def get_n():
    n = int(input('Enter amount of words '))
    return n


def new_file(file1, file2, amount):
    f1 = open(file1, 'r')#відкриття вхідного файлу для читання
    f2 = open(file2, 'w')#відкриття нового файлу для запису
    text = f1.read()
    word_list = text.split()#слова вхідного файлу
    checked_words = list()
    for word in word_list:
        counter = 0 #кількість однакових слів
        for key, word_check in enumerate(word_list):
            if word == word_check and word_check!='':
                counter += 1
                if counter>1:
                    word_list[key] = ''
        if counter > amount: #перевірка умови задачі
            checked_words.append(word + ' ') #слова, що будуть записані у 2 файл
    checked_words.sort(key=lambda s: len(s)) #сортування по довжині
    for word in checked_words:
        f2.write(word)#запис слів у новий файл
    f1.close()
    f2.close()

symb = input('Enter w - write in file, a - add text ')
write_file('input.txt', symb)#введення рядків користувачем
n = get_n()#кількість слів
new_file('input.txt', 'result.txt', n)#створення нового файлу
print('\nFile1:')
file_out('input.txt')#виведення вхідного файлу
print('\nFile2:')
file_out('result.txt')#виведення результату
