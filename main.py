from machine import UART
from time import sleep
from robot import Robot
import os

uart = UART(0, 9600)
robot = Robot()


b = None
msg = ""


while True:
    if uart.any():
        b = uart.readline()
        try:
            msg = b.decode('utf-8')
            print(">> " + msg)
            robot.decode_message(msg)
        except:
            pass