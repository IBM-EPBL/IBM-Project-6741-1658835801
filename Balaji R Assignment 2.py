import random
t=random.randint(1,100)
h=random.randint(1,100)
print("Temperature =",t);
print("humidity =",h);
if t > 50:
    print("Alert : Temparature is Greater than 50 , Stay Safe")
if h > 60:
    print("Alert : Humidity Is greater Than 60 , Stay Safe")