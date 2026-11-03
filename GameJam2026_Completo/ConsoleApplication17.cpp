#include "pch.h"
#include "iostream"
#include "conio.h"
#include "ctime"
#include "windows.h" 

using namespace System;
using namespace std;


void Configurar_Pantalla()
{
    Console::SetWindowSize(120, 30);
    Console::CursorVisible = false;
    SetConsoleOutputCP(CP_UTF8); 
}


enum Colores { AZUL = 1, VERDE = 2, CIAN = 3, ROJO = 4, PURPURA = 5, AMARILLO = 6, BLANCO = 7, GRIS = 8, AZULCLARO = 9, VERDE_CLARO = 10, AGUAMARINA_CLARO = 11, ROJO_CLARO = 12, PURPURA_CLARO = 13, AMARILLO_CLARO = 14, BLANCO_CLARO = 15 };

void CambiarColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//colisiones
bool chocan(int x1, int y1, int ancho1, int alto1, int x2, int y2, int ancho2, int alto2) {
   
    bool colisionX = (x1 < x2 + ancho2) && (x1 + ancho1 > x2);
    bool colisionY = (y1 < y2 + alto2) && (y1 + alto1 > y2);

    return (colisionX && colisionY);
}

//dibujos

void Dibujar_Tierra() {
    CambiarColor(AZUL);

    Console::SetCursorPosition(0, 10); cout << "  .-;;-.";
    Console::SetCursorPosition(0, 11); cout << " / ;;;' \\ ";
    Console::SetCursorPosition(0, 12); cout << "|.  :    | ";
    Console::SetCursorPosition(0, 13); cout << " \\:   ; / ";
    Console::SetCursorPosition(0, 14); cout << "  '-..-'";
}


void Dibujar_Luna() {
    CambiarColor(BLANCO);

    Console::SetCursorPosition(105, 10); cout << "       _..._ ";
    Console::SetCursorPosition(105, 11); cout << "     .' .::::.";
    Console::SetCursorPosition(105, 12); cout << "    :  ::::::::";
    Console::SetCursorPosition(105, 13); cout << "    :  ::::::::";
    Console::SetCursorPosition(105, 14); cout << "    `. '::::::'";
    Console::SetCursorPosition(105, 15); cout << "      `-.::''";
}

void Dibujar_Nave(int x, int y) {
    CambiarColor(CIAN);
    Console::SetCursorPosition(x, y);     cout << " /\\ ";
    Console::SetCursorPosition(x, y + 1); cout << "|O |";
    Console::SetCursorPosition(x, y + 2); cout << "/==\\";
}

void Borrar(int x, int y, int ancho, int alto) {
    for (int i = 0; i < alto; i++) {
        Console::SetCursorPosition(x, y + i);
        for (int j = 0; j < ancho; j++) {
            cout << " ";
        }
    }
}



