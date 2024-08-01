/**
 * @brief      This file contains all the tests performed
 *
 * @author     Némo CAZIN & Antoine CEGARRA
 * @date       2024
 */

#include <check.h>
#include <stdlib.h>
#include <stdint.h>
#include "../src/functions.h"

/**
 * @brief Test for the delay 
 */
START_TEST (test_delay) {
    uint32_t time = 5000;
    ck_assert_int_eq(time, delay(time));
}
END_TEST


/**
 * @brief Test on the return MODER register value for LED1
 */
START_TEST (test_LED1_config) {
    uint32_t result = LED1_config();
    uint32_t register_config = 0x48000001;
    ck_assert_int_eq(result, register_config);
}
END_TEST


/**
 * @brief Test on the return ODR register value for LED1 when OFF
 */
START_TEST (test_LED1_off) {
    uint32_t result = LED1_off();
    uint32_t register_off = 0x48000014;
    ck_assert_int_eq(result, register_off);
}
END_TEST


/**
 * @brief Test on the return ODR register value for LED1 when ON
 */
START_TEST (test_LED1_on) {
    uint32_t result = LED1_on();
    uint32_t register_on = 0x48000015;
    ck_assert_int_eq(result, register_on);
}
END_TEST


/**
 * @brief Test on the return ODR register value for LED1 after a blink
 */
START_TEST (test_LED1_blink) {
    uint32_t result = LED1_blink();
    uint32_t register_blink = 0x48000015;
    ck_assert_int_eq(result, register_blink);
}
END_TEST


/**
 * @brief Test on the return MODER register value for LED2
 */
START_TEST (test_LED2_config) {
    uint32_t result = LED2_config();
    uint32_t register_config = 0x48000400;
    ck_assert_int_eq(result, register_config);
}
END_TEST


/**
 * @brief Test on the return ODR register value for LED2 when OFF
 */
START_TEST (test_LED2_off) {
    uint32_t result = LED2_off();
    uint32_t register_off = 0x48000014;
    ck_assert_int_eq(result, register_off);
}
END_TEST


/**
 * @brief Test on the return ODR register value for LED2 when ON
 */
START_TEST (test_LED2_on) {
    uint32_t result = LED2_on();
    uint32_t register_on = 0x48000034;
    ck_assert_int_eq(result, register_on);
}
END_TEST


/**
 * @brief Test on the return ODR register value for LED2 after a blink
 */
START_TEST (test_LED2_blink) {
    uint32_t result = LED2_blink();
    uint32_t register_blink = 0x48000034;
    ck_assert_int_eq(result, register_blink);
}
END_TEST


/**
 * @brief Test on the return MODER register value for TEMP
 */
START_TEST (test_TEMP_config) {
    uint32_t result = temp_sensor_config();
    uint32_t register_config = 0x48000000;
    ck_assert_int_eq(result, register_config);
}
END_TEST


/**
 * @brief Test for the temperature conversion
 */
START_TEST (test_readtemp) {
    uint32_t temp = 100;
    uint32_t voltage = 1; //in V
    ck_assert_float_eq(temp, temperature_conversion(voltage));
}
END_TEST


Suite *sort_suite (void)
{
    Suite *s       = suite_create ("FunctionsTests");
    TCase *tc_core = tcase_create ("Core");
    tcase_add_test (tc_core, test_delay);
    tcase_add_test (tc_core, test_LED1_config);
    tcase_add_test (tc_core, test_LED1_off);
    tcase_add_test (tc_core, test_LED1_on);
    tcase_add_test (tc_core, test_LED1_blink);
    tcase_add_test (tc_core, test_LED2_config);
    tcase_add_test (tc_core, test_LED2_off);
    tcase_add_test (tc_core, test_LED2_on);
    tcase_add_test (tc_core, test_LED2_blink);
    tcase_add_test (tc_core, test_TEMP_config);
    tcase_add_test (tc_core, test_readtemp);
    suite_add_tcase (s, tc_core);

    return s;
}


int main (void)
{
    int      no_failed = 0;
    Suite   *s         = sort_suite ();
    SRunner *runner    = srunner_create (s);
    srunner_run_all (runner, CK_NORMAL);
    no_failed = srunner_ntests_failed (runner);
    srunner_free (runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
