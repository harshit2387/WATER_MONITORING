#define TDS_PIN 35

void setup()
{
    Serial.begin(115200);
    analogReadResolution(12);
}

void loop()
{
    int adcValue = analogRead(TDS_PIN);

    float voltage = adcValue * (3.3 / 4095.0);

    float compensationCoefficient = 1.0; // 25°C
    float compensationVoltage = voltage / compensationCoefficient;

    float tdsValue =
        (133.42 * compensationVoltage * compensationVoltage * compensationVoltage
        - 255.86 * compensationVoltage * compensationVoltage
        + 857.39 * compensationVoltage) * 0.5;

    Serial.print("Voltage: ");
    Serial.print(voltage, 3);
    Serial.print(" V");

    Serial.print("  TDS: ");
    Serial.print(tdsValue);
    Serial.println(" ppm");

    delay(1000);
}
