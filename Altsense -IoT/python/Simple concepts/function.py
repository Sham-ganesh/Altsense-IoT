from time import sleep

#defining a function
def fun1():
    for i in range(4):
        print("Sham Ganesh")
        sleep(1)
        fun2()

def fun2():
    j=1
    while(j<5):
        
        print("Dhanush Gupta")
        sleep(2)
        j=j+1
   

fun1()  #calling fun1      

