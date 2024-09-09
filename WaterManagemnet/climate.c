#include <stdio.h>

// Define safe thresholds for water quality parameters
#define SAFE_PH_MIN 6.5
#define SAFE_PH_MAX 8.5
#define SAFE_TEMP_MIN 0.0
#define SAFE_TEMP_MAX 35.0
#define SAFE_TURBIDITY_MAX 5.0

// Function prototypes
void checkWaterQuality(float ph, float temperature, float turbidity);

int main() {
    // Simulated sensor data
    float ph, temperature, turbidity;

    // Take input from user or sensors
    printf("Enter the current pH level: ");
    scanf("%f", &ph);
    printf("Enter the current temperature (°C): ");
    scanf("%f", &temperature);
    printf("Enter the current turbidity (NTU): ");
    scanf("%f", &turbidity);

    // Check water quality
    checkWaterQuality(ph, temperature, turbidity);

    return 0;
}

void checkWaterQuality(float ph, float temperature, float turbidity) {
    int alert = 0;  // 0: no alert, 1: alert

    // Check pH levels
    if (ph < SAFE_PH_MIN || ph > SAFE_PH_MAX) {
        printf("ALERT: pH level (%.2f) is out of the safe range (%.1f - %.1f)!\n", ph, SAFE_PH_MIN, SAFE_PH_MAX);
        alert = 1;
    }

    // Check temperature levels
    if (temperature < SAFE_TEMP_MIN || temperature > SAFE_TEMP_MAX) {
        printf("ALERT: Temperature (%.2f°C) is out of the safe range (%.1f°C - %.1f°C)!\n", temperature, SAFE_TEMP_MIN, SAFE_TEMP_MAX);
        alert = 1;
    }

    // Check turbidity levels
    if (turbidity > SAFE_TURBIDITY_MAX) {
        printf("ALERT: Turbidity (%.2f NTU) exceeds the safe level (%.1f NTU)!\n", turbidity, SAFE_TURBIDITY_MAX);
        alert = 1;
    }

    // Final status check
    if (alert == 0) {
        printf("Water quality is within the safe range. No alerts!\n");
    } else {
        printf("Warning: Water quality parameters exceeded safe limits. Please take action.\n");
    }
}
