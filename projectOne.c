#include <stdio.h>
#include <ctype.h>

#define LETTERCOUNT 26

void readFreq(float given[], char fname[]);
void calcFreq(float found[], char fname[]);

int main(){

	float given[LETTERCOUNT];
	float found[LETTERCOUNT]= { 0 } ;
	readFreq(given, "LetFreq.txt");
	for(int i = 0; i<LETTERCOUNT; i++)
		printf("%lf\n", given[i]);

	calcFreq(found, "test.txt");

	for(int i = 0; i<LETTERCOUNT; i++)
		printf("%f\n", found[i]);	
	return(0);
}

//Load array given with the letter freq for English from file LetFreq.txt
void readFreq(float given[], char fname[]){

	FILE * fp;
	char buf[20];
	fp = fopen(fname, "r");
	int i = 0;
	while(fgets(buf, 20, fp)!=NULL){
		sscanf(buf, "%*s%f", &given[i]);
		i++;
	}
	fclose(fp);
}

//Read the encoded text from an input file and accumulate the letter frequency
//data for teh encoded text. Store the frequency data in array found
void calcFreq(float found[], char fname[]){

	FILE * fp;
	fp = fopen(fname, "r");
	char current;
	current = fgetc(fp);
	float total = 0;
	while(current != EOF){
		if(isalpha(current)){
			printf("%c\n", current);
			current = tolower(current);
			printf("After lower %d\n", current-97);
			found[current-97] = found[current-97] + 1;
		}
		total++;
		current = fgetc(fp);	
	}
	for(int i = 0; i<LETTERCOUNT; i++){
		found[i] = found[i] / total;
	}	
	
}
