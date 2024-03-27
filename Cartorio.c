#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int continuar_registro() //fun��o para continuar a cadastrar usu�rios
{	
	int op = 0; //declara��o da vari�vel que ser� retornada
	
	system("cls"); //limpa tela
	//menu de continuar cadastro
	printf("\t1 - Continuar cadastrando usu�rios\n"); 
	printf("\t2 - Voltar ao menu\n\n");
	printf("Op��o: "); 
	scanf("%d", &op); //input da escolha do cliente
	
	return op; //returno da escolha
}

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int continuar = 0;
	//final cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
		
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
		
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
		
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, ","); //salva uma v�rugula para separar os dados do aluno
	fclose(file); //fecha o arquivo
		
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", nome); //%s refere-se a strings
		
	file = fopen(arquivo, "a"); //abre o aquivo 
	fprintf(file, nome); //salva o nome do aluno 
	fclose(file); //fecha o arquivo
		
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file, ","); //v�rgula para separar os dados
	fclose(file); //fecha o arquivo
		
	printf("Digite o sobrenome a ser cadastrado: "); //coleta o sobrenome do aluno
	scanf("%s", sobrenome); //salva na vari�vel sobrenome
		
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file, sobrenome); //salva no aquivo o sobrenome do aluno
	fclose(file); //fecha o arquivo
		
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file, ","); //salva uma v�rugula para separar o nome do sobrenome do aluno
	fclose(file); //fecha o arquivo
		
	printf("Digite o cargo a ser cadastrado: "); //coleta o cargo do aluno
	scanf("%s", cargo); //guarda na vari�vel cargo
		
	file = fopen(arquivo, "a"); //abre o arquivo dentro na vari�vel file
	fprintf(file, cargo); //salva o valor da vari�vel cargo no arquivo
	fclose(file); //fecha o arquivo
		
	printf("CPF cadatrado com sucesso!\n\n");
	
	system("pause"); //pausa o sistema
	
	continuar = continuar_registro(); //vari�vel continuar recebe o retorno da fun��o continuar registro
	
	switch (continuar) //condicional que decide o fluxo de c�digo a partir da escolha do cliente
	{
		//op��o 1: volta para a fun��o de registro limpando a tela
		case 1:
			system("cls");
			registro(); 
			break;
		//volta para o menu
		case 2:
			return 0;
			break;
		//tratamento de exce��o: caso o cliente digite um op��o inv�lida
		default:
			printf("\nOp��o inv�lida! Voltando ao menu...\n\n"); //considera voltar ao menu como op��o
			system("pause");
			return 0;
			break;
	}
}

int consulta() //fun��o para consultar 
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40]; //cria uma string com 40 espa�os
	char conteudo[200]; //cria uma string com 200 espa�os
	
	printf("Digite o CPF a ser consultado: "); //coleta o cpf do aluno
	scanf("%s", cpf); //guarda dentro da string cpf
	
	FILE *file; //abre a fun��o de arquivos
	file = fopen(cpf, "r"); //abre o arquivo cpf no modo de leitura
	
	if(file == NULL) //valida��o para saber se o arquivo realmente exite
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //arquivo n�o encontrado
	} 
	
	while(fgets(conteudo, 200, file) != NULL) //l� todo o conte�do do arquivo cpf que foi encontrado
	{
		char *t;
		
		printf("\nEssas s�o as informa��es do usu�rio: \n\n"); //t�tulo para apresenta��o dos dados do aluno
		//formata��o em linhas das informa��es do usu�rio
		t = strtok(conteudo, ","); //busca na string conte�do a primeira "," e print tudo o que foi lido antes	
		printf("CPF: %s\n", t); //printa essa informa��o
		
		t = strtok(NULL, ","); //busca a pr�xima "," da onde parou de ler
		printf("Nome: %s\n", t); //printa essa informa��o
		
		t = strtok(NULL, ","); //busca a pr�xima "," da onde parou de ler
		printf("Sobrenome: %s\n", t); //printa essa informa��o
		
		t= strtok(NULL, ","); //busca a pr�xima "," da onde parou de ler
		printf("Cargo: %s\n", t); //printa essa informa��o na tela
		
		printf("\n\n"); //duas linhas em branco
	}
	
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa no sistema
}

int deletar() //fun��o de deletar um cadastro da base de dados
{
	char cpf[40]; //cria a string cpf com 40 espa�os
	char resposta[] = "Sim";
	int remover = 0;
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coleta o cpf a ser deletado
	scanf("%s", cpf); //guarda o cpf na vari�vel criada
	//pergunta se realmente deseja deletar aceitando somente "Sim" ou "N�o" como resposta
	printf("Deseja realmente excluir este CPF do sistema? 'Sim' ou 'N�o'? ");
	scanf("%s", resposta); //guarda a escolha do cliente
	
	if (strcmp(resposta, "Sim") != 0) //usa a fun��o strcmp para comparar as strings e ver se retorna: 0 para Sim ou != 0 para N�o
	{ //caso a resposta seja != 0 � igual a N�o
		printf("\n\nA opera��o de cancelamento de usu�rio foi cancelada! \n"); //a opera��o � cancelada
		printf("Voltando ao menu... \n\n"); //mensagem de voltando ao menu
		system("pause"); //pausa o sistema
		return 0; //retorna 0 para acabar com a fun��o
	}
	else //caso a resposta seja Sim (strcmp(resposta, "Sim" == 0))
	{	
		remover = remove(cpf); //joga o valor da fun��o remove(cpf) para dentro da vari�vel remover
		//se remover for igual a 0 = sucesso!
		//se remover for igual a NULL == o usu�rio n�o existe!
		if (remover == 0)
		{
			printf("Usu�rio deletado com sucesso do sistema! \n");
			system("pause");
		}
		else 
		{
			printf("Usu�rio n�o se encontra no sistema! \n");
			system("pause");
		}
	
		FILE *file; //abre a fun��o de arquivos
		file = fopen(cpf, "r"); //abre o arquivo do cpf que pode ter sido deletado	
	}
}



int main()
{
	int opcao = 0; //definindo as vari�veis
	int laco = 1;
	
	for (laco = 1; laco == 1;) 
	{
		system("cls"); //limpa a console
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Resgitrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: "); //fim do menu
		
		scanf("%d", &opcao); //armazenando as informa��es
		
		system("cls");
		
		switch (opcao) //inicio da sele��o
		{
			case 1:
				registro(); //fun��o para registrar
				break;
				
			case 2:
				consulta(); //fun��o par cadastrar
				break;
				
			case 3:
				deletar(); //fun��o para deletar
				break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
			default:
				printf("Essa op��o n�o est� dispon�vel!\n"); 
				system("pause");
				break;
		} //fim da sele��o
	}
}

