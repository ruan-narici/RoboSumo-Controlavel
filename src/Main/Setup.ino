void run() {
  Serial.begin(115200);
  delay(1000);

  setPinMode();

  WiFi.softAP(ssid, pass); //Inicia o ponto de acesso
  Serial.print("\nSe conectando a: ");
  Serial.println(ssid);

  IPAddress ip = WiFi.softAPIP(); //Endereço de IP
  
  Serial.print("Endereço de IP: ");
  Serial.println(ip); // 192.168.4.1

  sv.begin(); //Inicia o servidor 
  Serial.println("Servidor online"); //Imprime a mensagem de início

  myLeftStepper.setSpeed(120);
  myRightStepper.setSpeed(120);
}