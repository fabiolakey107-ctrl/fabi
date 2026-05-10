// Sistema Verificador de Años Bisiestos y Múltiplos
// Versión para Consola C++
// Rango: 1800 - 2025

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int YEAR_START = 1800;
const int YEAR_END = 2025;
const int TOTAL_YEARS = YEAR_END - YEAR_START + 1;

// Variables globales para estadísticas
int leap_years_count = 0;
int non_leap_years_count = 0;
int multiples_11_count = 0;
int multiples_27_count = 0;
int multiples_both_count = 0;
bool led_status = false;

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
    cout << "\n========================================" << endl;
    cout << "  VERIFICADOR DE AÑOS BISIESTOS (1800-2025)" << endl;
    cout << "========================================" << endl;
    cout << "1. Ver estadísticas completas" << endl;
    cout << "2. Verificar un año específico" << endl;
    cout << "3. Listar años bisiestos" << endl;
    cout << "4. Listar múltiplos de 11 (años no bisiestos)" << endl;
    cout << "5. Listar múltiplos de 27 (años no bisiestos)" << endl;
    cout << "6. Listar múltiplos de 11 Y 27 (años no bisiestos)" << endl;
    cout << "7. Salir" << endl;
    cout << "========================================" << endl;
    cout << "Ingrese una opción (1-7): ";
}

// Función para mostrar estadísticas completas
void displayStatistics() {
    calculateStatistics();
    
    double leap_percentage = (double)leap_years_count / TOTAL_YEARS * 100;
    double non_leap_percentage = (double)non_leap_years_count / TOTAL_YEARS * 100;
    
    cout << "\n========== ESTADÍSTICAS (1800-2025) ==========" << endl;
    cout << "Total de años: " << TOTAL_YEARS << endl;
    cout << "Años bisiestos: " << leap_years_count << " (" << fixed << setprecision(2) << leap_percentage << " %)" << endl;
    cout << "Años no bisiestos: " << non_leap_years_count << " (" << fixed << setprecision(2) << non_leap_percentage << " %)" << endl;
    cout << "\n--- Múltiplos en años NO BISIESTOS ---" << endl;
    cout << "Múltiplos de 11: " << multiples_11_count << endl;
    cout << "Múltiplos de 27: " << multiples_27_count << endl;
    cout << "Múltiplos de 11 Y 27: " << multiples_both_count << endl;
    
    // Verificar si enciende el LED
    cout << "\n";
    if (multiples_both_count > 4) {
        cout << "*** [LED ENCENDIDO] ***" << endl;
        cout << "Hay más de 4 múltiplos de 11 Y 27 en años no bisiestos" << endl;
        led_status = true;
    } else {
        cout << "*** [LED APAGADO] ***" << endl;
        cout << "No hay más de 4 múltiplos de 11 Y 27 en años no bisiestos" << endl;
        led_status = false;
    }
    cout << "=============================================" << endl;
}

// Función para verificar un año específico
void verifySpecificYear() {
    int year;
    cout << "\nIngrese el año a verificar (1800-2025): ";
    cin >> year;
    
    if (year < YEAR_START || year > YEAR_END) {
        cout << "Error: El año debe estar entre 1800 y 2025" << endl;
        return;
    }
    
    cout << "\n--- Información del año: " << year << " ---" << endl;
    cout << "Es bisiesto: " << (isLeapYear(year) ? "SÍ" : "NO") << endl;
    
    if (!isLeapYear(year)) {
        cout << "Es múltiplo de 11: " << (isMultipleOf11(year) ? "SÍ" : "NO") << endl;
        cout << "Es múltiplo de 27: " << (isMultipleOf27(year) ? "SÍ" : "NO") << endl;
        cout << "Es múltiplo de 11 Y 27: " << (isMultipleOf11(year) && isMultipleOf27(year) ? "SÍ" : "NO") << endl;
    } else {
        cout << "(Año bisiesto: no se analizan múltiplos)" << endl;
    }
}

// Función para listar años bisiestos
void listLeapYears() {
    cout << "\n--- Años Bisiestos (1800-2025) ---" << endl;
    int count = 0;
    for (int year = YEAR_START; year <= YEAR_END; year++) {
        if (isLeapYear(year)) {
            cout << setw(5) << year << " ";
            count++;
            if (count % 10 == 0) cout << endl;
        }
    }
    cout << "\nTotal: " << count << endl;
}

// Función para listar múltiplos de 11 en años no bisiestos
void listMultiplesOf11() {
    cout << "\n--- Múltiplos de 11 en años NO BISIESTOS (1800-2025) ---" << endl;
    int count = 0;
    for (int year = YEAR_START; year <= YEAR_END; year++) {
        if (!isLeapYear(year) && isMultipleOf11(year)) {
            cout << setw(5) << year << " ";
            count++;
            if (count % 10 == 0) cout << endl;
        }
    }
    cout << "\nTotal: " << count << endl;
}

// Función para listar múltiplos de 27 en años no bisiestos
void listMultiplesOf27() {
    cout << "\n--- Múltiplos de 27 en años NO BISIESTOS (1800-2025) ---" << endl;
    int count = 0;
    for (int year = YEAR_START; year <= YEAR_END; year++) {
        if (!isLeapYear(year) && isMultipleOf27(year)) {
            cout << setw(5) << year << " ";
            count++;
            if (count % 10 == 0) cout << endl;
        }
    }
    cout << "\nTotal: " << count << endl;
}

// Función para listar múltiplos de 11 Y 27 en años no bisiestos
void listMultiplesOfBoth() {
    cout << "\n--- Múltiplos de 11 Y 27 en años NO BISIESTOS (1800-2025) ---" << endl;
    int count = 0;
    for (int year = YEAR_START; year <= YEAR_END; year++) {
        if (!isLeapYear(year) && isMultipleOf11(year) && isMultipleOf27(year)) {
            cout << setw(5) << year << " ";
            count++;
            if (count % 10 == 0) cout << endl;
        }
    }
    cout << "\nTotal: " << count << endl;
}

int main() {
    int option = 0;
    
    cout << "\n*** Sistema de Verificación de Años Bisiestos ***" << endl;
    cout << "Rango: 1800 - 2025" << endl;
    
    while (true) {
        showMenu();
        cin >> option;
        
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
            case 7:
                cout << "\n¡Hasta luego!" << endl;
                return 0;
            default:
                cout << "\nOpción inválida. Intente nuevamente." << endl;
        }
    }
    
    return 0;
}
