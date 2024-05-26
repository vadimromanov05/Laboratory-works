#include <stdio.h>
#include <string.h>
#include "student.h"


void generateBinaryFile(const char *filename) {
    int amount;
    printf("Enter the amount of students: ");
    scanf("%d", &amount);
    Student student;
    FILE *file = fopen(filename, "wb");
    for (int i = 0; i < amount; i++) {
        printf("Введите данные для абитуриента %d:\n", i+1);
        printf("Фамилия: ");
        scanf("%s", student.last_name);
        printf("Инициалы: ");
        scanf("%s", student.initials);
        printf("Пол (M/F): ");
        scanf(" %c", &student.gender);
        printf("Номер школы: ");
        scanf("%d", &student.school_number);
        printf("Наличие медали (1-да, 0-нет): ");
        scanf("%d", &student.has_medal);
        
        printf("Балл по математике: ");
        scanf("%d", &student.math_score);
        printf("Балл по русскому языку: ");
        scanf("%d", &student.russian_score);
        printf("Балл по информатике: ");
        scanf("%d", &student.informatics_score);
        printf("Балл по физике: ");
        scanf("%d", &student.physics_score);
        
        printf("Сочинение (1-зачтено, 0-не зачтено): ");
        scanf("%d", &student.essay_pass);
        fwrite(&student, sizeof(Student), 1, file);
    }

    if (file != NULL) {
        printf("Бинарный файл %s с данными абитуриентов успешно создан.\n", filename);
    } else {
        printf("Ошибка при создании бинарного файла.\n");
    }
    fclose(file);
}

int findStudentsByTotalScore(const char *filename, int targetScore) {
    FILE *file = fopen(filename, "rb");
    if (file != NULL) {
        Student student;
        int count = 0;

        /*printf("Данные абитуриентов в бинарном файле %s:\n", filename);*/
        while (fread(&student, sizeof(Student), 1, file)) {
            int totalScore = student.math_score + student.russian_score + student.informatics_score + student.physics_score;
            
            /*printf("Фамилия: %s, Инициалы: %s, Пол: %c, Номер школы: %d, Медаль: %s, Сумма баллов по предметам: %d, Сочинение: %s\n",
                   student.last_name, student.initials, student.gender,
                   student.school_number, (student.has_medal == 1) ? "есть" : "нет",
                   totalScore,
                   (student.essay_pass == 1) ? "зачтено" : "не зачтено");*/
            
            if (totalScore == targetScore) {
                count++;
            }
        }

        fclose(file);
        return count;
    } else {
        printf("Ошибка при открытии бинарного файла.\n");
        fclose(file);
        return -1;
    }
}

int main() {
    const char filename[MAX_FILENAME_LEN] = "students_data.bin";
    
    generateBinaryFile(filename);
    
    int targetTotalScore = 0;
    printf("Введите сумму баллов: ");
    scanf("%d", &targetTotalScore);
    int studentCountTotalScore = findStudentsByTotalScore(filename, targetTotalScore);
    
    if (studentCountTotalScore >= 0) {
        printf("Количество абитуриентов с суммой баллов %d: %d\n", targetTotalScore, studentCountTotalScore);
    }

    return 0;
}