char Menu() {
    system("cls");
    CambiarColor(CIAN);

    CambiarColor(3);  cout << "███    ███ ██ ███████ ██  ██████  ███    ██ "; CambiarColor(6);   cout << "  ██████  ██████  ██  ██████  ███    ██ " << endl;
    CambiarColor(15); cout << "████  ████ ██ ██      ██ ██    ██ ████   ██ "; CambiarColor(15);  cout << " ██    ██ ██   ██ ██ ██    ██ ████   ██  " << endl;
    CambiarColor(3);  cout << "██ ████ ██ ██ ███████ ██ ██    ██ ██ ██  ██ "; CambiarColor(6);   cout << " ██    ██ ██████  ██ ██    ██ ██ ██  ██ " << endl;
    CambiarColor(15); cout << "██  ██  ██ ██      ██ ██ ██    ██ ██  ██ ██ "; CambiarColor(15);  cout << " ██    ██ ██   ██ ██ ██    ██ ██  ██ ██ " << endl;
    CambiarColor(3);  cout << "██      ██ ██ ███████ ██  ██████  ██   ████ "; CambiarColor(6);   cout << "  ██████  ██   ██ ██  ██████  ██   ████ " << endl;


    Console::SetCursorPosition(83, 13); CambiarColor(15); cout << "⠀⠀    ⠀⠀⠀⠀⠀⣀⡤"; CambiarColor(15); cout << "⣤⣒⣒⡾⢭⡩⠉⢰⢖⣖"; CambiarColor(15); cout << "⠤⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(83, 14); CambiarColor(1); cout << "⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⣿"; CambiarColor(10); cout << "⢷⣫⠤⢲⠄⠀⠀⠧⡵⠀⡛⠉⢂⢄⣀"; CambiarColor(1); cout << "⢻⣶⣄⡀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(83, 15); CambiarColor(1); cout << "⠀⠀⠀⠀⠀⢀⡴"; CambiarColor(10); cout << "⣏⡽⢿⣿⣜⢲⡀⡼⠃⠀⡠⢻⣓⣄⢹⣼⢪⠇⢠⠉⠞⠋⠉"; CambiarColor(1); cout << "⠢⡀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(83, 16); CambiarColor(1); cout << "⠀⠀⠀⢀⣴⠏⠀"; CambiarColor(10); cout << "⢠⠴⢾⡽⣥⡟⡃⢙⡤⢤⡱⣈⠤⡍⣄⣞⠛⣒⣼⣲⠀⠀⠀⠀"; CambiarColor(1); cout << "⠈⢢⡀⠀⠀⠀";
    Console::SetCursorPosition(83, 17); CambiarColor(1); cout << "⠀⠀⢠⡞⠁"; CambiarColor(10); cout << "⠀⠀⠳⡤⡼⠀⠋⠱⣔⢄⡎⠭⠕⠁⠸⢹⠛⢯⣦⠊⠉⠁⠀⠀⠀⠀⠀⠀"; CambiarColor(1); cout << "⠱⡄⠀⠀";
    Console::SetCursorPosition(83, 18); CambiarColor(1); cout << "⠀⢠⡟"; CambiarColor(10); cout << "⠀⠀⠀⠀⠀⠛⠀⠀⢤⣶⡸⡼⠸⡀⠀⠀⠸⢸⢠⠈⠃⡠⠤⣲⣄⢀⣗⣷⡄⢷⡀"; CambiarColor(1); cout << "⠘⡄⠀";
    Console::SetCursorPosition(83, 19); CambiarColor(1); cout << "⠀⣮⠃"; CambiarColor(10); cout << "⠀⠀⠀⠀⠀⢀⡠⠞⠛⠁⠈⠑⡣⠃⠀⠀⢰⢈⠈⡢⠶⠕⠒⣜⡋⣻⣟⢦⠀⠘⠃⠀"; CambiarColor(1); cout << "⢱⡀";
    Console::SetCursorPosition(83, 20); CambiarColor(1); cout << "⢸⢻"; CambiarColor(10); cout << "⠀⠀⠀⠀⠀⢀⡼⣘⡕⠀⠀⠀⠈⠀⠀⠀⢀⢇⢎⡜⠁⠀⠀⠀⢀⠈⠈⠉⠉⣄⠀⠀⠀⡀"; CambiarColor(1); cout << "⡇";
    Console::SetCursorPosition(83, 21); CambiarColor(1); cout << "⡿"; CambiarColor(10); cout << "⡔⢝⣄⢇⢶⠀⠽⢲⠁⠀⠀⠀⠀⠀⠀⠀⠀⢇⢇⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣶⡇⠀"; CambiarColor(1); cout << "⣿";
    Console::SetCursorPosition(83, 22); CambiarColor(1); cout << "⣷"; CambiarColor(10); cout << "⠈⠢⣈⠉⡪⣧⡂⠌⠒⠄⠀⠀⠀⠀⠀⠀⠀⠘⢎⠪⡓⠤⠠⠤⠲⡄⠀⠀⠀⠀⠀⠀⣰⢱⢡"; CambiarColor(1); cout << "⢻";
    Console::SetCursorPosition(83, 23); CambiarColor(1); cout << "⢸⡄"; CambiarColor(10); cout << "⠀⠀⠙⢎⡎⡎⠑⠒⠲⣄⡀⠀⢦⡀⠀⠀⠀⠀⠑⠢⠄⠀⡄⡇⢧⠀⠀⠀⠀⠀⠞⢡⠃"; CambiarColor(1); cout << "⡠⡇";
    Console::SetCursorPosition(83, 24); CambiarColor(1); cout << "⠈⣷ "; CambiarColor(10); cout << "⠀⠀⠀⠘⣇⠇⠀⠀⠀⠀⠹⢂⣂⡀⠉⠲⡄⠀⠀⠀⠀⠀⠁⠠⢸⠀⠀⠀⠀⢸⢀⡹"; CambiarColor(1); cout << "⢱⠁";
    Console::SetCursorPosition(83, 25); CambiarColor(1); cout << "⠀⠘⣧⠀"; CambiarColor(10); cout << "⠀⢰⢇⢆⠀⠀⠀⠀⠀⠀⠀⠈⡵⡀⡅⠀⠀⠀⠀⠀⠀⠀⡎⠀⠀⠀⠰⢳⢫⢣"; CambiarColor(1); cout << "⢣⠇⠀";
    Console::SetCursorPosition(83, 26); CambiarColor(1); cout << "⠀⠀⠘⣧⠀"; CambiarColor(10); cout << "⠀⠳⣗⢳⢤⠀⠀⠀⠀⠀⠸⣰⢱⠁⠀⠀⠀⠀⠀⠀⠀⢹⠀⢀⠜⠁⠓⡣"; CambiarColor(1); cout << "⣣⠏⠀⠀";
    Console::SetCursorPosition(83, 27); CambiarColor(1); cout << "⠀⠀⠀⠀⠙⢷⣄⠀"; CambiarColor(10); cout << "⢫⠘⡄⢀⡞⡝⡰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠁⠒⠒⠊⢁  "; CambiarColor(1); cout << "⡴⠋⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(83, 28); CambiarColor(1); cout << "⠀⠀⠀⠀⠀⠀⠀⠉⠻⢦"; CambiarColor(10); cout << "⣧⡘⢾⣜⠰⡅⠀⠀⠀⠀⠀⠀⠀⠀"; CambiarColor(1); cout << "⠀⠀⢀⡠⠖⠉⠉⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(83, 29); CambiarColor(15); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠳⠿⢤⣌⣀⣀⣀⣀⣀⣠⡤⠤⠖⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";



    Console::SetCursorPosition(52, 7); CambiarColor(15);cout << "⣴⠖⠒⠶⣦⠤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 8);CambiarColor(15); cout << "⡇⠀⣠⠞⠁⢀⡔⠋⢋⠟⢲⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 9);CambiarColor(15); cout << "⢿⠞⠁⢀⡴⠋⠀⠀⠀⠀⠉⠀⢟⡷⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 10); CambiarColor(15);cout << "⢸⡄⣠⠎"; CambiarColor(3); cout << "⠀⢠⢾⣿⣝⢷⡀"; CambiarColor(15); cout << "⠀⠀⠀⠩⣻⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 11); CambiarColor(15); cout << "⠀⢿⠃"; CambiarColor(3); cout << "⠀⠀⢾⢺⣿⣿⣯⠇⠀"; CambiarColor(15); cout << "⠀⠀⠀⠁⠞⣳⣤⠤⠤⠤⢤⣄⣀⡀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 12); CambiarColor(15);cout << "⠀⠘⣧⠂⠀"; CambiarColor(3); cout << "⠈⠳⠿⠿⠋⣠⣶⣶⣦⡀"; CambiarColor(15); cout << "⠀⠐⡡⢻⣦⠤⠤⠤⠤⠤⠉⣳⡄⠀⠀⠀";
    Console::SetCursorPosition(52, 13);CambiarColor(15); cout << "⠀⠀⠹⣏⠀⠀⠀"; CambiarColor(3); cout << "⠀⠀⠀⡇⣿⣿⣏⡇⠀"; CambiarColor(15); cout << "⠀⣠⠏⠙⣆⠀⠀⠀⠀⠀⠀⢹⡀⠀⠀";
    Console::SetCursorPosition(52, 14);CambiarColor(15); cout << "⠀⠀⠀⠙⣖⠴⡂⠀"; CambiarColor(3); cout << "⠀⠀⠙⠯⠿⠞⠁"; CambiarColor(15); cout << "⢀⡞⠁⢠⠾⢿⡆⠀⠀⠀⠀⠀⠘⣇⠀⠀";
    Console::SetCursorPosition(52, 15); CambiarColor(15);cout << "⠀⠀⠀⠀⠘⢿⣔⡠⢀⠀⠀⠀⠀⠀⡴⢻⡶⣴⣃⠀⢐⡿⠒⠒⠒⢦⡀⠀⢻⠀⠀";
    Console::SetCursorPosition(52, 16);CambiarColor(15); cout << " ⠀⠀⠀⠀⠀⠙⢶⣥⢂⠀⠀⣠⠎⠀⡰⢷⡀⠉⠛⣟⠁⠀⠀⠀⠀⠙⢦⣸⡆⠀";
    Console::SetCursorPosition(52, 17);CambiarColor(15); cout << " ⠀⠀⠀⠀⠀⠀⠀⢿⢻⣦⣞⡁⡠⢊⠀⠀⣷⣄⣀"; CambiarColor(12); cout << "⠹⣗⠶⣄⡀⠀⠀"; CambiarColor(15); cout << "⠈⠻⡇⠀";
    Console::SetCursorPosition(52, 18);CambiarColor(15); cout << " ⠀⠀⠀⠀⠀⠀⠀⢸⠀⡇⠈⠉⠛⠿⢷⡞⠁"; CambiarColor(12); cout << "⠈⢿"; CambiarColor(6); cout << "⠻⣿⠗⣌"; CambiarColor(12); cout << "⠻⣦⡀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 19); CambiarColor(15);cout << " ⠀⠀⠀⠀⠀⠀⠀⢸⡆⢧⠀⠀⠀⠀⠘⡇⠀⠀"; CambiarColor(12); cout << "⠈⢷⣌"; CambiarColor(6); cout << "⠳⣌"; CambiarColor(6); cout << "⠳⡈"; CambiarColor(12); cout << "⠻⣄⠀⠀⠀";
    Console::SetCursorPosition(52, 20);CambiarColor(15); cout << " ⠀⠀⠀⠀⠀⠀⠀⠀⢷⢸⡀⠀⠀⠀⠀⠳⣄⠀⠀⠀"; CambiarColor(12); cout << "⠙⠷⣄"; CambiarColor(6); cout << "⡙⠻⠄"; CambiarColor(12); cout << "⠹⣆⠀⠀";
    Console::SetCursorPosition(52, 21); CambiarColor(15);cout << " ⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⢧⣄⣀⠀⠀⠀⠘⢷⣄⠀⠀⠀"; CambiarColor(12); cout << "⠈⠛⠶⣄⣀⠘⣆⠀";
    Console::SetCursorPosition(52, 22);CambiarColor(15); cout << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠙⠓⠒⠒⠛⠃⠀⠀⠀"; CambiarColor(12); cout << "⠀⠀⠀⠉⠛⠾⠆";


    CambiarColor(15);

    Console::SetCursorPosition(5, 15);cout << " ╔═════════════════   MENÚ   ════════════════╗";
    Console::SetCursorPosition(5, 16);cout << " ║                                           ║";
    Console::SetCursorPosition(5, 17);cout << " ║                                           ║";
    Console::SetCursorPosition(5, 18);cout << " ║        1. Iniciar partida                 ║";
    Console::SetCursorPosition(5, 19);cout << " ║        2. Creditos                        ║";
    Console::SetCursorPosition(5, 20);cout << " ║        3. Salir                           ║";
    Console::SetCursorPosition(5, 21);cout << " ║                                           ║";
    Console::SetCursorPosition(5, 22);cout << " ║                                           ║";
    Console::SetCursorPosition(5, 23);cout << " ║                            © Game Jam 2026║";
    Console::SetCursorPosition(5, 24);cout << " ╚═══════════════════════════════════════════╝";



    return _getch();
}

