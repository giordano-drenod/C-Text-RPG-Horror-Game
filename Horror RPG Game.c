#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <unistd.h>


//Player Definitions
typedef struct PlayerChar
{
    unsigned char id;
    char Name[30];
    unsigned char ITEMS;
    unsigned char LVL;
    unsigned char XPM;
    unsigned char XP;
    unsigned char HPM;
    unsigned char HP;
    unsigned char ATK;
    unsigned char DEF;
    unsigned char SPD;
}player;
    
player Player;


//Enemy Definitions
typedef struct EnemyChar
{
    unsigned char id;
    char Name[30];
    unsigned char ITEMS;
    unsigned char LVL;
    unsigned char XP;
    unsigned char HPM;
    unsigned char HP;
    unsigned char ATK;
    unsigned char DEF;
    unsigned char SPD;
}enemy;
    
//
typedef struct ItemInfo
{
	unsigned char id;
	char Name[30];
	unsigned char Special;
}item;

typedef struct ItemArmor
{
	item Info;
	unsigned char Defense;
	unsigned char Position;
}armor;

typedef struct ItemWeapon
{
	item Info;
	unsigned char Damage;
	unsigned char Type;
}weapon;

//Function Declarations
void GameStart();
void Scene_1();
void WildOne();
void Combat(unsigned char EnemySelect, enemy A);
int ValidChar(char Input, char LowInp1, char HighInp1);
void PlayerDied(unsigned char Reason);
void GameExit();
void PlayerDied(unsigned char Reason);



void main ()												//Main Screen
{
    do
    {
        setlocale(LC_ALL, "Portuguese");
        srand (time(NULL));
        unsigned char Option;
        printf ("|}    {|  *   ___   ___  *            ____  \n");
        printf ("| }  { |  |  (     (     |  |}   |   /      \n");
        printf ("|  }{  |  |   =     =    |  | }  |  {   ___ \n");
        printf ("|      |  |    =)    =)  |  |  } |   {   |  \n");
        printf ("|      |  |  ___)  ___)  |  |   }|    ===/  RE-ALPHA\n");

        printf ("1.New Game \n2.Load Game\n3.Options\n4.Close");
        printf ("\n\nYour choice? ");
        Option = getche();
		if (ValidChar(Option, '1', '4') == 1)
		{
	        switch(Option)
	        {
	            case '1':
	                GameStart();
	            break;
	
	            case '2':
	                printf ("\nCurrently unavaible!\n");
	            break;
	
	            case '3':
	                printf ("\nCurrently unavaible!\n");
	            break;
	
	            case '4':
	                GameExit();
	            break;
	        }
		}
        system("PAUSE");
        system("cls");
	} while (1);
}


