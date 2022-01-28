from socket import *


server = socket(AF_INET,SOCK_STREAM)
server.bind(('localhost',5000))
server.listen()
print(' Server is listening at port number 5000')
connection,address=server.accept()
print('Now server is connected to client')
while True:
     input_data=input('Server msg:')
     connection.send(bytes(input_data,'utf-8'))
     rec_Data=connection.recv(1024).decode()
     print("Client msg: ", rec_Data)
     if not input_data:
         break

connection.close(server)



