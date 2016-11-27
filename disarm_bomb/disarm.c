#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_OF_WIRES 4

int main(int argc, char *argv[])
{
    
	FILE *fp;
	char wire[255];
    char *wires[NUM_OF_WIRES];
    

    // try and open sequence file
	if (( fp = fopen("./sequence.txt", "r")) == NULL){
        puts("File could not be open");
        return EXIT_FAILURE;
    }
    else { // store wire sequence into an array
        int idx = 0;
		fscanf(fp, "%s", wire);

		while( !feof( fp )){
			/* printf("%d: %s\n", idx, wire ); */
            wires[idx] = malloc(strlen(wire)+1);
            strcpy(wires[idx], wire);
            idx++;
			fscanf(fp, "%s", wire);
		}
    }

	fclose(fp);
	bool disarmed = true; 
	bool value = false;

    for(int i = 0; i < NUM_OF_WIRES-1; i++){
        printf("%d: %s\n", i, wires[i]);

        if(strcmp(wires[i], "white") == 0){
            if(strcmp(wires[i+1], "white") == 0 || strcmp(wires[i+1], "black") == 0){
                disarmed = false;
				printf("Boom Baby\n");
            }
        }
        if(strcmp(wires[i], "red") == 0){
            if(strcmp(wires[i+1], "green") != 0){
                disarmed = false;
				printf("Boom Baby\n");
            }
        }
        if(strcmp(wires[i], "black") == 0){
            if(strcmp(wires[i+1], "white") == 0 || strcmp(wires[i+1], "green") == 0 || strcmp(wires[i+1], "orange") == 0){
                disarmed = false;
				printf("Boom Baby\n");
            }
        }
        if(strcmp(wires[i], "orange") == 0){
            if(strcmp(wires[i+1], "red") != 0 && strcmp(wires[i+1], "black") != 0){
                disarmed = false;
				printf("Boom Baby\n");
            }
        }
        if(strcmp(wires[i], "green") == 0){
            if(strcmp(wires[i+1], "white") != 0 && strcmp(wires[i+1], "orange") != 0){
				value = (strcmp(wires[i+1], "white") != 0 || strcmp(wires[i+1], "orange") != 0);
                disarmed = false;
				printf("Boom Baby\n");
            }
        }
		if(strcmp(wires[i], "purple") == 0){
            if(strcmp(wires[i+1], "white") != 0 && strcmp(wires[i+1], "green") != 0 && strcmp(wires[i+1], "orange") != 0
					&& strcmp(wires[i+1], "purple") != 0){
                disarmed = false;
				printf("Boom Baby\n");
            }
        }

    }
    printf("%d: %s\n", NUM_OF_WIRES-1, wires[NUM_OF_WIRES-1]);

    if(disarmed)
        printf("All clear\n");
    /* else */
    /*     printf("Boom Baby\n"); */

    return EXIT_SUCCESS;
}
