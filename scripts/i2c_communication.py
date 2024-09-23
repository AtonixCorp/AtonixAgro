import smbus
import time

bus = smbus.SMBus(1)
address = 0x08

def write_number(value):
    bus.write_byte(address, value)
    return -1

def read_number():
    number = bus.read_byte(address)
    return number

while True:
    write_number(1)
    time.sleep(1)
    number = read_number()
    print(f"Received: {number}")
    time.sleep(1)