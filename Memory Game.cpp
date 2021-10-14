#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

int turn = 0;

void splash(){
printf("  __  __  U _____ u  __  __    U  ___ u   ____     __   __\n");
printf("U|\' \\/ \'|u\\| ___\"|/U|\' \\/ \'|u   \\/\"_ \\/U |  _\"\\ u  \\ \\ / /\n");
printf("\\| |\\/| |/ |  _|\"  \\| |\\/| |/   | | | | \\| |_) |/   \\ V /\n");
printf(" | |  | |  | |___   | |  | |.-,_| |_| |  |  _ <    U_|\"|_u\n");
printf(" |_|  |_|  |_____|  |_|  |_| \\_)-\\___/   |_| \\_\\     |_|\n");
printf("<<,-,,-.   <<   >> <<,-,,-.       \\\\     //   \\\\_.-,//|(_\n");
printf(" (./  \\.) (__) (__) (./  \\.)     (__)   (__)  (__)\\_) (__)\n\n\n");
}
// ini UNTUK 2x2-------------------------------------------------------------
void printmap(bool (*selected)[2], char (*card)[2], int size){

	for(int i = 0; i<=size; i++){
		if(i == 0){
			printf(" # |");
		} else if (i == size){
			printf(" %d |\n",i);
		} else {
			printf(" %d |",i);
		}
	}
		
	for(int j = 0; j<size; j++){
		printf(" %d |",j+1);
		for(int k = 0; k<size; k++){
			if(selected[j][k]){
				printf(" %c |",card[j][k]);
			} else {
				printf(" - |");
			}
		}
		printf("\n");
	}	
}	
	
void begin(bool (*selected)[2], char (*card)[2], int size){
	int x1, y1, x2, y2;
	printf("Turn : %d\n\n",turn);
	printmap(selected,card, size);
	printf("\n\n");
	do{
		printf("Input tile-1 to open [row column]: ");
		scanf("%D", &x1);
		scanf("%D", &y1);
		if(selected[x1-1][y1-1] == true){
			printf("Please choose another row and column!\n");
		} else if (x1>size || y1>size){
			printf("Must INPUT on available Row and Column !!!\n");
		} else {
			printf("Bad INPUT !\n");
		}
	}while(selected[x1-1][y1-1] == true || (x1>size || y1>size));
	turn++;
	getchar();
	system("cls");
	selected[x1-1][y1-1] = true;
	printf("Turn : %d\n\n",turn);
	printmap(selected, card, size);
	printf("\n\n");
	do{
	printf("Input tile-2 to open [row column]: ");	
	scanf("%d",&x2);
	scanf("%d",&y2);
		if(selected[x2-1][y2-1] == true){
			printf("Please choose another row and column!\n");
		} else if(x2 == x1 && y2 == y1){
			printf("Cannot INPUT same Row and Column !!!\n");
		} else if (x2>size || y2>size){
		printf("Must INPUT on available Row and Column !!!\n");
		}
	}while(selected[x2-1][y2-1] == true || (x2 == x1 && y2 == y1) || (x2>size || y2>size));
	turn++;
	getchar();
	system("cls");
	selected[x2-1][y2-1] = true;
	
	if (card[x1-1][y1-1] != card[x2-1][y2-1]){
		printf("Turn : %d\n\n", turn);
		printmap(selected, card, size);
		selected[x1-1][y1-1] = false;
		selected[x2-1][y2-1] = false;
		printf("\nNOPE !\npress ENTER to continue...");
		getchar();	
		system("cls");
	} else {
		printf("Turn : %d \n\n",turn);
		printmap(selected, card, size);
		printf("\nYeah !\npress ENTER to continue...");
		getchar();

	}
		

//	printmap(selected, card, size);
}
//INI UNTUK 4x4-------------------------------------------------------------
void printmap4(bool (*selected)[4], char (*card)[4], int size){

	for(int i = 0; i<=size; i++){
		if(i == 0){
			printf(" # |");
		} else if (i == size){
			printf(" %d |\n",i);
		} else {
			printf(" %d |",i);
		}
	}
		
	for(int j = 0; j<size; j++){
		printf(" %d |",j+1);
		for(int k = 0; k<size; k++){
			if(selected[j][k]){
				printf(" %c |",card[j][k]);
			} else {
				printf(" - |");
			}
		}
		printf("\n");
	}	
}	
	
