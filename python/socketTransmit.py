import socket 

ESP32_IP = "YourEsp32Ip"
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

def transmit(sig):
    sock.sendto(sig.encode(), (ESP32_IP, 1234))