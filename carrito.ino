
int trig = A0;
int echo = A1;

int motor1A = 2;
int motor1B = 3;
int motor2A = 4;
int motor2B = 5;

long duracion;
int distancia;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Medir la distancia
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duracion = pulseIn(echo, HIGH, 30000);

  // Convertir el tiempo en centimetros
  if (duracion == 0) {
    distancia = 999;
  } else {
    distancia = duracion * 0.034 / 2;
  }

  Serial.println(distancia);

  // Si hay un obstaculo cerca, detenerse
  if (distancia <= 20) {
    digitalWrite(motor1A, LOW);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, LOW);
    digitalWrite(motor2B, LOW);
  } else {
    // Avanzar hacia adelante
    digitalWrite(motor1A, HIGH);
    digitalWrite(motor1B, LOW);
    digitalWrite(motor2A, HIGH);
    digitalWrite(motor2B, LOW);
  }

  delay(100);
}
