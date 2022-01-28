from socket import*

client = socket()
client.connect(('localhost',5000))
print('Now client is connected to server')

while True:

     rec_Data = client.recv(1024).decode()
     print('Server msg :',rec_Data)
     input_data=input('client msg:')
     client.send(bytes(input_data, 'utf-8'))

client.close(client)
