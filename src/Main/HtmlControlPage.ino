void drawControlPage(WiFiClient &client) {
  client.print(R"====(
    Clique para <a href="/esquerda_frente">Esquerda frente</a><br>
    Clique para <a href="/esquerda_costa">Esquerda costa</a><br><br>
    Clique para <a href="/direita_frente">Direita frente</a><br>
    Clique para <a href="/direita_costa">Direita costa</a><br>
    )====");
}