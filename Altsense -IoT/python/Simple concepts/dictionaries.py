import time
#[]-the given data is list
#{}-the given data is a dictionary
#the value of key can be accessed with name of the key
fruits = {"mango":200,"apple":140,"lemon":45,"mango":100 }
print(fruits["mango"])
#the value of latetst key will be printed
i=0
for i in fruits.items():
    print(i)
    
#if fruits.values() is given in  for loop keys will be printed
#if fruits.keys() is given in for loop valuues will be printed
