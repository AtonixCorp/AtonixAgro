#include <Arduino.h>
#include <unity.h>
#include "key.h" // Ensure this header file is available and correctly included

#define LED_PIN 13

key k; // Declare the key object

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

// LED Tests
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

// Key Class Tests
void test_toUpperCase(void)
{
    TEST_ASSERT_EQUAL('A', k.toUpperCase('a'));
    TEST_ASSERT_EQUAL('Z', k.toUpperCase('z'));
    TEST_ASSERT_EQUAL('A', k.toUpperCase('A'));
    TEST_ASSERT_EQUAL('Z', k.toUpperCase('Z'));
    TEST_ASSERT_EQUAL('1', k.toUpperCase('1'));
}

void test_isHexCharacter(void)
{
    TEST_ASSERT_TRUE(k.isHexCharacter('A'));
    TEST_ASSERT_TRUE(k.isHexCharacter('F'));
    TEST_ASSERT_TRUE(k.isHexCharacter('0'));
    TEST_ASSERT_TRUE(k.isHexCharacter('9'));
    TEST_ASSERT_FALSE(k.isHexCharacter('G'));
    TEST_ASSERT_FALSE(k.isHexCharacter('a'));
}

void test_valueFromHexCharacter(void)
{
    TEST_ASSERT_EQUAL(0, k.valueFromHexCharacter('0'));
    TEST_ASSERT_EQUAL(9, k.valueFromHexCharacter('9'));
    TEST_ASSERT_EQUAL(10, k.valueFromHexCharacter('A'));
    TEST_ASSERT_EQUAL(15, k.valueFromHexCharacter('F'));
    TEST_ASSERT_EQUAL(0, k.valueFromHexCharacter('G')); // Not a hex character
}

void test_hexCharacterFromValue(void)
{
    TEST_ASSERT_EQUAL('0', k.hexCharacterFromValue(0));
    TEST_ASSERT_EQUAL('9', k.hexCharacterFromValue(9));
    TEST_ASSERT_EQUAL('A', k.hexCharacterFromValue(10));
    TEST_ASSERT_EQUAL('F', k.hexCharacterFromValue(15));
    TEST_ASSERT_EQUAL('?', k.hexCharacterFromValue(16)); // Out of range
}

void setup()
{
    UNITY_BEGIN();
    // LED Tests
    RUN_TEST(test_led_builtin_pin_number);
    RUN_TEST(test_led_on);
    RUN_TEST(test_led_off);
    // Key Class Tests
    RUN_TEST(test_toUpperCase);
    RUN_TEST(test_isHexCharacter);
    RUN_TEST(test_valueFromHexCharacter);
    RUN_TEST(test_hexCharacterFromValue);
    UNITY_END();
}

void loop()
{
    // Empty loop
}