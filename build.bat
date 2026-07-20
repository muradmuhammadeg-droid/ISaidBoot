@echo off
title ISaidBoot!! Native Build Toolchain
echo ========================================================
echo       ISaidBoot!! Automatic Compilation Routine       
echo ========================================================
echo.

where cl >nul 2>nul
if %errorlevel% neq 0 (
    echo [-] Error: MSVC Compiler 'cl' not found in path.
    echo [*] Please run this script inside the 'Developer Command Prompt for VS'.
    echo.
    pause
    exit /b 1
)

echo [*] Compiling application resource script (version information)...
rc.exe app.rc

echo [*] Compiling production GUI binary with embedded metadata...
cl /EHsc main.cpp app.res /link /SUBSYSTEM:WINDOWS user32.lib /out:ISaidBoot.exe

if %errorlevel% eq 0 (
    echo.
    echo [+] SUCCESS: 'ISaidBoot.exe' compiled flawlessly with embedded metadata!
    echo [*] Launching application...
    start ISaidBoot.exe
) else (
    echo.
    echo [-] Build Failure: Check compiler output logs for syntax errors.
)

echo.
pause
