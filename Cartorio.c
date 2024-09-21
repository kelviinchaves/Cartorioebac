#include <stdio.h>  //biblioteca de comunica��o com o usuario
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>  //biblioteca de aloca��es de texto por regi�o
#include <string.h>  // biblioteca respons�vel por cuidar das strings


int registro() // Fun��o para cadastrar os usu�rios
	{
		
		setlocale(LC_ALL, "Portuguese");
		
		
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
	
		
		printf("Digite o CPF a ser cadastrado: ");
		scanf("%s", cpf);	// %s refere-se  ler a strings
		
		strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
		
		FILE *file;  // cria o arquivo no banco de dados
		file = fopen(arquivo, "w"); // "w" cria um novo arquivo / escreve um novo arquivo
		fprintf(file,cpf); // salvo o valor da vari�vel
		fclose(file); // fecho o arquivo
		
		file = fopen(arquivo, "a"); // abrir arquivo e em seguida "a" Significa Atualizar o arquivo 
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s", nome); // %s para ler a string 
		
		file = fopen(arquivo, "a"); // abrir arquivo e em seguida "a" Significa Atualizar o arquivo 
		fprintf(file, nome);
		fclose(file);
		
		file = fopen(arquivo, "a"); // abrir arquivo e em seguida "a" Significa Atualizar o arquivo  
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o sobrenome: ");
		scanf("%s", sobrenome);  // %s para ler a string 
		
		file = fopen(arquivo, "a"); // abrir arquivo e em seguida "a" Significa Atualizar o arquivo  
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a"); // abrir arquivo e em seguida "a" Significa Atualizar o arquivo 
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s", cargo); // %s para ler a string  
		
		file = fopen(arquivo, "a"); // abrir arquivo e em seguida "a" Significa Atualizar o arquivo 
		fprintf(file,cargo);
		fclose(file);
		
		system("pause");
		
			
		
	}


int consulta()  // Fun��o para consultar os usu�rios e seus dados
	{
		setlocale(LC_ALL, "Portuguese"); //denindo a linguagem
		
		char cpf[40];
		char conteudo[200];
		char nome[50];
		
		printf("Digite o CPF a ser consultado");
		scanf("%s",cpf); // %s para ler a string 
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
		
		printf("N�o foi poss�vel localizar o CPF!\n");
		
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo);  // %s para ler a string 
			printf("%s", nome);  // %s para ler a string 
			printf("\n\n");
		}
		
		system("pause");
		
	}

int deletar() // Fun��o respons�vel por deletar os usu�rios e seus dados.
	{
		setlocale(LC_ALL, "Portuguese");
		
		
		char cpf[40];
		
		printf("Informe o CPF do usu�rio que deseja deletar");
		scanf("%s", cpf); // %s para ler a string 
			
			
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf, "r");	 // "r" de READ significa LER o arquivo informado
			
			
		if (file == NULL)  //"Se o arquivo for igual a nulo"
		{
			printf("O Usu�rio n�o se encontra no sistema!\n");
			system("pause");
		}	
		
		else  // "Se n�o, informe que o CPF foi deletado"
		{
			printf("CPF deletado!\n");
		  
		} 
		
		
		system("pause");
	
		
	}


int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1; laco==1;)
	{
		
		system("cls"); // respons�vel por limpar a tela
		
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: ");//fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
		system("cls");  // respons�vel por limpar a tela
		
		switch(opcao)  //inicio da sele��o do menu
		{
			case 1:
				registro();  // chamada da fun��o registro
				break;
				
			case 2:
				consulta(); // chamada da fun��o consulta
				break;
			
			case 3:
				deletar();  // chamada da fun��o deletar
				break;
				
			default:  // Caso o usu�rio digite algum comando inexistente mostre a mensagem printf
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
		} //fim da sele��o do menu
			
			
	}
	
	
}











