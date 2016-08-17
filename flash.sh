#!/bin/bash

esptool.py --port $1 --baud $2 write_flash \
-fs 32m \
-ff 40m \
0x00000 /home/abradburn/Programming/esp8266/ESP8266_NONOS_SDK/bin/boot_v1.5.bin \
0x01000 /home/abradburn/Programming/esp8266/ESP8266_NONOS_SDK/bin/upgrade/user1.4096.new.4.bin \
0x7e000 /home/abradburn/Programming/esp8266/ESP8266_NONOS_SDK/bin/blank.bin \
0x3fe000 /home/abradburn/Programming/esp8266/ESP8266_NONOS_SDK/bin/blank.bin

### Flash size 32Mbit: 512KB+512KB
#    boot_v1.2+.bin              0x00000
#    user1.1024.new.2.bin        0x01000
#    esp_init_data_default.bin   0x3fc000 (optional)
#    blank.bin                   0x7e000 & 0x3fe000
