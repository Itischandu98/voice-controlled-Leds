import serial
import time
import webcolors
import speech_recognition as sr

# Connects to Arduino Serial Port
ser=serial.Serial('com4',115200)
time.sleep(3)

# reading the voice commands 
r=sr.Recognizer()
with sr.Microphone() as source:
    r.adjust_for_ambient_noise(source)
    print("Please Say 'change the color to ...' ")
    audio=r.listen(source)
    try:     
        cfs=r.recognize_google(audio)
        print("you said... "+cfs)
    except Exception as e:
        print ("Error :"+str(e))
cfs=cfs.replace("change the color to ","")

# get the color value form the webcolors library
rgb=webcolors.name_to_rgb(cfs)
val=str("{},{},{}".format(rgb.red,rgb.green,rgb.blue))
print(val)

#send value to the arduino
ser.write(val.encode())
time.sleep(2)
# print(ser.readline().decode()) ## Print the Serial.println() lines from the arduino code 
ser.close()