void begin4(bool (*selected)[4], char (*card)[4], int size){
	int x1, y1, x2, y2;
	printf("Turn : %d\n\n",turn);
	printmap4(selected,card, size);
	printf("\n\n");
	do{
	printf("Input tile-1 to open [row column]: ");
	scanf("%d", &x1);
	scanf("%d", &y1);
		if(selected[x1-1][y1-1] == true){
			printf("Please choose another row and column!\n");
		} else if (x1>size || y1>size){
			printf("Must INPUT on available Row and Column !!!\n");
		} else {
			printf("Bad INPUT !\n");
		}
	}while(selected[x1-1][y1-1] == true || (x1>size || y1>size));
	turn++;
	getchar();
	system("cls");
	selected[x1-1][y1-1] = true;
	printf("Turn : %d\n\n",turn);
	printmap4(selected, card, size);
	printf("\n\n");
	do{
	printf("Input tile-2 to open [row column]: ");	
	scanf("%d",&x2);
	scanf("%d",&y2);
		if(selected[x2-1][y2-1] == true){
			printf("Please choose another row and column!\n");
		} else if(x2 == x1 && y2 == y1){
			printf("Cannot INPUT same Row and Column !!!\n");
		} else if (x2>size || y2>size){
		printf("Must INPUT on available Row and Column !!!\n");
		}
	}while(selected[x2-1][y2-1] == true || (x2 == x1 && y2 == y1) || (x2>size || y2>size));
	turn++;
	getchar();
	system("cls");
	selected[x2-1][y2-1] = true;
	
	if (card[x1-1][y1-1] != card[x2-1][y2-1]){
		printf("Turn : %d\n\n", turn);
		printmap4(selected, card, size);
		selected[x1-1][y1-1] = false;
		selected[x2-1][y2-1] = false;
		printf("\nNOPE !\npress ENTER to continue...");
		getchar();	
		system("cls");
	} else {
		printf("Turn : %d \n\n",turn);
		printmap4(selected, card, size);
		printf("\nYeah !\npress ENTER to continue...");
		getchar();

	}
		

//	printmap4(selected, card, size);
}
//INI UNTUK 8x8-------------------------------------------------------------
void printmap8(bool (*selected)[8], char (*card)[8], int size){

	for(int i = 0; i<=size; i++){
		if(i == 0){
			printf(" # |");
		} else if (i == size){
			printf(" %d |\n",i);
		} else {
			printf(" %d |",i);
		}
	}
		
	for(int j = 0; j<size; j++){
		printf(" %d |",j+1);
		for(int k = 0; k<size; k++){
			if(selected[j][k]){
				printf(" %c |",card[j][k]);
			} else {
				printf(" - |");
			}
		}
		printf("\n");
	}	
}	
	
void begin8(bool (*selected)[8], char (*card)[8], int size){
	int x1, y1, x2, y2;
	printf("Turn : %d\n\n",turn);
	printmap8(selected,card, size);
	printf("\n\n");
	do{
	printf("Input tile-1 to open [row column]: ");
	scanf("%d", &x1);
	scanf("%d", &y1);
		if(selected[x1-1][y1-1] == true){
			printf("Please choose another row and column!\n");
		} else if (x1>size || y1>size){
			printf("Must INPUT on available Row and Column !!!\n");
		} else {
			printf("Bad INPUT !\n");
		}
	}while(selected[x1-1][y1-1] == true || (x1>size || y1>size));
	turn++;
	getchar();
	system("cls");
	selected[x1-1][y1-1] = true;
	printf("Turn : %d\n\n",turn);
	printmap8(selected, card, size);
	printf("\n\n");
	do{
	printf("Input tile-2 to open [row column]: ");	
	scanf("%d",&x2);
	scanf("%d",&y2);
		if(selected[x2-1][y2-1] == true){
			printf("Please choose another row and column!\n");
		} else if(x2 == x1 && y2 == y1){
			printf("Cannot INPUT same Row and Column !!!\n");
		} else if (x2>size || y2>size){
		printf("Must INPUT on available Row and Column !!!\n");
		}
	}while(selected[x2-1][y2-1] == true || (x2 == x1 && y2 == y1) || (x2>size || y2>size));
	turn++;
	getchar();
	system("cls");
	selected[x2-1][y2-1] = true;
	
	if (card[x1-1][y1-1] != card[x2-1][y2-1]){
		printf("Turn : %d\n\n", turn);
		printmap8(selected, card, size);
		selected[x1-1][y1-1] = false;
		selected[x2-1][y2-1] = false;
		printf("\nNOPE !\npress ENTER to continue...");
		getchar();	
		system("cls");
	} else {
		printf("Turn : %d \n\n",turn);
		printmap8(selected, card, size);
		printf("\nYeah !\npress ENTER to continue...");
		getchar();

	}
		

//	printmap8(selected, card, size);
}
//divider

