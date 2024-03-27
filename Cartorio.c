#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int continuar_registro() //função para continuar a cadastrar usuários
{	
	int op = 0; //declaração da variável que será retornada
	
	system("cls"); //limpa tela
	//menu de continuar cadastro
	printf("\t1 - Continuar cadastrando usuários\n"); 
	printf("\t2 - Voltar ao menu\n\n");
	printf("Opção: "); 
	scanf("%d", &op); //input da escolha do cliente
	
	return op; //returno da escolha
}

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int continuar = 0;
	//final criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a strings
		
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
		
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
		
	file = fopen(arquivo, "a"); //cria o arquivo e o "a" significa atualizar
	fprintf(file, ","); //salva uma vírugula para separar os dados do aluno
	fclose(file); //fecha o arquivo
		
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", nome); //%s refere-se a strings
		
	file = fopen(arquivo, "a"); //abre o aquivo 
	fprintf(file, nome); //salva o nome do aluno 
	fclose(file); //fecha o arquivo
		
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file, ","); //vírgula para separar os dados
	fclose(file); //fecha o arquivo
		
	printf("Digite o sobrenome a ser cadastrado: "); //coleta o sobrenome do aluno
	scanf("%s", sobrenome); //salva na variável sobrenome
		
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file, sobrenome); //salva no aquivo o sobrenome do aluno
	fclose(file); //fecha o arquivo
		
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file, ","); //salva uma vírugula para separar o nome do sobrenome do aluno
	fclose(file); //fecha o arquivo
		
	printf("Digite o cargo a ser cadastrado: "); //coleta o cargo do aluno
	scanf("%s", cargo); //guarda na variável cargo
		
	file = fopen(arquivo, "a"); //abre o arquivo dentro na variável file
	fprintf(file, cargo); //salva o valor da variável cargo no arquivo
	fclose(file); //fecha o arquivo
		
	printf("CPF cadatrado com sucesso!\n\n");
	
	system("pause"); //pausa o sistema
	
	continuar = continuar_registro(); //variável continuar recebe o retorno da função continuar registro
	
	switch (continuar) //condicional que decide o fluxo de código a partir da escolha do cliente
	{
		//opção 1: volta para a função de registro limpando a tela
		case 1:
			system("cls");
			registro(); 
			break;
		//volta para o menu
		case 2:
			return 0;
			break;
		//tratamento de exceção: caso o cliente digite um opção inválida
		default:
			printf("\nOpção inválida! Voltando ao menu...\n\n"); //considera voltar ao menu como opção
			system("pause");
			return 0;
			break;
	}
}

int consulta() //função para consultar 
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40]; //cria uma string com 40 espaços
	char conteudo[200]; //cria uma string com 200 espaços
	
	printf("Digite o CPF a ser consultado: "); //coleta o cpf do aluno
	scanf("%s", cpf); //guarda dentro da string cpf
	
	FILE *file; //abre a função de arquivos
	file = fopen(cpf, "r"); //abre o arquivo cpf no modo de leitura
	
	if(file == NULL) //validação para saber se o arquivo realmente exite
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //arquivo não encontrado
	} 
	
	while(fgets(conteudo, 200, file) != NULL) //lê todo o conteúdo do arquivo cpf que foi encontrado
	{
		char *t;
		
		printf("\nEssas são as informações do usuário: \n\n"); //título para apresentação dos dados do aluno
		//formatação em linhas das informações do usuário
		t = strtok(conteudo, ","); //busca na string conteúdo a primeira "," e print tudo o que foi lido antes	
		printf("CPF: %s\n", t); //printa essa informação
		
		t = strtok(NULL, ","); //busca a próxima "," da onde parou de ler
		printf("Nome: %s\n", t); //printa essa informação
		
		t = strtok(NULL, ","); //busca a próxima "," da onde parou de ler
		printf("Sobrenome: %s\n", t); //printa essa informação
		
		t= strtok(NULL, ","); //busca a próxima "," da onde parou de ler
		printf("Cargo: %s\n", t); //printa essa informação na tela
		
		printf("\n\n"); //duas linhas em branco
	}
	
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa no sistema
}

int deletar() //função de deletar um cadastro da base de dados
{
	char cpf[40]; //cria a string cpf com 40 espaços
	char resposta[] = "Sim";
	int remover = 0;
	
	printf("Digite o CPF do usuário a ser deletado: "); //coleta o cpf a ser deletado
	scanf("%s", cpf); //guarda o cpf na variável criada
	//pergunta se realmente deseja deletar aceitando somente "Sim" ou "Não" como resposta
	printf("Deseja realmente excluir este CPF do sistema? 'Sim' ou 'Não'? ");
	scanf("%s", resposta); //guarda a escolha do cliente
	
	if (strcmp(resposta, "Sim") != 0) //usa a função strcmp para comparar as strings e ver se retorna: 0 para Sim ou != 0 para Não
	{ //caso a resposta seja != 0 é igual a Não
		printf("\n\nA operação de cancelamento de usuário foi cancelada! \n"); //a operação é cancelada
		printf("Voltando ao menu... \n\n"); //mensagem de voltando ao menu
		system("pause"); //pausa o sistema
		return 0; //retorna 0 para acabar com a função
	}
	else //caso a resposta seja Sim (strcmp(resposta, "Sim" == 0))
	{	
		remover = remove(cpf); //joga o valor da função remove(cpf) para dentro da variável remover
		//se remover for igual a 0 = sucesso!
		//se remover for igual a NULL == o usuário não existe!
		if (remover == 0)
		{
			printf("Usuário deletado com sucesso do sistema! \n");
			system("pause");
		}
		else 
		{
			printf("Usuário não se encontra no sistema! \n");
			system("pause");
		}
	
		FILE *file; //abre a função de arquivos
		file = fopen(cpf, "r"); //abre o arquivo do cpf que pode ter sido deletado	
	}
}



int main()
{
	int opcao = 0; //definindo as variáveis
	int laco = 1;
	
	for (laco = 1; laco == 1;) 
	{
		system("cls"); //limpa a console
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Resgitrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: "); //fim do menu
		
		scanf("%d", &opcao); //armazenando as informações
		
		system("cls");
		
		switch (opcao) //inicio da seleção
		{
			case 1:
				registro(); //função para registrar
				break;
				
			case 2:
				consulta(); //função par cadastrar
				break;
				
			case 3:
				deletar(); //função para deletar
				break;
			
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
			default:
				printf("Essa opção não está disponível!\n"); 
				system("pause");
				break;
		} //fim da seleção
	}
}

