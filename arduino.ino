#include <Servo.h>

Servo servo1;
Servo servo2;

const int LED1_PIN = 2;
const int LED2_PIN = 3;
const int SERVO1_PIN = 9;
const int SERVO2_PIN = 10;

void setup() {
  Serial.begin(9600);
  
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
  
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  
  // Posição inicial: 0 graus e LEDs desligados
  servo1.write(0);
  servo2.write(0);
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    
    // Processa o comando recebido (ex: "S1:90" ou "S2:45")
    if (command.startsWith("S1:")) {
      int angle = command.substring(3).toInt();
      angle = constrain(angle, 0, 180);
      servo1.write(angle);
      
      // Liga o LED se o servo estiver acionado (ângulo maior que 0)
      digitalWrite(LED1_PIN, angle > 0 ? HIGH : LOW);
    } 
    else if (command.startsWith("S2:")) {
      int angle = command.substring(3).toInt();
      angle = constrain(angle, 0, 180);
      servo2.write(angle);
      
      // Liga o LED se o servo estiver acionado (ângulo maior que 0)
      digitalWrite(LED2_PIN, angle > 0 ? HIGH : LOW);
    }
  }
}
