#include "wdt.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define WDT_THREAD_PRIO (configMAX_PRIORITIES - 1)

static const char *TAG = "WDT";

extern void esp_task_wdt_reset(void);

static void wdt_task(void)
{
    for(;;)
    {
        esp_task_wdt_reset();
        //ESP_LOGI(TAG, "watchdog feed.\n");
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
    vTaskDelete(NULL);
}

void wdt_task_init(void)
{
    ESP_LOGI(TAG, "wdt_task_init.\n");
    static TaskHandle_t wdt_handle;
    if(xTaskCreate(wdt_task, "WDT_TASK", 1024, NULL, WDT_THREAD_PRIO, (void *)&wdt_handle) != pdPASS)
    {
        ESP_LOGI(TAG, "WDT Task create failed!!");
    }
}
