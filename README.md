# RayCaster

A small C++17 raycasting project with a working ASCII-rendered sample scene.
It includes a grid map, player state, a DDA raycaster, and a renderer. It is a
foundation for a fuller 2.5D renderer; graphics, texture loading, and player
controls are not implemented yet.

## Project status

| Area | Status |
| --- | --- |
| C++ entry point and game orchestration | Implemented |
| Grid map loading and validation | Implemented |
| DDA raycasting | Implemented |
| ASCII scene rendering | Implemented |
| Interactive controls and image textures | Not implemented |

## Build and run

### Requirements

- A C++ compiler with C++17 support, such as MinGW-w64 GCC
- A terminal opened in the project directory

Build from the repository root:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude main.cpp src/Game.cpp src/Map.cpp src/Raycaster.cpp src/Renderer.cpp -o raycaster.exe
```

Run the executable:

```powershell
.\raycaster.exe
```

Run the command from the repository root so the program can find
`maps/demo.map`. It prints a single ASCII view of the sample map.

## Project layout

```text
RayCaster/
├── main.cpp                 # Program entry point
├── include/                 # Component declarations
│   ├── Game.h
│   ├── Map.h
│   ├── Player.h
│   ├── Raycaster.h
│   └── Renderer.h
├── src/
│   ├── Game.cpp              # Loads the sample scene and coordinates rendering
│   ├── Map.cpp               # Loads and validates grid maps
│   ├── Raycaster.cpp         # Casts rays using the DDA algorithm
│   ├── Renderer.cpp          # Draws an ASCII view
│   └── Startup.cpp           # Original starter scaffold (not used by the renderer)
├── maps/
│   └── demo.map              # Sample enclosed level
├── textures/                 # Reserved for future image assets
└── .vscode/                 # VS Code C/C++ configuration
```

## Development

Open the repository folder in Visual Studio Code to use the included C/C++
editor configuration. The launch configuration expects a debug executable at
`build/Debug/outDebug`; adjust it to match your build output if needed.

## Contributing

Contributions are welcome. As the renderer takes shape, keep build instructions
and project status up to date so that new contributors can quickly understand
what works and how to try it.
