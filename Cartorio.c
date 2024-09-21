#include <stdio.h>  //biblioteca de comunicação com o usuario
#include <stdlib.h>  //biblioteca de alocação de espaço em memória
#include <locale.h>  //biblioteca de alocações de texto por região
#include <string.h>  // biblioteca responsável por cuidar das strings


int registro() // Função para cadastrar os usuários
	{
		
		setlocale(LC_ALL, "Portuguese");
		
		
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
	
		
		printf("Digite o CPF a ser cadastrado: ");
		scanf("%s", cpf);	// %s refere-se  ler a strings
		
		strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
		
		FILE *file;  // cria o arquivo no banco de dados
		file = fopen(arquivo, "w"); // "w" cria um novo arquivo / escreve um novo arquivo
		fprintf(file,cpf); // salvo o valor da variável
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


int consulta()  // Função para consultar os usuários e seus dados
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
		
		printf("Não foi possível localizar o CPF!\n");
		
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas são as informações do usuário: ");
			printf("%s", conteudo);  // %s para ler a string 
			printf("%s", nome);  // %s para ler a string 
			printf("\n\n");
		}
		
		system("pause");
		
	}

int deletar() // Função responsável por deletar os usuários e seus dados.
	{
		setlocale(LC_ALL, "Portuguese");
		
		
		char cpf[40];
		
		printf("Informe o CPF do usuário que deseja deletar");
		scanf("%s", cpf); // %s para ler a string 
			
			
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf, "r");	 // "r" de READ significa LER o arquivo informado
			
			
		if (file == NULL)  //"Se o arquivo for igual a nulo"
		{
			printf("O Usuário não se encontra no sistema!\n");
			system("pause");
		}	
		
		else  // "Se não, informe que o CPF foi deletado"
		{
			printf("CPF deletado!\n");
		  
		} 
		
		
		system("pause");
	
		
	}


int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1; laco==1;)
	{
		
		system("cls"); // responsável por limpar a tela
		
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
		
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");//fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usuário
		
		system("cls");  // responsável por limpar a tela
		
		switch(opcao)  //inicio da seleção do menu
		{
			case 1:
				registro();  // chamada da função registro
				break;
				
			case 2:
				consulta(); // chamada da função consulta
				break;
			
			case 3:
				deletar();  // chamada da função deletar
				break;
				
			default:  // Caso o usuário digite algum comando inexistente mostre a mensagem printf
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;
		} //fim da seleção do menu
			
			
	}
	
	
}











