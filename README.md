# Line-follower-bot


This project demonstrates a simple line follower robot built using Arduino. The robot autonomously follows a black line on a white surface using infrared (IR) sensors and motors for movement control.

Features
1. Follows a predefined path (black line) using infrared sensors.
2. Motors controlled via Arduino for smooth navigation.
3. Adjustable sensor sensitivity for better performance on different surfaces.
4. Easy to modify for various robots and paths.

Components Required
1. Arduino Uno (or compatible board)
2. IR Sensors (5 channels for better accuracy)
3. DC Motors (2)
4. Motor Driver (L298N or similar)
6. Chassis and wheels (and castor wheel)
7. Power Supply (battery pack)
8. Jumper wires and breadboard

Circuit Diagram
IR sensors are placed at the front of the robot to detect the line.
The motors are connected to the motor driver, which interfaces with the Arduino for speed control.

Code
The robot uses a simple algorithm to detect the line and steer left or right based on the sensor input. The code reads the sensor values, determines the robot’s position relative to the line, and adjusts the motors accordingly.
