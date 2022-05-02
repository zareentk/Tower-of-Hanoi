#include <stdio.h>
#include <unistd.h>
#include <string.h>

int peg1[9]={0,0,0,0,0,0,0,0,0};
int peg2[9]={0,0,0,0,0,0,0,0,0};
int peg3[9]={0,0,0,0,0,0,0,0,0};

void multiplier(int disk){
	int i=0;
	int space = 10 - disk;
	int plus = disk;
	char pegstring[26] = " ";

	for(i=1; i<=space; i++){
		strncat(pegstring, " ",1);
	}
	if(plus >0){
		for(i=1;i<=plus; i++){
			strncat(pegstring,"+",1);
		}
		strncat(pegstring,"|",1);
        	for(i=1;i<=plus; i++){
                	strncat(pegstring,"+",1);
        	}
	}else{
		strncat(pegstring, "|",1);
	}
        for(i=1; i<=space; i++){
                strncat(pegstring," ",1);
        }
	strncat(pegstring,"    ",4);
	printf("%s", pegstring);
}
void display_pegs(){
        int i;
        for(i=8; i>=0; i--){
	       multiplier(peg1[i]);
               multiplier(peg2[i]);
	       multiplier(peg3[i]);
	       printf(" \n");	
	}
	printf(" XXXXXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXXXXX     XXXXXXXXXXXXXXXXXXXXX\n");
}
void move(int pegA[9], int pegB[9],int pegC[9]){
	int i,j;
	int temp;

	for(i = 0; i<=8; i++){
		if(pegA[i+1] == 0){
			temp = pegA[i];
			pegA[i] = 0;
			break;
		}
	}
	for(j = 0; j<=8; j++){
		if(pegB[j] == 0){	
			pegB[j] = temp;
			break;
		}
	}
	display_pegs();
}

void hantow(int nod, int pego[9], int pegd[9], int pegh[9]){

	if(nod > 1){
		hantow(nod-1, pego,pegh,pegd);

	}
	move(pego,pegd,pegh);
	sleep(1);
	if(nod > 1){
		hantow(nod-1,pegh,pegd,pego);

	}
}
void init(int nod,int peg1[9]){
	int i;
	for(i=nod; i>=1; i--){
		peg1[nod-i] = i;
	}
}

int main(int argc,char* argv[]) {
	int i, n;
	if (argc != 2) {
		printf("Incorrect number of command line arguments\n");
		return 0;
	}
	 
  	if (strlen(argv[1]) == 1) {
		if('0' < argv[1][0] && argv[1][0] <= '9'){
			int nod = argv[1][0] - '0';
			init(nod, peg1);
			display_pegs();
			hantow(nod, peg1, peg2, peg3);
			printf("done\n");
		}
		else{
			printf("Incorrect argument\n");
			return 0;
		}

	}else{
		printf("Incorrect length of command line argument\n");
	}
return 0;
}
