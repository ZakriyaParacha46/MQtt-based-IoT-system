import paho.mqtt.client as mqtt
import paho.mqtt.publish as publish
import sys
Switches=[0,0,0,0,0,0,0,0]
#import RelayHandler as rh
State_topic= "state"   #enter the state topic, you added on your app under global variable "Topic State"
cmd_topic= "cmd"   #enter the cmd topic, you added on your app under global variable "Topic Cmd"


def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    print ("--------------------------")
    client.subscribe(cmd_topic)

def Send_states(states):
    for i in range(8):
     publish.single(State_topic,str(i+1)+"-"+str(states[i]), hostname="mqtt.eclipseprojects.io")

def on_message(client, userdata, msg):
    message=(str(msg.payload)[2])
    print(str(msg.payload))
    if(message=="D"):
        Send_states(Switches)
        print("Data_sent")
        print ("--------------------------")
    else:
        message=int(message)
        if (Switches[message-1]==0):Switches[message-1]=1
        elif (Switches[message-1]==1):Switches[message-1]=0
        publish.single(State_topic ,str(message)+"-"+str(Switches[message-1]), hostname="mqtt.eclipseprojects.io")
        #rh.handleRelays(Switches)    //uncomment if you have relays on Raspberry pi pins
        print (Switches)
        print ("--------------------------")
        
print("Initializing the switches...")
#rh.handleRelays(Switches)
Send_states(Switches)

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message

client.connect("mqtt.eclipseprojects.io", 1883, 60)
client.loop_forever()










