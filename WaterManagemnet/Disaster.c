#include <stdio.h>

// Threshold values for flood risk assessment
#define SAFE_RAINFALL 100.0  // mm (Safe limit for rainfall)
#define SAFE_WATER_LEVEL 8.0 // meters (Safe water level in rivers)
#define SAFE_SOIL_SATURATION 70.0 // percentage (Safe soil saturation)

// Function prototypes
void checkFloodRisk(float rainfall, float riverWaterLevel, float soilSaturation);

int main() {
    // Variables to store sensor data
    float rainfall, riverWaterLevel, soilSaturation;

    // Input the current conditions (simulated or real-time from sensors)
    printf("Enter current rainfall (in mm): ");
    scanf("%f", &rainfall);
    printf("Enter current river water level (in meters): ");
    scanf("%f", &riverWaterLevel);
    printf("Enter current soil saturation level (in percentage): ");
    scanf("%f", &soilSaturation);

    // Check flood risk based on input data
    checkFloodRisk(rainfall, riverWaterLevel, soilSaturation);

    return 0;
}

void checkFloodRisk(float rainfall, float riverWaterLevel, float soilSaturation) {
    int floodRisk = 0;  // 0: No risk, 1: Risk detected

    // Check rainfall levels
    if (rainfall > SAFE_RAINFALL) {
        printf("ALERT: Rainfall (%.2f mm) exceeds safe limit (%.2f mm)!\n", rainfall, SAFE_RAINFALL);
        floodRisk = 1;
    }

    // Check river water levels
    if (riverWaterLevel > SAFE_WATER_LEVEL) {
        printf("ALERT: River water level (%.2f meters) exceeds safe limit (%.2f meters)!\n", riverWaterLevel, SAFE_WATER_LEVEL);
        floodRisk = 1;
    }

    // Check soil saturation levels
    if (soilSaturation > SAFE_SOIL_SATURATION) {
        printf("ALERT: Soil saturation (%.2f%%) exceeds safe limit (%.2f%%)!\n", soilSaturation, SAFE_SOIL_SATURATION);
        floodRisk = 1;
    }

    // Final flood risk assessment
    if (floodRisk == 0) {
        printf("No flood risk detected. Conditions are safe.\n");
    } else {
        printf("Warning: High risk of flooding. Immediate action recommended!\n");
    }
}
