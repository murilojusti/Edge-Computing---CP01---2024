// Define os pinos dos componentes
int redPin = 13;        // Define o pino digital conectado ao LED vermelho.
int yellowPin = 12;     // Define o pino digital conectado ao LED amarelo.
int greenPin = 8;       // Define o pino digital conectado ao LED verde.
int ldrPin = A0;        // Define o pino analógico conectado ao sensor LDR.
int buzzPin = 7;        // Define o pino digital conectado ao buzzer.
int luminosidade;       // Variável para armazenar a leitura do sensor LDR.
bool emAlerta = false;  // Variável para indicar se o sistema está em estado de alerta ou não.

void setup() {
  // Configuração dos pinos como entrada ou saída
  pinMode(redPin, OUTPUT);     // Configura o pino do LED vermelho como saída.
  pinMode(yellowPin, OUTPUT);  // Configura o pino do LED amarelo como saída.
  pinMode(greenPin, OUTPUT);   // Configura o pino do LED verde como saída.
  pinMode(ldrPin, INPUT);      // Configura o pino do sensor LDR como entrada.
  pinMode(buzzPin, OUTPUT);    // Configura o pino do buzzer como saída.
  
  // Inicialização da comunicação serial
  Serial.begin(9600);          // Inicializa a comunicação serial com uma taxa de transmissão de 9600 bps.
}

void loop() {
  // Leitura da luminosidade
  luminosidade = analogRead(ldrPin);
  
  // Mapeamento da luminosidade lida para uma faixa de 0 a 100
  int IntensidadeLuz = map(luminosidade, 152, 974, 0, 100);
  
  // Saída dos valores lidos via comunicação serial
  Serial.print("Intensidade de luz 0 - 1023 = ");
  Serial.println(luminosidade);  // Imprime o valor lido do sensor LDR na porta serial.
  Serial.print("Intensidade de luz 0 - 100% = ");
  Serial.println(IntensidadeLuz);  // Imprime o valor lido em porcentagem
  
  delay(500); // Aguarda 500 milissegundos
  
  // Lógica de controle dos LEDs e do buzzer baseada na intensidade da luz
  if (IntensidadeLuz > 70) {       // Se a intensidade da luz for maior que 70...
    digitalWrite(buzzPin, HIGH);   // Ligar o buzzer.
    digitalWrite(redPin, HIGH);    // Ligar o LED vermelho.
    digitalWrite(yellowPin, LOW);  // Desligar o LED amarelo.
    digitalWrite(greenPin, LOW);   // Desligar o LED verde.
    emAlerta = true;
    tone(buzzPin, 2000, 1000);     // Emitir um tom de 2 kHz por 1 segundo.
  }
  else if (IntensidadeLuz > 20 && IntensidadeLuz < 70) { // Se a intensidade da luz estiver entre 20 e 70...
    digitalWrite(buzzPin, LOW);                         // Desligar o buzzer.
    digitalWrite(redPin, LOW);                          // Desligar o LED vermelho.
    digitalWrite(yellowPin, HIGH);                      // Ligar o LED amarelo.
    digitalWrite(greenPin, LOW);                        // Desligar o LED verde.
    emAlerta = true;
    tone(buzzPin, 1000, 500);                           // Emitir um tom de 1 kHz por 500 milissegundos.
    delay(500);                                          // Aguarda 500 milissegundos.
  }
  else {                         // Se a intensidade da luz for menor ou igual a 20...
    digitalWrite(buzzPin, LOW);  // Desligar o buzzer.
    digitalWrite(redPin, LOW);   // Desligar o LED vermelho.
    digitalWrite(yellowPin, LOW);// Desligar o LED amarelo.
    digitalWrite(greenPin, HIGH);// Ligar o LED verde.
    emAlerta = false;
    noTone(buzzPin);             // Parar de emitir som pelo buzzer.
  }
}