void Titulo_Juego() {
    system("cls");
    
    Console::SetCursorPosition(23, 0); cout << "     __  ____________ ________  _   __    ____  ____  ________  _   __    \n";
    Console::SetCursorPosition(23, 1); cout << "    /  |/  /  _/ ___//  _/ __ \\/ | / /   / __ \\/ __ \\/  _/ __ \\/ | / /    \n";
    Console::SetCursorPosition(23, 2); cout << "   / /|_/ // / \\__ \\ / // / / /  |/ /   / / / / /_/ // // / / /  |/ /     \n";
    Console::SetCursorPosition(23, 3); cout << "  / /  / // / ___/ // // /_/ / /|  /   / /_/ / _, _// // /_/ / /|  /      \n";
    Console::SetCursorPosition(23, 4); cout << " /_/  /_/___//____/___/\\____/_/ |_/    \\____/_/ |_/___/\\____/_/ |_/       \n";

    Console::SetCursorPosition(28, 6); cout << "                       .'_.- ('''') -._'.";
    Console::SetCursorPosition(28, 7); cout << "                     .'.'    |'..'|    '.'.";
    Console::SetCursorPosition(28, 8); cout << "              .-.  .' /'--.__|____|__.--'\\ '.  .-.";
    Console::SetCursorPosition(28, 9); cout << "             (O).)-| |  \\    |    |    /  | |-(.(O)";
    Console::SetCursorPosition(28, 10); cout << "              -'  '-'-._'-./      \\.-'_.-'-'  -'";
    Console::SetCursorPosition(28, 11); cout << "                 _ | |   '-.________.-'   | | _";
    Console::SetCursorPosition(28, 12); cout << "              .' _ | |     |   __   |     | | _ '.";
    Console::SetCursorPosition(28, 13); cout << "             / .' ''.|     | /    \\ |     |.'' '. \\";
    Console::SetCursorPosition(28, 14); cout << "             | |( )| '.    ||      ||    .' |( )| |";
    Console::SetCursorPosition(28, 15); cout << "             \\ '._.'   '.  | \\    / |  .'   '._.' /";
    Console::SetCursorPosition(28, 16); cout << "              '.__ ______'.|__'--'__|.'______ __.'";
    Console::SetCursorPosition(28, 17); cout << "             .'_.-|         |------|         |-._'.";
    Console::SetCursorPosition(28, 18); cout << "            //\\\\  |         |--::--|         |  //\\\\";
    Console::SetCursorPosition(28, 19); cout << "           //  \\\\ |         |--::--|         | //  \\\\";
    Console::SetCursorPosition(28, 20); cout << "          //    \\\\|        /|--::--|\\        |//    \\\\";
    Console::SetCursorPosition(28, 21); cout << "         / '._.-'/|_______/ |--::--| \\_______|\\-._.' \\";
    Console::SetCursorPosition(28, 22); cout << "        / __..--'        /__|--::--|__\\       '--..__ \\";
    Console::SetCursorPosition(28, 23); cout << "       / /               '-.|--::--|.-'              \\ \\";
    Console::SetCursorPosition(28, 24); cout << "      / /                   |--::--|                  \\ \\";
    Console::SetCursorPosition(28, 25); cout << "     / /                    |--::--|                   \\ \\";
    Console::SetCursorPosition(28, 26); cout << "  .-'  -.                  _..||.._                   .- '-.";

    Console::SetCursorPosition(77, 29); cout << "Presiona cualquier tecla para continuar...";

    system("pause>0");
}

void Introduccion() {
    system("cls");

    Console::SetCursorPosition(20, 4); cout << "    ____ _   __ _________  ____  ____  __  __  ______ ______ ____  ____  _   __ \n";
    Console::SetCursorPosition(20, 5); cout << "   /  _// | / //_  __/ __ \\/ __ \\/ __ \\/ / / // ____// ____//  _// __ \\/ | / / \n";
    Console::SetCursorPosition(20, 6); cout << "   / / /  |/ /  / / / /_/ / / / / / / / / / // /    / /     / / / / / /  |/ /  \n";
    Console::SetCursorPosition(20, 7); cout << " _/ / / /|  /  / / / _, _/ /_/ / /_/ / /_/ // /___ / /___ _/ / / /_/ / /|  /   \n";
    Console::SetCursorPosition(20, 8); cout << "/___//_/ |_/  /_/ /_/ |_|\\____/_____/\\____/ \\____/ \\____//___/ \\____//_/ |_/   \n";

    Console::SetCursorPosition(24, 12); cout << "======================================================================";
    Console::SetCursorPosition(24, 13); cout << "  La Tierra se encuentra en proceso de colonizacion lunar. Tu mision  ";
    Console::SetCursorPosition(24, 14); cout << "  es pilotar la nave Orion y rescatar a las personas en la Tierra,    ";
    Console::SetCursorPosition(24, 15); cout << "  trasladandolas hacia un lugar seguro en la Luna.                    ";
    Console::SetCursorPosition(24, 16); cout << "======================================================================";

    Console::SetCursorPosition(24, 17); cout << " INSTRUCCIONES Y REGLAS:";

    Console::SetCursorPosition(24, 18); cout << " - Capacidad: La nave Orion solo rescata 2 personas a la vez.";
    Console::SetCursorPosition(24, 19); cout << " - Peligro: Evita la lluvia de meteoritos durante el viaje.";
    Console::SetCursorPosition(24, 20); cout << " - Limite: Tienes 3 vidas y un tiempo aleatorio entre 80 y 120 segundos.";
    Console::SetCursorPosition(24, 21); cout << " - Controles: Usa W, A, S, D para moverte.";
    Console::SetCursorPosition(24, 22); cout << " - Velocidad: Velocidad aleaoria entre partidas (3 velocidades).";
    Console::SetCursorPosition(24, 23); cout << "======================================================================";
    Console::SetCursorPosition(26, 25); cout << "Presiona cualquier tecla para aceptar la mision...";

    system("pause>0");
}



//panesl del juego
void Dibujar_Panel(int velocidad, int vidas, int pasajeros, int tiempoRestante, int rescatadosLuna) {
    CambiarColor(BLANCO);
    Console::SetCursorPosition(2, 1);  cout << "NAVE: Orion | VEL: " << velocidad << "   ";
    Console::SetCursorPosition(35, 1); cout << "VIDAS: " << vidas << " | PASAJEROS: " << pasajeros << "/2   ";
    Console::SetCursorPosition(75, 1); cout << "TIEMPO: " << tiempoRestante << "s | RESCATADOS: " << rescatadosLuna << "/12   ";
}


