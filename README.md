# MQtt-based-IoT-system
Multiplatform IoT code for Android, Raspberry pi , and Node MCU esp8266 for controlling 8 Digital pins through Android to The receiver devices.

How To use:
1- .aia file
 Go to MIT App Inventor and upload the aia file.
 Go to Blocks and enter TopicState amd TopicCmd in the variables.
 Note down your TopicState amd TopicCmd.
 Save the .apk file on your phone and you are good to go.
 
2- .Py file
 open for Edit the Deamon.py .
 change State_topic and cmd_topic variables to the variables set in the .apk file.
 save the file and run.
 Note: if you running it on raspberry pi ,uncoment the calling of relay handler in line#31

3- .ino file
 open the .Relay_control_node_mcu_.ino file.
 Set your WLAN_SSID and WLAN_PASS in line# 14 and 15.
 Set the state and topic in line# 27 and 28.
 Save and upload your file on Node MCU.