void swap(char *dis, char *toDis){
	char temp = *dis;
	*dis = *toDis;
	*toDis = temp;
}

void shuffle(char *card, int size){
    srand(time(0));
    
    for(int i = 0; i<size; i++){
    	int r = i+(rand()%(size-i));
    	swap(&card[i],&card[r]);
	}
}
//checker 2x2
bool checker(bool (*selected)[2], int size){
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++){
			if(!selected[i][j]){
				return false;
			}
		}
	}
	return true;
}
//checker 4x4
bool checker4(bool (*selected)[4], int size){
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++){
			if(!selected[i][j]){
				return false;
			}
		}
	}
	return true;
}
//checker 8x8
bool checker8(bool (*selected)[8], int size){
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size; j++){
			if(!selected[i][j]){
				return false;
			}
		}
	}
	return true;
}


//Hall Of Fame AREA

//dis global-----------------------------------
char name[300][5];
int level[300];
int steps[300];
int counterData = 0;
int diff = 0;
//up global------------------------------------

void readFile(){	
	counterData = 0;
	FILE *fp = fopen("./hall-of-fame.txt","r");
	while( fscanf(fp,"%d#%[^#]#%d\n",&level[counterData],name[counterData],&steps[counterData]) != EOF){
		counterData++;
	}
	fclose(fp);
}

void swapInt(int *dis, int *toDis){
	int temp = *dis;
	*dis = *toDis;
	*toDis = temp;
}

//sorting 2 tingkat, sort 4 - 16 - 64 Dulu, lalu sort Score TURN nya. nama tidak diutamakan.
void bubbleSort(){
	for(int i = 0; i<counterData; i++){
		for(int j = i+1; j<counterData; j++){
			if(strcmpi(name[i],name[j])>0){
				swapInt(&level[i],&level[j]);
				swapInt(&steps[i],&steps[j]);
				char temp[30];
				strcpy(temp, name[j]);
				strcpy(name[j],name[i]);
				strcpy(name[i],temp);
			}
		}
	}
	
	for(int i = 0; i<counterData; i++){
		for(int j = i+1; j<counterData; j++){
			if(level[i] > level[j]){
				swapInt(&level[i],&level[j]);
				swapInt(&steps[i],&steps[j]);
				char temp[30];
				strcpy(temp, name[j]);
				strcpy(name[j],name[i]);
				strcpy(name[i],temp);
			}
		}
	}
	
	for(int i = 0; i<counterData; i++){
		for(int j = i+1; j<counterData; j++){
			if(steps[i] > steps[j]){
				swapInt(&level[i],&level[j]);
				swapInt(&steps[i],&steps[j]);
				char temp[30];
				strcpy(temp, name[j]);
				strcpy(name[j],name[i]);
				strcpy(name[i],temp);
			}	
		}
	}
}

void saveToFile(char (*newname)){
	FILE *FA = fopen("./hall-of-fame.txt","a");
	fprintf(FA,"%d#%s#%d",diff, newname, turn);
	fclose(FA);
}
//MUST BUBBLE FIRST BEFORE UPDATING!!!
void updateTXT(){
	FILE *FW = fopen("./hall-of-fame.txt","w");
	for(int i = 0; i<counterData; i++){
		fprintf(FW,"%d#%s#%d\n",level[i],name[i],steps[i]);
	}
	fclose(FW);
}

void printHOF(){
	int i = 0, j = 0, k = 0;
	printf("Hall Of Fame - Easy\n");
	printf("==========================\n");
	for(i = 0; i<3; i++){
		printf("%d. %s (%-4d)\n",i+1, name[i], steps[i]);
	}
	
	printf("\nHall Of Fame - Normal\n");
	printf("==========================\n");
	while(level[i] == 4){
		i++;
	};
	for(j = i; j<i+3; j++){
		printf("%d. %s (%-4d)\n",j-i+1, name[j], steps[j]);		
	}
	
	printf("\nHall Of Fame - Hard\n");
	printf("==========================\n");
	while(level[j]==16){
		j++;
	};
	for(k = j; k<j+3; k++){
		printf("%d. %s (%-4d)\n",k-j+1, name[k], steps[k]);		
	}
printf("\n");
}



