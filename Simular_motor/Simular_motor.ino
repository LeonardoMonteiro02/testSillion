/*
 * Controle de Motor com Botão
 * Este código liga um motor por 10 segundos quando um botão é pressionado. 
 * Após esse tempo, o motor é desligado e o botão pode ser pressionado novamente.
 * 
 * Autor: Leonardo Monteiro da Sé
 * Data: 17/12/2024
 */

#include <Wire.h>  // Biblioteca para comunicação I2C
#include "DFRobot_LCD.h"  // Biblioteca para controle do LCD

// Definição dos pinos
const int buttonPin = 2;  // Pino onde o botão está conectado
const int transistorPin = 3;  // Pino onde o transistor está conectado


DFRobot_LCD lcd(16, 2);

// Variáveis de controle
unsigned long motorOnTime = 0;  
const unsigned long motorDuration = 10000;  

bool motorRunning = false;  // Indica se o motor está ligado
bool buttonPressed = false;  // Indica se o botão foi pressionado
bool buttonLocked = false;   // Indica se o botão está bloqueado (não pode ser pressionado)

void setup() {
    lcd.init();  
    lcd.print("Motor Desligado");  

    pinMode(buttonPin, INPUT_PULLUP);  
    pinMode(transistorPin, OUTPUT);        
}

void loop() {
    int buttonState = digitalRead(buttonPin);  // Lê o estado do botão

    // Verifica se o botão foi pressionado e não está bloqueado
    if (buttonState == LOW && !buttonPressed && !buttonLocked) {
        buttonPressed = true;  // Marca que o botão foi pressionado

        digitalWrite(transistorPin, HIGH);  // Liga o motor
        lcd.clear();  // Limpa a tela
        lcd.setCursor(0, 0);  // Coloca o cursor na primeira linha
        lcd.print("Motor Ligado");  // Exibe mensagem

        motorOnTime = millis();  // Armazena o tempo de início
        motorRunning = true;  // Marca que o motor está ligado
        buttonLocked = true;  // Bloqueia o botão
    }

    // Se o motor estiver ligado, exibe o tempo decorrido
    if (motorRunning) {
        unsigned long elapsedTime = millis() - motorOnTime;  // Tempo decorrido desde que o motor foi ligado

        if (elapsedTime < motorDuration) {
            unsigned long elapsedSeconds = elapsedTime / 1000;  
            lcd.setCursor(0, 1);  // Coloca o cursor na segunda linha
            lcd.print("Tempo: ");
            lcd.print(elapsedSeconds);  // Exibe o tempo decorrido
            lcd.print("s   ");  // Adiciona espaços para limpar a tela
        } else {
            digitalWrite(transistorPin, LOW);  // Desliga o motor
            lcd.clear();  // Limpa a tela
            lcd.setCursor(0, 0);  // Coloca o cursor na primeira linha
            lcd.print("Motor Desligado");  // Exibe mensagem
            motorRunning = false;  // Marca que o motor foi desligado
            buttonLocked = false;  // Desbloqueia o botão
        }
    }

    // Se o botão foi solto, permite nova ativação
    if (buttonState == HIGH) {
        buttonPressed = false;  // Marca que o botão foi solto
    }

    delay(100);  // Atraso para evitar leituras múltiplas do botão
}
