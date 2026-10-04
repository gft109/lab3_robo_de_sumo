#pragma once

// Configurações de hardware do projeto (pinos, tempos etc.).
// Credenciais NÃO vão aqui — use secrets.h (veja secrets.example.h).

constexpr uint8_t LED_PIN = 2;  // LED azul onboard do ESP32 DevKit V1
constexpr uint32_t BLINK_INTERVAL_MS = 500;
