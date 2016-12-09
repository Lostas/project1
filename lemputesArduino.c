const int ledPin = 12;

void setup(){
			pinMode(ledPin, OUTPUT);
			Serial.begin(9600);
			Serial.printIn("Laukiama instrukciju...");
}

void loop(){
			if (Serial.available()) {
						int command = Serial.read() - '0';
						light(command);
			}
			delay(500);
}

void light (int n){
			Serial.printIn(n);
			for (int i = 0; i < n; i++) {
						digitalWrite(ledPin, HIGH)
						delay(100);
						digitalWrite(ledPin, LOW);
						delay(100);
				}
}
