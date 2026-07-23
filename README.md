> [!CAUTION]
> If you will do a single mistake on booting an .iso file, Your system will be corrupted. Tutorial is coming soon. Tutorials and Blogs are in this website: https://muradm.my.canva.site/isaidboottab/
# ISaidBoot!!

An advanced cross-platform visual deployment application that handles native ISO images for **Windows** and **Linux** systems. (Note: macOS is explicitly unsupported).

## Programming Code Languages Inside
This repository showcases an optimized, multi-language architecture featuring:
*   **C++ & C:** Powers the native Win32 Graphical User Interface (GUI) container and windows structures.
*   **Rust (`validator.rs`):** Provides a blazing-fast file path extension checker module.
*   **Python (`analyzer.py`):** Automatically parses header metadata and configurations.
*   **Assembly (`utils.asm`):** Low-level x64 driver hook providing raw CPU halt loops.
*   **Batch & Shell (`build.bat` / `setup.sh`):** Cross-platform automated build tools.

## How to Compile
### Windows
Run the automatic build pipeline inside the Developer Command Prompt for Visual Studio:
```cmd
build.bat
```

### Linux
Execute the multi-OS shell routing engine:
```bash
chmod +x setup.sh
./setup.sh
```
