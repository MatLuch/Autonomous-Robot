# Gesture Controlled Robot

A wireless robot car controlled using real-time hand gestures. The system uses computer vision to detect hand poses and sends movement commands over WiFi to an ESP32-based robotic platform.

## Overview

This project allows a user to control a four-wheel robot using hand gestures. The camera detects the user's hand positions, classifies the gestures, and sends commands wirelessly to the robot.

Gesture controls:

* Two open palms → Move forward
* Two closed fists → Move backward
* One open palm and one closed fist → Turn left
* One closed fist and one open palm → Turn right

## Features

* Real-time hand gesture recognition
* Wireless control using WiFi
* ESP32-based motor control
* Four-wheel drive robot platform
* Computer vision-based interaction
* Dual motor driver control

## Hardware

### Robot

* ESP32 microcontroller
* 4 DC motors
* 2 L293D motor drivers
* Robot chassis
* Motor power supply

### Control System

* Camera for hand tracking
* Computer running gesture recognition software
* WiFi communication between the computer and ESP32

## How It Works

1. The camera captures the user's hand movements.
2. Hand landmarks are processed to determine if each hand is open or closed.
3. The detected gesture is converted into a movement command.
4. The command is transmitted over WiFi to the ESP32.
5. The ESP32 controls the L293D motor drivers to move the four motors.

## System Architecture

```
Camera
   |
   v
Gesture Recognition
   |
   v
WiFi Communication
   |
   v
ESP32
   |
   v
L293D Motor Drivers
   |
   v
4 DC Motors
```

## Software

Technologies used:

* Python
* Computer Vision
* Hand Tracking
* ESP32 Programming
* WiFi Communication

## Future Improvements

* Add obstacle detection
* Implement autonomous navigation
* Add live camera streaming
* Improve gesture recognition accuracy
* Add variable speed control


## Author

Mateo Luchian
