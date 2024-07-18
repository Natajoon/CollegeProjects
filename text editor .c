#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
#include <conio.h> 
 
#define MAX_SIZE 1000 
 
char filename[50]; 
char buffer[MAX_SIZE]; 
int top = -1; 
int stack[MAX_SIZE]; 
 
void push(int value) 
{ 
    if (top == MAX_SIZE - 1) 
    { 
        printf("\nStack overflow.\n"); 
        exit(0); 
    } 
    stack[++top] = value; 
} 
 
int pop() 
{ 
    if (top == -1) 
    { 
        printf("\nStack underflow.\n"); 
        exit(0); 
    } 
    return stack[top--]; 
} 
 
void createFile() 
{ 
    FILE *fp; 
    char ch; 
    printf("\nEnter the filename: "); 
    scanf("%s", filename); 
    fp = fopen(filename, "w"); 
    if (fp == NULL) 
    { 
        printf("\nError creating file.\n"); 
        exit(0); 
    } 
    printf("\nEnter text (Press Ctrl + Z to save and exit):\n\n"); 
    while ((ch = getchar()) != EOF) 
    { 
        fputc(ch, fp); 
    } 
    fclose(fp); 
    printf("\nFile created successfully.\n"); 
} 
 
void readFile() 
{ 
    FILE *fp; 
    char ch; 
    printf("\nEnter the filename: "); 
    scanf("%s", filename); 
    fp = fopen(filename, "r"); 
    if (fp == NULL) 
    { 
        printf("\nError opening file.\n"); 
        exit(0); 
    } 
    printf("\nFile contents:\n\n"); 
    while ((ch = fgetc(fp)) != EOF) 
    { 
        printf("%c", ch); 
    } 
    fclose(fp); 
} 
 
void appendFile() 
{ 
    FILE *fp; 
    char ch; 
    printf("\nEnter the filename: "); 
    scanf("%s", filename); 
    fp = fopen(filename, "a"); 
    if (fp == NULL) 
    { 
        printf("\nError opening file.\n"); 
        exit(0); 
    } 
    printf("\nEnter text (Press Ctrl + Z to save and exit):\n\n"); 
    while ((ch = getchar()) != EOF) 
    { 
        push(ch); 
        fputc(ch, fp); 
    } 
    fclose(fp); 
    printf("\nFile appended successfully.\n"); 
} 
 
void deleteFile() 
{ 
    printf("\nEnter the filename: "); 
    scanf("%s", filename); 
    if (remove(filename) == 0) 
    { 
        printf("\nFile deleted successfully.\n"); 
    } 
    else 
    { 
        printf("\nError deleting file.\n"); 
    } 
} 
 
void undo() 
{ 
    FILE *fp; 
    int ch; 
    printf("\nUndoing last action...\n"); 
    fp = fopen(filename, "w"); 
    if (fp == NULL) 
    { 
        printf("\nError opening file.\n"); 
        exit(0); 
    } 
    while ((ch = pop()) != -1) 
    { 
        fputc(ch, fp); 
    } 
    fclose(fp); 
} 
 
int main() 
{ 
    int choice; 
    bool loop = true; 
    push(-1); 
 
    while (loop) 
    { 
        printf("\nMenu:\n"); 
        printf("1. Create a file\n"); 
        printf("2. Read a file\n"); 
        printf("3. Append to a file\n"); 
        printf("4. Delete a file\n"); 
        printf("5. Undo last action\n"); 
        printf("6. Exit\n"); 
        printf("\nEnter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) 
{ 
case 1: 
createFile(); 
break; 
case 2: 
readFile(); 
break; 
case 3: 
appendFile(); 
break; 
case 4: 
deleteFile(); 
break; 
case 5: 
undo(); 
break; 
case 6: 
loop = false; 
break; 
default: 
printf("\nInvalid choice.\n"); 
break; 
} 
} 
return 0; 
} 