#include "esp_adc/adc_oneshot.h"
#include "freertos/FreeRTOS.h"
#include "driver/gpio.h"
#include "esp_log.h"

static const char* TAG = "tag";
static const adc_channel_t channel = ADC_CHANNEL_0;

void app_main(void) {
  int readout;

  gpio_set_direction(2, GPIO_MODE_OUTPUT);

  adc_oneshot_unit_handle_t adc1_handle;
  adc_oneshot_unit_init_cfg_t init_config1 = {
    .unit_id = ADC_UNIT_1,
    .ulp_mode = ADC_ULP_MODE_DISABLE,
  };
  ESP_ERROR_CHECK(adc_oneshot_new_unit(&init_config1, &adc1_handle));

  while(1){
    adc_oneshot_read(adc1_handle, channel, &readout);

    if((readout)>=2000){
      ESP_LOGI(TAG, "ADC%d Channel[%d] Raw Data: %d", ADC_UNIT_1 + 1, channel, readout);
      gpio_set_level(2,1);

    }
    vTaskDelay(1000/portTICK_PERIOD_MS);
    gpio_set_level(2,0);
  }
}
