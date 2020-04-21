# GLUT Implementation
Implementation of some important algorithm ans some questions provided by Course Teacher. 

## HOW TO RUN GLUT IN MAC USING TERMINAL

Just open terminal in MAC and RUN : [Car Game will not run with MAC Terminal because that renders exe file]

```javascript
For C language
gcc -o test test.cpp -framework GLUT -framework OpenGL -Wno-deprecated

For C++ language
g++ -o test test.cpp -framework GLUT -framework OpenGL -Wno-deprecated

./test

```

## Universal Common Template, also for MAC

```javascript
#include <GLUT/glut.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
```

### INFOS

Vscode for c/c++ <br>
https://code.visualstudio.com/docs/cpp/config-clang-mac
<br>