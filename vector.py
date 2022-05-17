import math
class TVector:
    def __init__(self, x, y, z=0):
        self.x = x #базовий клас 
        self.y = y
        self.z = z
class R2(TVector):
    def __init__(self, x, y):
        super().__init__(x,y) #створення вектора 2D 
    def scalar(self, R2):
        res = self.x*R2.x + self.y*R2.y
        return res
    def length(self):
        res = math.sqrt(self.x*self.x + self.y*self.y) 
        return res  
    def vectorOut(self):
        print("vector R2: "+str(self.x)+" "+str(self.y))
class R3(TVector):
    def __init__(self, x, y, z):
        super().__init__(x,y, z) #створення вектора 3D 
    def scalar(self, R3):
        res = self.x*R3.x + self.y*R3.y + self.z*R3.z
        return res
    def length(self):
        res = math.sqrt(self.x*self.x + self.y*self.y + self.z*self.z) 
        return res  
    def vectorOut(self):
        print("vector R3: "+str(self.x)+" "+str(self.y)+" "+str(self.z))                  