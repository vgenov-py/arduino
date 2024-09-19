String pwd = "1234asd89";

void setup() {
  // put your setup code here, to run once:
  
  int pwdLength = pwd.length(); // -> 0
  Serial.begin(9600);
  // if (pwdLength >= 20) {
  //   Serial.println("La contraseña tiene 8 o más caracteres.");
  // } else {
  //   Serial.println("La contraseña tiene menos de 8 caracteres.");
  // }
  // pwd[4]
  for (int i = 0; i < pwd.length(); ) {

  }
  Serial.println("Fin.");

}

void loop() {
  // put your main code here, to run repeatedly:

}
