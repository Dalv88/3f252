#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "Dibujo.hpp"
#include "GestorDibujos.hpp"

using namespace std::chrono_literals;

int main() {
    srand(time(nullptr));

    // Dimensiones de la pantalla
    int ancho = 60;
    int alto = 20;
    ftxui::Screen screen = ftxui::Screen::Create(
        ftxui::Dimension::Fixed(ancho),
        ftxui::Dimension::Fixed(alto)
    );

    GestorDibujos gestor;

    // Crear gotas iniciales
    int cantidad_gotas = 50;
    for (int i = 0; i < cantidad_gotas; i++) {
        int x = rand() % ancho;
        int y = rand() % alto;
        std::vector<std::u32string> figura = { U"|" };
        gestor.Agregar(Dibujo(x, y, figura, ftxui::Color::Blue));
    }

    // Animación infinita
    while (true) {
        screen.Clear();

        for (auto& gota : gestor.dibujos) {
            gota.y += 1;
            if (gota.y >= alto) {
                gota.y = 0;
                gota.x = rand() % ancho;
            }
        }

        gestor.DibujarTodos(screen);
        screen.Print();
        std::this_thread::sleep_for(100ms);
    }

    return 0;
}