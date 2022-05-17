#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct audio audio;

struct audio
{
    char name[256];
    char group[256];
    char album[256];
    char genre[256];
    int year;

};

void add_note(audio music[], int n)
{

    char note[256];
    printf("Enter name: ");
    fgets(note, 100, stdin);
    note[strlen(note) - 1] = 0;
    sprintf(music[n].name, "%s", note);
    printf("Enter group: ");
    fgets(note, 100, stdin);
    note[strlen(note) - 1] = 0;
    sprintf(music[n].group, "%s", note);
    printf("Enter album: ");
    fgets(note, 100, stdin);
    note[strlen(note) - 1] = 0;
    sprintf(music[n].album, "%s", note);
     printf("Enter genre: ");
    fgets(note, 100, stdin);
    note[strlen(note) - 1] = 0;
    sprintf(music[n].genre, "%s", note);
    printf("year: ");
    scanf("%d", &music[n].year);

    fgets(note, 10, stdin);
}

void all_notes(audio music[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d note: name: %s, group: %s, album: %s, genre: %s, year: %d \n", i + 1, music[i].name, music[i].group, music[i].album, music[i].genre, music[i].year);
}

void del_note(audio music[], int n, int del)
{
    for (int i = del; i < n - 1; i++)
    {
        audio temp = music[i];
        music[i] = music[i + 1];
        music[i + 1] = temp;
    }
}

int file_input(FILE* f, audio sp[])
{
    char str[256];
    char* istr;
    int count = 0;
    while (fgets(str, 256, f) != NULL)
    {
        istr = strtok(str, ";");
        sprintf(sp[count].name, "%s", istr);
        istr = strtok(NULL, ";");
        sprintf(sp[count].group, "%s", istr);
        istr = strtok(NULL, ";");
        sprintf(sp[count].album, "%s", istr);
        istr = strtok(NULL, ";");
        sprintf(sp[count].genre, "%s", istr);
        istr = strtok(NULL, ";");
        sp[count].year = atoi(istr);
        count++;
    }
    return count;
}

void file_output(FILE *f, audio sp[], int count)
{
    for (int i = 0; i < count; i++)
        fprintf(f, "%s;%s;%s;%s;%d\n", sp[i].name, sp[i].group, sp[i].album, sp[i].genre, sp[i].year);
}

int main()
{
    int count = 0;
    int del;
    char *query = (char *)malloc(sizeof(char) * 100);
    struct audio music[50];
    FILE *file = fopen("input.txt", "r");
    count = file_input(file, music);
    fclose(file);

    printf("Enter \"q\" if you watn to quit\n");
    printf("Enter \"add\" if you want to add a new note\n");
    printf("Enter \"del\" and then number of note if you want to delete a note\n");
    printf("Enter \"ls\" if you want to see all notes\n");

    while (strcmp(query, "q"))
    {
        printf("-> ");
        fgets(query, 100, stdin);
        query[strlen(query) - 1] = 0;
        if (!strcmp(query, "add"))
        {
            add_note(music, count);
            count++;
        }
        else if (!strcmp(query, "ls"))
            all_notes(music, count);
        else if (!strcmp(query, "del"))
        {
            printf("Enter a number of note you want to delete -> ");
            scanf("%d", &del);
            fgets(query, 10, stdin);
            del_note(music, count, del - 1);
            count--;
        }
    }
    file = fopen("input.txt", "w");
    file_output(file, music, count);
    fclose(file);
    free(query);
    return 0;
}