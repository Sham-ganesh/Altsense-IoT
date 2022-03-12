from time import sleep
import threading

def fun1():
    for i in range(4):
        print("Hi ")
        sleep(2)

def fun2():
    for i in range(4):
        print("Hello ")
        sleep(2)

def fun3():
    
    for i in range(4):
        
        print("World ")
        sleep(2)

one = threading.Thread(target=fun1)
two = threading.Thread(target=fun2)
three = threading.Thread(target=fun3)

one.start()
two.start()
three.start()
