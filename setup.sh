#!/bin/bash

echo "========================================================"
echo "       ISaidBoot!! Cross-Platform Setup & Build         "
echo "========================================================"
echo ""

OS_NAME="$(uname -s)"

case "${OS_NAME}" in
    Linux*)
        echo "[+] Linux environment detected successfully."
        echo "[*] Preparing compiler tools check..."
        
        if command -v g++ >/dev/null 2>&1; then
            echo "[*] Compiling native Linux implementation..."
            g++ -std=c++11 main.cpp -o ISaidBootLinux
            echo "[+] SUCCESS: Linux binary 'ISaidBootLinux' compiled!"
        else
            echo "[-] Error: GCC compiler (g++) is not installed on this system."
            echo "[*] Please run: sudo apt install build-essential"
        fi
        ;;
        
    MINGW*|MSYS*|CYGWIN*)
        echo "[+] Windows Subsystem environment detected."
        echo "[*] Launching native Windows build toolchain..."
        
        if [ -f "./build.bat" ]; then
            cmd.exe /c build.bat
        else
            echo "[-] Error: build.bat script could not be found."
        fi
        ;;
        
    Darwin*)
        echo "[-] Platform Error: macOS environment detected."
        echo "[!] Execution terminated. This application strictly refuses to support macOS."
        exit 1
        ;;
        
    *)
        echo "[-] Error: Unknown or unsupported operating system environment."
        exit 1
        ;;
esac

echo ""
echo "[+] Operation process finalized."
