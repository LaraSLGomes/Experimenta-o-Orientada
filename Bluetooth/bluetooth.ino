#include <SoftwareSerial.h>

// Definição dos pinos para comunicação com o módulo Bluetooth
int bluetoothTx = 9;  // Pino TX do módulo Bluetooth conectado ao RX do Arduino
int bluetoothRx = 8;  // Pino RX do módulo Bluetooth conectado ao TX do Arduino

// Inicialização do objeto para comunicação Bluetooth
SoftwareSerial bluetooth(bluetoothRx, bluetoothTx);

// Variável para armazenar o tempo da última ação
unsigned long ultimoTempo = 0;
// Tempo limite para considerar uma ação antes de parar o carrinho (em milissegundos)
const unsigned long tempoLimite = 1000; // 1 segundo

void setup() 
{
  // Inicialização da comunicação serial padrão (para comunicação com o computador via USB)
  Serial.begin(9600);
  
  // Inicialização da comunicação serial com o módulo Bluetooth
  bluetooth.begin(9600);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}


void loop() 
{
   if(bluetooth.available() > 0)
   {
    char direcao = bluetooth.read();
    // Atualiza o tempo da última ação
    ultimoTempo = millis();

    if (direcao == '1') {
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      Serial.println("Frente");
    }
    if (direcao == '2') {
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      Serial.println("Ré");
    }
    if (direcao == '3') {
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      Serial.println("Direita");
    }
    if (direcao == '4') {
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      Serial.println("Esquerda");
    }
  }

  // Verifica se o tempo desde a última ação excedeu o tempo limite
  if (millis() - ultimoTempo > tempoLimite) {
    // Se excedeu, pare o carrinho
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    Serial.printlnaa("Parado automaticamente");
  }
}