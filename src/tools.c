#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

char file_path[100] = "/home/shn/Works/reminder/data/time.dat";

void writeData(int min)
{
    FILE *min_data = fopen(file_path, "w");
    fprintf(min_data, "%d", min);
    fclose(min_data);
}

void readData(int *ptr)
{
    FILE *min_data = fopen(file_path, "r");
	if(!min_data)
	{
		fprintf(stderr, "Time file doesn\'t exists\nSupplying default time");
		*ptr = 45;
	}
	else
	{
		char data[10];
		fgets(data, 10, min_data);
		*ptr = atoi(data);
		fclose(min_data);
	}
}
