#include <stdio.h>
#include <windows.h>
#include <errno.h>
#include <string.h>

int main() {
    char computerName[MAX_COMPUTERNAME_LENGTH + 1];  
    char userName[257];                             
    DWORD computerNameLength = MAX_COMPUTERNAME_LENGTH + 1;
    DWORD userNameLength = 257;
    
    if (!GetComputerNameA(computerName, &computerNameLength)) {
        printf("Не удалось получить имя компьютера\n");
        return 1;
    }
    
    if (!GetUserNameA(userName, &userNameLength)) {
        printf("Не удалось получить имя пользователя\n");
        return 1;
    }
    
    FILE *file = fopen("info.txt", "a");
    if (file == NULL) {
        printf("Не удалось открыть файл: %s\n", strerror(errno));
        return 1;
    }
    
    fprintf(file, "%s %s\n", computerName, userName);
    fclose(file);
    printf("Информация успешно записана в файл info.txt\n");
    return 0;
}
