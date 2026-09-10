 const int N_RED = 2,  N_YEL = 4,  N_GRN = 5;
const int S_RED = 13, S_YEL = 14, S_GRN = 15;
const int E_RED = 23, E_YEL = 27, E_GRN = 18;
const int W_RED = 19, W_YEL = 21, W_GRN = 22;

const int GREEN_TIME = 5000;
const int YELLOW_TIME = 2000;
const int ALL_RED_TIME = 1000;

void setup() {
  int pins[] = {
    N_RED, N_YEL, N_GRN,
    S_RED, S_YEL, S_GRN,
    E_RED, E_YEL, E_GRN,
    W_RED, W_YEL, W_GRN
  };

  for (int i = 0; i < 12; i++) {
    pinMode(pins[i], OUTPUT);
  }

  allRed();
}

void allOff() {
  digitalWrite(N_RED, LOW);
  digitalWrite(N_YEL, LOW);
  digitalWrite(N_GRN, LOW);

  digitalWrite(S_RED, LOW);
  digitalWrite(S_YEL, LOW);
  digitalWrite(S_GRN, LOW);

  digitalWrite(E_RED, LOW);
  digitalWrite(E_YEL, LOW);
  digitalWrite(E_GRN, LOW);

  digitalWrite(W_RED, LOW);
  digitalWrite(W_YEL, LOW);
  digitalWrite(W_GRN, LOW);
}

void allRed() {
  allOff();

  digitalWrite(N_RED, HIGH);
  digitalWrite(S_RED, HIGH);
  digitalWrite(E_RED, HIGH);
  digitalWrite(W_RED, HIGH);

  delay(ALL_RED_TIME);
}

void nsGreen() {
  allOff();

  digitalWrite(N_GRN, HIGH);
  digitalWrite(S_GRN, HIGH);

  digitalWrite(E_RED, HIGH);
  digitalWrite(W_RED, HIGH);

  delay(GREEN_TIME);
}

void nsYellow() {
  digitalWrite(N_GRN, LOW);
  digitalWrite(S_GRN, LOW);

  digitalWrite(N_YEL, HIGH);
  digitalWrite(S_YEL, HIGH);

  delay(YELLOW_TIME);

  digitalWrite(N_YEL, LOW);
  digitalWrite(S_YEL, LOW);
}

void ewGreen() {
  allOff();

  digitalWrite(E_GRN, HIGH);
  digitalWrite(W_GRN, HIGH);

  digitalWrite(N_RED, HIGH);
  digitalWrite(S_RED, HIGH);

  delay(GREEN_TIME);
}

void ewYellow() {
  digitalWrite(E_GRN, LOW);
  digitalWrite(W_GRN, LOW);

  digitalWrite(E_YEL, HIGH);
  digitalWrite(W_YEL, HIGH);

  delay(YELLOW_TIME);

  digitalWrite(E_YEL, LOW);
  digitalWrite(W_YEL, LOW);
}

void loop() {
  
  nsGreen();
  nsYellow();
  allRed();
  ewGreen();
  ewYellow();
  allRed();
}
