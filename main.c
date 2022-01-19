#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <dir.h>
#include <process.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

bool ayrackontrol(char c) {
    if (c == ' ' || c == '*' || c == '/' ||c == ';' || c == '>' ||c == '<' || c == '{' || c == '}')
        return (true);
    return (false);
}

char *AltKelime(char *kelime, int kelimesol, int kelimesag) {
    int i;
    char * AltKelime= (char * ) malloc(sizeof(char) * (kelimesag - kelimesol + 2));
    for (i = kelimesol; i <= kelimesag; i++)
        AltKelime[i - kelimesol] = kelime[i];
    AltKelime[kelimesag - kelimesol + 1] = '\0';
    return (AltKelime);
}

bool VeriKontrol(char * kelime) {
    int uzunluk = strlen(kelime);
    int i = 0;
    int kelimebaslangic = 0;
    for (i; i < uzunluk; i++) {
        if (kelime[i] == '<' && kelimebaslangic == 0) {
            kelimebaslangic = 1;
        } else if (kelime[i] == '>' && kelimebaslangic == 1) {
            return (true);
        }
    }
    return false;
}

bool OrderKontrol(char * kelime) {
    int uzunluk= strlen(kelime);
    int i;
    int kelimebaslangic=0;
    for (i=0; i < uzunluk; i++) {
        if (((kelime[i] == 'm' && kelime[i + 1] == 'a' && kelime[i + 2] == 'k' && kelime[i + 3] == 'e') ||(kelime[i] == 'g' && kelime[i + 1] == 'o')) && kelimebaslangic == 0){
            kelimebaslangic=1;
        }
        else if (kelime[i] == ';' && kelimebaslangic== 1){
            return (true);
        }
    }
    return false;
}

bool YapiKontrol(char * kelime) {
    int uzunluk = strlen(kelime);
    int i;
    int kelimebaslangic = 0;
    for (i=0; i < uzunluk; i++) {
        if (((kelime[i] == 'i' && kelime[i + 1] == 'f') ||(kelime[i] == 'i' && kelime[i + 1] == 'f' && kelime[i + 2] == 'n' && kelime[i + 3] == 'o' && kelime[i + 4] == 't')) && kelimebaslangic == 0){
            kelimebaslangic = 1;
        }
        else if (kelime[i] == ';' && kelimebaslangic == 1){
            return (true);
        }
    }
    return false;
}

bool SartKontrol(char* kelime){
    char defaultdirectory[256];

    char *harfler;
    char *harfler_dizisi[1024];
    int sayac = 0;
    harfler= strtok(kelime," </>;");
    while (harfler!= NULL)
    {
        harfler_dizisi[sayac] = harfler;
        sayac++;
        harfler = strtok(NULL, " </>;");
    }

    if(!strcmp(harfler_dizisi[0],"if")){
        printf("IF Conditional Detected!\n");
       }
    else if(!strcmp(harfler_dizisi[0],"ifnot")){
        printf("IF NOT Condinitional Detected!\n");
    }

}

void OrdersFromPmk(char * str) {
    char defaultdirectory[256];
    printf("Default Directory is: %s\n", getcwd(defaultdirectory,256));
    char *harfler;
    char *harfler_dizisi[1024];
    int sayac= 0;
    harfler = strtok(str, "</>; ");
    while (harfler != NULL) {
        harfler_dizisi[sayac] = harfler;
        sayac++;
        harfler= strtok(NULL, "</>;");
    }

    if (!strcmp(harfler_dizisi[0], "make") || 6 == strlen(harfler_dizisi[0])) {
        int deger;
        int sayi = 0;
        for (int m = 1; m <= sayac - 1; m++) {
            if (!strcmp(harfler_dizisi[m], "*")) {
                chdir("..");
                printf("Going Parental Directory\n");
                deger++;
            }
            else {
                int a = mkdir(harfler_dizisi[m]);
                int b = chdir(harfler_dizisi[m]);
                if (a == -1 || b == -1) {
                    printf("Error! %s Directory Already Exists!\n",harfler_dizisi[m]);
                }
                else {
                    printf("%s Directory is created\n",harfler_dizisi[m]);
                    sayi++;
                }
            }
        }
        chdir(defaultdirectory);
        printf("Current Directory:%s\n", getcwd(defaultdirectory,256));
    }
    else if (!strcmp(harfler_dizisi[0], "go") || 4 == strlen(harfler_dizisi[0])) {
    printf("\n");
    int check = 1;
    for (int d = 1; d < sayac; d++) {
        if (!strcmp(harfler_dizisi[d], "*")) {
            chdir("..");
            check = 0;
        }
        int c = chdir(harfler_dizisi[d]);
        if (c != 0 && check == 1) {
            printf("\nError For Go Command in here! %s \n",harfler_dizisi[d]);
        }
        printf("New Current Directory:%s\n",getcwd(defaultdirectory,256));
        }
    }
}

