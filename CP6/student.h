#ifndef student_h
#define student_h

#define MAX_FILENAME_LEN 50
#define MAX_STUDENTS 20

typedef struct {
    char last_name[50];
    char initials[5];
    char gender;
    int school_number;
    int has_medal;
    int math_score;
    int russian_score;
    int informatics_score;
    int physics_score;
    int essay_pass;
} Student;

void generateBinaryFile(const char *filename);
int findStudentsByTotalScore(const char *filename, int targetScore);


#endif