void GameStart()											//Class Selector
{
	system ("cls");
    char Class;
    Class = 0;

    printf ("Choose a class: \n1)Cop(Press -A- for more information) \n2)Thief(Press -B- for more information) \n3)Cientista(Aperte -C- para mais informações) \n4)Botânico(Aperte -D- para mais informações) \n5)Padre(Aperte -E- para mais informações) \n>");

    Class = getche();
    setbuf (stdin, NULL);

	if ((Class == 'a' || Class == 'A') && (ValidChar(Class, 'a', 'f') == 1))
        printf ("\nCurrently unavaible! \n\nStats:\n->Starting HP: \n->Max Weight: \n->Strenght: \n->Precision: \n->Medicine: \n->Sanity: \n->Luck: \n");
	
	if ((Class == 'b' || Class == 'B') && (ValidChar(Class, 'a', 'f') == 1))
		printf ("\nCurrently unavaible! \n\nStats:\n->Starting HP: \n->Max Weight: \n->Strenght: \n->Precision: \n->Medicine: \n->Sanity: \n->Luck: \n");
	
	if ((Class == 'c' || Class == 'C') && (ValidChar(Class, 'a', 'f') == 1))
        printf ("\nCurrently unavaible! \n\nStats:\n->Starting HP: \n->Max Weight: \n->Strenght: \n->Precision: \n->Medicine: \n->Sanity: \n->Luck: \n");
        
    if ((Class == 'd' || Class == 'D') && (ValidChar(Class, 'a', 'f') == 1))
        printf ("\nCurrently unavaible! \n\nStats:\n->Starting HP: \n->Max Weight: \n->Strenght: \n->Precision: \n->Medicine: \n->Sanity: \n->Luck: \n");
    
    if ((Class == 'e' || Class == 'E') && (ValidChar(Class, 'a', 'f') == 1))
        printf ("\nCurrently unavaible! \n\nStats:\n->Starting HP: \n->Max Weight: \n->Strenght: \n->Precision: \n->Medicine: \n->Sanity: \n->Luck: \n");
            
    if ((Class == 'f' || Class == 'F') && (ValidChar(Class, 'a', 'f') == 1))
        printf ("\nCurrently unavaible! \n\nStats:\n->Starting HP: \n->Max Weight: \n->Strenght: \n->Precision: \n->Medicine: \n->Sanity: \n->Luck: \n");

    if (Class == '1')
    {
        Player.HPM = 10;
		Player.HP = 10;
		Player.ATK = 6;
		Player.DEF = 0;
		Player.SPD = 5;
    }
    
    if (Class == '2')
    {
        Player.HPM = 8;
		Player.HP = 8;
		Player.ATK = 7;
		Player.DEF = 0;
		Player.SPD = 7;
    }
    
    if (Class >= '1' && Class <='6')
    {
    	printf ("\nWrite your name: ");
    	scanf ("%s", Player.Name);
    	SceneStart();					//MUDAR AQUI DEPOIS!
	}
    
    system("PAUSE");
    GameStart();
}


void SceneStart(void)										//Start Cutscene
{
    system ("cls");
    printf ("Existem coisas, seres e mundos...\n");
    Sleep (1500);
    printf ("                            ...Que nós não vemos; Não porque não os enchergamos...\n");
    Sleep (2000);
    printf ("        ...Não somente por causa de nossa ignorância ou tolice...\n");
    Sleep (2000);
    printf ("                    ...Mas por causa que algumas verdades se ocultam...\n");
    Sleep (3500);
    system ("cls");
    printf ("...para se revelarem nos piores momentos...\n");
    Sleep (4000);
    
    Scene_1();
}


void Scene_1()												//Main Bedroom
{
	system ("cls");
	char Opt;
    printf ("Você acorda em uma sala extremamente escura. ");
    printf ("O que você faz?\n");
    printf ("1)Investigar a cama\n");
    printf ("2)Investigar o armário\n");
    printf ("3)Olhar para o espelho\n");
    printf ("4)Investigar bidê\n");
    printf ("5)Gritar por ajuda\n");
    printf ("6)Ir em direção à janela\n");
    printf ("i)Inventory\n");
    printf ("s)Status\n");
    
    setbuf(stdin, "NULL");
    scanf ("%c", &Opt);
    
    if (Opt == 'i')
    	Inventory();
    	
    if (Opt == 's')
    	Status();
    
    switch (Opt)
    {
    	case 1:
    		
    		break;
	}
    system("PAUSE");
    Scene_1();
}




void WildOne()												//Enemy Searcher System
{
	int Count, Timer, Searcher;
	unsigned char Enemy;
	Enemy='A';
	Timer=1000;
	Sleep (100);
	for (Count=0;Count<Timer;Count++)
	{
		Searcher = RandomNumber(100);
		if (Searcher > 0 && Searcher < 3);
			//Combat();
	}
	WildOne();
}


