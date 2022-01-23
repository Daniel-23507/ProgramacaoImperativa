#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "meioMobilidade.h"

meioMobilidade *criarMeio(){
	char cod[5], tipo[20];
	float custo;
	int autonomia;
	
	printf("Qual o codigo do meio: ");
	scanf("%s", &cod);
	
	printf("Qual o tipo do meio: ");
	gets(tipo);
	
	printf("Custo por hora do meio: ");
	scanf("%f", &custo);
	
	printf("Autonomia do meio: ");
	scanf("%d", &autonomia);	
	
	//Alocar espa�o na mem�ria exato do tamanho de um meio de mobildiade e retornar para uma variavel que � um pointer para usar
	meioMobilidade *elemento = (meioMobilidade *)malloc(sizeof(meioMobilidade));
	
	strcpy(elemento->codigo, cod);
	strcpy(elemento->tipo, tipo);
	elemento->custo = custo;
	elemento->autonomia = autonomia;
	
	return elemento;
}

//fun��o para adicionar o meio criado ao ficheiro e � array, acabar
//e ver o ponteiro para o ficheiro e falta adicionar a uma array
void adicionarMeio(){
	meioMobilidade *meio = criarMeio();
	FILE *fp;
	fp = fopen("meioMobilidade.csv", "w");
	
	printf("\nPonteiro para o ficheiro %d\n", fp);
	
	if(!fp){
		printf("Ocorreu um erro!");
		return;
	}
	
	fprintf(fp, "%s, %s, %f, %d", meio->codigo, meio->tipo, meio->custo, meio->autonomia);
	
	fclose(fp);
}

void lerFicheiroMeioMobilidade(){
	FILE *fp;
	fp = fopen("meioMobilidade.csv", "r");
	int i = 0;
	char buff[1024];
	int contagemLinhas = 0;
	int contagemCampo = 0;
		
	printf("\nPonteiro para o ficheiro %d\n", fp);
	
	if(!fp){
		printf("Ocorreu um erro!");
		return;
	}
		
	meioMobilidade Values[5];
				
	while(fgets(buff, 1024, fp)){
		contagemCampo = 0;
		contagemLinhas++;
		if(contagemLinhas == 1)
			continue;
			
		char *campo = strtok(buff, ",");
		while(campo){
			if(contagemCampo == 0)
				strcpy(Values[i].codigo, campo);
			if(contagemCampo == 1)
				strcpy(Values[i].tipo, campo);
			if(contagemCampo == 2)
				Values[i].custo = (float)*campo;
			if(contagemCampo == 3)
				Values[i].autonomia = (int)*campo;
				
			campo = strtok(NULL, ",");
			contagemCampo++;
		}
		i++;
	}
	
	for(i = 0; i < 5; i++){
		
		printf("codigo: %s, tipo %s, custo: %.2f, autonomia; %d\n", Values[i].codigo, Values[i].tipo, Values[i].custo, Values[i].autonomia);
	}
	
	fclose(fp);
}
