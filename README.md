# Obstacle-Avoiding-Robot
An obstacle avoiding robot is an autonomous system that uses an ultrasonic sensor to detect objects in its path. When an obstacle is detected within a safe distance, the robot stops, scans left and right using a servo motor, and moves toward the free direction to avoid collision.

📌 Features

Automatic obstacle detection

Servo-based environment scanning

Intelligent left/right turning

Real-time distance measurement

Simple and efficient control logic

⚙️ Working Principle

The ultrasonic sensor continuously measures the distance ahead of the robot. When no obstacle is detected, the robot moves forward. If an obstacle is detected within a predefined threshold distance, the robot stops and rotates the ultrasonic sensor using a servo motor to scan left and right. The robot then compares the distances and turns toward the direction with more free space.

🔧 Components Used

Arduino Uno (or compatible board)

Ultrasonic Sensor (HC-SR04)

Servo Motor (SG90 / MG90)

DC Motors with Motor Driver (L298N / L293D)

Robot Chassis and Wheels

External Power Supply

Jumper Wires

🖥️ Software Used

Arduino IDE

Embedded C (Arduino)


🔌 Circuit Connections

Ultrasonic Sensor: Trig & Echo → Digital Pins

Servo Motor: Signal → PWM Pin

Motor Driver: Connected to DC Motors

Power: External supply with common ground

▶️ How to Run

Clone or download the repository

Open the code in Arduino IDE

Select the correct board and port

Upload the code

Power the robot and place it on the ground

📈 Applications

Autonomous navigation systems

Robotics learning projects

Smart vehicles

Industrial automation

📚 Learning Outcomes

Sensor interfacing

Servo motor control

Motor driver operation

Autonomous decision making

📝 License

This project is open-source and intended for educational use.
