from machine import Pin, PWM

class Motor:
    def __init__(self, pin1, pin2, enable):
        self.pinId1 = pin1
        self.pinId2 = pin2
        self.enable_pin_id = enable
        self.__max_duty__ = 65025
        
        self.dir1 = Pin(self.pinId1, Pin.OUT)
        self.dir2 = Pin(self.pinId2, Pin.OUT)
        
        self.pwm = PWM(Pin(self.enable_pin_id))
        self.pwm.freq(1000)
        self.pwm.duty_u16(0)
    
    def run(self, direction, speed):
        duty = self.__get_duty__(speed)
        
        if direction == 'forward':
            self.pwm.duty_u16(duty)     
            self.dir1.value(1)
            self.dir2.value(0)
        elif direction == 'back':
            self.pwm.duty_u16(duty)
            self.dir1.value(0)
            self.dir2.value(1)
        else:
            self.pwm.duty_u16(0)
            self.dir1.value(1)
            self.dir2.value(1)
            
    def __get_duty__(self, pwm):
        return int(pwm * self.__max_duty__ / 100)
