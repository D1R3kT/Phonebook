#include<stdio.h>

struct person {
    int number;
    char name[30];
};

int main(void) {
    
    int num;
    int back = 0;                       // Используем для возвращения switch
    
    printf("Выберите действие:\n");
    printf("1.Добавить контакт\n");
    printf("2.Просмотр контактов:\n");
    
    scanf("%d", &num);
    
    struct person male = {123567, "male"};
    int size = sizeof(struct person);
   // int count = sizeof male / size;
   // struct person users[count];
    
    while (back != 1){
        switch (num)
        {
            case 1:
                printf("Введите имя:");
                scanf("%s", male.name);
                printf("Введите номер телефона:");
                scanf("%d", &male.number);
                printf("Контакт успешно записан!\n Имя: %s \t Номер: %d\n", male.name, male.number);
                // Записываем в файл структуру
                
                FILE *file;
                file = fopen("phonebook.bin", "a");
                size_t count = fwrite(&male, size, 1, file);
                printf("%zu %d\n",count,1);
                fclose(file);
                
                back++;
                break;
            case 2:
                
                printf("Список контактов:\n");
               /* file = fopen("phonebook.bin", "r");
                size_t read = fread(users, size, 255, file);
                printf("read %zu elements\n", read);
                if (read > 0) {
                    for (int i = 0; i < 100; i ++) {
                        printf("Имя: %s \t Номер: %d\n", users[i].name, users[i].number);
                    }
                }
                fclose(file);
                */
                // выводим то, что записали в файл
                file = fopen("phonebook.bin", "r");
                count = fread(&male, size, 1, file);
                if (count == 1) {
                        printf("Имя: %s \t", male.name);
                        printf("Номер: %d \n", male.number);
                }
                fclose(file);
                
                back++;
                break;
            default:
                printf("Ошибка!\n Выберите номер (1 - 2)\n");
                printf("1.Добавить контакт\n");
                printf("2.Просмотр контактов:\n");
                scanf("%d", &num);
                
        }
    }
    return 0;
}
