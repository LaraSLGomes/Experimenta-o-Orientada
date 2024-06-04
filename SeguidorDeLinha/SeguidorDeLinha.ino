int motor1_pin1 = 4;
int motor1_pin2 = 5;
int motor2_pin1 = 6;
int motor2_pin2 = 7;

int sensor_esquerdo = 3;
int sensor_direito = 12;

void setup() {
  
  pinMode(motor1_pin1, OUTPUT);
  pinMode(motor1_pin2, OUTPUT);
  pinMode(motor2_pin1, OUTPUT);
  pinMode(motor2_pin2, OUTPUT);

  pinMode(sensor_esquerdo, INPUT);
  pinMode(sensor_direito, INPUT);
}

void loop() {
  // Leitura dos sensores de seguidor de linha
  int esquerdo = digitalRead(sensor_esquerdo);
  int direito = digitalRead(sensor_direito);

  // Controle do movimento do carrinho
  if (esquerdo == LOW && direito == LOW) {
    // Ambos os sensores detectaram a linha, siga em frente
    frente();
  } else if (esquerdo == HIGH && direito == LOW) {
    // Sensor esquerdo não detectou a linha, vire para a esquerda
    esquerda();
  } else if (esquerdo == LOW && direito == HIGH) {
    // Sensor direito não detectou a linha, vire para a direita
    direita();
  } else {
    // Nenhum sensor detectou a linha, pare
    parar();
  }
}

// Função para mover o carrinho para frente
void frente() {
  digitalWrite(motor1_pin1, HIGH);
  analogWrite(motor1_pin2, 100);
  analogWrite(motor2_pin1, 155);
  digitalWrite(motor2_pin2, LOW);
}

// Função para mover o carrinho para a esquerda
void esquerda() {
  digitalWrite(motor1_pin1, LOW);
  analogWrite(motor1_pin2, 155);
  analogWrite(motor2_pin1, 155);
  digitalWrite(motor2_pin2, LOW);
}

// Função para mover o carrinho para a direita
void direita() {
  digitalWrite(motor1_pin1, HIGH);
  analogWrite(motor1_pin2, 100);
  analogWrite(motor2_pin1, 100);
  digitalWrite(motor2_pin2, HIGH);
}

// Função para parar o carrinho
void parar() {
  digitalWrite(motor1_pin1, LOW);
  digitalWrite(motor1_pin2, LOW);
  digitalWrite(motor2_pin1, LOW);
  digitalWrite(motor2_pin2, LOW);
}