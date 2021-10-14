#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>

int CData = 0, CScore = 0;
char question[16][200];
char Ans[16][5][200];
int AnsR[16];

int whichPoint = 0;
char name[500][16];
int score[500] = {0};


void splash(){
	printf(" __  __  _  _  _  _                       _\n");	
	printf("|  \\/  |(_)| || |(_)                     (_)\n");
	printf("| \\  / | _ | || | _   ___   _ __    __ _  _  _ __  ___\n");
	printf("| |\\/| || || || || | / _ \\ | \'_ \\  / _` || || \'__|/ _ \\\n");
	printf("| |  | || || || || || (_) || | | || (_| || || |  |  __/\n");
	printf("|_|  |_||_||_||_||_| \\___/ |_| |_| \\__,_||_||_|   \\___|\n");
	printf("\n\n");
}

void swapInt(int *dis, int *toDis){
	int temp = *dis;
	*dis = *toDis;
	*toDis = temp;
}

void swap(char *dis, char *toDis){
	char temp[200];
	strcpy(temp,dis);
	strcpy(dis,toDis);
	strcpy(toDis,temp);
}


void readQuestion(){
	FILE *read = fopen("./questions.txt","r");
 	CData = 0;
	while( fscanf(read, "%[^#]#%[^#]#%[^#]#%[^#]#%[^@]@%d\n",&question[CData],&Ans[CData][0],&Ans[CData][1],&Ans[CData][2],&Ans[CData][3],&AnsR[CData]) != EOF){
//		printf("%s\n%s - %s - %s - %s\n%d\n-----",question[CData],Ans[CData][0],Ans[CData][1],Ans[CData][2],Ans[CData][3],AnsR[CData]);
		CData++;
	}
	fclose(read);
}

void bubbleSort(){
	for(int i = 0; i<CScore; i++){
		for(int j = i+1; j<CScore; j++){
			if(strcmpi(name[i],name[j])>0){
				swap(name[i],name[j]);
				swapInt(&score[i],&score[j]);
			}
		}
	}
	
	for(int i = 0; i<CScore; i++){
		for(int j = i+1; j<CScore; j++){
			if(score[i]<score[j]){
				swap(name[i],name[j]);
				swapInt(&score[i],&score[j]);
			}
		}
	}
}
void readScore(){
	FILE *read = fopen("./scores.txt","r");
	CScore = 0;
	while( fscanf(read, "%[^#]#%d\n",&name[CScore],&score[CScore]) != EOF){
			CScore++;
	}
	fclose(read);
}

void printHOF(){
	printf("Hall of Fame\n=================================\n");
	bubbleSort();
	for(int i = 0; i<CScore; i++){
		printf("%03d. %-20s %7d\n",i+1,name[i],score[i]);
	}
}

void updateHOF(){
	FILE *FW = fopen("./scores.txt","w");
	bubbleSort();
	for(int i = 0; i<CScore; i++){
		fprintf(FW,"%s#%d\n",name[i],score[i]);
	}
	fclose(FW);
}


void shuffle(){
	srand(time(0));
	
	for(int i = 0; i<CData; i++){
		int r = i+(rand()%(CData-i));
		swap(question[i],question[r]);
		swap(Ans[i][0],Ans[r][0]);
		swap(Ans[i][1],Ans[r][1]);
		swap(Ans[i][2],Ans[r][2]);
		swap(Ans[i][3],Ans[r][3]);
		swapInt(&AnsR[i],&AnsR[r]);
	}
}

int money[16] = {0,500,1000,2000,3000,5000,7500,10000,15000,25000,50000,75000,150000,250000,500000,1000000};

void printStep(int questionNum){
questionNum++;	

for(int i = 15; i>0; i--){		
		if(questionNum == i && i == 15){
			printf("[x] $%7d    <- Safe Zone 3\n",money[i]);
			whichPoint = 3;
		} else if (questionNum == i && i == 5){
			printf("[x] $%7d    <- Safe Zone 1\n",money[i]);
			whichPoint = 1;
		} else if (questionNum == i && i == 10){
			printf("[x] $%7d    <- Safe Zone 2\n",money[i]);
			whichPoint = 2;
		} else if (questionNum == i){
			printf("[x] $%7d\n",money[i]);
		} else if (i == 15){
			printf("[ ] $%7d    <- Safe Zone 3\n",money[i]);			
		} else if (i == 10){
			printf("[ ] $%7d    <- Safe Zone 2\n",money[i]);			
		} else if (i == 5){
			printf("[ ] $%7d    <- Safe Zone 1\n",money[i]);			
		} else {
			printf("[ ] $%7d\n",money[i]);
		}
	}
	printf("\nGet ready for $%d question! Press ENTER to continue...",money[questionNum]);
}

void print205(){
	for(int i = 0; i<73; i++){
		printf("%c",205);
	}
}

void printMid(int xxx){
	for(int i = 0; i<36;i++){
		printf("%c",205);
	}
	if(xxx == 1){
		printf("%c",203);
	} else if (xxx == 2){
		printf("%c",206);
	} else if (xxx == 3){
		printf("%c",202);
	}
	for(int i = 0; i<36; i++){
		printf("%c",205);
	}
}

void printQuestions(int questionNum){
	printf("%c",201);
	print205();
	printf("%c\n",187);
	printf("%c %-71s %c\n",186,question[questionNum],186);
	printf("%c",204);
	printMid(1);
	printf("%c\n",185);
	printf("%c A: %-32s%c B: %-32s%c\n",186,Ans[questionNum][0],186,Ans[questionNum][1],186);
	printf("%c",204);
	printMid(2);
	printf("%c\n",185);
	printf("%c C: %-32s%c D: %-32s%c\n",186,Ans[questionNum][2],186,Ans[questionNum][3],186);
	printf("%c",200);
	printMid(3);
	printf("%c\n",188);
}

