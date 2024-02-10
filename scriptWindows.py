import serial
import time
import psutil

arduino = serial.Serial(port='COM4', baudrate=9600, timeout=.1)

def write_read(x): 
    # send
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05) 

    # return
    data = arduino.readline() 

    return data 

while True: 
    cpu_percent = psutil.cpu_percent(interval=1)
    memory_usage = psutil.virtual_memory()
    data = f"CPU: {cpu_percent}% - RAM: {memory_usage.percent}"
    
    # call arduino
    value = write_read(data) 
    
    # show result
    print(value)
    
    time.sleep(1)
    

