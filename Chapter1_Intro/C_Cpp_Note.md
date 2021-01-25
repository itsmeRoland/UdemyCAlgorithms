# C++ Kompabilität des Kurses

Auch wenn wir innerhalb des Kurses in C (C99) implementieren, ist der code zu ~99% C++ kompatibel. Das heißt man kann ohne großen Aufwand den Code zu einem gültigen C++ Code umformen.
Dabei sind die folgenden Sachen zu beachten:

- Anstatt malloc, verwende ```new```, bzw. ```new[]```
- Anstatt free, verwende ```delete```, bzw. ```delete[]```
- Anstatt ```#include <stdint.h>```, verwende ```#include <cstdint.h>```
- Anstatt ```#include <string.h>```, verwende ```#include <cstring.h>```
- Nicht benötigter include: ```#include <stdbool.h>```
