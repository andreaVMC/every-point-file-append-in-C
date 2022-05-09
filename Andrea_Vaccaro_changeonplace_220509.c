//Andrea Vaccaro Github:andreaVMC 09/05/2022
//change on place of a txt in everypoint of it, without an array to save the sting in the file
#include <stdio.h>
#include <string.h>
int main(){
	FILE *f=fopen("file.txt","r+"); //open the file in r+
	int i,p,lf,dif; //p=positionwhere you want to put the string, lf=len of file, di=dif between lf and pos
	char box,parola[20]; //parola=string you wanto to put in the file box=box where to save file char
	
	printf("inserire parola:"); //dataentry of word
	gets(&parola[0]);
	
	fseek(f,0,2); //go to the last point of file 
	lf=ftell(f); //memorize the len of file
	
	do{ //dataentry of the word's position with entry control 
		printf("posizione parola:");
		scanf("%d",&p);
		if(p>lf)
			printf("posizione troppo grande"); //error message
	}while(p>lf);
	
	dif=lf-p; //calculate the dif between the len of the file and the word's position
	for(i=0;i<strlen(parola);i++) //for the len of the new word i append at the end of the file n space char
		fputc(32,f);
	
	for(i=0;i<dif;i++){ //i bring every letter from word's position to the end f the file (previusly the adding of spaces) to the end of the file
		fseek(f,-(strlen(parola)+1+i),2);
		box=fgetc(f);
		fseek(f,-(1+i),2);
		fputc(box,f);
	}
	
	fseek(f,p,0); // i return to the designed position of the new word
	fputs(parola,f); //i put the new word
	
	return 0;
}

//69
