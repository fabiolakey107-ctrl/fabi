// Sistema Verificador de Años Bisiestos y Múltiplos
// Para TinkerCAD / Arduino
// Rango: 1800 - 2025

#define BUTTON_PIN 2    // Pin del pulsador
#define LED_PIN 13      // Pin del LED
#define BAUD_RATE 9600  // Velocidad de comunicación serial

const int YEAR_START = 1800;
const int YEAR_END = 2025;
const int TOTAL_YEARS = YEAR_END - YEAR_START + 1;

// Variables globales para estadísticas
int leap_years_count = 0;
int non_leap_years_count = 0;
int multiples_11_count = 0;
int multiples_27_count = 0;
int multiples_both_count = 0;

volatile bool button_pressed = false;

// Función para verificar si un año es bisiesto
bool isLeapYear(int year) {
  if (year % 400 == 0) return true;
  if (year % 100 == 0) return false;
  if (year % 4 == 0) return true;
  return false;
}

// Función para verificar si es múltiplo de 11
bool isMultipleOf11(int year) {
  return (year % 11 == 0);
}

// Función para verificar si es múltiplo de 27
bool isMultipleOf27(int year) {
  return (year % 27 == 0);
}

// Función para calcular estadísticas del rango completo
void calculateStatistics() {
  leap_years_count = 0;
  non_leap_years_count = 0;
  multiples_11_count = 0;
  multiples_27_count = 0;
  multiples_both_count = 0;
  
  for (int year = YEAR_START; year <= YEAR_END; year++) {
    if (isLeapYear(year)) {
      leap_years_count++;
    } else {
      non_leap_years_count++;
      
      // Contar múltiplos en años NO bisiestos
      if (isMultipleOf11(year)) {
        multiples_11_count++;
      }
      if (isMultipleOf27(year)) {
        multiples_27_count++;
      }
      if (isMultipleOf11(year) && isMultipleOf27(year)) {
        multiples_both_count++;
      }
    }
  }
}

// Función para mostrar el menú
void showMenu() {
  Serial.println("\n========================================");
  Serial.println("  VERIFICADOR DE AÑOS BISIESTOS (1800-2025)");
  Serial.println("========================================");
  Serial.println("1. Ver estadísticas completas");
  Serial.println("2. Verificar un año específico");
  Serial.println("3. Listar años bisiestos");
  Serial.println("4. Listar múltiplos de 11 (años no bisiestos)");
  Serial.println("5. Listar múltiplos de 27 (años no bisiestos)");
  Serial.println("6. Listar múltiplos de 11 Y 27 (años no bisiestos)");
  Serial.println("========================================");
  Serial.println("Ingrese una opción (1-6): ");
}

// Función para mostrar estadísticas completas
void displayStatistics() {
  calculateStatistics();
  
  float leap_percentage = (float)leap_years_count / TOTAL_YEARS * 100;
  float non_leap_percentage = (float)non_leap_years_count / TOTAL_YEARS * 100;
  
  Serial.println("\n========== ESTADÍSTICAS (1800-2025) ==========");
  Serial.print("Total de años: ");
  Serial.println(TOTAL_YEARS);
  Serial.print("Años bisiestos: ");
  Serial.print(leap_years_count);
  Serial.print(" (");
  Serial.print(leap_percentage, 2);
  Serial.println(" %)");
  Serial.print("Años no bisiestos: ");
  Serial.print(non_leap_years_count);
  Serial.print(" (");
  Serial.print(non_leap_percentage, 2);
  Serial.println(" %)");
  Serial.println("\n--- Múltiplos en años NO BISIESTOS ---");
  Serial.print("Múltiplos de 11: ");
  Serial.println(multiples_11_count);
  Serial.print("Múltiplos de 27: ");
  Serial.println(multiples_27_count);
  Serial.print("Múltiplos de 11 Y 27: ");
  Serial.println(multiples_both_count);
  
  // Verificar si enciende el LED
  if (multiples_both_count > 4) {
    Serial.println("\n*** LED ENCENDIDO: Hay más de 4 múltiplos de 11 Y 27 ***");
    digitalWrite(LED_PIN, HIGH);
  } else {
    Serial.println("\n*** LED APAGADO: No hay más de 4 múltiplos de 11 Y 27 ***");
    digitalWrite(LED_PIN, LOW);
  }
  Serial.println("=============================================");
}

