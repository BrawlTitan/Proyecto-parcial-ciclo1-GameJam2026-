# 🚀 Misión Orión / Orion Mission

**🇪🇸 Español** | [🇬🇧 English](#-english)

---

## 🇪🇸 Español

Juego de consola desarrollado en C++ para la **Game Jam 2026**. Fue un proyecto del curso de introducción del primer ciclo de Ingeniería de Software. El enunciado se recibió el sábado a las 00:00 y debía enviarse antes de las 23:30 del domingo, es decir, **menos de 48 horas de desarrollo**. Se cumplieron todos los requisitos del enunciado.

### Historia
La Tierra se encuentra en proceso de colonización lunar. El jugador pilota la nave **Orion** para rescatar a las personas que quedan en la Tierra y trasladarlas a un lugar seguro en la Luna.

### Reglas y controles
| Elemento | Detalle |
|---|---|
| Movimiento | `W` `A` `S` `D` |
| Capacidad | 2 pasajeros por viaje |
| Objetivo | Rescatar a las 12 personas y dejarlas en la Luna |
| Peligro | Lluvia de meteoritos |
| Vidas | 3 |
| Tiempo | Aleatorio entre 80 y 120 segundos |
| Velocidad de la nave | Aleatoria entre partidas |

### Características
- Pantalla de título, introducción con instrucciones, menú principal y créditos
- Posición y color de las personas generados aleatoriamente
- Detección de colisiones con meteoritos y recogida de pasajeros
- Panel en tiempo real: velocidad, vidas, pasajeros, tiempo y rescatados
- Pantallas de victoria y derrota

### Tecnologías
- C++/CLI (aplicación de consola) en Visual Studio
- Windows (usa `windows.h` y `conio.h`)

### Ejecución
1. Clona el repositorio.
2. Abre `ConsoleApplication17.vcxproj` (carpeta `GameJam2026_Completo`) con Visual Studio. Debe estar instalado el componente de **C++/CLI**.
3. Compila y ejecuta. La consola se ajusta automáticamente a 120x30.

### Capturas
<!-- Reemplaza con tus imágenes: ![Menú](docs/menu.png) -->
*Próximamente.*

### Uso de IA
Se utilizó inteligencia artificial como apoyo en la asignación de colores y en la generación de ciertos caracteres ASCII. El diseño y la programación del juego fueron realizados por el equipo.

### Limitaciones y mejoras futuras
Este proyecto refleja el nivel de un primer ciclo. Con la experiencia posterior, estas serían las mejoras:
- Reemplazar los arreglos paralelos (`personaX[]`, `personaY[]`, etc.) por `struct` o clases (`Nave`, `Persona`, `Meteorito`).
- Reducir el parpadeo evitando `system("cls")` y redibujando solo lo necesario.
- Usar un temporizador de mayor precisión y un ciclo de juego independiente de `Sleep`.
- Separar el código en varios archivos (`.h`/`.cpp`) y eliminar el código duplicado de los créditos y el menú.
- Agregar niveles de dificultad, pausa, puntaje máximo y sonidos.
- Reemplazar el movimiento por teclas discretas con uno más fluido.

### Equipo
| Integrante | Rol | GitHub |
|---|---|---|
| Robben Cercado | Programación | [@robbeneca-spec](https://github.com/robbeneca-spec) |
| Mateo Alvarado | Programación | [@BrawlTitan](https://github.com/BrawlTitan) |
| Rodrigo Cerrano | Programación y diseño | — |

---

## 🇬🇧 English

Console game written in C++ for **Game Jam 2026**. It was a project for the introductory course of the first semester of Software Engineering. The brief was received on Saturday at 00:00 and had to be submitted before 23:30 on Sunday, meaning **less than 48 hours of development**. All the requirements of the brief were met.

### Story
Earth is undergoing lunar colonization. The player pilots the **Orion** spacecraft to rescue the people left on Earth and carry them to safety on the Moon.

### Rules and controls
| Element | Detail |
|---|---|
| Movement | `W` `A` `S` `D` |
| Capacity | 2 passengers per trip |
| Goal | Rescue all 12 people and drop them on the Moon |
| Hazard | Meteor shower |
| Lives | 3 |
| Time limit | Random, between 80 and 120 seconds |
| Ship speed | Random per game |

### Features
- Title screen, intro with instructions, main menu and credits
- Randomly generated position and color for each person
- Collision detection for meteors and passenger pickup
- Real-time HUD: speed, lives, passengers, time and rescued count
- Win and game over screens

### Technologies
- C++/CLI (console application) in Visual Studio
- Windows (uses `windows.h` and `conio.h`)

### How to run
1. Clone the repository.
2. Open `ConsoleApplication17.vcxproj` (inside `GameJam2026_Completo`) with Visual Studio. The **C++/CLI** component must be installed.
3. Build and run. The console resizes itself to 120x30.

### Screenshots
<!-- Replace with your images: ![Menu](docs/menu.png) -->
*Coming soon.*

### AI usage
Artificial intelligence was used as support for color assignment and for generating certain ASCII characters. The game's design and programming were done by the team.

### Limitations and future improvements
This project reflects a first-semester skill level. With the experience gained since, these would be the improvements:
- Replace parallel arrays (`personaX[]`, `personaY[]`, etc.) with `struct`s or classes (`Ship`, `Person`, `Meteor`).
- Reduce flicker by avoiding `system("cls")` and redrawing only what changes.
- Use a more precise timer and a game loop independent from `Sleep`.
- Split the code into several files (`.h`/`.cpp`) and remove duplicated code in the credits and menu.
- Add difficulty levels, pause, high scores and sound.
- Replace the discrete key-press movement with smoother controls.

### Team
| Member | Role | GitHub |
|---|---|---|
| Robben Cercado | Programming | [@robben4579](https://github.com/robbeneca-spec) |
| Mateo Alvarado | Programming | [@BrawlTitan](https://github.com/BrawlTitan) |
| Rodrigo Cerrano | Programming and design | — |