int Status()												//Player Status
{
	system("cls");
	printf ("**Status**\n");
	
	printf ("%s, Level %d\n", Player.Name, Player.LVL);
	printf ("%d de XP para o nivel %d\n", (Player.XPM-Player.XP), (Player.LVL+1));
	if (Player.HP>((Player.HPM*8)/10))
		printf ("Saudável");
		
	if (Player.HP<=((Player.HPM*8)/10) && Player.HP>((Player.HPM*6)/10))
		printf ("Machucado");
		
	if (Player.HP<=((Player.HPM*6)/10) && Player.HP>((Player.HPM*4)/10))
		printf ("Ferido");
		
	if (Player.HP<=((Player.HPM*4)/10) && Player.HP>((Player.HPM*2)/10))
		printf ("Gravemente ferido");
		
	if (Player.HP<=((Player.HPM*2)/10) && Player.HP>0)
		printf ("Quase morto");
		
	printf ("\nAtaque: %d", Player.ATK);
	printf ("\nDefesa: %d", Player.DEF);
	printf ("\nVelocidade: %d", Player.SPD);
}


int Inventory()												//Player Inventory
{
	
}


int ItemsData(unsigned char ItemID)							//Game's Item Data Bank
{
	switch (ItemID)
	{
		case 0:

		break;
	}
}


enemy EnemyData()									//Game's Enemy Data Bank
{
	unsigned char EnemySelect;
	enemy Enemy;
	
	switch (EnemySelect)
	{
		case 1:             //Ghost
		    strcpy (Enemy.Name, "Ghost");
		    Enemy.XP = 2;
		    Enemy.HPM = 6;
            Enemy.HP = 6;
            Enemy.ATK = 3;
            Enemy.DEF = 2;
            Enemy.SPD = 3;
        break;
		case 2:             //Ghast
		    strcpy (Enemy.Name, "Ghast");
		    Enemy.XP = 3;
            Enemy.HPM = 6;
            Enemy.HP = 6;
            Enemy.ATK = 3;
            Enemy.DEF = 2;
            Enemy.SPD = 3;
        break;
	}
	
	//return Enemy;
}


void Combat(unsigned char EnemySelect, enemy A)	//Combat System
{
	system ("cls");
	unsigned char CombOpt, CombState;
	enemy Enemy1;
	CombState = 0;
	
	do
	{
		do
		{
			printf ("1.Fight\n2.Defend\n3.Items\n4.Run");
        	scanf (" %c", &CombOpt);
		} while (ValidChar(CombOpt, '1', '4') != 1);
		
		switch (CombOpt)
		{
			case 1:
				if (Player.SPD > Enemy1.SPD)
				{
					Enemy1.HP = Enemy1.HP - (Player.ATK + (Player.LVL*RandomNumber(3)) - Enemy1.DEF/2);
					if (Enemy1.HP <= 0)
					{
						CombState = 1;
						break;
					}
					Player.HP = Player.HP - (Enemy1.ATK+ - Player.DEF/2);
					if (Player.HP <= 0)
					{
						CombState = 2;
						break;
					}
				}
				if (Player.SPD < Enemy1.SPD)
				{
					Player.HP = Player.HP - (Enemy1.ATK - Player.DEF/2);
					if (Player.HP <= 0)
					{
						CombState = 2;
						break;
					}
					Enemy1.HP = Enemy1.HP - (Player.ATK + (Player.LVL*RandomNumber(3)) - Enemy1.DEF/2);
					if (Enemy1.HP <= 0)
					{
						CombState = 1;
						break;
					}
				}
            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;
		}
	}
	while (CombState=0);
	
	if (CombState==1)
	{
		printf ("You survived! You've earned %d XP!", Enemy1.XP);
	}
	
	if (CombState==2)
		PlayerDied(Enemy1.XP);
	system ("PAUSE");
}


void PlayerDied(unsigned char Reason)						//Player Death Screen
{
	char Decision;
	system ("cls");
	if (Reason == 1)
		printf ("Your souls has been harvested by GHOST...");
	if (Reason == 2)
		printf ("Your soul has been send to hell by GHAST...");
	printf ("You died! \n\n(Y.Continue N.Return to the main menu) ");
	scanf ("%d", &Decision);
	
	if (ValidChar(Decision, 'Y', 'N') == 1)
		printf("It will come soon...");
	if (ValidChar(Decision, 'Y', 'N') == 2)
		main();
	system ("PAUSE");
}




