/*
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

/* 5000 msec = 5 sec */
#define SLEEP_TIME_MS   5000
#define RELAY_NODE DT_ALIAS(relay0)

static const struct gpio_dt_spec relay = GPIO_DT_SPEC_GET(RELAY_NODE, gpios);

int main(void)
{
	int ret;

	if (!gpio_is_ready_dt(&relay)) {
		return 0;
	}

	ret = gpio_pin_configure_dt(&relay, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}

	while (1) {
		ret = gpio_pin_set_dt(&relay, 1);
		if (ret < 0) {
			return 0;
		}

		k_msleep(SLEEP_TIME_MS);

		ret = gpio_pin_set_dt(&relay, 0);
		if (ret < 0) {
			return 0;
		}

		k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}
