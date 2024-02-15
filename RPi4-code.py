import paho.mqtt.client as mqtt
 
mqttBroker = "xxx.xxx.xxx.xxx"
mqttPort = 1883
mqttUsername = "username"
mqttPassword = "password"
 
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe("lm35/temperature")
 
def on_message(client, userdata, msg):
    print(msg.payload.decode())
 
client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION1)
client.on_connect = on_connect
client.on_message = on_message
 
client.username_pw_set(mqttUsername, password=mqttPassword)
client.connect(mqttBroker, mqttPort, 60)
 
client.loop_forever()