int main(){
	
	int input = -1;		
	readFile();
	bubbleSort();
	updateTXT();
	do{
		char YN;
		char newname[4];
		if(input != 1 && input != 2 && input != 3 && input != 0){
			splash();
			printf("Choose your difficulty level [0 to exit]:\n");
			printf("1) LoL\n2) Close Enough\n3) GGWP\n>> ");
			scanf("%d",&input);
			getchar();	
		}
		
		if(input == 1){
			do{
				printf("Seriously??? [Y/N]: ");
				scanf("%c",&YN);
				getchar();
				if(YN == 'Y'){
					bool done = false;
					turn = 0, diff = 4;
					bool selected[2][2] = {false};
					char card[2][2] = { 
										{'A','B'},
										{'A','B'}
									  };
					shuffle(*card, 4);
					readFile();
					turn = 0;
					system("cls");
					printHOF();
					//HOF(_);
					printf("Let's 'PLAY' !!! (Press ENTER to continue...)");
					getchar();
					system("cls");
					
					do{
						system("cls");
						done = checker(selected,2);
						begin(selected,card,2);
						done = checker(selected,2);
						if(done == true){
							printf("\n\nInput your nickname [3 characters]: ");
							scanf("%s",&newname);
							getchar();
							printf("\n\nPress ENTER to continue...");
							saveToFile(newname);
							readFile();
							bubbleSort();
							updateTXT();
							getchar();
						}
					} while (done != true);
					break;
				}
			}while(YN != 'N');
			system("cls");
			input = -1;
			
		} else if (input == 2){
			do{
				printf("Seriously??? [Y/N]: ");
				scanf("%c",&YN);
				getchar();
				if(YN == 'Y'){
					int done = 0;
					turn = 0, diff = 16;
					bool selected[4][4] = {false};
					char card[4][4] = { 
										{'A','B','C','D'},
										{'D','C','B','A'},
										{'E','F','G','H'},
										{'H','G','F','E'}
									  };
					shuffle(*card, 16);
		
					turn = 0;
					system("cls");
					printHOF();
					//HOF(_);
					printf("Let's 'PLAY' !!! (Press ENTER to continue...)");
					getchar();
					system("cls");
					
					do{
						system("cls");
						done = checker4(selected,4);
						begin4(selected,card,4);
						done = checker4(selected,4);
						if(done == true){
							printf("\n\nInput your nickname [3 characters]: ");
							scanf("%s",&newname);
							getchar();
							printf("\n\nPress ENTER to continue...");
							saveToFile(newname);
							readFile();
							bubbleSort();
							updateTXT();
							getchar();
						}
					} while (done != true);
					break;
				}
			}while(YN != 'N');
			system("cls");
			input = -1;
					
		} else if (input == 3){
			do{
				printf("Seriously??? [Y/N]: ");
				scanf("%c",&YN);
				getchar();
				if(YN == 'Y'){
					int done = 8;
					turn = 0, diff = 64;
					bool selected[8][8] = {false};
					char card[8][8] = { 
										{'A','B','C','D','E','F','G','H'},
										{'H','G','F','E','D','C','B','A'},
										{'I','J','K','L','M','N','O','P'},
										{'P','O','N','M','L','K','J','I'},
										{'Q','R','S','T','U','V','W','X'},
										{'X','W','V','U','T','S','R','Q'},
										{'Y','Z','0','1','2','3','4','5'},
										{'5','4','3','2','1','0','Z','Y'}
									  };
					shuffle(*card, 64);
		
					turn = 0;
					system("cls");
					printHOF();
					//HOF(_);
					printf("Let's 'PLAY' !!! (Press ENTER to continue...)");
					getchar();
					system("cls");
					
					do{
						system("cls");
						done = checker8(selected,8);
						begin8(selected,card,8);
						done = checker8(selected,8);
						if(done == true){
							printf("\n\nInput your nickname [3 characters]: ");
							scanf("%s",&newname);
							getchar();
							printf("\n\nPress ENTER to continue...");
							saveToFile(newname);
							readFile();
							bubbleSort();
							updateTXT();
							getchar();
						}
					} while (done != true);
					break;
				}
			}while(YN != 'N');
			system("cls");
			input = -1;
			
		} else if (input == 0){
			do{
				printf("Seriously??? [Y/N]: ");
				scanf("%c",&YN);
				getchar();
				if(YN == 'Y'){
					printf("See Yaa !!!");
					getchar();
					exit(0);			
				}
			}while(YN != 'N');
			system("cls");
			input = -1;
		
		} else {
			do{
				if(input != -1 || input != sizeof(int)){printf(">> ");};
				scanf("%d",&input);
				getchar();
			}while(input != 1 && input != 2 && input != 3 && input != 0);
		}
		
	}while(true);
}
