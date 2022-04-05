import pickle
import os
def create_file(filename):
    train_data = []
    days = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
    if os.stat(filename).st_size == 0: f = open(filename, 'wb')#перевірка чи файл пустий
    else:
        #вибір відкрити файл в режимі дозапису чи перезаписати
        add = input("There is already some information in the file, to add something enter a, to rewrite it press enter ")
        if add: f = open(filename, 'ab')
        else: f = open(filename, 'wb')
    for day in days:#створення руху поїздів на кожний день
        add = input("To add trains for " + day + "  press a, to skip press enter ")
        if add:#перевірка чи додається інформація
            num = int(input("Amount "))#кількість поїздів в 1 день
            for x in range(num):
                 train_day = day
                 number = input("Enter train number ")
                 departure = input("Enter departure ")
                 arrival = input("Enter arrival ")
                 dep_time = input("Enter departure time ")
                 arr_time = input("Enter arrival time ")
                 train = [train_day, departure, arrival, dep_time, arr_time, number]
                 train_data.append(train)#додавання інформації про рейс до усіх даних
                
    pickle.dump(train_data, f)#запис даних у файл
    f.close
 
def out_file(filename):
    print("\nList of trains\n")
    days = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
    f = open(filename, 'rb')
    train_data = []
    while True:
        try:
            train_data.append(pickle.load(f))#завантаження усіх рейсів з файлу
        except EOFError:
            break
    f.close
    for day in days:
         print("Trains for " + day)
         for trains in train_data:
            for train in trains:
                 if(day==train[0]):#виведення інформації по дням
                     print(train[5] + " "+ train[1] + "-" + train[2] + " : " + train[3] + " - " + train[4])
         print()
         
def new_file(filename1, filename2):
    f1 = open(filename1, 'rb')
    train_data = []
    while True:
        try:
            train_data.append(pickle.load(f1))
        except EOFError:
            break
    f1.close
    f2 = open(filename2, 'wb')
    train_data2 = []
    for trains in train_data:
            for train in trains:
             dep_time = int(train[3][0:2])#час відправлення
             if dep_time<=10 or dep_time>=18:#перевірка чи час задовольняє умову завдання
                 train_data2.append(train)#додавання поїзда в до усіх даних
        
    pickle.dump(train_data2, f2)#запис перевірених даних у новий файл
    f2.close
   
