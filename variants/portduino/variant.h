#ifndef HAS_SCREEN
#define HAS_SCREEN 1
#endif
#define CANNED_MESSAGE_MODULE_ENABLE 1
#define HAS_GPS 1
#define MAX_RX_TOPHONE settingsMap[maxtophone]
#define MAX_NUM_NODES settingsMap[maxnodes]

#define HAS_NEOPIXEL settingsMap[has_neopixel]                                     // Enable the use of neopixels
#define NEOPIXEL_COUNT settingsMap[neo_count]                                      // How many neopixels are connected
#define NEOPIXEL_DATA settingsMap[neo_data]                                        // gpio pin used to send data to the neopixels
#define NEOPIXEL_TYPE (settingsStrings[neo_colormode] + settingsStrings[neo_type]) // type of neopixels in use
