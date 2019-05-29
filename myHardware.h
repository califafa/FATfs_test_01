
typedef unsigned char BYTE;
typedef unsigned int UINT;
typedef unsigned long DWORD;

unsigned char *myVirtualDisk;

int RAM_disk_status();

int RAM_disk_write(BYTE*buff, DWORD sector,UINT count );

int RAM_disk_read(BYTE*buff, DWORD sector,UINT count );

int RAM_disk_initialize();


int MMC_disk_status();

int MMC_disk_write(BYTE*buff, DWORD sector,UINT count );

int MMC_disk_read(BYTE*buff, DWORD sector,UINT count );

int MMC_disk_initialize();


int USB_disk_status();

int USB_disk_write(BYTE*buff, DWORD sector,UINT count );

int USB_disk_read(BYTE*buff, DWORD sector,UINT count );

int USB_disk_initialize();

DWORD get_fattime();