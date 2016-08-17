/******************************************************************************
 * Copyright 2013-2014 Espressif Systems (Wuxi)
 *
 * FileName: user_main.c
 *
 * Description: entry file of user application
 *
 * Modification history:
 *     2014/1/1, v1.0 create this file.
*******************************************************************************/
#include "ets_sys.h"
#include "osapi.h"

#include "user_interface.h"

#include "user_devicefind.h"
#include "user_webserver.h"

void user_rf_pre_init(void)
{
}

/******************************************************************************
 * FunctionName : user_init
 * Description  : entry of user application, init user function here
 * Parameters   : none
 * Returns      : none
*******************************************************************************/
void user_init(void)
{
      // Attempting to make sense of the os_printf output, which is currently junk.
      // Tip found @ kacangbawang.com/esp8266-sdk-os_printf-prints-garbage/
    uart_div_modify(0, UART_CLK_FREQ / 115200);

    os_printf("SDK version:%s\n", system_get_sdk_version());

    /*Establish a udp socket to receive local device detect info.*/
    /*Listen to the port 1025, as well as udp broadcast.
    /*If receive a string of device_find_request, it relays its IP address and MAC.*/
    user_devicefind_init();

    /*Establish a TCP server for http(with JSON) POST or GET command to communicate with the device.*/
    /*You can find the command in "2B-SDK-Espressif IoT Demo.pdf" to see the details.*/
#ifdef SERVER_SSL_ENABLE
    user_webserver_init(SERVER_SSL_PORT);
#else
    user_webserver_init(SERVER_PORT);
#endif
}

