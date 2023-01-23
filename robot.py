from motor import Motor

class Robot:
    def __init__(self):
        self.motor1 = Motor(18, 19, 16)
        self.motor2 = Motor(20, 21, 17)
        self.motor3 = Motor(13, 12, 15)
        self.motor4 = Motor(11, 10, 14)
        self.speed = 0
        self.old_msg = "stop"
                
    def steer_motors(self, msg):
        print(msg)
        print(self.speed)

        if msg == "forward":
            self.motor1.run('forward', self.speed)
            self.motor2.run('forward', self.speed)
            self.motor3.run('forward', self.speed)
            self.motor4.run('forward', self.speed)
        elif msg == "back":
            self.motor1.run('back', self.speed)
            self.motor2.run('back', self.speed)
            self.motor3.run('back', self.speed)
            self.motor4.run('back', self.speed)
        elif  msg == "left":
            pass
        elif msg == "right":
            pass
        elif msg == "stop":
            self.motor1.run('stop', self.speed)
            self.motor2.run('stop', self.speed)
            self.motor3.run('stop', self.speed)
            self.motor4.run('stop', self.speed)
        elif msg == "L":
            pass
        elif  msg == "R":
            pass

    def decode_message(self, msg):
        message = msg.split('_')
        if message[0] != 'speed':
            self.old_msg = message[0]
            self.steer_motors(message[0])
        else:
            self.speed = int(message[1])
            self.steer_motors(self.old_msg)