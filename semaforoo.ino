#include <Servo.h>

int rojo = 2;
int amarillo = 3;
int verde = 4;
int pinServo = 9;

Servo barrera;

void setup() {
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);

  barrera.attach(pinServo);

  // Empezar con la barrera abajo
  barrera.write(0);
}

void loop() {
  // ROJO: detener el paso
  digitalWrite(rojo, HIGH);
  digitalWrite(amarillo, LOW);
  digitalWrite(verde, LOW);

  barrera.write(0);
  delay(5000);

  // VERDE: permitir el paso
  digitalWrite(rojo, LOW);
  digitalWrite(amarillo, LOW);
  digitalWrite(verde, HIGH);

  barrera.write(90);
  delay(5000);

  // AMARILLO: prepararse para cerrar
  digitalWrite(rojo, LOW);
  digitalWrite(amarillo, HIGH);
  digitalWrite(verde, LOW);

  barrera.write(0);
  delay(2000);
}