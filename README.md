# random-figure-cpp

Ein kleines C++ Projekt aus dem Studium um zufällige Bilder im Terminal zu generieren.

## Kompilieren und Ausführen

```bash
mkdir build
cd build
cmake ..
cmake --build .
./random_figure_cpp
```

### Alternativen ohne CMake

Mit g++ direkt:

```bash
g++ -std=c++14 pch.cpp main.cpp -o random_figure_cpp
./random_figure_cpp
``` 

Mit clang++ direkt:

```bash
clang++ -std=c++14 pch.cpp main.cpp -o random_figure_cpp
./random_figure_cpp
```

Hinweis: Da du Windows verwendest, muss bei direkter Kompilierung mit g++ oder clang++
die ausführbare Datei random_figure_cpp.exe heißen und mit .\random_figure_cpp.exe ausgeführt werden.