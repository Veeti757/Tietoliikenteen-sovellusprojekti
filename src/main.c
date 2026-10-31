
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/sys/printk.h>

#define DT_SPEC_AND_COMMA(node_id, prop, idx) \
    ADC_DT_SPEC_GET_BY_IDX(node_id, idx),

static const struct adc_dt_spec channels[] = {
    DT_FOREACH_PROP_ELEM(DT_PATH(zephyr_user),
                         io_channels, DT_SPEC_AND_COMMA)
};

int main(void)
{
    int16_t sample;
    int32_t values[3];

    printk("ADXL335 mittaus alkaa\n");

    for (int i = 0; i < 3; i++) {
        if (!adc_is_ready_dt(&channels[i])) {
            printk("ADC ei ole valmis\n");
            return 0;
        }

        if (adc_channel_setup_dt(&channels[i]) < 0) {
            printk("ADC-kanavan alustus epaonnistui\n");
            return 0;
        }
    }

    while (1) {
        for (int i = 0; i < 3; i++) {
            struct adc_sequence sequence = {
                .buffer = &sample,
                .buffer_size = sizeof(sample),
            };

            if (adc_sequence_init_dt(&channels[i],
                                     &sequence) < 0 ||
                adc_read_dt(&channels[i], &sequence) < 0) {
                printk("ADC-luku epaonnistui\n");
                return 0;
            }

            values[i] = sample;

            if (adc_raw_to_millivolts_dt(&channels[i],
                                         &values[i]) < 0) {
                printk("Muunnos epaonnistui\n");
                return 0;
            }
        }

        printk("X: %d mV, Y: %d mV, Z: %d mV\n",
               (int)values[0],
               (int)values[1],
               (int)values[2]);

        k_msleep(500);
    }
}
