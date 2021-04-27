#include <stdio.h>

//FreeRTOS Essentials
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

//ESP system Essentials
#include <esp_system.h>
#include <esp_event.h>
#include <esp_log.h>
#include <nvs_flash.h>

void app_main(void) {

    ESP_LOGI("ESP", "Free heap: %d bytes", esp_get_free_heap_size());
    ESP_LOGI("ESP", "IDF version: %s", esp_get_idf_version());

    for (int i = 10; i >= 0; i--) {
        ESP_LOGI("MAIN", "Restarting in %d seconds...", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    ESP_LOGI("ESP", "Restarting now.");
    fflush(stdout);
    esp_restart();
}