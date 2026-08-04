import socket

ESP32_IP = "192.168.2.233"
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

while True:
    msg = ""
    while(msg != "-1"):
        msg = input("Send: ")
        sock.sendto(msg.encode(), (ESP32_IP, 1234))
    