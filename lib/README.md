# lib/

Bibliotecas privadas do projeto. Cada biblioteca fica em sua própria pasta:

```
lib/
└── MeuSensor/
    ├── MeuSensor.h
    └── MeuSensor.cpp
```

O PlatformIO encontra e compila automaticamente. Bibliotecas de terceiros
devem ir em `lib_deps` no `platformio.ini`, não aqui.
