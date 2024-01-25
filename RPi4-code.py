import paho.mqtt.client as mqtt
 
mqttBroker = "192.168.249.249"
mqttPort = 1883
mqttUsername = "d"
mqttPassword = "d"
 
def on_connect(client, userdata, flags, rc):
    print("Connected with result code "+str(rc))
    client.subscribe("lm35/temperature")
 
def on_message(client, userdata, msg):
    print(msg.payload.decode())
 
client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
 
client.username_pw_set(mqttUsername, password=mqttPassword)
client.connect(mqttBroker, mqttPort, 60)
 
client.loop_forever()

