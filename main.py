import vector
vec = [vector.R2(5, 8), vector.R2(2, 1), vector.R3(7, 9, 5), vector.R3(5, 1, 4)]
for v in vec:
    v.vectorOut() #виведення координат вектора
res = vec[2].scalar(vec[3]) + vec[0].scalar(vec[1]) + vec[2].length()
print(str(int(res)))    