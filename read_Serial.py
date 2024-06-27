import serial
import time

# Sesuaikan dengan port serial yang digunakan oleh Arduino
SERIAL_PORT = 'COM3'
BAUD_RATE = 9600

def read_from_serial():
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE)
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').rstrip()
            print(line)
            with open('data.txt', 'w') as f:
                f.write(line)
        time.sleep(1)

if __name__ == '__main__':
    read_from_serial()
