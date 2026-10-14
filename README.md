# RayCaster

A C++ project for building a real-time raycasting renderer. The repository is
currently at the starter-scaffold stage: the entry point and an initial
`Init` class are in place, but rendering, input, and scene logic have not yet
been implemented.

## Project status

| Area | Status |
| --- | --- |
| C++ entry point | Present |
| Initialization scaffold | Present |
| Raycasting and rendering | Not implemented |
| Textures and shadows | Directories are reserved; no assets or logic yet |

## Build and run

### Requirements

- A C++ compiler with C++17 support, such as MinGW-w64 GCC
- A terminal opened in the project directory

Build from the repository root:

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp src/Startup.cpp -o raycaster.exe
```

Run the executable:

```powershell
.\raycaster.exe
```

The current program is a scaffold and does not display a scene yet.

## Project layout

```text
RayCaster/
├── main.cpp                 # Program entry point
├── src/
│   └── Startup.cpp          # Initialisation scaffold
├── shadows/                 # Reserved for shadow-related code or assets
├── textures/                # Reserved for texture assets
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
