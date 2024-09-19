// PWD verifier:

String pwd = "12345678as";

void setup() {
  // put your setup code here, to run once:
  
  int pwdLength = pwd.length(); // -> 10
  Serial.begin(9600);

  // Variables bools de verificación:
  int isPwdLength8 = 0;
  int isPwdAlpha = 0;
  int isPwdDigit = 0;
  int isPwdSpace = 0; 

  // Vericar longitud:

  if (pwdLength >= 8) {
    isPwdLength8 = 1;
  } 

  // Verificar letra:

  for (int i = 0; i < pwd.length(); i++) {

    char letter = pwd[i];
    if (isAlpha(letter) == 1) {
      isPwdAlpha = 1;
    }
    if (isDigit(letter) == 1) {
      isPwdDigit = 1;
    } 
  }
  Serial.print("Longitud: ");
  Serial.println(isPwdLength8);
  Serial.print("Letra: ");
  Serial.println(isPwdAlpha);
  Serial.print("Dígito: ");
  Serial.println(isPwdDigit);
  Serial.println("Fin.");

}

void loop() {
  // put your main code here, to run repeatedly:

}
