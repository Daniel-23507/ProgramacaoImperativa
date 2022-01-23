//#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#include "structs/meioMobilidade.c"
#include "structs/utilizador.c"
int main();
int menu();

int main(int argc, char** argv) {
	int opcao;
	

    
	do{
	    opcao = menu();
	    switch (opcao){
	        case 1:
	            break;
	        case 2:
				lerFicheiroMeioMobilidade();
	            break;
	        case 3: 
	        	adicionarMeio();
	            break;
	        case 4: 
	            break;
	        case 5: 
	            break;
	        case 6: 
	            break;
	        case 7: 
	            break;
	        case 8: 
	            break;
	        case 9: 
	            break;
	        case 10: 
	            break;
	        case 11: 
	            break;
	        case 12: 
	            break;
	        case 13: 
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