// Función para verificar un año específico
void verifySpecificYear() {
  Serial.println("\nIngrese el año a verificar (1800-2025): ");
  while (!Serial.available()) delay(100);
  int year = Serial.parseInt();
  
  if (year < YEAR_START || year > YEAR_END) {
    Serial.println("Error: El año debe estar entre 1800 y 2025");
    return;
  }
  
  Serial.print("\n--- Información del año: ");
  Serial.println(year);
  Serial.print("Es bisiesto: ");
  Serial.println(isLeapYear(year) ? "SÍ" : "NO");
  
  if (!isLeapYear(year)) {
    Serial.print("Es múltiplo de 11: ");
    Serial.println(isMultipleOf11(year) ? "SÍ" : "NO");
    Serial.print("Es múltiplo de 27: ");
    Serial.println(isMultipleOf27(year) ? "SÍ" : "NO");
    Serial.print("Es múltiplo de 11 Y 27: ");
    Serial.println((isMultipleOf11(year) && isMultipleOf27(year)) ? "SÍ" : "NO");
  }
}

// Función para listar años bisiestos
void listLeapYears() {
  Serial.println("\n--- Años Bisiestos (1800-2025) ---");
  int count = 0;
  for (int year = YEAR_START; year <= YEAR_END; year++) {
    if (isLeapYear(year)) {
      Serial.print(year);
      Serial.print(" ");
      count++;
      if (count % 10 == 0) Serial.println();
    }
  }
  Serial.print("\nTotal: ");
  Serial.println(count);
}

// Función para listar múltiplos de 11 en años no bisiestos
void listMultiplesOf11() {
  Serial.println("\n--- Múltiplos de 11 en años NO BISIESTOS (1800-2025) ---");
  int count = 0;
  for (int year = YEAR_START; year <= YEAR_END; year++) {
    if (!isLeapYear(year) && isMultipleOf11(year)) {
      Serial.print(year);
      Serial.print(" ");
      count++;
      if (count % 10 == 0) Serial.println();
    }
  }
  Serial.print("\nTotal: ");
  Serial.println(count);
}

// Función para listar múltiplos de 27 en años no bisiestos
void listMultiplesOf27() {
  Serial.println("\n--- Múltiplos de 27 en años NO BISIESTOS (1800-2025) ---");
  int count = 0;
  for (int year = YEAR_START; year <= YEAR_END; year++) {
    if (!isLeapYear(year) && isMultipleOf27(year)) {
      Serial.print(year);
      Serial.print(" ");
      count++;
      if (count % 10 == 0) Serial.println();
    }
  }
  Serial.print("\nTotal: ");
  Serial.println(count);
}

// Función para listar múltiplos de 11 Y 27 en años no bisiestos
void listMultiplesOfBoth() {
  Serial.println("\n--- Múltiplos de 11 Y 27 en años NO BISIESTOS (1800-2025) ---");
  int count = 0;
  for (int year = YEAR_START; year <= YEAR_END; year++) {
    if (!isLeapYear(year) && isMultipleOf11(year) && isMultipleOf27(year)) {
      Serial.print(year);
      Serial.print(" ");
      count++;
      if (count % 10 == 0) Serial.println();
    }
  }
  Serial.print("\nTotal: ");
  Serial.println(count);
}

// Interrupción para el botón
void buttonInterrupt() {
  button_pressed = true;
}

void setup() {
  Serial.begin(BAUD_RATE);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonInterrupt, RISING);
  
  Serial.println("\n*** Sistema de Verificación de Años Bisiestos Iniciado ***");
  Serial.println("Presione el pulsador para mostrar el menú...");
}

void loop() {
  if (button_pressed) {
    button_pressed = false;
    delay(300); // Debounce
    
    showMenu();
    
    while (!Serial.available()) delay(100);
    int option = Serial.parseInt();
    
    switch (option) {
      case 1:
        displayStatistics();
        break;
      case 2:
        verifySpecificYear();
        break;
      case 3:
        listLeapYears();
        break;
      case 4:
        listMultiplesOf11();
        break;
      case 5:
        listMultiplesOf27();
        break;
      case 6:
        listMultiplesOfBoth();
        break;
      default:
        Serial.println("Opción inválida. Intente nuevamente.");
    }
    
    Serial.println("\n\nPresione el pulsador nuevamente para ver el menú...");
  }
  delay(100);
}
