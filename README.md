# Sistema Verificador de Años Bisiestos y Múltiplos

## Objetivo
Desarrollar un sistema sencillo que permita a los usuarios verificar si un año es bisiesto y si es múltiplo de 11 o 27 en un rango de años desde 1800 hasta 2025. La interacción con el sistema se realizará mediante un menú, accesible tras presionar un pulsador.

## Funcionalidades
- ✅ Verificar si un año es bisiesto
- ✅ Verificar si es múltiplo de 11 o 27
- ✅ Analizar rango completo (1800-2025)
- ✅ Mostrar estadísticas:
  - Cantidad de años bisiestos
  - Cantidad de años no bisiestos
  - Porcentaje de años bisiestos
  - Porcentaje de años no bisiestos
  - Cantidad de múltiplos de 11
  - Cantidad de múltiplos de 27
  - Cantidad de múltiplos de ambos (11 y 27)
- ✅ LED indicador: Se enciende si hay más de 4 años que sean múltiplos simultáneos de 11 y 27

## Componentes (TinkerCAD)
- Microcontrolador Arduino
- Pulsador (botón)
- LED
- Resistencia

## Archivos del Proyecto
- `leap_year_validator.ino` - Código principal para Arduino/TinkerCAD
- `leap_year_validator.cpp` - Versión de consola para C++

## Cómo Usar
1. Presionar el pulsador para mostrar el menú
2. Seleccionar opción deseada
3. Ver resultados y estadísticas en pantalla
4. LED indicará si hay más de 4 múltiplos de 11 y 27

## Rango de Análisis
- Desde: 1800
- Hasta: 2025
- Total de años: 226
