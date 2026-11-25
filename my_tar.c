#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int my_strlen(char *str){
  int i = 0;
  for (i = 0; str[i] != '\0'; i++){}
  return i; 
}

int my_strcmp(const char *s1, const char *s2) {
    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;

    while (*p1 == *p2 && *p1 != '\0') {
        p1++;
        p2++;
    }
    return (*p1 > *p2) - (*p1 < *p2);
}

struct tar_headers{ 
    char name[100]; //numbers are the number of bytes
    char mode[8];
    char owner[8];
    char group[8];
    char size[12];
    char modified[12];
    char checksum[8];
    char type[1];
    char link[100];
    char padding[255];
};

int main(int argc, char **argv){
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-' || argv[i][1] == '\0'){       // not an option, ignore it
            continue;  
        }
        for (int j = 1; argv[i][j] != '\0'; j++) {
            if (argv[i][j] == 'r'){
                if (argv[i][j + 1] == 'f'){
                    printf("-rf\n");
                    j++;
                }
                else{
                    printf("-r\n");
                }
            }

            else if (argv[i][j] == 'c'){
                printf("-c\n");
            }
        

            else if (argv[i][j] == 't'){
                printf("-t\n");
            }

            else if (argv[i][j] == 'u'){
                if (argv[i][j + 1] == 'f'){
                    printf("-uf\n");
                    j++;
                }
                
                else{
                    printf("-u\n");
                }
            }

            else if (argv[i][j] == 'x'){
                printf("-x\n");
            }
            else {
                fprintf(stderr, "Unknown option: -%c\n", argv[i][j]); //fprint is same as printf but for files
                return 1;                                   // nothing allocated yet, safe to return
            }
            
        }
    }
    return 0;
}
