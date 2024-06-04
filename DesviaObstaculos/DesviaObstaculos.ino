#include <Servo.h>

int e = 0;

int esquerda = 0;

int direita = 0;

Servo servo_11;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Define o pino de disparo (trigger) para HIGH por 10 microssegundos
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Lê o pino de eco e retorna o tempo da onda sonora em microssegundos
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  servo_11.attach(11, 500, 2500);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  servo_11.write(90);
  delay(500); // espera 500 milissegundos
  if (0.01723 * readUltrasonicDistance(A0, A1) <= 40) {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    // para o carrinho para realizar leitura...
    servo_11.write(0);
    delay(500); // espera 500 milissegundos
    esquerda = 0.01723 * readUltrasonicDistance(A0, A1);
    servo_11.write(180);
    delay(500); // espera 500 milissegundos
    direita = 0.01723 * readUltrasonicDistance(A0, A1);
    delay(500); // espera 500 milissegundos
    if (direita > 50) {
      // vira para direita caso esteja livre...
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
    }
    if (esquerda > 50) {
      // vira para esquerda caso esteja livre...
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
    }
    // para o carrinho...
    delay(500); // espera 500 milissegundos
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  } else {
    // Segue em frente...
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
  }
}