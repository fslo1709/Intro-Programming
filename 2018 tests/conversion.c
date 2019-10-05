#include <stdio.h>
void bin2ascii(char input_file[32], char output_file[32], char dict[17]) {
    int i, k = 0;
    FILE* fin = fopen(input_file, "rb");
    FILE* fout = fopen(output_file, "wa");
    fseek(fin, 0, SEEK_END);
    int size = ftell(fin);
    fseek(fin, 0, SEEK_SET);
    while (k < size) {
        unsigned char temp;
        fread(&temp, sizeof(unsigned char), 1, fin);
        unsigned char id1 = temp>>4;
        unsigned char id2 = 0;
        for (i = 0; i < 3; i++) {
            if (temp & 1u)
                id2++;
            id2 <<= 1;
            temp >>= 1;
        }
        if (temp & 1u)
            id2++;
        fwrite(&dict[id1], 1, sizeof(unsigned char), fout);
        fwrite(&dict[id2], 1, sizeof(unsigned char), fout);
        k++;
    }
    fclose(fin);
    fclose(fout);
}
void ascii2bin(char input_file[32], char output_file[32], char dict[17]) {
    int i, k = 0;
    FILE* fin = fopen(input_file, "r");
    FILE* fout = fopen(output_file, "wb");
    fseek(fin, 0, SEEK_END);
    int size = ftell(fin);
    rewind(fin);
    char temp1, temp2;
    while (k < size) {
        fread(&temp1, 1, sizeof(char), fin);
        fread(&temp2, 1, sizeof(char), fin);
        unsigned char encoded = 0;
        unsigned char id1 = 0, id2 = 0;
        for (i = 0; i < 17; i++) {
            if (dict[i] == temp1) 
                id1 = i;
            if (dict[i] == temp2)
                id2 = i;
        }
        id1 <<= 4;
        encoded = id1;
        encoded |= id2;
        fwrite(&encoded, 1, sizeof(char), fout);
        k++;
        k++;
    }
    fclose(fin);
    fclose(fout);
}