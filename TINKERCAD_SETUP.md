# Configuración en TinkerCAD

## Componentes Necesarios
1. **Arduino Uno**
2. **Pulsador (Push Button)**
3. **LED**
4. **Resistencia de 220Ω** (para proteger el LED)
5. **Cables de conexión**

## Esquema de Conexión

### Pulsador
- Pin GND → GND del Arduino
- Pin 1 del Pulsador → Pin 2 (Digital) del Arduino
- Pin 2 del Pulsador → 5V
- Agregar resistencia Pull-Down de 10kΩ entre Pin 2 y GND (opcional pero recomendado)

### LED
- Ánodo (pin largo) → Resistencia de 220Ω → Pin 13 (Digital) del Arduino
- Cátodo (pin corto) → GND del Arduino

## Configuración del Serial Monitor
1. Abre el Monitor Serial (Tools → Serial Monitor)
2. Velocidad: **9600 baud**
3. Presiona el pulsador para activar el menú
4. Ingresa las opciones en el Serial Monitor

## Funcionamiento
- **Presionar el pulsador** → Muestra el menú
- **Seleccionar opción** → Ejecuta la acción
- **LED se enciende** si hay más de 4 múltiplos simultáneos de 11 y 27 en años no bisiestos

## Código a Cargar
Copia el contenido de `leap_year_validator.ino` en el IDE de Arduino y sube a la placa.

## Pruebas
1. Presiona el pulsador
2. Escribe "1" para ver estadísticas
3. Verifica que el LED se encienda (hay 5 múltiplos de 11 y 27: 1944, 1998, 2052...)
4. Prueba las otras opciones del menú