void printQuestionsE(int questionNum,int Answer){
	printf("%c",201);
	print205();
	printf("%c\n",187);
	printf("%c %-71s %c\n",186,question[questionNum],186);
	printf("%c",204);
	printMid(1);
	printf("%c\n",185);
	if(Answer == 1 || Answer == 2){
		printf("%c A: %-32s%c B: %-32s%c\n",186,Ans[questionNum][0],186,Ans[questionNum][1],186);
		printf("%c",204);
		printMid(2);
		printf("%c\n",185);
		printf("%c C: %-32c%c D: %-32c%c\n",186,'-',186,'-',186);
		printf("%c",200);
		printMid(3);
		printf("%c\n",188);
	} else {
		printf("%c A: %-32c%c B: %-32c%c\n",186,'-',186,'-',186);
		printf("%c",204);
		printMid(2);
		printf("%c\n",185);
		printf("%c C: %-32s%c D: %-32s%c\n",186,Ans[questionNum][2],186,Ans[questionNum][3],186);
		printf("%c",200);
		printMid(3);
		printf("%c\n",188);		
	}
	
}

int main(){
	
	int input = 0;
	readQuestion();
	readScore();
	
	do{
		system("cls");
		int questionNum = 0;
		if(input != 1 && input != 2 && input != 3){
			splash();
			printf("MENU\n");
			printf("1. Let's Play!!\n2. Hall of Fame\n3. Exit and Save Hall of Fame\n>> ");
			scanf("%d",&input);
			getchar();
		}
		
		if(input == 1){
			system("cls");
			shuffle();
			bool chance = true;
			bool lose = true;
			int level = 0;
			questionNum = 0;
			int converted = 0;
			int moneyEarned = 0;

			do{
			system("cls");
			printStep(questionNum);
			getchar();
			system("cls");
			printQuestions(questionNum);
			char confirmc;
			char inputc; 
			lose = false;
			
				do{
					
					if(chance == true){
						printf("Input \'E\' to use 50:50\n");
					}

					printf("Input \'F\' to surrender\nYour answer: ");
					scanf("%c",&inputc);
					getchar();
					
					if(chance == true && inputc == 'E'){
						system("cls");
						printQuestionsE(questionNum,AnsR[questionNum]);
						chance = false;
						
					}
					if(inputc == 'F'){
						printf("Are you sure to surrender? [Y/N]: ");
						scanf("%c",&confirmc);
						getchar();
					} else if (inputc == 'A' || inputc == 'B' || inputc == 'C' || inputc == 'D'){
						printf("Lock your answer to \'%c\'? [Y/N]: ",inputc);
						scanf("%c",&confirmc);
						getchar();
					}
				}while( confirmc!='Y' || (inputc != 'A' && inputc != 'B' && inputc != 'C' && inputc != 'D' && inputc != 'F') );
				
			if(inputc == 'A'){
				converted = 1;
			} else if (inputc == 'B'){
				converted = 2;
			} else if (inputc == 'C'){
				converted = 3;
			} else if (inputc == 'D'){
				converted = 4;
			} else {
				converted = 0;
			}
			
			if(converted == AnsR[questionNum]){
				if(questionNum > 13){
					
				} else {
					printf("\nYou are right! You won $%d\n",money[questionNum+1]);
					moneyEarned = money[questionNum+1];
					printf("Press ENTER to continue...");
					getchar();
				}

			} else if(inputc == 'F'){
				system("cls");
				printf("Thank you for playing.\nYou got $%d\n",money[questionNum]/2);
				moneyEarned = (money[questionNum]/2);
				lose = true;
			} else {
				system("cls");
				printf("Sorry, you got the answer wrong.\n");
				printf("Thank you for playing.\n");
				if(whichPoint == 1){
					printf("You got $5000\n");
					moneyEarned = 5000;
				} else if (whichPoint == 2){
					printf("You got $50000\n");
					moneyEarned = 50000;
				} else if (whichPoint == 3){
					printf("You got $1000000\n");
					moneyEarned = 1000000;
				} else {
					printf("You got $0\n");
				}
				lose = true;
			}
			
			if(lose == false){
				questionNum++;	
			} else {
				printf("\nPlease input your nickname [Max 15 characters]: ");
				scanf("%s",&name[CScore]);
				score[CScore] = moneyEarned;
				CScore++;
				getchar();
				printf("Press ENTER to continue...");
				getchar();
				break;
			}
			if(questionNum > 14){
				
				printf("You are right! you win $1000000");
				getchar();
				system("cls");
				printf("Congratulations! You are the next Millionaire!!\n");
				printf("\nPlease input your nickname [Max 15 characters]: ");
				scanf("%s",&name[CScore]);
				score[CScore] = 1000000;
				CScore++;
				getchar();
				lose = true;	
				printf("Press ENTER to continue...");
			}

			}while(lose == false);
			
			input = -1;

		} else if (input == 2){
			system("cls");
			printHOF();
			printf("\nPress ENTER to continue...");
			getchar();
			input = -1;
		} else if (input == 3){
			updateHOF();
			printf("\n\"scores.txt\" file has been updated.\nThank you for playing!\n\nPress ENTER to exit...");
			getchar();
			exit(0);
			
		} else {
			do{
				if(input != -1 || input != sizeof(int)){printf(">> ");};
				scanf("%d",&input);
				getchar();
			}while(input != 1 && input != 2 && input != 3);
		}
	}while(true);
	
}


