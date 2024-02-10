import serial
import time

arduino = serial.Serial(port='COM4', baudrate=9600, timeout=.1)

def write_read(x): 
    
    # send
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05) 
    
    # return
    data = arduino.readline() 
    
    return data 

while True: 
    
    # set data input
    data = input("Enter a la data: ") 
    
    # call arduino
    value = write_read(data) 
    
    # show result
    print(value)
    