int ValidChar(char Input, char LowInp, char HighInp)	//Input Validation for Characters
{
	if ((Input>=LowInp) && (Input<=HighInp))
		return 1;
		
	if (((LowInp>='a') && (HighInp<='z')) || ((LowInp>='A') && (HighInp<='Z')) || ((LowInp>='0') && (LowInp<='9')))
	{
		if (((LowInp>='a') && (HighInp<='z')) && ((Input>=LowInp-32) && (Input<=HighInp-32)))
			return 1;
				
		if (((LowInp>='A') && (HighInp<='Z')) && ((Input>=LowInp+32) && (Input<=HighInp+32)))
			return 1;
				
		if (((LowInp>='0') && (LowInp<='9')) && ((Input>=LowInp) && (Input<=HighInp)))
			return 1;
			
		system("cls");
		printf ("Invalid value!\n");
		return (-1);
	}
	
	/*if ((LowInp>='a') && (HighInp<='z')) 
	{
		if (((Input>=LowInp) && (Input<=HighInp)) || ((Input>=LowInp-32) && (Input<=HighInp-32)))
			return (1);
		else
		{
			system("cls");
			printf ("Invalid value!\n");
			return (-1);
		}
	}
	
	if ((LowInp>='A') && (HighInp<='Z'))
	{
		if (((Input>=LowInp) && (Input<=HighInp)) || ((Input>=LowInp+32) && (Input<=HighInp+32)))
			return (1);
		else
		{
			system("cls");
			printf ("Invalid value!\n");
			return (-1);
		}
	}
	
	if ((LowInp>='0') && (LowInp<='9'))
	{
		if (((Input>=LowInp) && (Input<=HighInp)) || ((Input>=LowInp) && (Input<=HighInp)))
			return (1);
		else
		{
			system("cls");
			printf ("Invalid value!\n");
			return (-1);
		}
	}*/
}

int ValidUnsignedChar(unsigned char Input, unsigned char LowInp, unsigned char HighInp)	//Input Validation for Unsigned Chars
{
		if (((Input>=LowInp) && (Input<=HighInp)) || ((Input>=LowInp) && (Input<=HighInp)))
			return (1);
		else
		{
			system("cls");
			printf ("Invalid value!\n");
			return (-1);
		}
}

int ValidInt(int Input, int LowInp1, int HighInp1)	//Input Validation for Integers
{
		
}

unsigned char ValidBoolean(char Input)
{
	if ((Input == 'y' || Input == 'Y') || (Input == 'n' || Input == 'N'))
	{
		if (Input == 'y' || Input == 'Y')
			return 1;
		
		if (Input == 'n' || Input == 'N')
			return 0;
	}
	
	else
	{
		system("cls");
		printf ("Invalid value!\n");
		return -1;
	}
}


int RandomNumber(int Limite)								//Random Number Generator
{
    return rand()%Limite;
}


void GameExit()												//Game Exit Screen
{
	int YN;
	system ("cls");
	
	printf ("Você tem certeza? (Y para sair, N para voltar) ");
    setbuf(stdin, NULL);
    YN = getche();
    
    if (ValidBoolean(YN) == 1)
    {
    	switch (RandomNumber(8))
        {
        	case 0:
                printf ("\nSeu pescoço, trucidado em minha mãos, será algo tão marcante quanto sua vida: Insignificante...\n");
            break;
            
            case 1:
                printf ("\nÉ muito tarde para tentar escapar... \n");
            break;

            case 2:
                printf ("\nNos veremos novamente... \n");
            break;

            case 3:
                printf ("\nQuando menos esperar, estará morto... \n");
            break;

            case 4:
                printf ("\nO bode negro da floresta mandará seus filhos até sua tumba...\n");
            break;

            case 5:
                printf ("\nOs Deuses Antigos lhe vigiam durante seus pesadelos...\n");
            break;

            case 6:
                printf ("\nEscute os suspiros das trevas, ou seja queimado no fogo eterno...\n");
            break;

            case 7:
                printf ("\nVocê não precisa se explicar comigo. Já com ele...\n");
            break;
        }
        exit(0);
	}
}
