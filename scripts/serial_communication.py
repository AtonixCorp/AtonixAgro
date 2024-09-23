import serial
import time

# Initialize serial communication
ser = serial.Serial('/dev/ttyS0', 9600, timeout=1)
ser.flush()

while True:
    ser.write(b"Hello from Raspberry Pi\n")
    if ser.in_waiting > 0:
        line = ser.readline().decode('utf-8').rstrip()
        print(f"Received: {line}")
    time.sleep(1)