void httpListener() {
  WiFiClient client = sv.available();  //Cria o objeto cliente
  int numClients = WiFi.softAPgetStationNum();

  if (numClients == 0) {
    setLedStatusRobot(0);
  } else if (client) {  //Se este objeto estiver disponível
    String line = "";  //Variável para armazenar os dados recebidos

    while (client.connected()) {                //Enquanto estiver conectado
      setLedStatusRobot(1);
      if (client.available()) {                 //Se estiver disponível
        char c = client.read();                 //Lê os caracteres recebidos
        if (c == '\n') {                        //Se houver uma quebra de linha
          if (line.length() == 0) {             //Se a nova linha tiver 0 de tamanho
            setLedDataReceived(0);
            client.println("HTTP/1.1 200 OK");  //Envio padrão de início de comunicação
            client.println("Content-type:text/html");
            client.println();

            drawControlPage(client);
            client.println();
            break;
          } else {
            line = "";
          }
        } else if (c != '\r') {
          line += c;  //Adiciona o caractere recebido à linha de leitura
          setLedDataReceived(1);
        }

        if (line.endsWith("GET /up")) {
          goToFront();
        } 
        if (line.endsWith("GET /down")) {
          goToBack();
        } 
        if (line.endsWith("GET /left")) {
          goToLeft();
        } 
        if (line.endsWith("GET /right")) {
          goToRight();
        }         
      }
    }
    client.stop();  //Para o cliente
  }
}