#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "meioMobilidade.h"

//Criar o meio de mobilidade
meioMobilidade *criarMeio(){
	char cod[5], tipo[20];
	float custo;
	int autonomia;
	
	printf("Qual o codigo do meio: ");
	scanf("%s", &cod);
	
	printf("Qual o tipo do meio: ");
	scanf("%s", &tipo);
	
	printf("Custo por hora do meio: ");
	scanf("%f", &custo);
	
	printf("Autonomia do meio: ");
	scanf("%d", &autonomia);	
	
	//Alocar espaço na memória exato do tamanho de um meio de mobildiade e retornar para uma variavel que é um pointer para usar
	meioMobilidade *elemento = (meioMobilidade *)malloc(sizeof(meioMobilidade));
	
	strcpy(elemento->codigo, cod);
	strcpy(elemento->tipo, tipo);
	elemento->custo = custo;
	elemento->autonomia = autonomia;
	
	return elemento;
}

//função para adicionar o meio criado ao ficheiro e á array, acabar
//e ver o ponteiro para o ficheiro e falta adicionar a uma array
void adicionarMeio(meioMobilidade *meiosMobilidade, int *index){
	meioMobilidade *meio = criarMeio();
	
	meiosMobilidade[*index].custo = meio->custo;
	meiosMobilidade[*index].autonomia = meio->autonomia;
	strcpy(meiosMobilidade[*index].tipo, meio->tipo);
	strcpy(meiosMobilidade[*index].codigo, meio->codigo);
	
	(*index)++;
}

//Adicionar a array de meios ao ficheiro 
void adicionarMeioAoFicheiro(meioMobilidade *meiosMobilidade, int index){
	FILE *fp;
	fp = fopen("files/meioMobilidade.csv", "w");
	
	printf("\nPonteiro para o ficheiro %d\n", fp);
	
	if(!fp){
		printf("Ocorreu um erro!");
		return;
	}
	
	//fputs("\n%s, %s, %f, %d", meio->codigo, meio->tipo, meio->custo, meio->autonomia, fp);->Voltar a ver como fazer
	
	if(fwrite == 0){
		printf("\nEscrito\n");
	}else{
		printf("\nNão foi escrito\n");
	}
}

//Função para ler ficheiro e carregar num array
meioMobilidade *lerFicheiroMeioMobilidade(int *indexMeios){
	FILE *fp;
	fp = fopen("files/meioMobilidade.csv", "rb");
	int i = 0;
	char buff[1024];
	int contagemLinhas = 0, numLinhas = 0;
	int contagemCampo = 0;
	meioMobilidade meio[100];
	
		
	printf("\nPonteiro para o ficheiro %d\n", fp);
	
	if(!fp){
		printf("Ocorreu um erro!");
		return;
	}

	while(fgets(buff, 1024, fp)){
		contagemCampo = 0;
		contagemLinhas++;
			
		char *campo = strtok(buff, ",");
		while(campo){
			if(contagemCampo == 0)
				strcpy(meio[i].codigo, campo);
			if(contagemCampo == 1)
				strcpy(meio[i].tipo, campo);
			if(contagemCampo == 2)
				meio[i].custo = (float)*campo;
			if(contagemCampo == 3)
				meio[i].autonomia = (int)*campo;
				
			campo = strtok(NULL, ",");
			contagemCampo++;
		}
		i++;
		numLinhas++;
	}
	
	*indexMeios = numLinhas;
	meioMobilidade *meios;
	meios = malloc(sizeof(meioMobilidade) * numLinhas);
	
	for(i = 0; i < numLinhas; i++){
		strcpy(meios[i].codigo, meio[i].codigo);
		strcpy(meios[i].tipo, meio[i].tipo);
		meios[i].custo = meio[i].custo;
		meios[i].autonomia = meio[i].autonomia;
	}
	
	fclose(fp);
	
	return meios;
}

//Função para remover um meio do array
void removerAparirDeCodigo(meioMobilidade *meios, int indexMeios){
	int i, j;
	char codigoProcurar[4];
	
	fflush(stdin);//Limpar o stdin, buffer do teclado
	
	printf("Qual o código do meio a procurar: ");//Pedir o código a procurar
	scanf("%s", &codigoProcurar);
	
	if(indexMeios == 0){//Se não tem meios de mobilidade
		printf("\nNão existem meios na lista.\n");
	}else{//Se houver, tentar procurar
		for(i = 0; i < indexMeios;i++){//Percorrer todos os elementos da array
			if(strcmp(meios[i].codigo, codigoProcurar)){//Se encontrar o mesmo código, retirar esse veiculo, mas fazer um novo array como os carros que vai precisar
				printf("Elemento a retirar:\n");
				printf("\nCódigo: %s, tipo: %s, custo: %f, autonomia: %d", meios[i].codigo, meios[i].tipo, meios[i].custo, meios[i].autonomia);
				
			}
		}
	}
	
	
}

//Listar todos os meios da array
void listarTodosOsmeios(meioMobilidade *meios, int numMeios){
	int i;
	printf("Meios Mobilidade:\n");
	if(numMeios == 0){
		printf("Nenhum carro na lista. Tente usar a opção 2 para carregar do ficheiro.\n");
	}else{
		for(i = 0;i < numMeios; i++){
			printf("Meio[%d]:\n", (i+1));
			printf("Código %s, tipo: %s, custo: %f, autonomia: %d", meios[i].codigo, meios[i].tipo, meios[i].custo, meios[i].autonomia);
		}
	}

	printf("\n");
}
