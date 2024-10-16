void drawControlPage(WiFiClient &client) {
  client.print(R"====(
    <!DOCTYPE html>
    <html lang="pt-br">
    <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <title>Robô | Controle</title>
      <meta name="author" content="Ruan Narici &amp; Cínthia Oliveira">
    </head>
    <style>
      :root {
        --color-gray-dark: #1F2022;
        --color-black-normal: #000000;
        --color-green-normal: #009B52;
        --color-green-light: #00E676;
        --color-yellow-normal: #F6EB61;
      }

      * {
        padding: 0;
        margin: 0;
        box-sizing: border-box;
      }

      body {
        background-color: #979797;
        display: flex;
        justify-content: center;
        align-items: center;
        height: 100vh;
        -webkit-tap-highlight-color: transparent;
        user-select: none;
      }

      .controller {
        display: flex;
        align-items: center;
        justify-content: center;
        gap: 5rem;
        padding: 2rem;
        border: 10px solid var(--color-black-normal);
        background-color: var(--color-gray-dark);
        border-radius: 2rem;
      }
      
      .left-container,
      .right-container {
        display: flex;
        flex-direction: column;
        align-items: center;
        justify-content: center;
        border: 10px solid var(--color-black-normal);
        border-radius: 50%;
        overflow: hidden;
      }

      .right-container {
        flex-direction: row;
      }

      .left-container button,
      .right-container button {
        width: 230px;
        height: 107px;
        font-size: 2rem;
        background: linear-gradient(90deg, var(--color-green-normal), var(--color-green-light));
        outline: none;
        border: none;
        transition: .3s all;
      }

      .right-container button {
        width: 107px;
        height: 230px;
      }

      .left-container button:nth-child(1) {
        border-bottom: 10px solid var(--color-black-normal);
      }

      .right-container button:nth-child(1) {
        border-right: 10px solid var(--color-black-normal);
      }

      .left-container button:nth-child(2) {
        border-top: 10px solid var(--color-black-normal);
      }

      .right-container button:nth-child(2) {
        border-left: 10px solid var(--color-black-normal);
      }
      
      .left-container button:hover,
      .right-container button:hover {
        filter: brightness(70%);
        cursor: pointer;
      }

      .left-container button:active,
      .right-container button:active {
        background: var(--color-yellow-normal);
      }

      .logo {
        display: flex;
        flex-direction: column;
        align-items: center;
        justify-content: center;
        gap: 4rem;
      }

      .logo span {
        font-size: 2rem;
        color: var(--color-yellow-normal);
        width: 100px;
        text-align: center;
        text-transform: uppercase;
      }
    </style>
    <body>
      <section class="controller">
        <div class="left-container">
          <button onclick="move('up');">▲</button>
          <button onclick="move('down');">▼</button>
        </div>
        <div class="logo">
          <span id="countCommands">NONE</span>
          <svg width="60" height="60" viewBox="0 0 60 60" fill="none" xmlns="http://www.w3.org/2000/svg">
            <path d="M46.6667 24.4167C46.5188 22.3092 45.576 20.3365 44.0289 18.8977C42.4818 17.4589 40.446 16.6615 38.3333 16.6667L21.6667 16.6667C19.5296 16.6638 17.4731 17.482 15.9222 18.9523C14.3713 20.4226 13.4445 22.4325 13.3333 24.5667C13.3239 24.711 13.3239 24.8557 13.3333 25L13.3333 37.5C13.3289 38.2673 13.4768 39.0278 13.7684 39.7375C14.06 40.4473 14.4895 41.0921 15.032 41.6346C15.5746 42.1772 16.2194 42.6067 16.9291 42.8983C17.6389 43.1899 18.3994 43.3378 19.1667 43.3333C21.55 43.3333 23.0333 41.5667 24.4833 39.85C25.0167 39.2333 25.5667 38.5833 26.15 38.0167C26.9237 37.4495 27.7931 37.0261 28.7167 36.7667C29.5693 36.6665 30.4307 36.6665 31.2833 36.7667C32.2069 37.0261 33.0763 37.4495 33.85 38.0167C34.4333 38.5833 34.9833 39.2333 35.5167 39.85C36.9667 41.5167 38.45 43.3333 40.8333 43.3333C41.6006 43.3378 42.3612 43.1899 43.0709 42.8983C43.7806 42.6067 44.4254 42.1772 44.968 41.6346C45.5105 41.0921 45.9401 40.4473 46.2316 39.7375C46.5232 39.0278 46.6711 38.2673 46.6667 37.5L46.6667 25C46.6761 24.8557 46.6761 24.711 46.6667 24.5667V24.4167ZM43.3333 37.5C43.3333 38.163 43.0699 38.7989 42.6011 39.2678C42.1323 39.7366 41.4964 40 40.8333 40C40 40 39.1667 38.9333 38.0667 37.7C37.5 37.05 36.8667 36.2833 36.15 35.6C34.9427 34.6286 33.5464 33.9191 32.05 33.5167C30.6944 33.2711 29.3056 33.2711 27.95 33.5167C26.4536 33.9191 25.0573 34.6286 23.85 35.6C23.1333 36.2833 22.5 37.05 21.9333 37.7C20.9 38.9333 20 40 19.1667 40C18.5036 40 17.8678 39.7366 17.3989 39.2678C16.9301 38.7989 16.6667 38.163 16.6667 37.5V25C16.6729 24.9168 16.6729 24.8332 16.6667 24.75C16.7309 23.4677 17.2859 22.2593 18.2167 21.375C19.1475 20.4907 20.3828 19.9984 21.6667 20L38.3333 20C39.5824 19.9945 40.7883 20.4568 41.7136 21.2958C42.639 22.1348 43.2168 23.2897 43.3333 24.5333V24.7333C43.3262 24.8221 43.3262 24.9113 43.3333 25V37.5Z" fill="#F6EB61"/>
            <path d="M36.6667 31.6667C37.5871 31.6667 38.3333 30.9205 38.3333 30C38.3333 29.0795 37.5871 28.3333 36.6667 28.3333C35.7462 28.3333 35 29.0795 35 30C35 30.9205 35.7462 31.6667 36.6667 31.6667Z" fill="#F6EB61"/>
            <path d="M40 28.3333C40.9205 28.3333 41.6666 27.5871 41.6666 26.6667C41.6666 25.7462 40.9205 25 40 25C39.0795 25 38.3333 25.7462 38.3333 26.6667C38.3333 27.5871 39.0795 28.3333 40 28.3333Z" fill="#F6EB61"/>
            <path d="M36.6667 25C37.5871 25 38.3333 24.2538 38.3333 23.3333C38.3333 22.4129 37.5871 21.6667 36.6667 21.6667C35.7462 21.6667 35 22.4129 35 23.3333C35 24.2538 35.7462 25 36.6667 25Z" fill="#F6EB61"/>
            <path d="M33.3334 28.3333C34.2538 28.3333 35 27.5871 35 26.6667C35 25.7462 34.2538 25 33.3334 25C32.4129 25 31.6667 25.7462 31.6667 26.6667C31.6667 27.5871 32.4129 28.3333 33.3334 28.3333Z" fill="#F6EB61"/>
            <path d="M23.3333 30C25.1743 30 26.6667 28.5076 26.6667 26.6667C26.6667 24.8257 25.1743 23.3333 23.3333 23.3333C21.4924 23.3333 20 24.8257 20 26.6667C20 28.5076 21.4924 30 23.3333 30Z" fill="#F6EB61"/>
            <circle cx="30" cy="30" r="28" transform="rotate(-90 30 30)" stroke="#F6EB61" stroke-width="4"/>
          </svg>
        </div>
        <div class="right-container">
          <button onclick="move('left');">◀</button>
          <button onclick="move('right');">▶</button>
        </div>
      </section>

      <script>
        function move(direction) {
          sendCommand(direction);
          showDirection(direction);
        }

        async function sendCommand(direction) {
          let url = `/${direction}`;
          let request = await fetch(url);
        }

        function showDirection(currentDirection) {
          const countCommands = document.querySelector('#countCommands');
          countCommands.innerHTML = currentDirection;
        }
      </script>
    </body>
    </html>
    )====");
}