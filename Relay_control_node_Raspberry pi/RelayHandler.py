import RPi.GPIO as GPIO
import time

def handleRelays(commandsList2):
    try:
        commandsList=[]
        for value in commandsList2:
            commandsList.append(str(value))
        GPIO.setmode(GPIO.BCM)
        GPIO.setwarnings(False)
        GPIO.setup(2,GPIO.OUT)
        GPIO.setup(4,GPIO.OUT)
        GPIO.setup(14,GPIO.OUT)
        GPIO.setup(15,GPIO.OUT)
        GPIO.setup(18,GPIO.OUT)
        GPIO.setup(24,GPIO.OUT)
        GPIO.setup(23,GPIO.OUT)
        GPIO.setup(25,GPIO.OUT)
        
        led1=commandsList[0]
        if led1=='1':
            GPIO.output(2,GPIO.HIGH)
        elif led1=='0':
            GPIO.output(2,GPIO.LOW)
            
        led2=commandsList[1]
        if led2=='1':
            GPIO.output(4,GPIO.HIGH)
        elif led2=='0':
            GPIO.output(4,GPIO.LOW)
            
        led3=commandsList[2]
        if led3=='1':
            GPIO.output(14,GPIO.HIGH)
        elif led3=='0':
            GPIO.output(14,GPIO.LOW)
            
        led4=commandsList[3]
        if led4=='1':
            GPIO.output(15,GPIO.HIGH)
        elif led4=='0':
            GPIO.output(15,GPIO.LOW)
            
        led5=commandsList[4]
        if led5=='1':
            GPIO.output(18,GPIO.HIGH)
        elif led5=='0':
            GPIO.output(18,GPIO.LOW)

        led6=commandsList[5]
        if led6=='1':
            GPIO.output(23,GPIO.HIGH)
        elif led6=='0':
            GPIO.output(23,GPIO.LOW)
        
        led7=commandsList[6]
        if led7=='1':
            GPIO.output(24,GPIO.HIGH)
        elif led7=='0':
            GPIO.output(24,GPIO.LOW)

        led8=commandsList[7]
        if led8=='1':
            GPIO.output(25,GPIO.HIGH)
        elif led8=='0':
            GPIO.output(25,GPIO.LOW)

        #GPIO.cleanup()
        return True
    
    except Exception as E:
        print(E)
        return False

