#include <Windows.h>
#include <iostream>

int main(int argc, char** argv) {
    // Encuentra la ventana de Wesnoth.
    HWND wesnoth_window = FindWindow(NULL, L"La batalla por Wesnoth - 1.14.9");
    if (!wesnoth_window) {
        std::cerr << "Error: No se pudo encontrar la ventana." << std::endl;
        return 1;
    }

    // Obtén el ID de proceso para el proceso de Wesnoth.
    DWORD process_id = 0;
    GetWindowThreadProcessId(wesnoth_window, &process_id);
    if (process_id == 0) {
        std::cerr << "Error: No se pudo obtener el ID del proceso." << std::endl;
        return 1;
    }

    // Abre el proceso de Wesnoth con todos los accesos.
    HANDLE wesnoth_process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, process_id);
    if (!wesnoth_process) {
        std::cerr << "Error: No se pudo abrir el proceso." << std::endl;
        return 1;
    }

    // Lee el valor en 0x017EED18 y coloca su valor en la variable gold_value.
    DWORD gold_value = 0;
    SIZE_T bytes_read = 0;
    if (!ReadProcessMemory(wesnoth_process, (void*)0x017EED18, &gold_value, sizeof(gold_value), &bytes_read)) {
        std::cerr << "Error: No se pudo leer la memoria del proceso." << std::endl;
        CloseHandle(wesnoth_process);
        return 1;
    }

    // Añade 0xA90 al valor leído y luego lee el valor en esa nueva dirección.
    gold_value += 0xA90;
    if (!ReadProcessMemory(wesnoth_process, (void*)gold_value, &gold_value, sizeof(gold_value), &bytes_read)) {
        std::cerr << "Error: No se pudo leer la memoria del proceso." << std::endl;
        CloseHandle(wesnoth_process);
        return 1;
    }

    // Añade 4 al gold_value y escribe el nuevo valor de oro.
    gold_value += 4;
    DWORD new_gold_value = 555;
    SIZE_T bytes_written = 0;
    if (!WriteProcessMemory(wesnoth_process, (void*)gold_value, &new_gold_value, sizeof(new_gold_value), &bytes_written)) {
        std::cerr << "Error: No se pudo escribir en la memoria del proceso." << std::endl;
        CloseHandle(wesnoth_process);
        return 1;
    }

    // Cierra el manejador del proceso.
    CloseHandle(wesnoth_process);

    std::cout << "El valor del oro se ha actualizado correctamente." << std::endl;

    return 0;
}