void Dibujar_Personas(int personaX[], int personaY[], bool personaEstaRescatada[], int personaColor[], int TOTAL_PERSONAS) {
    for (int i = 0; i < TOTAL_PERSONAS; i++) {
        if (personaEstaRescatada[i] == false) {
            
            Console::SetCursorPosition(personaX[i], personaY[i]);
            CambiarColor(14); 
            cout << "O";      
            Console::SetCursorPosition(personaX[i], personaY[i] + 1);
            CambiarColor(personaColor[i]);
            cout << "█";      
        }
    }
}


void Mover_Nave(int& naveX, int& naveY, int naveAncho, int naveAlto, int naveVelocidad) {
    if (_kbhit()) {
        char tecla = _getch();
        Borrar(naveX, naveY, naveAncho, naveAlto);

        if ((tecla == 'w' || tecla == 'W') && naveY > 3)   naveY -= naveVelocidad;
        if ((tecla == 's' || tecla == 'S') && naveY < 25)  naveY += naveVelocidad;
        if ((tecla == 'a' || tecla == 'A') && naveX > 11)  naveX -= naveVelocidad;
        if ((tecla == 'd' || tecla == 'D') && naveX < 100) naveX += naveVelocidad;
    }
}


void Actualizar_Meteoritos(int meteoritoX[], int meteoritoY[], int TOTAL_METEORITOS, int& naveX, int& naveY, int naveAncho, int naveAlto, int& naveVidas, bool& gameOver) {
    CambiarColor(ROJO);
    for (int i = 0; i < TOTAL_METEORITOS; i++) {
        Console::SetCursorPosition(meteoritoX[i], meteoritoY[i]);
        cout << " ";

        
        if (rand() % 2 == 0) {  //paar velocidad de meteoritos laetorio
            meteoritoY[i] += 1;
        }

        if (meteoritoY[i] > 28) {
            meteoritoY[i] = 2;
            meteoritoX[i] = (rand() % 60) + 30;
        }

        Console::SetCursorPosition(meteoritoX[i], meteoritoY[i]);
        cout << "*";

        if (chocan(naveX, naveY, naveAncho, naveAlto, meteoritoX[i], meteoritoY[i], 1, 1)) {
            Borrar(naveX, naveY, naveAncho, naveAlto);
            naveVidas -= 1;
            naveX = 12;
            naveY = 15;
            if (naveVidas <= 0) {
                gameOver = true;
            }
        }
    }
}


void Gestionar_Rescates(int& naveX, int& naveY, int naveAncho, int naveAlto, int& navePasajeros, int personaX[], int personaY[], bool personaEstaRescatada[], int TOTAL_PERSONAS, int& totalRescatadosEnLuna, bool& victoria) {
    for (int i = 0; i < TOTAL_PERSONAS; i++) {
        if (personaEstaRescatada[i] == false && navePasajeros < 2) {
            
            if (chocan(naveX, naveY, naveAncho, naveAlto, personaX[i], personaY[i], 1, 2)) {
            
                Console::SetCursorPosition(personaX[i], personaY[i]); cout << " ";
                Console::SetCursorPosition(personaX[i], personaY[i] + 1); cout << " ";
                personaEstaRescatada[i] = true;
                personaX[i] = -1;
                navePasajeros += 1;
            }
        }
    }

    if (naveX >= 99 && navePasajeros > 0) {
        totalRescatadosEnLuna += navePasajeros;
        navePasajeros = 0;
        if (totalRescatadosEnLuna >= TOTAL_PERSONAS) {
            victoria = true;
        }
    }
}


void Juego() {
    system("cls");
    Dibujar_Tierra();
    Dibujar_Luna();
    int naveX = 12, naveY = 15, naveAncho = 4, naveAlto = 3;
    
    int naveVidas = 3, navePasajeros = 0, naveVelocidad = (rand() % 3) + 1;

    const int TOTAL_PERSONAS = 12;
    int personaX[TOTAL_PERSONAS], personaY[TOTAL_PERSONAS];
    bool personaEstaRescatada[TOTAL_PERSONAS];
    int personaColor[TOTAL_PERSONAS]; 

    
    for (int i = 0; i < TOTAL_PERSONAS; i++) {
        bool posicionValida;
        do {
            posicionValida = true;
            personaX[i] = (rand() % 10) + 12;
            personaY[i] = (rand() % 15) + 5;

            for (int j = 0; j < i; j++) {
                if (personaX[i] == personaX[j] && personaY[i] == personaY[j]) {
                    posicionValida = false; 
                    break;
                }
            }
        } while (!posicionValida);

        personaEstaRescatada[i] = false;

        personaColor[i] = (rand() % 15) + 1;
    }

    const int TOTAL_METEORITOS = 4;
    int meteoritoX[TOTAL_METEORITOS], meteoritoY[TOTAL_METEORITOS];

    for (int i = 0; i < TOTAL_METEORITOS; i++) {
        meteoritoX[i] = (rand() % 60) + 30;
        meteoritoY[i] = (rand() % 20) + 2;
    }

    int tiempoTotal = 80 + rand() % 41;
    time_t tiempoInicio = time(0);
    int totalRescatadosEnLuna = 0;
    bool gameOver = false, victoria = false;

    while (!gameOver && !victoria) {
        int tiempoActual = time(0) - tiempoInicio;
        int tiempoRestante = tiempoTotal - tiempoActual;

        if (tiempoRestante <= 0) {
            gameOver = true;
            break;
        }

        Dibujar_Panel(naveVelocidad, naveVidas, navePasajeros, tiempoRestante, totalRescatadosEnLuna);

        
        Dibujar_Personas(personaX, personaY, personaEstaRescatada, personaColor, TOTAL_PERSONAS);

        Mover_Nave(naveX, naveY, naveAncho, naveAlto, naveVelocidad);
        Dibujar_Nave(naveX, naveY);

        Actualizar_Meteoritos(meteoritoX, meteoritoY, TOTAL_METEORITOS, naveX, naveY, naveAncho, naveAlto, naveVidas, gameOver);
        Gestionar_Rescates(naveX, naveY, naveAncho, naveAlto, navePasajeros, personaX, personaY, personaEstaRescatada, TOTAL_PERSONAS, totalRescatadosEnLuna, victoria);

        Sleep(40);
    }

    system("cls");
    if (victoria) {
        do
        {
            CambiarColor(VERDE);

            Console::SetCursorPosition(0, 6);
            for (int i = 0; i < 120; i++)
            {
                cout << "=";
            }

            Console::SetCursorPosition(33, 8);  cout << "  _  _____          _   _           _____ _______ ______ _ ";
            Console::SetCursorPosition(33, 9);  cout << " (_)/ ____|   /\\   | \\ | |   /\\    / ____|__   __|  ____| |";
            Console::SetCursorPosition(33, 10); cout << " | | |  __   /  \\  |  \\| |  /  \\  | (___    | |  | |__  | |";
            Console::SetCursorPosition(33, 11); cout << " | | | |_ | / /\\ \\ | . ` | / /\\ \\  \\___ \\   | |  |  __| | |";
            Console::SetCursorPosition(33, 12); cout << " | | |__| |/ ____ \\| |\\  |/ ____ \\ ____) |  | |  | |____|_|";
            Console::SetCursorPosition(33, 13); cout << " |_|\\_____/_/    \\_\\_| \\_/_/    \\_\\_____/   |_|  |______(_)";

            CambiarColor(15);
            Console::SetCursorPosition(35, 17); cout << "        PRESIONE ESPACIO PARA VOLVER AL MENU          ";

            CambiarColor(VERDE);

            Console::SetCursorPosition(0, 19);
            for (int i = 0; i < 120; i++)
            {
                cout << "=";
            }



        } while (_getch() != ' ');


    }
    else {

        do
        {
            CambiarColor(ROJO);

            Console::SetCursorPosition(0, 6);
            for (int i = 0; i < 120; i++)
            {
                cout << "=";
            }


            Console::SetCursorPosition(35, 8);   cout << "                 *             )            (     ";
            Console::SetCursorPosition(35, 9);  cout << " (       (     (  `         ( /(            )\\ )  ";
            Console::SetCursorPosition(35, 10); cout << " )\\ )    )\\    )\\))(  (     )\\())(   (  (  (()/(  ";
            Console::SetCursorPosition(35, 11); cout << "(()/( ((((_)( ((_)()\\ )\\   ((_)\\ )\\  )\\ )\\  /(_)) ";
            Console::SetCursorPosition(35, 12); cout << " /(_))_)\ _ )\(_()((_|(_)    ((_|(_)((_|(_)(_))   ";
            Console::SetCursorPosition(35, 13); cout << "(_)) __(_)_\\(_)  \\/  | __|  / _ \\ \\ / /| __| _ \\  ";
            Console::SetCursorPosition(35, 14); cout << "  | (_ |/ _ \\ | |\\/| | _|  | (_) \\ V / | _||   /  ";
            Console::SetCursorPosition(35, 15); cout << "   \\___/_/ \\_\\|_|  |_|___|  \___/ \\_/  |___|_|_\\  ";
            CambiarColor(15);
            Console::SetCursorPosition(35, 17); cout << "        PRESIONE ESPACIO PARA VOLVER AL MENU          ";

            CambiarColor(ROJO);

            Console::SetCursorPosition(0, 19);
            for (int i = 0; i < 120; i++)
            {
                cout << "=";
            }


        } while (_getch() != ' ');


    }
}

