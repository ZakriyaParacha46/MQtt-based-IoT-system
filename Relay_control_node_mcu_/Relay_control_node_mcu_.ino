// This sketch is made by Zakriya asif paracha for istructable,link "https://www.instructables.com/member/ZakriyaP/" 
// If you want any arduino,respberry, python or C, IOT or Robotics project, chack out my fiver account "https://www.fiverr.com/zakriyaparacha "
// If you have any question related to this project, comment it no my instructalbles.

#include <ESP8266WiFi.h>   //include important libraries
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define WLAN_SSID       ""  //enter your wifi network id here 
#define WLAN_PASS       ""  //enter your wifi network pasword here

#define AIO_SERVER      "mqtt.eclipseprojects.io"   //setting up the server
#define AIO_SERVERPORT  1883                  
#define AIO_USERNAME    ""
#define AIO_KEY         ""

int states[] = {0,0,0,0,0,0,0,0};    //inicializing stats
int gpio[] ={16,5,4,0,2,14,12,13};   //selecting gpios for relays
int y;
String command ="";
String x;
char outC[4];
int togS;

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Publish state = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "");   ///// enter the state topic, you added on your app under global variable "Topic State"
Adafruit_MQTT_Subscribe cmd = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME ""); ///// enter the cmd topic, you added on your app under global variable "Topic Cmd"

void MQTT_connect() {           //this function is to make the node  connect with mqtt server 
  int8_t ret;
  if (mqtt.connected()) {
    return;
  }
  Serial.print("Connecting to MQTT... ");
  
  
  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) {
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(3000);  
       retries--;
       if (retries == 0) {
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}



void SEND_STATE()            {                          //this function send all the states off gpios
  for (int i = 0; i <8; i++) {   
         x=String(i+1)+ "-" +String(states[i]);
          x.toCharArray(outC,4);
          state.publish(outC);
         
                           }}

                           
void setup() {                                       
  for (int i = 0 ; i<8;i++){ pinMode(gpio[i], OUTPUT);}
  Serial.begin(115200);                                       //boud rate must me 115200
  delay(10);
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");                              //conecting to wifi
  Serial.println(WLAN_SSID);
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("IP address: "); Serial.println(WiFi.localIP());
  mqtt.subscribe(&cmd);                                       //subscribing command topic
}




void loop() {
 state.publish("ping"); // we will ping the server to keep connection alive
  MQTT_connect();
//READING STUFFFFFFF###########################################################
  Adafruit_MQTT_Subscribe *subscription;
  while ((subscription = mqtt.readSubscription(1000))) {
    
    if (subscription == &cmd) {
      Serial.print(F("Got:"));
      command=(char*)cmd.lastread;
      Serial.println(command);
       
       if (command=="Data_Req"){SEND_STATE();}
       
       else{
         togS=int(command[0])-49;
         Serial.print(togS);
         Serial.print("\n");
                                                                             
         if(states[togS]==0){states[togS]=1;}
         else if(states[togS]==1){states[togS]=0;}
         for (int i =0; i<8 ; i++){digitalWrite(gpio[i], states[i]);}
         x=String(togS+1)+ "-" +String(states[togS]);
         x.toCharArray(outC,4);
         state.publish(outC);
         }
         }
    }
}
