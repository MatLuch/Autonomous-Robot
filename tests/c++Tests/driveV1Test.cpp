const int M1A = 12;
const int M1B = 13;

const int M2A = 27;
const int M2B = 14;

const int M3A = 25;
const int M3B = 33;

const int M4A = 2;
const int M4B = 4;

void setup() {
  // Set all 8 motor control pins as outputs
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);

  pinMode(M3A, OUTPUT);
  pinMode(M3B, OUTPUT);
  pinMode(M4A, OUTPUT);
  pinMode(M4B, OUTPUT);
}

void loop() {
  // 1. Move Forward (Both wheels spin forward)
  digitalWrite(M1A, HIGH);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, HIGH);
  digitalWrite(M2B, LOW);

  digitalWrite(M3A, HIGH);
  digitalWrite(M3B, LOW);
  digitalWrite(M4A, HIGH);
  digitalWrite(M4B, LOW);
  delay(2000); // Drive forward for 2 seconds

  // 3. Move Backward (Both wheels spin backward)
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, HIGH);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, HIGH);

  digitalWrite(M3A, LOW);
  digitalWrite(M3B, HIGH);
  digitalWrite(M4A, LOW);
  digitalWrite(M4B, HIGH);
  delay(2000);

}