void Creditos() {
    system("cls");


    CambiarColor(3);  cout << "███    ███ ██ ███████ ██  ██████  ███    ██ "; CambiarColor(6);   cout << "  ██████  ██████  ██  ██████  ███    ██ " << endl;
    CambiarColor(15); cout << "████  ████ ██ ██      ██ ██    ██ ████   ██ "; CambiarColor(15);  cout << " ██    ██ ██   ██ ██ ██    ██ ████   ██  " << endl;
    CambiarColor(3);  cout << "██ ████ ██ ██ ███████ ██ ██    ██ ██ ██  ██ "; CambiarColor(6);   cout << " ██    ██ ██████  ██ ██    ██ ██ ██  ██ " << endl;
    CambiarColor(15); cout << "██  ██  ██ ██      ██ ██ ██    ██ ██  ██ ██ "; CambiarColor(15);  cout << " ██    ██ ██   ██ ██ ██    ██ ██  ██ ██ " << endl;
    CambiarColor(3);  cout << "██      ██ ██ ███████ ██  ██████  ██   ████ "; CambiarColor(6);   cout << "  ██████  ██   ██ ██  ██████  ██   ████ " << endl;


    Console::SetCursorPosition(83, 13); CambiarColor(15); cout << "⠀⠀    ⠀⠀⠀⠀⠀⣀⡤"; CambiarColor(15); cout << "⣤⣒⣒⡾⢭⡩⠉⢰⢖⣖"; CambiarColor(15); cout << "⠤⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(83, 14); CambiarColor(1); cout << "⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⣿"; CambiarColor(10); cout << "⢷⣫⠤⢲⠄⠀⠀⠧⡵⠀⡛⠉⢂⢄⣀"; CambiarColor(1); cout << "⢻⣶⣄⡀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(83, 15); CambiarColor(1); cout << "⠀⠀⠀⠀⠀⢀⡴"; CambiarColor(10); cout << "⣏⡽⢿⣿⣜⢲⡀⡼⠃⠀⡠⢻⣓⣄⢹⣼⢪⠇⢠⠉⠞⠋⠉"; CambiarColor(1); cout << "⠢⡀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(83, 16); CambiarColor(1); cout << "⠀⠀⠀⢀⣴⠏⠀"; CambiarColor(10); cout << "⢠⠴⢾⡽⣥⡟⡃⢙⡤⢤⡱⣈⠤⡍⣄⣞⠛⣒⣼⣲⠀⠀⠀⠀"; CambiarColor(1); cout << "⠈⢢⡀⠀⠀⠀";
    Console::SetCursorPosition(83, 17); CambiarColor(1); cout << "⠀⠀⢠⡞⠁"; CambiarColor(10); cout << "⠀⠀⠳⡤⡼⠀⠋⠱⣔⢄⡎⠭⠕⠁⠸⢹⠛⢯⣦⠊⠉⠁⠀⠀⠀⠀⠀⠀"; CambiarColor(1); cout << "⠱⡄⠀⠀";
    Console::SetCursorPosition(83, 18); CambiarColor(1); cout << "⠀⢠⡟"; CambiarColor(10); cout << "⠀⠀⠀⠀⠀⠛⠀⠀⢤⣶⡸⡼⠸⡀⠀⠀⠸⢸⢠⠈⠃⡠⠤⣲⣄⢀⣗⣷⡄⢷⡀"; CambiarColor(1); cout << "⠘⡄⠀";
    Console::SetCursorPosition(83, 19); CambiarColor(1); cout << "⠀⣮⠃"; CambiarColor(10); cout << "⠀⠀⠀⠀⠀⢀⡠⠞⠛⠁⠈⠑⡣⠃⠀⠀⢰⢈⠈⡢⠶⠕⠒⣜⡋⣻⣟⢦⠀⠘⠃⠀"; CambiarColor(1); cout << "⢱⡀";
    Console::SetCursorPosition(83, 20); CambiarColor(1); cout << "⢸⢻"; CambiarColor(10); cout << "⠀⠀⠀⠀⠀⢀⡼⣘⡕⠀⠀⠀⠈⠀⠀⠀⢀⢇⢎⡜⠁⠀⠀⠀⢀⠈⠈⠉⠉⣄⠀⠀⠀⡀"; CambiarColor(1); cout << "⡇";
    Console::SetCursorPosition(83, 21); CambiarColor(1); cout << "⡿"; CambiarColor(10); cout << "⡔⢝⣄⢇⢶⠀⠽⢲⠁⠀⠀⠀⠀⠀⠀⠀⠀⢇⢇⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣶⡇⠀"; CambiarColor(1); cout << "⣿";
    Console::SetCursorPosition(83, 22); CambiarColor(1); cout << "⣷"; CambiarColor(10); cout << "⠈⠢⣈⠉⡪⣧⡂⠌⠒⠄⠀⠀⠀⠀⠀⠀⠀⠘⢎⠪⡓⠤⠠⠤⠲⡄⠀⠀⠀⠀⠀⠀⣰⢱⢡"; CambiarColor(1); cout << "⢻";
    Console::SetCursorPosition(83, 23); CambiarColor(1); cout << "⢸⡄"; CambiarColor(10); cout << "⠀⠀⠙⢎⡎⡎⠑⠒⠲⣄⡀⠀⢦⡀⠀⠀⠀⠀⠑⠢⠄⠀⡄⡇⢧⠀⠀⠀⠀⠀⠞⢡⠃"; CambiarColor(1); cout << "⡠⡇";
    Console::SetCursorPosition(83, 24); CambiarColor(1); cout << "⠈⣷ "; CambiarColor(10); cout << "⠀⠀⠀⠘⣇⠇⠀⠀⠀⠀⠹⢂⣂⡀⠉⠲⡄⠀⠀⠀⠀⠀⠁⠠⢸⠀⠀⠀⠀⢸⢀⡹"; CambiarColor(1); cout << "⢱⠁";
    Console::SetCursorPosition(83, 25); CambiarColor(1); cout << "⠀⠘⣧⠀"; CambiarColor(10); cout << "⠀⢰⢇⢆⠀⠀⠀⠀⠀⠀⠀⠈⡵⡀⡅⠀⠀⠀⠀⠀⠀⠀⡎⠀⠀⠀⠰⢳⢫⢣"; CambiarColor(1); cout << "⢣⠇⠀";
    Console::SetCursorPosition(83, 26); CambiarColor(1); cout << "⠀⠀⠘⣧⠀"; CambiarColor(10); cout << "⠀⠳⣗⢳⢤⠀⠀⠀⠀⠀⠸⣰⢱⠁⠀⠀⠀⠀⠀⠀⠀⢹⠀⢀⠜⠁⠓⡣"; CambiarColor(1); cout << "⣣⠏⠀⠀";
    Console::SetCursorPosition(83, 27); CambiarColor(1); cout << "⠀⠀⠀⠀⠙⢷⣄⠀"; CambiarColor(10); cout << "⢫⠘⡄⢀⡞⡝⡰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠁⠒⠒⠊⢁  "; CambiarColor(1); cout << "⡴⠋⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(83, 28); CambiarColor(1); cout << "⠀⠀⠀⠀⠀⠀⠀⠉⠻⢦"; CambiarColor(10); cout << "⣧⡘⢾⣜⠰⡅⠀⠀⠀⠀⠀⠀⠀⠀"; CambiarColor(1); cout << "⠀⠀⢀⡠⠖⠉⠉⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(83, 29); CambiarColor(15); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠳⠿⢤⣌⣀⣀⣀⣀⣀⣠⡤⠤⠖⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";




    Console::SetCursorPosition(52, 7); CambiarColor(15);cout << "⣴⠖⠒⠶⣦⠤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 8);CambiarColor(15); cout << "⡇⠀⣠⠞⠁⢀⡔⠋⢋⠟⢲⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 9);CambiarColor(15); cout << "⢿⠞⠁⢀⡴⠋⠀⠀⠀⠀⠉⠀⢟⡷⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 10); CambiarColor(15);cout << "⢸⡄⣠⠎"; CambiarColor(3); cout << "⠀⢠⢾⣿⣝⢷⡀"; CambiarColor(15); cout << "⠀⠀⠀⠩⣻⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 11); CambiarColor(15); cout << "⠀⢿⠃"; CambiarColor(3); cout << "⠀⠀⢾⢺⣿⣿⣯⠇⠀"; CambiarColor(15); cout << "⠀⠀⠀⠁⠞⣳⣤⠤⠤⠤⢤⣄⣀⡀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 12); CambiarColor(15);cout << "⠀⠘⣧⠂⠀"; CambiarColor(3); cout << "⠈⠳⠿⠿⠋⣠⣶⣶⣦⡀"; CambiarColor(15); cout << "⠀⠐⡡⢻⣦⠤⠤⠤⠤⠤⠉⣳⡄⠀⠀⠀";
    Console::SetCursorPosition(52, 13);CambiarColor(15); cout << "⠀⠀⠹⣏⠀⠀⠀"; CambiarColor(3); cout << "⠀⠀⠀⡇⣿⣿⣏⡇⠀"; CambiarColor(15); cout << "⠀⣠⠏⠙⣆⠀⠀⠀⠀⠀⠀⢹⡀⠀⠀";
    Console::SetCursorPosition(52, 14);CambiarColor(15); cout << "⠀⠀⠀⠙⣖⠴⡂⠀"; CambiarColor(3); cout << "⠀⠀⠙⠯⠿⠞⠁"; CambiarColor(15); cout << "⢀⡞⠁⢠⠾⢿⡆⠀⠀⠀⠀⠀⠘⣇⠀⠀";
    Console::SetCursorPosition(52, 15); CambiarColor(15);cout << "⠀⠀⠀⠀⠘⢿⣔⡠⢀⠀⠀⠀⠀⠀⡴⢻⡶⣴⣃⠀⢐⡿⠒⠒⠒⢦⡀⠀⢻⠀⠀";
    Console::SetCursorPosition(52, 16);CambiarColor(15); cout << " ⠀⠀⠀⠀⠀⠙⢶⣥⢂⠀⠀⣠⠎⠀⡰⢷⡀⠉⠛⣟⠁⠀⠀⠀⠀⠙⢦⣸⡆⠀";
    Console::SetCursorPosition(52, 17);CambiarColor(15); cout << " ⠀⠀⠀⠀⠀⠀⠀⢿⢻⣦⣞⡁⡠⢊⠀⠀⣷⣄⣀"; CambiarColor(12); cout << "⠹⣗⠶⣄⡀⠀⠀"; CambiarColor(15); cout << "⠈⠻⡇⠀";
    Console::SetCursorPosition(52, 18);CambiarColor(15); cout << " ⠀⠀⠀⠀⠀⠀⠀⢸⠀⡇⠈⠉⠛⠿⢷⡞⠁"; CambiarColor(12); cout << "⠈⢿"; CambiarColor(6); cout << "⠻⣿⠗⣌"; CambiarColor(12); cout << "⠻⣦⡀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 19); CambiarColor(15);cout << " ⠀⠀⠀⠀⠀⠀⠀⢸⡆⢧⠀⠀⠀⠀⠘⡇⠀⠀"; CambiarColor(12); cout << "⠈⢷⣌"; CambiarColor(6); cout << "⠳⣌"; CambiarColor(6); cout << "⠳⡈"; CambiarColor(12); cout << "⠻⣄⠀⠀⠀";
    Console::SetCursorPosition(52, 20);CambiarColor(15); cout << " ⠀⠀⠀⠀⠀⠀⠀⠀⢷⢸⡀⠀⠀⠀⠀⠳⣄⠀⠀⠀"; CambiarColor(12); cout << "⠙⠷⣄"; CambiarColor(6); cout << "⡙⠻⠄"; CambiarColor(12); cout << "⠹⣆⠀⠀";
    Console::SetCursorPosition(52, 21); CambiarColor(15);cout << " ⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⢧⣄⣀⠀⠀⠀⠘⢷⣄⠀⠀⠀"; CambiarColor(12); cout << "⠈⠛⠶⣄⣀⠘⣆⠀";
    Console::SetCursorPosition(52, 22);CambiarColor(15); cout << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠙⠓⠒⠒⠛⠃⠀⠀⠀"; CambiarColor(12); cout << "⠀⠀⠀⠉⠛⠾⠆";



    CambiarColor(15);

    Console::SetCursorPosition(5, 15);cout << " ╔═════════════════ CREDITOS ════════════════╗";
    Console::SetCursorPosition(5, 16);cout << " ║                                           ║";
    Console::SetCursorPosition(5, 17);cout << " ║                                           ║";
    Console::SetCursorPosition(5, 18);cout << " ║        Programador: Robben Cercado        ║";
    Console::SetCursorPosition(5, 19);cout << " ║        Programador: Mateo Alvarado        ║";
    Console::SetCursorPosition(5, 20);cout << " ║   Programador y diseño: Rodrigo Cerrano   ║";
    Console::SetCursorPosition(5, 21);cout << " ║              © Game Jam 2026              ║";
    Console::SetCursorPosition(5, 22);cout << " ║                                           ║";
    Console::SetCursorPosition(5, 23);cout << " ║                                           ║";
    Console::SetCursorPosition(5, 24);cout << " ╚═══════════════════════════════════════════╝";
    Console::SetCursorPosition(5, 26);cout << "    Presiona espacio para volver al Menú...   ";


   
}





