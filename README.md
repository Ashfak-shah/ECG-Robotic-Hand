# 🤖 Robotic Hand Controlled by EMG Sensor

This project demonstrates a **prosthetic robotic hand** controlled using **EMG (Electromyography) signals** from muscle movement. It aims to provide a low-cost, Arduino-based solution for disabled individuals or prosthetics development.

---

## 🔧 Features

- EMG sensor-based hand control
- Low-pass filter to smooth sensor data
- Control of all 5 fingers via servo motors
- Real-time response to muscle activity
- Easy-to-build and low-cost setup

---

## 🛠️ Components Used

| Component              | Quantity |
|------------------------|----------|
| Arduino UNO/Nano       | 1        |
| EMG Muscle Sensor      | 1        |
| Servo Motors (SG90)    | 5        |
| PVC Sheet (1mm)        | As per design |
| Jumper Wires           | Many     |
| Power Supply           | 5V DC    |

---

## ⚙️ Circuit Diagram

![Circuit Diagram](https://raw.githubusercontent.com/yourusername/your-repo-name/main/diagram.png)


---

## 🧠 Working Principle

- The EMG sensor detects muscle activity from the forearm.
- The analog signal is filtered using a low-pass filter.
- Based on a set threshold, the Arduino triggers servo motors to either **open** or **close** each finger.
- All five fingers (thumb, index, middle, ring, little) move together based on signal intensity.

---

## 🎥 Demo Video

> Click below to see the project in action:

📽️ [Watch Demo](https://github.com/yourusername/your-repo-name/blob/main/demo.mp4)


---

## 🧾 Code Overview

The code uses analog input (A0) for EMG signal and controls 5 servos connected to digital pins 2 to 6.  
Low-pass filtering is implemented using exponential smoothing.

filteredValue = alpha * rawValue + (1 - alpha) * filteredValue;
Servo control is applied based on a threshold:

if (filteredValue > THRESHOLD) {
    closehand();
} else {
    openhand();
}

📚 Applications
Prosthetic hand design for amputees

Biomedical engineering projects

Muscle signal analysis

Robotics and embedded system learning

📩 Contact
Created by Ashfak Shah
B.Tech (Electronics & Communication)
🔗 LinkedIn: www.linkedin.com/in/ashfak-shah
