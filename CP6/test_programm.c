#include <stdio.h>
 
int main(void)
{
    int var_i = 1;
    double pi = 3.14;
    char ch = "A";

    FILE* fp = fopen("test_file.bin", "wb");
    fwrite(&var_i, sizeof(var_i), 1, fp);
    fwrite(&pi, sizeof(pi), 1, fp);
    fwrite(&ch, sizeof(ch), 1, fp);
    fclose(fp);
 
    FILE* in = fopen("test_file.bin", "rb");
    if(in == NULL) {
        perror("test_file.bin");
        return 1;
    }
 
    fread(&var_i, sizeof(var_i), 1, in);
    fread(&pi, sizeof(pi), 1, in);
    fread(&ch, sizeof(ch), 1, in);
 
    fclose(in);
 
    printf("r_var_i = %d, r_pi = %f, r_ch = %c\n", var_i, pi, ch);
 
    return 0;
}