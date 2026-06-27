# Image Viewer


##### Steps to run this:
1. Take an image in png/jpeg
2. Convert to PPM format (P6) using `magic.py`
   - (A PPM (Portable Pixmap) file is a simple, uncompressed raster image format that stores 24-bit RGB color pixels)
4. Check if your image has a comment - if yes, uncomment the comment-handling line in the C code
5. Setup SDL2 (see below) this is for windows powershell 
   - (Simple DirectMedia Layer (SDL for short) is a cross-platform library designed to make it easy to write multi-media software)
---
- output example : ![alt text](image.png)

## SDL2 Setup on Windows 64-bit (ucrt64)

**1. Download**

Go to https://github.com/libsdl-org/SDL/releases and download `SDL2-devel-x.x.x-mingw.tar.gz`

---

**2. Extract**

Extract the archive. Navigate into `SDL2-x.x.x > x86_64-w64-mingw32`

---

**3. Find your MinGW root**

```cmd
where gcc
```

If output is `C:\msys64\ucrt64\bin\gcc.exe` → your root is `C:\msys64\ucrt64`

---

**4. Copy files (run terminal as Admin)**

```cmd
xcopy /E /I "SDL2-x.x.x\x86_64-w64-mingw32\include\SDL2" "C:\msys64\ucrt64\include\SDL2"
```
```cmd
xcopy /E /I "SDL2-x.x.x\x86_64-w64-mingw32\lib" "C:\msys64\ucrt64\lib"
```
```cmd
copy "SDL2-x.x.x\x86_64-w64-mingw32\bin\SDL2.dll" "C:\msys64\ucrt64\bin\"
```

---

**5. Delete the downloaded folder**

Not needed anymore.

---

**6. In every SDL2 file, add this at the very top**

```c
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
```

> This is required on ucrt64. Without it, SDL redefines `main` internally and causes a `WinMain` linker error due to ABI mismatch with `libSDL2main.a`.

---

**7. Compile**

```cmd
gcc yourfile.c -o output -lSDL2
```

Works from any directory, any terminal, any editor.
