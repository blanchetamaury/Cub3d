# Build Dependencies

This document lists the system dependencies required to build Cub3D.

## Required System Packages

### Ubuntu/Debian
```bash
sudo apt-get update
sudo apt-get install -y libx11-dev libxext-dev libxrandr-dev libxcursor-dev libxinerama-dev libxi-dev libsdl2-dev
```

### What these packages provide:
- **libx11-dev**: X11 core library development files
- **libxext-dev**: X11 extension library development files  
- **libxrandr-dev**: X11 RandR extension development files
- **libxcursor-dev**: X11 cursor management development files
- **libxinerama-dev**: X11 Xinerama extension development files
- **libxi-dev**: X11 Input extension development files
- **libsdl2-dev**: SDL2 (Simple DirectMedia Layer) development files

## Build Instructions

After installing dependencies:

```bash
make clean
make
```

## Notes

- The project uses MacroLibX which requires Vulkan/SDL2 support
- In headless environments (CI/containers), the binary will compile but cannot run due to lack of graphics support
- This is expected behavior and not a compilation issue