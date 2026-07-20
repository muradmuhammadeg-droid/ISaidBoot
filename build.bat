@echo off
title ISaidBoot!! Native Build Toolchain
echo ========================================================
echo       ISaidBoot!! Automatic Compilation Routine       
echo ========================================================
echo.

where cl >nul 2>nul
if %errorlevel% neq 0 (
    echo [-] Error: MSVC Compiler 'cl' not found in path.
    exit /b 1
)

echo [*] Compiling Windows resource script layout...
rc.exe app.rc

echo [*] Compiling production GUI binary with metadata...
cl /EHsc main.cpp app.res /link /SUBSYSTEM:WINDOWS /out:ISaidBoot.exe

if %errorlevel% eq 0 (
    echo [+] SUCCESS: Compiled flawlessly!
) else (
    echo [-] Build Failure.
    exit /b 255
)
