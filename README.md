# Edge-Computing---CP01---2024

Controle de Iluminação com Arduino
Este projeto consiste em um sistema de controle de iluminação utilizando um Arduino, LEDs e um sensor LDR (Resistor Dependente de Luz). O objetivo é ajustar a intensidade da iluminação com base na luminosidade ambiente medida pelo sensor LDR.

Componentes Utilizados
Arduino Uno
LEDs (vermelho, amarelo e verde)
Sensor LDR
Buzzer
Funcionamento
Jumpers

O código carregado no Arduino monitora continuamente a intensidade da luz ambiente lida pelo sensor LDR. Com base nessa leitura, os LEDs são controlados de acordo com as seguintes condições:

Se a intensidade da luz for alta (maior que 70), o LED vermelho é ligado e o buzzer é ativado.
Se a intensidade da luz estiver entre 20 e 70, o LED amarelo é ligado.
Se a intensidade da luz for baixa (menor ou igual a 20), o LED verde é ligado.
Além disso, os valores de intensidade de luz são enviados via comunicação serial para fins de monitoramento e depuração.

Pinagem
LED Vermelho: Pino 13
LED Amarelo: Pino 12
LED Verde: Pino 8
Sensor LDR: Pino A0
Buzzer: Pino 7
Instruções de Uso
Monte o circuito conforme a pinagem especificada.
Carregue o código no Arduino utilizando a IDE do Arduino.
Conecte a alimentação ao Arduino.
Observe o comportamento dos LEDs com base na intensidade da luz ambiente.
Autores
Este projeto foi desenvolvido por Murilo Justi, Renan Utida, Gustavo Melanda e Fabrício Carlos

Contribuições
Contribuições são bem-vindas! Se você identificar melhorias ou correções no código ou na documentação, sinta-se à vontade para enviar um pull request.
