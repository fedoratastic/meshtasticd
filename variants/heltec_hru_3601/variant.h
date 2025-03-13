// Replace the current NEOPIXEL_TYPE macro with a function
#define HAS_NEOPIXEL 1
#define NEOPIXEL_COUNT 1
#define NEOPIXEL_DATA 2
// #define NEOPIXEL_TYPE (NEO_GRB + NEO_KHZ800) <-- Remove this line

// In a suitable implementation file (e.g., your variant.cpp)
uint16_t getNeoPixelType()
{
    const char *colorOrder = settingsMap.getStr("neopixel_color_order", "GRB");
    uint16_t pixelType = NEO_KHZ800; // Default speed

    if (strcmp(colorOrder, "RGB") == 0) {
        pixelType |= NEO_RGB;
    } else if (strcmp(colorOrder, "GRB") == 0) {
        pixelType |= NEO_GRB;
    } else if (strcmp(colorOrder, "RGBW") == 0) {
        pixelType |= NEO_RGBW;
    } // Add more color orders as needed

    return pixelType;
}
