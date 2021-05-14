#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char nombre[50];
	int pos;
} jugador;

typedef struct{
	char pregunta[256];
	char op[4][256];
	int resp;
} quizz;

typedef struct {
	int num_op;
	int num_preg;	
	int gameOver; //como bandera
	int turno;
	int itPreg;
	int categoria;
	int numJugadores;
}tablero;

int main(int argc, char const *argv[]){

	FILE *fp;
	tablero maraton;
	quizz preguntas[200];
	jugador players[4];

	int dado;
	int respJugador;

	maraton.num_op = 3;
	maraton.num_preg = 8;
	maraton.gameOver=0;
	maraton.turno=0;
	maraton.itPreg=0;
	
	printf("***************Bienvendo al maraton******************\n");
	printf("Seleccione una categoria\n");
	printf("  1) Musica\n");
	printf("  2) Historia\n");
	printf("  3) matematicas\n");
	printf("op: ");
	scanf("%d",&maraton.categoria);

	if (maraton.categoria == 1){
		printf("Veamos que tan bueno eres en la musica \n");
		fp = fopen("musica.txt", "r"); // read mode
	}
	if (maraton.categoria == 2){
		printf("Veamos que tan bueno eres en historia \n");
		fp = fopen("historia.txt", "r"); // read mode
	}
	if (maraton.categoria == 3){
		printf("Veamos que tan bueno eres en el deporte\n");
		fp = fopen("matematicas.txt", "r"); // read mode
	}
	
	if (fp == NULL){
	   perror("Error while opening the file.\n");
	   exit(EXIT_FAILURE);
	}

	printf("Cargando preguntas... espere por favor...\n");
	int ptr=0;
	while (!feof(fp)){
		fscanf(fp,"%[^\n]s",preguntas[ptr].pregunta); //leer la pregunta
		fgetc(fp);
		for (int i = 0; i < maraton.num_op; ++i){
			fscanf(fp,"%[^\n]s",preguntas[ptr].op[i]); // le opcion 1,2,3
			fgetc(fp);
		}
		fscanf(fp,"%d",&preguntas[ptr].resp); // resp correcta
		fgetc(fp);
		ptr++;
	}
	fclose(fp);

	for (int j = 0; j < ptr; ++j){
		printf("Q: %s\n", preguntas[j].pregunta);
		for (int i = 0; i < maraton.num_op; ++i)
			printf("R[%d]: %s\n",i,preguntas[j].op[i]);
		printf("Res: %d\n", preguntas[j].resp);
	}

	printf("Ingresa el numero de jugadores (máx 4): ");
	scanf("%d",&maraton.numJugadores);

	printf("Ingrese el nombre los jugadores \n");
	for (int i = 0; i < maraton.numJugadores; ++i)	{
		printf("\tJugador [%d]: ", i+1);
		scanf("%s", players[i].nombre);
		players[i].pos=0;
	}

	//El juego
	do{
		printf("\n\t*****TURNO DE %s *********\n",players[maraton.turno].nombre);
		printf("\tLa posicion actual del jugador es: %d\n",players[maraton.turno].pos);
		
		printf("\t¿Cuanto cayó tu dado? ");
		scanf("%d",&dado);

		//Se le hace una pregunta
		printf("\n\t%s\n",preguntas[maraton.itPreg].pregunta);
		for (int i = 0; i < 4; ++i)
			printf("\t\t%s\n",preguntas[maraton.itPreg].op[i]);		

		printf("\tSu respuesta: ");
		scanf("%d",&respJugador);

		//Si esta bien pos aumenta
		if (respJugador-1 == preguntas[maraton.itPreg].resp){ 
			players[maraton.turno].pos += dado;
			printf("\t--->La nueva posicion de %s es: %d\n",players[maraton.turno].nombre,players[maraton.turno].pos);
		}else
			printf("El jugador no avanzo :(\n");
		
		//Logica para ver cuando se gana
		if (players[maraton.turno].pos<50){
			maraton.itPreg++;
			maraton.turno++;
		}else {maraton.gameOver=1;}

		if ( maraton.turno == maraton.numJugadores){maraton.turno=0;}	

	}while(maraton.gameOver!=1);

	printf("El ganador es el jugador %s\n", players[maraton.turno].nombre);
	return 0;
}

/*
	FILE PROTOTYPE

		Responde: 2+1=?
		1) 1 
		2) 3
		3) 2
		1
		Responde: 2+2=?
		1) 0
		2) 3
		3) 4
		2
		Responde: 2*9=?
		1) 0
		2) 18
		3) 9
		2
		Responde: -2*9=?
		1) -18
		2) 18
		3) 9
		1
		Responde: -2*-2+1=?
		1) 8
		2) 18
		3) 5
		3
		Responde: -2*2+1=?
		1) 1
		2) -3
		3) 5
		2
*/