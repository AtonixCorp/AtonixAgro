#include <Arduino.h>
#include <unity.h>

#define LED_PIN 13

void setUp(void)
{
    // Set up code here
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW); // Ensure the LED is off before each test
}

void tearDown(void)
{
    // Clean up code here
    digitalWrite(LED_PIN, LOW); // Turn off the LED after each test
}

void test_led_builtin_pin_number(void)
{
    TEST_ASSERT_EQUAL(13, LED_BUILTIN);
}

void test_led_on(void)
{
    digitalWrite(LED_PIN, HIGH);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(LED_PIN));
}

void test_led_off(void)
{
    digitalWrite(LED_PIN, LOW);
    TEST_ASSERT_EQUAL(LOW, digitalRead(LED_PIN));
}

void setup()
{
    UNITY_BEGIN();
    RUN_TEST(test_led_builtin_pin_number);
    RUN_TEST(test_led_on);
    RUN_TEST(test_led_off);
    UNITY_END();
}

void loop()
{
    // Empty loop
}