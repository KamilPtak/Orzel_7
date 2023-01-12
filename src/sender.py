import time
import serial
import sys

ser = serial.Serial(
  port='/dev/ttyS0',
  baudrate = 9600,
  parity=serial.PARITY_NONE,
  stopbits=serial.STOPBITS_ONE,
  bytesize=serial.EIGHTBITS,
  timeout=1
)
msg = sys.argv[1]

print("Sending messega via UART")
ser.write(msg.encode('utf-8'))
time.sleep(1)
