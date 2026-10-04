# Lab3 — Robô de Sumô (ESP32)

Firmware em C++ (framework Arduino) para ESP32 DevKit V1, compilado com [PlatformIO](https://platformio.org/).

## Configuração do ambiente (uma vez por máquina)

1. Instale o [VS Code](https://code.visualstudio.com/) e o [Git](https://git-scm.com/).
2. Clone o repositório e abra a pasta no VS Code:
   ```bash
   git clone https://github.com/gft109/lab3_robo_de_sumo.git
   cd lab3_robo_de_sumo
   code .
   ```
3. Aceite a sugestão de instalar a extensão recomendada **PlatformIO IDE**
   (ou instale manualmente pela aba Extensions). Na primeira abertura ela
   baixa a toolchain do ESP32, o que pode levar alguns minutos.
4. Crie seu arquivo de credenciais (ele não vai para o git):
   ```bash
   cp include/secrets.example.h include/secrets.h
   ```
5. **Driver USB:** a maioria das DevKits usa o chip CP2102 ou CH340.
   No Linux e no macOS recente geralmente funciona direto; no Windows pode ser
   preciso instalar o driver
   ([CP210x](https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers) /
   [CH340](https://www.wch-ic.com/downloads/CH341SER_EXE.html)).
   No Linux, adicione seu usuário ao grupo `dialout` e instale as
   [regras udev do PlatformIO](https://docs.platformio.org/en/latest/core/installation/udev-rules.html).

Todas as versões (plataforma, framework, bibliotecas) estão fixadas no
`platformio.ini`, então todos compilam exatamente com a mesma toolchain.

## Uso

Pela barra de status do PlatformIO no VS Code (parte inferior da janela):

| Ação              | Botão | Terminal (`pio`)              |
|-------------------|-------|-------------------------------|
| Compilar          | ✓     | `pio run`                     |
| Gravar na placa   | →     | `pio run -t upload`           |
| Monitor serial    | 🔌    | `pio device monitor`          |
| Limpar build      | 🗑    | `pio run -t clean`            |

> Se o upload travar em `Connecting...`, segure o botão **BOOT** da placa até a gravação começar.

## Estrutura

```
├── platformio.ini          # Configuração do build e dependências (versões fixadas)
├── src/                    # Código-fonte (.cpp)
├── include/                # Headers do projeto
│   ├── config.h            # Pinos e constantes de hardware
│   └── secrets.example.h   # Modelo para secrets.h (credenciais, não versionado)
├── lib/                    # Bibliotecas próprias do projeto
└── .github/workflows/      # CI: compila a cada push/PR
```

## Adicionando bibliotecas

Procure em <https://registry.platformio.org> e adicione em `lib_deps` no
`platformio.ini`, **sempre com versão fixa**:

```ini
lib_deps =
    bblanchon/ArduinoJson @ 7.2.0
```

## Fluxo de trabalho

1. Crie uma branch: `git checkout -b minha-feature`
2. Faça commits e envie: `git push -u origin minha-feature`
3. Abra um Pull Request no GitHub. O CI compila o projeto automaticamente;
   só faça merge se o check estiver verde.
