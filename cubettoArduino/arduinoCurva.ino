//codigo para o carrinho virar lentamente para direita

const int IN1 = 5;
const int IN2 = 6;
const int IN3 = 9;
const int IN4 = 10;

const int PWM1 = 100;
const int PWM2 = 20;

void setup(){
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void loop(){
    // Motor 1 - Left
    digitalWrite(IN1, PWM1);
    digitalWrite(IN2, 0);

    // Motor 2 - Right
    digitalWrite(IN3, PWM2);
    digitalWrite(IN4, 0);

    delay(1000); // Wait for 1 second to maintain the turn

    // Stop motors

    digitalWrite(IN1, 0);
    digitalWrite(IN2, 0);
    digitalWrite(IN3, 0);
    digitalWrite(IN4, 0);

    delay(2000); // Wait for 1 second before the next loop iteration
}