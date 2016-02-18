#include <stdio.h>
#include <ctype.h>

#define LETTERCOUNT 26

void readFreq(float given[], char fname[]);
void calcFreq(float found[], char fname[]);
char rotate(char ch, int num);
int findKey(float given[], float found[]);

int main(){

	float given[LETTERCOUNT];
	float found[LETTERCOUNT]= { 0 } ;
	readFreq(given, "LetFreq.txt");
	
	for(int i = 0; i<LETTERCOUNT; i++)
		printf("%lf\n", given[i]);

	calcFreq(found, "testparagraphenc.txt");

	for(int i = 0; i<LETTERCOUNT; i++)
		printf("%f\n", found[i]);	
	
	int key = findKey(given, found);	

	printf("Key is: %d", key);
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

//Rotate the character in paramtere ch down the alphabet for the number of
//positions as given in parameter num and return the resulting character.
char rotate(char ch, int num){

	if((ch+num)-97 > 26)
		return ((ch+num)-26);
	return ch+num;
}

//Compare the data in array found with thre frequency data in array given, looking 
//for a key that will give you the best match. To do this, try each of teh 26 rotations,
//and remember which gives the smallest difference between the frequencies you 
//observed and teh frequencies given. Return the key.
int findKey(float given[], float found[]){

	int key = 0;
	float differenceTotal = 0;
	float lowestDifferenceTotal = 1000;
	for(int i = 0; i<LETTERCOUNT; i++){
		for(int j = 0; j<LETTERCOUNT; j++){
			int foundIndex = j+i;
			if(foundIndex >= 26)
				foundIndex = foundIndex - 26;
			float temp = given[j] - found[foundIndex];
			temp = temp * temp;
			differenceTotal = differenceTotal + temp;
		}
		if(differenceTotal < lowestDifferenceTotal){
			lowestDifferenceTotal = differenceTotal;
			key = i;
		}
		
		differenceTotal = 0;
	}
	return key;
}

void decrypt(int key, char fname[]){

		



}
