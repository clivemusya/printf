#include <stdio.h>

int _printf(const char *format, ...){
char string[] = formart;
int count = 0;
for(int i = 0; i < strlen(string); i++)
{
if(string[i] != ' ')
count++;
} 
return count; 
}
