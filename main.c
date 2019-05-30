#include<stdio.h>
#include<stdlib.h>

#include"ff.h"
#include"myHardware.h"

//<meta charset="GB-2312">

BYTE workSpace[2048]={0};

unsigned char fileName[16]="b3.txt";

unsigned int fileLen=0xFFFFFF;

int main(){

    myVirtualDisk=(unsigned char*)malloc(sizeof(unsigned char)*0x3FFFFFFF);

    //myVirtualDisk=NULL;
    printf("%d\n\n",myVirtualDisk);

    FATFS fs;

    FIL fil;

    unsigned int tmp=0;
    unsigned char *bu;
    unsigned char *br;
    bu=(unsigned char*)malloc(sizeof(unsigned char)*fileLen);
    br=(unsigned char*)malloc(sizeof(unsigned char)*fileLen);

    if(bu){
        printf("bu is not NULL\n\n");
        bu[fileLen-1]='\0';
    }
    if(br){
        printf("br is not NULL\n\n");
        br[fileLen-1]='\0';
    }


    for(int i=0;i<(fileLen-1);i++){
        bu[i]=(i%10)+48;
    }

    int res;
    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>> f_mkfs start\n\n");
    //f_open();
    res=f_mkfs("",FM_ANY,0,NULL,0);

    printf("f_mkfs result: %d\n\n",res);

    printf("||||||||||||||||||||||||||| f_mkfs end\n\n");

    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>> f_mount start\n\n");
    res=f_mount(&fs,"",1);

    printf("f_mount result: %d\n\n",res);

    printf("||||||||||||||||||||||||||| f_mount end\n\n");

//write files
    res=f_open(&fil,"Ianother4.txt",FA_CREATE_NEW | FA_WRITE);
    res=f_write(&fil,bu,fileLen/5,&tmp);
    f_close(&fil);
    res=f_open(&fil,"Ianother3.txt",FA_CREATE_NEW | FA_WRITE);
    res=f_write(&fil,bu,fileLen/4,&tmp);
    f_close(&fil);
    res=f_open(&fil,"你Ianother2.txt",FA_CREATE_NEW | FA_WRITE);
    res=f_write(&fil,bu,fileLen/3,&tmp);
    f_close(&fil);
    res=f_open(&fil,"我Ianother1.txt",FA_CREATE_NEW | FA_WRITE);
    res=f_write(&fil,bu,fileLen/2,&tmp);
    f_close(&fil);
    res=f_open(&fil,"Ianother0.txt",FA_CREATE_NEW | FA_WRITE);
    res=f_write(&fil,bu,fileLen/1,&tmp);
    f_close(&fil);


    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>> f_open start\n\n");

    res=f_open(&fil,fileName,FA_CREATE_NEW | FA_WRITE);

    printf("f_open(write) result: %d\n\n",res);

    printf("||||||||||||||||||||||||||| f_open end\n\n");



    res=f_write(&fil,bu,fileLen,&tmp);
    printf("f_write result: %d\n\n",res);
    res=f_close(&fil);
    printf("f_close result: %d\n\n",res);

    res=f_open(&fil,fileName,1);
    printf("f_open(read) result: %d\n\n",res);
    tmp=0;
    res=f_size(&fil);   //获取文件长度
    printf("file size  : %d\n\n",res);
    //res=f_read(&fil,br,res,&tmp);

    
    for(int i=0;!f_eof(&fil);i++){
        res=f_read(&fil,br+i,1,&tmp);
        //printf("%c ",*(br+tmp));
        //printf("%d\n",tmp);
    }
    
    printf("readed byte count: %d\n\n",tmp);
    printf("f_read result: %d\n\n",res);

    f_lseek(&fil,0xFFFFFF); //文件指针 offset：file head

    res=f_eof(&fil);

    printf("f_eof result: %d\n\n",res);

    res=f_close(&fil);
    printf("f_close result: %d\n\n",res);
    //br[300]=3;
    printf("\n\nVerification of correctness \n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
//    printf("origin Data :  \n%s\n\n",bu);
//    printf("read Data   :  \n%s\n\n",br);
    unsigned char ifError=0;
    for(int i=0;i<fileLen;i++){
        if(bu[i]!=br[i]){
            
            printf("Error %d\n",i);
            
            ifError=1;
        }
    }

    if(ifError){
        printf("Something Error!\n\n");
    }else{
        printf("Nothing Error!\n\n");
    }
    printf("Finish!\n\n\n");

    //printf("fs_type: %d\n\n",fs.fs_type);


    FRESULT fr;
    DIR dj;
    FILINFO fno;

    f_mkdir("我的myFolder");

    fr=f_findfirst(&dj,&fno,"0:/","*");
    //printf("%d\n",fno.fname);
    while(fr==FR_OK&&fno.fname[0]){
        if(fno.fattrib&AM_DIR){ //if is folder
            printf("%s\n",fno.fname);
        }
        fr=f_findnext(&dj,&fno);
    }

    printf("\n\nIn folder '我的myFolder'\n\n");

    f_chdir("我的myFolder");
//write files
    res=f_open(&fil,"InFolder01.txt",FA_CREATE_NEW | FA_WRITE);
    res=f_write(&fil,bu,fileLen/5,&tmp);
    f_close(&fil);
    res=f_open(&fil,"InFolder02.txt",FA_CREATE_NEW | FA_WRITE);
    res=f_write(&fil,bu,fileLen/4,&tmp);
    f_close(&fil);
    res=f_open(&fil,"InFolder03.txt",FA_CREATE_NEW | FA_WRITE);
    res=f_write(&fil,bu,fileLen/3,&tmp);
    f_close(&fil);

    fr=f_findfirst(&dj,&fno,"","*");
    //printf("%d\n",fno.fname);
    while(fr==FR_OK&&fno.fname[0]){
        printf("%s\n",fno.fname);
        fr=f_findnext(&dj,&fno);
    }

    free(bu);
    free(br);
    free(myVirtualDisk);

    //while(1);

    return 0;
}