#ifndef __USER_CONFIG_H__
#define __USER_CONFIG_H__

#define USE_OPTIMIZE_PRINTF

#define SENSOR_DEVICE 1

#define HUMITURE_SUB_DEVICE 1
#define FLAMMABLE_GAS_SUB_DEVICE 0

//#define SERVER_SSL_ENABLE
//#define CLIENT_SSL_ENABLE
//#define UPGRADE_SSL_ENABLE

#define USE_DNS

#ifdef USE_DNS
#define ESP_DOMAIN "iot.espressif.cn"
#endif

//#define SOFTAP_ENCRYPT

#ifdef SOFTAP_ENCRYPT
#define PASSWORD "v*%W>L<@i&Nxe!"
#endif

#define SENSOR_DEEP_SLEEP

#if HUMITURE_SUB_DEVICE
#define SENSOR_DEEP_SLEEP_TIME 30000000
#elif FLAMMABLE_GAS_SUB_DEVICE
#define SENSOR_DEEP_SLEEP_TIME 60000000
#endif

#define AP_CACHE           1

#if AP_CACHE
#define AP_CACHE_NUMBER    5
#endif

#endif
