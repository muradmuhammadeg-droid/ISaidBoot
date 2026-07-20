#ifndef CONFIG_H
#define CONFIG_H

// Application Metadata
#define APP_TITLE        L"ISaidBoot!! Deployment Engine"
#define APP_CLASS_NAME   L"ISaidBootGuiClass"

// Main Window Dimensions
#define WINDOW_WIDTH     400
#define WINDOW_HEIGHT    190

// Interface Component Positions (X, Y, Width, Height)
#define BTN_VIRTUAL_X    20
#define BTN_VIRTUAL_Y    30
#define BTN_VIRTUAL_W    340
#define BTN_VIRTUAL_H    40

#define BTN_PHYSICAL_X   20
#define BTN_PHYSICAL_Y   90
#define BTN_PHYSICAL_W   340
#define BTN_PHYSICAL_H   40

// Custom Warning Text Configuration
#define VIRTUAL_BOX_MSG  L"Launching Isolated Sandbox...\n\nThis will safely mount the ISO inside a local virtual instance without altering your host hardware configurations."
#define PHYSICAL_BOX_MSG L"CRITICAL WARNING:\n\nPhysical flashing writes data blocks directly to raw storage sectors, destroying all pre-existing partitions.\n\nOne incorrect targeted drive index can permanently wipe your host operating system.\n\nAre you absolutely certain you want to proceed?"

#endif // CONFIG_H
