import trains

print()
trains.create_file("input.dat")#запис інформації у файл
trains.out_file("input.dat")#виведення першого створеного файлу
trains.new_file("input.dat", "result.dat")#створення 2 файлу на основі даних, які були введені
print()
print("WINTER LIST")
trains.out_file("result.dat")#виведення результату
