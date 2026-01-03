#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 15

   struct Patient {
            char name[50];
            char egn[11];
            int age;
            int reason;
            int urgent;
        };


int validName(char name[]) {                            // Функция за проверка на име
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            return 0;
        }
    }
    return 1;
}
                                                    // Функция за проверка на ЕГН
int validEgn(char egn[]) {
    if (strlen(egn) < 10 ||strlen(egn) > 10) {
        return 0;
        }
    for (int i = 0; i < 10; i++) {
        if (!isdigit(egn[i]))
        return 0;
    }
    return 1;
}

int validAge(int age) {                             // Функция за проверка на възраст
    if (age >= 1 && age <= 100) {
        return 1;
    }
    return 0;
}

int main() {
    struct Patient queue[MAX];
    int count = 0;
    int choice;

do{
    printf("\n=== Меню ===\n");                             // Меню
    printf("1. Добавяне на нов пациент\n");
    printf("2. Показване на всички чакащи пациенти\n");
    printf("3. Следващ пациент\n");
    printf("4. Изход\n");
    printf("Избор: ");

    scanf("%d", &choice);
    if (choice < 1 || choice > 4)
    {                                                               // Автоматично определяне на спешност
        printf("Моля въведете стойност от 1 до 4.\n");
    }

        switch (choice) {                                       // При препълнена опашка
case 1:
    if (count >= MAX) {
        printf("Опашката е пълна!\n");
    } else {
                                                                    //Меню:Добавяне на нов пациент
                                                                      // 1. Въвеждане на име
   do {
        printf("Моля въведете име на латиница: ");
        scanf("%s", queue[count].name);

        if (!validName(queue[count].name)) {
            printf("Грешка! Моля въведете валидно име на латиница.\n");
        }
    } while (!validName(queue[count].name));


                                                                    // 2. Въвеждане и проверка на ЕГН
    do {
        printf("Моля въведете  ЕГН: ");
        scanf("%s", queue[count].egn);

        if (!validEgn(queue[count].egn)) {
            printf("Грешка! Моля въведете валидно ЕГН.\n");
        }
    } while (!validEgn(queue[count].egn));

                                                                    // 3. Въвеждане на възраст
    do {
        printf("Моля въведете  възраст: ");
        scanf("%d", &queue[count].age);

        if (!validAge(queue[count].age)) {
            printf("Грешка! Моля въведете валидна възраст.\n");
        }
    } while (!validAge(queue[count].age));


    if (queue[count].age <= 10 || queue[count].age >= 60) {         // Автоматично определяне на спешност
        queue[count].urgent = 1;

    } else {
        queue[count].urgent = 0;


    }

                                                                // 4. Причина за посещение
   do   {
     printf("Причина за посещение:\n");
    printf("1. Температура\n2. Кашлица\n3. Болки в корема\n4. Главоболие\n5. Контролен преглед\n6. Изследвания\n");
    printf("Избор: ");
    scanf("%d", &queue[count].reason);
    if (queue[count].reason < 1 || queue[count].reason > 6)
    {                                                               // Автоматично определяне на спешност
        printf("Моля въведете стойност от 1 до 6.\n");
    }

        } while (queue[count].reason < 1 || queue[count].reason > 6);
    count++;
    printf("Пациентът е добавен успешно към списъка.\n");
}
break;

case 2:                                                        //Меню:Показване на всички чакащи пациенти
    if (count == 0) {
        printf("Няма чакащи пациенти.\n");
    } else {
        printf("Чакащи пациенти:\n");
        for (int i = 0; i < count; i++) {
            printf("%d. %s, ЕГН: %s, Възраст: %d, Спешен: %s\n",
                    i + 1,
                    queue[i].name,
                    queue[i].egn,
                    queue[i].age,
                    queue[i].urgent ? "Да" : "Не");
        }
    }
    break;

case 3:                                            //Меню:Следващ пациент
    if (count == 0) {
        printf("Няма пациенти за обслужване.\n");
    } else {
                                                        // Търсим спешен пациент първо
        int index = -1;
        for (int i = 0; i < count; i++) {
            if (queue[i].urgent) {
                index = i;
                break;
        }
    }
                                                    // Ако няма спешен, вземаме първия в опашката - queue[0]
    if (index == -1) index = 0;

    printf("Следващ пациент: %s, ЕГН: %s\n",
            queue[index].name,
            queue[index].egn);

                                                    // Преместване на останалите напред в опашката
    for (int i = index; i < count - 1; i++) {
        queue[i] = queue[i + 1];
    }
    count--;
}
break;

case 4:
    printf("Изход...\n");
    break;

}

}while (choice != 4);                               // затваря do-while цикъла
return 0;                                                   // край на main()
}
