#include <stdio.h>

//FreeRTOS Essentials
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//ESP system Essentials
#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"

void app_main(void) {
	ESP_LOGI("MAIN", "Hello world!");

    ESP_LOGI("MAIN", "Minimum free heap size: %d bytes", esp_get_minimum_free_heap_size());

    for (int i = 60; i >= 0; i--) {
        ESP_LOGI("MAIN", "Restarting in %d seconds...", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    ESP_LOGI("MAIN", "Restarting now.");
    fflush(stdout);
    esp_restart();
}