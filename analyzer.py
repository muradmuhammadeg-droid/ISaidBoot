import os
import re

def analyze_config():
    print("=========================================")
    print("  ISaidBoot!! - Python Configuration Parser")
    print("=========================================\n")
    
    if not os.path.exists("config.h"):
        print("[-] Error: config.h file could not be located in this directory.")
        return

    print("[*] Reading config.h metadata definitions...")
    with open("config.h", "r", encoding="utf-8") as file:
        content = file.read()

    # Find the title definition using regular expressions
    title_match = re.search(r'#define\s+APP_TITLE\s+L"([^"]+)"', content)
    if title_match:
        print(f"[+] Found Application Title: {title_match.group(1)}")
        
    # Find window layout dimensions
    width_match = re.search(r'#define\s+WINDOW_WIDTH\s+(\d+)', content)
    height_match = re.search(r'#define\s+WINDOW_HEIGHT\s+(\d+)', content)
    if width_match and height_match:
        print(f"[+] Interface Window Size: {width_match.group(1)}x{height_match.group(1)} pixels")

    print("\n[+] Analysis complete. Settings verified safely.")

if __name__ == "__main__":
    analyze_config()
