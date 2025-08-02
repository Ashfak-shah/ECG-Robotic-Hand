
#include <Servo.h>

#define THRESHOLD 280 // Threshold to determine hand state (open/close)
#define EMGPIN A0 // Analog pin connected to Muscle Sensor (use A0 for analog input)

// Digital pins for servo motors
#define LITTLEPIN 2 
#define RINGPIN 3 
#define MIDDLEPIN 4 
#define INDEXPIN 5 
#define THUMBPIN 6 

// Constants for finger identification
#define LITTLE 1 
#define RING 2 
#define MIDDLE 3 
#define INDEX 4 
#define THUMB 5 

// Servo objects for fingers
Servo servoLittleFinger; 
Servo servoRingFinger; 
Servo servoMiddleFinger; 
Servo servoIndexFinger; 
Servo servoThumbFinger; 

int finger; // Used for loop iterations

// Low-pass filter variables
float filteredValue = 0;  // Filtered EMG value
float alpha = 0.1;        // Smoothing factor (adjust for responsiveness vs smoothness)

// Open hand by moving all fingers
void openhand() {
  for (finger = 1; finger < 6; finger++) {
    openFinger(finger);
  }
}

// Close hand by moving all fingers
void closehand() {
  for (finger = 1; finger < 6; finger++) {
    closeFinger(finger);
  }
}

// Open individual fingers
void openFinger(int finger) {
  if (finger == LITTLE) {
    servoLittleFinger.write(0);
  } else if (finger == RING) {
    servoRingFinger.write(0);
  } else if (finger == MIDDLE) {
    servoMiddleFinger.write(0);
  } else if (finger == INDEX) {
    servoIndexFinger.write(0);
  } else if (finger == THUMB) {
    servoThumbFinger.write(0);
  }
}

// Close individual fingers
void closeFinger(int finger) {
  if (finger == LITTLE) {
    servoLittleFinger.write(180);
  } else if (finger == RING) {
    servoRingFinger.write(180);
  } else if (finger == MIDDLE) {
    servoMiddleFinger.write(180);
  } else if (finger == INDEX) {
    servoIndexFinger.write(180);
  } else if (finger == THUMB) {
    servoThumbFinger.write(180);
  }
}

void setup() {
  Serial.begin(115200); // Set baud rate for serial monitor

  // Attach servos to corresponding pins
  servoLittleFinger.attach(LITTLEPIN); 
  servoRingFinger.attach(RINGPIN); 
  servoMiddleFinger.attach(MIDDLEPIN); 
  servoIndexFinger.attach(INDEXPIN); 
  servoThumbFinger.attach(THUMBPIN); 

  // Initialize the filtered value with the first sensor reading
  filteredValue = analogRead(EMGPIN);
}

void loop() {
  int rawValue = analogRead(EMGPIN); // Read raw value from EMG sensor

  // Apply low-pass filter
  filteredValue = alpha * rawValue + (1 - alpha) * filteredValue;

  // Determine hand state based on threshold
  if (filteredValue > THRESHOLD) {
    closehand();
  } else {
    openhand();
  }

  // Print raw and filtered sensor values to serial monitor
  Serial.print("Raw Value: ");
  Serial.print(rawValue);
  Serial.print(" | Filtered Value: ");
  Serial.println(filteredValue);

  delay(500); // Add delay to stabilize readings
}