void Despedida() {
    system("cls");



    CambiarColor(3); cout << " ██████╗ ██████╗  █████╗  ██████╗██╗ █████╗ ███████╗ "; CambiarColor(6);cout << "██████╗  ██████╗ ██████╗     ██╗██╗   ██╗ ██████╗  █████╗ ██████╗" << endl;
    CambiarColor(15); cout << "██╔════╝ ██╔══██╗██╔══██╗██╔════╝██║██╔══██╗██╔════╝ "; CambiarColor(15);cout << "██╔══██╗██╔═══██╗██╔══██╗    ██║██║   ██║██╔════╝ ██╔══██╗██╔══██╗" << endl;
    CambiarColor(3); cout << "██║  ███╗██████╔╝███████║██║     ██║███████║███████╗ "; CambiarColor(6);cout << "██████╔╝██║   ██║██████╔╝    ██║██║   ██║██║  ███╗███████║██████╔╝" << endl;
    CambiarColor(15); cout << "██║   ██║██╔══██╗██╔══██║██║     ██║██╔══██║╚════██║ "; CambiarColor(15);cout << "██╔═══╝ ██║   ██║██╔══██╗    ██║██║   ██║██║   ██║██║  ██║██║  ██╗" << endl;
    CambiarColor(3); cout << "╚██████╔╝██║  ██║██║  ██║╚██████╗██║██║  ██║███████║ "; CambiarColor(6);cout << "██║     ╚██████╔╝██║  ██║╚█████║ ██████╔╝██████╔═╝██║  ██║██║  ██║" << endl;
    CambiarColor(3); cout << " ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝╚═╝╚═╝  ╚═╝╚══════╝ "; CambiarColor(6);cout << "╚═╝      ╚═════╝ ╚═╝  ╚═╝ ╚═══╝  ╚════╝  ╚═════╝  ╚═╝  ╚═╝╚═╝  ╚═╝" << endl;



    Console::SetCursorPosition(83, 13); CambiarColor(15); cout << "⠀⠀    ⠀⠀⠀⠀⠀⣀⡤"; CambiarColor(15); cout << "⣤⣒⣒⡾⢭⡩⠉⢰⢖⣖"; CambiarColor(15); cout << "⠤⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(83, 14); CambiarColor(1); cout << "⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⣿"; CambiarColor(10); cout << "⢷⣫⠤⢲⠄⠀⠀⠧⡵⠀⡛⠉⢂⢄⣀"; CambiarColor(1); cout << "⢻⣶⣄⡀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(83, 15); CambiarColor(1); cout << "⠀⠀⠀⠀⠀⢀⡴"; CambiarColor(10); cout << "⣏⡽⢿⣿⣜⢲⡀⡼⠃⠀⡠⢻⣓⣄⢹⣼⢪⠇⢠⠉⠞⠋⠉"; CambiarColor(1); cout << "⠢⡀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(83, 16); CambiarColor(1); cout << "⠀⠀⠀⢀⣴⠏⠀"; CambiarColor(10); cout << "⢠⠴⢾⡽⣥⡟⡃⢙⡤⢤⡱⣈⠤⡍⣄⣞⠛⣒⣼⣲⠀⠀⠀⠀"; CambiarColor(1); cout << "⠈⢢⡀⠀⠀⠀";
    Console::SetCursorPosition(83, 17); CambiarColor(1); cout << "⠀⠀⢠⡞⠁"; CambiarColor(10); cout << "⠀⠀⠳⡤⡼⠀⠋⠱⣔⢄⡎⠭⠕⠁⠸⢹⠛⢯⣦⠊⠉⠁⠀⠀⠀⠀⠀⠀"; CambiarColor(1); cout << "⠱⡄⠀⠀";
    Console::SetCursorPosition(83, 18); CambiarColor(1); cout << "⠀⢠⡟"; CambiarColor(10); cout << "⠀⠀⠀⠀⠀⠛⠀⠀⢤⣶⡸⡼⠸⡀⠀⠀⠸⢸⢠⠈⠃⡠⠤⣲⣄⢀⣗⣷⡄⢷⡀"; CambiarColor(1); cout << "⠘⡄⠀";
    Console::SetCursorPosition(83, 19); CambiarColor(1); cout << "⠀⣮⠃"; CambiarColor(10); cout << "⠀⠀⠀⠀⠀⢀⡠⠞⠛⠁⠈⠑⡣⠃⠀⠀⢰⢈⠈⡢⠶⠕⠒⣜⡋⣻⣟⢦⠀⠘⠃⠀"; CambiarColor(1); cout << "⢱⡀";
    Console::SetCursorPosition(83, 20); CambiarColor(1); cout << "⢸⢻"; CambiarColor(10); cout << "⠀⠀⠀⠀⠀⢀⡼⣘⡕⠀⠀⠀⠈⠀⠀⠀⢀⢇⢎⡜⠁⠀⠀⠀⢀⠈⠈⠉⠉⣄⠀⠀⠀⡀"; CambiarColor(1); cout << "⡇";
    Console::SetCursorPosition(83, 21); CambiarColor(1); cout << "⡿"; CambiarColor(10); cout << "⡔⢝⣄⢇⢶⠀⠽⢲⠁⠀⠀⠀⠀⠀⠀⠀⠀⢇⢇⢇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣶⡇⠀"; CambiarColor(1); cout << "⣿";
    Console::SetCursorPosition(83, 22); CambiarColor(1); cout << "⣷"; CambiarColor(10); cout << "⠈⠢⣈⠉⡪⣧⡂⠌⠒⠄⠀⠀⠀⠀⠀⠀⠀⠘⢎⠪⡓⠤⠠⠤⠲⡄⠀⠀⠀⠀⠀⠀⣰⢱⢡"; CambiarColor(1); cout << "⢻";
    Console::SetCursorPosition(83, 23); CambiarColor(1); cout << "⢸⡄"; CambiarColor(10); cout << "⠀⠀⠙⢎⡎⡎⠑⠒⠲⣄⡀⠀⢦⡀⠀⠀⠀⠀⠑⠢⠄⠀⡄⡇⢧⠀⠀⠀⠀⠀⠞⢡⠃"; CambiarColor(1); cout << "⡠⡇";
    Console::SetCursorPosition(83, 24); CambiarColor(1); cout << "⠈⣷ "; CambiarColor(10); cout << "⠀⠀⠀⠘⣇⠇⠀⠀⠀⠀⠹⢂⣂⡀⠉⠲⡄⠀⠀⠀⠀⠀⠁⠠⢸⠀⠀⠀⠀⢸⢀⡹"; CambiarColor(1); cout << "⢱⠁";
    Console::SetCursorPosition(83, 25); CambiarColor(1); cout << "⠀⠘⣧⠀"; CambiarColor(10); cout << "⠀⢰⢇⢆⠀⠀⠀⠀⠀⠀⠀⠈⡵⡀⡅⠀⠀⠀⠀⠀⠀⠀⡎⠀⠀⠀⠰⢳⢫⢣"; CambiarColor(1); cout << "⢣⠇⠀";
    Console::SetCursorPosition(83, 26); CambiarColor(1); cout << "⠀⠀⠘⣧⠀"; CambiarColor(10); cout << "⠀⠳⣗⢳⢤⠀⠀⠀⠀⠀⠸⣰⢱⠁⠀⠀⠀⠀⠀⠀⠀⢹⠀⢀⠜⠁⠓⡣"; CambiarColor(1); cout << "⣣⠏⠀⠀";
    Console::SetCursorPosition(83, 27); CambiarColor(1); cout << "⠀⠀⠀⠀⠙⢷⣄⠀"; CambiarColor(10); cout << "⢫⠘⡄⢀⡞⡝⡰⠋⠀⠀⠀⠀⠀⠀⠀⠀⠁⠒⠒⠊⢁  "; CambiarColor(1); cout << "⡴⠋⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(83, 28); CambiarColor(1); cout << "⠀⠀⠀⠀⠀⠀⠀⠉⠻⢦"; CambiarColor(10); cout << "⣧⡘⢾⣜⠰⡅⠀⠀⠀⠀⠀⠀⠀⠀"; CambiarColor(1); cout << "⠀⠀⢀⡠⠖⠉⠉⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(83, 29); CambiarColor(15); cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠳⠿⢤⣌⣀⣀⣀⣀⣀⣠⡤⠤⠖⠊⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";



    Console::SetCursorPosition(52, 7); CambiarColor(15);cout << "⣴⠖⠒⠶⣦⠤⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 8);CambiarColor(15); cout << "⡇⠀⣠⠞⠁⢀⡔⠋⢋⠟⢲⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 9);CambiarColor(15); cout << "⢿⠞⠁⢀⡴⠋⠀⠀⠀⠀⠉⠀⢟⡷⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 10); CambiarColor(15);cout << "⢸⡄⣠⠎"; CambiarColor(3); cout << "⠀⢠⢾⣿⣝⢷⡀"; CambiarColor(15); cout << "⠀⠀⠀⠩⣻⣦⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 11); CambiarColor(15); cout << "⠀⢿⠃"; CambiarColor(3); cout << "⠀⠀⢾⢺⣿⣿⣯⠇⠀"; CambiarColor(15); cout << "⠀⠀⠀⠁⠞⣳⣤⠤⠤⠤⢤⣄⣀⡀⠀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 12); CambiarColor(15);cout << "⠀⠘⣧⠂⠀"; CambiarColor(3); cout << "⠈⠳⠿⠿⠋⣠⣶⣶⣦⡀"; CambiarColor(15); cout << "⠀⠐⡡⢻⣦⠤⠤⠤⠤⠤⠉⣳⡄⠀⠀⠀";
    Console::SetCursorPosition(52, 13);CambiarColor(15); cout << "⠀⠀⠹⣏⠀⠀⠀"; CambiarColor(3); cout << "⠀⠀⠀⡇⣿⣿⣏⡇⠀"; CambiarColor(15); cout << "⠀⣠⠏⠙⣆⠀⠀⠀⠀⠀⠀⢹⡀⠀⠀";
    Console::SetCursorPosition(52, 14);CambiarColor(15); cout << "⠀⠀⠀⠙⣖⠴⡂⠀"; CambiarColor(3); cout << "⠀⠀⠙⠯⠿⠞⠁"; CambiarColor(15); cout << "⢀⡞⠁⢠⠾⢿⡆⠀⠀⠀⠀⠀⠘⣇⠀⠀";
    Console::SetCursorPosition(52, 15); CambiarColor(15);cout << "⠀⠀⠀⠀⠘⢿⣔⡠⢀⠀⠀⠀⠀⠀⡴⢻⡶⣴⣃⠀⢐⡿⠒⠒⠒⢦⡀⠀⢻⠀⠀";
    Console::SetCursorPosition(52, 16);CambiarColor(15); cout << " ⠀⠀⠀⠀⠀⠙⢶⣥⢂⠀⠀⣠⠎⠀⡰⢷⡀⠉⠛⣟⠁⠀⠀⠀⠀⠙⢦⣸⡆⠀";
    Console::SetCursorPosition(52, 17);CambiarColor(15); cout << " ⠀⠀⠀⠀⠀⠀⠀⢿⢻⣦⣞⡁⡠⢊⠀⠀⣷⣄⣀"; CambiarColor(12); cout << "⠹⣗⠶⣄⡀⠀⠀"; CambiarColor(15); cout << "⠈⠻⡇⠀";
    Console::SetCursorPosition(52, 18);CambiarColor(15); cout << " ⠀⠀⠀⠀⠀⠀⠀⢸⠀⡇⠈⠉⠛⠿⢷⡞⠁"; CambiarColor(12); cout << "⠈⢿"; CambiarColor(6); cout << "⠻⣿⠗⣌"; CambiarColor(12); cout << "⠻⣦⡀⠀⠀⠀⠀";
    Console::SetCursorPosition(52, 19); CambiarColor(15);cout << " ⠀⠀⠀⠀⠀⠀⠀⢸⡆⢧⠀⠀⠀⠀⠘⡇⠀⠀"; CambiarColor(12); cout << "⠈⢷⣌"; CambiarColor(6); cout << "⠳⣌"; CambiarColor(6); cout << "⠳⡈"; CambiarColor(12); cout << "⠻⣄⠀⠀⠀";
    Console::SetCursorPosition(52, 20);CambiarColor(15); cout << " ⠀⠀⠀⠀⠀⠀⠀⠀⢷⢸⡀⠀⠀⠀⠀⠳⣄⠀⠀⠀"; CambiarColor(12); cout << "⠙⠷⣄"; CambiarColor(6); cout << "⡙⠻⠄"; CambiarColor(12); cout << "⠹⣆⠀⠀";
    Console::SetCursorPosition(52, 21); CambiarColor(15);cout << " ⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⢧⣄⣀⠀⠀⠀⠘⢷⣄⠀⠀⠀"; CambiarColor(12); cout << "⠈⠛⠶⣄⣀⠘⣆⠀";
    Console::SetCursorPosition(52, 22);CambiarColor(15); cout << " ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠙⠓⠒⠒⠛⠃⠀⠀⠀"; CambiarColor(12); cout << "⠀⠀⠀⠉⠛⠾⠆";



    CambiarColor(15);

    Console::SetCursorPosition(5, 15);cout << " ╔═════════════════ CREDITOS ════════════════╗";
    Console::SetCursorPosition(5, 16);cout << " ║                                           ║";
    Console::SetCursorPosition(5, 17);cout << " ║                                           ║";
    Console::SetCursorPosition(5, 18);cout << " ║        Programador: Robben Cercado        ║";
    Console::SetCursorPosition(5, 19);cout << " ║        Programador: Mateo Alvarado        ║";
    Console::SetCursorPosition(5, 20);cout << " ║   Programador y diseño: Rodrigo Cerrano   ║";
    Console::SetCursorPosition(5, 21);cout << " ║              © Game Jam 2026              ║";
    Console::SetCursorPosition(5, 22);cout << " ║                                           ║";
    Console::SetCursorPosition(5, 23);cout << " ║                                           ║";
    Console::SetCursorPosition(5, 24);cout << " ╚═══════════════════════════════════════════╝";
    Console::SetCursorPosition(5, 25);cout << "     Apreta espacio para volver al Menú...    ";

}



void main() {
    srand(time(0));
    Configurar_Pantalla();
    Titulo_Juego();
    Introduccion();


    char opcion;
    do {
        opcion = Menu();

        if (opcion == '1') {
            Juego();
        }
        if (opcion == '2') {

            do
            {
                Creditos();


            } while (_getch() != ' ');

        }

    } while (opcion != '3');

    Despedida();

    system("pause>0");

    
}