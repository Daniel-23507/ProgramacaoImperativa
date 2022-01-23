//#include <iostream>
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "structs/meioMobilidade.c"
#include "structs/utilizador.c"

int menu();

int main(int argc, char** argv) {
	int opcao;
	int indexMeios = 0;
	int i;
	meioMobilidade *meios;
	

    
	do{
	    opcao = menu();
	    switch (opcao){
	        case 1:
	        	system("cls");
	            break;
	        case 2:
	        	system("cls");
				meios = lerFicheiroMeioMobilidade(&indexMeios);
				for(i = 0; i < indexMeios; i++){
					printf("\n111codigo: %s, tipo: %s, custo: %f, autonomia: %d", meios[i].codigo, meios[i].tipo, meios[i].custo, meios[i].autonomia);
				}
				printf("\nindexMeios: %d\n", indexMeios);
	            break;
	        case 3: 
	        	system("cls");
	        	adicionarMeio(meios, &indexMeios);
	        	printf("\nindexMeios: %d\n", indexMeios);
	            break;
	        case 4: 
	        	system("cls");
	        	removerAparirDeCodigo(meios, indexMeios);
	            break;
	        case 5: 
	        	system("cls");
	            break;
	        case 6: 
	        	system("cls");
	            break;
	        case 7: 
	        	system("cls");
	        	listarTodosOsmeios(meios, indexMeios);
	            break;
	        case 8: 
	        	system("cls");
	            break;
	        case 9: 
	        	system("cls");
	            break;
	        case 10: 
	        	system("cls");
	            break;
	        case 11: 
	        	system("cls");
	            break;
	        case 12: 
	        	system("cls");
	            break;
	        case 13: 
	        	system("cls");
	        	adicionarMeioAoFicheiro(meios, indexMeios);
	            break;
	    }
 }
 while (opcao != 0);
 return(0);
}

int menu(){
    int opcao;
	
	do{
		printf("MENU: \n");
	    printf("1 - Ler ficheiro com pedidos de utilizacao: \n");
	    printf("2 - Ler ficheiro tipo 2: \n");
	    printf("3 - Adicionar novo veiculo eletrico: \n");
	    printf("4 - Remover veiculo : \n");
	    printf("5 - Inserir novo pedido de utilizacao : \n");
	    printf("6 - Remover pedido de utilizacao : \n");
	    printf("7 - Listar dados dos veiculos : \n");
	    printf("8 - Listar pedidos de utilizacao : \n");
	    printf("9 - Calcular custo com numero de ordem: \n");
	    printf("10 - Distribuir veiculos : \n");
	    printf("11 - Listar plano de utilizacao de um veiculo a partir do codigo : \n");
	    printf("12 - Guardar pedidos de utilizacao em ficheiro : \n");
	    printf("13 - Guardar veiculos em ficheiro : \n");
	    printf("0 - Sair\n");
	    printf("Opcao: ");
	    scanf("%d",&opcao);
    } while ((opcao>8)||(opcao<0));
    return(opcao);
}
