#include"myHardware.h"
#include<stdio.h>

int RAM_disk_status(){
    //printf("RAM Status\n");
    return 0;
}
int RAM_disk_write(BYTE*buff, DWORD sector,UINT count ){
        for(int i=0;i<(count*512);i++){  
            myVirtualDisk[sector*512+i]=buff[i];
    }
    //printf("write RAM\n");
    return 0;
}
int RAM_disk_read(BYTE*buff, DWORD sector,UINT count ){
    for(int i=0;i<(count*512);i++){  
        buff[i]=myVirtualDisk[sector*512+i];
    }
    //printf("read RAM\n");
    return 0;
}
int RAM_disk_initialize(){
    //printf("RAM Init\n\n");
    return 0;
}

int MMC_disk_status(){
    //printf("MMC Status\n");

}
int MMC_disk_write(BYTE*buff, DWORD sector,UINT count ){
        //printf("write MMC\n");

}
int MMC_disk_read(BYTE*buff, DWORD sector,UINT count ){
    //printf("read MMC\n");
    return 0;
}
int MMC_disk_initialize(){

}

int USB_disk_status(){
    //printf("USB Status\n");

}
int USB_disk_write(BYTE*buff, DWORD sector,UINT count ){
    //printf("write USB\n");

}
int USB_disk_read(BYTE*buff, DWORD sector,UINT count ){
    //printf("read USB\n");
    return 0;
}
int USB_disk_initialize(){

}

DWORD get_fattime(){
    return 0;
}