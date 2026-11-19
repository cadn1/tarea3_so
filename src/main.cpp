#include <iostream>
#include <limits>
#include <sstream>
#include <string>

bool leerEnteroPositivo(const char* mensaje, long long& valor) {
    std::cout << mensaje << std::endl;

    std::string linea; // LEER HASTA ENTER
    if (!std::getline(std::cin, linea)) {
        return false;
    }

    std::istringstream entrada(linea); // VERIFICAR QUE SEA ENTERO POSITIVO (3 CONDICIONES)
    char sobrante;
    return (entrada >> valor) && valor > 0 && !(entrada >> sobrante);
}

int main() {
    constexpr long long kbPorMb = 1024;
    long long discoMb;
    long long bloqueKb;

    if (!leerEnteroPositivo("TAMAÑO DEL DISCO (MB):", discoMb) ||
        !leerEnteroPositivo("TAMAÑO DEL BLOQUE (KB):", bloqueKb)) {
        std::cerr << "[!] ERROR: INGRESA UN ENTERO POSITIVO [!].\n";
        return 1;
    }

    if (discoMb > std::numeric_limits<long long>::max() / kbPorMb) {
        std::cerr << "[!] ERROR: EL TAMAÑO DEL DISCO ES DEMASIADO GRANDE [!].\n";
        return 1;
    }

    const long long discoKb = discoMb * kbPorMb;
    std::cout << "BLOQUES COMPLETOS: " << discoKb / bloqueKb << '\n';
    return 0;
}
