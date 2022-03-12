import socket

s=socket.socket()

s.bind(('0.0.0.0',8090))
s.listen(0)

while True:
    client ,addr = s.accept()
    while True:
        content = client.recv(40)
        print(content)
        break
    print("closing Connection")
    client.close()

#append function used to input data
