#include <stdio.h>

#include "modules/AudioInputMonitor/AudioInputMonitor.h"



void AudioInputDataCallback(const void *pData, ma_uint32 frameCount) {

        for (int i = 0; i < frameCount; i++) {
                printf("%hd\n", *(short*)pData);
        }

}



int main() {

        if (!AudioInputMonitor__Monitor(ma_format_s16, 1, 100, &AudioInputDataCallback)) {
                puts("ERROR: Failed to start monitoring default audio input device.");
                getchar(); return 1;
        }

        for (;;);

        return 0;

}