void HataArayuzu(char* kelime){
    FILE *dosya;
    int kelimesol = 0;
    int kelimesag = 0;
    int uzunluk = strlen(kelime);
    while (kelimesag <= uzunluk && kelimesol <= kelimesag) {
        if (kelime[kelimesag]=='<'){
            int uzunluk=strlen(kelime);
            for(int i=kelimesag;i<=uzunluk;i++){
                    kelimesag++;
                if (kelime[kelimesag]=='>'){
                    break;
                }
            if (i==uzunluk){
                printf("Error! Data Type is finished too early.\n");
            }
            }
        }
        else if ( (kelime[kelimesag]=='m' && kelime[kelimesag+1]=='a' && kelime[kelimesag+2]=='k' && kelime[kelimesag+3]=='e')|| (kelime[kelimesag]=='g' && kelime[kelimesag+1]=='o') ) {
            int uzunluk=strlen(kelime);
            for(int i=kelimesag;i<=uzunluk;i++){
                kelimesag++;
                if (kelime[kelimesag]==';'){
                    break;
                }
            if (i==uzunluk){
                printf("Error! Command is finished too early!\n");
            }
            }
        }
            else if ( (kelime[kelimesag]=='i' && kelime[kelimesag+1]=='f' && kelime[kelimesag+2]=='n' && kelime[kelimesag+3]=='o'&& kelime[kelimesag+4]=='t') || (kelime[kelimesag]=='i' && kelime[kelimesag+1]=='f') ){
                int uzunluk=strlen(kelime);
                int kelimebaslangic=1;
                int parantez=0;
                    for(int i=kelimesag;i<=uzunluk;i++){
                        if(kelime[i]=='{'){
                            parantez++;
                        }
                    if(kelime[i]=='}' && parantez==1){
                        kelimesag=i;
                        break;
                    }
                    if (i==uzunluk && parantez==1){
                        printf("Error! If or Ifnot is finished too early!\n");
                    }
                    if(parantez==0){
                    for(int j=kelimesag;j<=uzunluk;j++){
                        kelimesag++;
                        if (kelime[kelimesag]==';' && kelimebaslangic==1){
                            break;
                        }
                        if (j==uzunluk){
                            printf("Error! Control Structure is finished too early!\n");
                        }
                    }
                    }
                }
            }
            else if (ayrackontrol(kelimesag) == false){
                kelimesag++;
            }

if (ayrackontrol(kelime[kelimesag]) == true && kelimesol == kelimesag) {
    kelimesag++;
    kelimesol = kelimesag;
    }
         else if (ayrackontrol(kelime[kelimesag]) == true && kelimesol != kelimesag|| (kelimesag == uzunluk && kelimesol!= kelimesag)) {
            char* altexampleKelime11=AltKelime(kelime,kelimesol,kelimesag);
            char* altexampleKelime22=AltKelime(kelime,kelimesol,kelimesag);
            if (OrderKontrol(altexampleKelime11)==true){
                OrdersFromPmk(altexampleKelime11);
                kelimesag++;
            }
            if (YapiKontrol(altexampleKelime22)==true){
                SartKontrol(altexampleKelime22);
                kelimesag++;
            }
            kelimesol = kelimesag;
        }
    }
}
int main(){
    FILE *fp;
    long capacity;
    char *memory;
    printf("READING X.PMK COMMAND FILE!\n");

    if ((fp = fopen("x.pmk", "rb")) == NULL) {
        printf("Error! opening file");
        exit(1);
    }
    if(!fp){
        perror("Error in File!");
        exit(1);
    }
    fseek(fp,0L,SEEK_END);
    capacity = ftell(fp);
    rewind(fp);
    memory = calloc(1,capacity+1);
    if(!memory){
        fclose(fp);
        fputs("Memorizing the commands failed!",stderr);
        exit(1);
    }
    if(1!=fread(memory,capacity,1,fp)){
        fclose(fp);
        free(memory);
        fputs("Reading from file failed!",stderr);
        exit(1);
    }

    HataArayuzu(memory);
    fclose(fp);
    free(memory);
    return (0);
}
