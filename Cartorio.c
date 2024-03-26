#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
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
	
	system("pause"); //pausa o sistema
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
		printf("\nEssas são as informações do usuário: "); //título para apresentação dos dados do aluno
		printf("%s", conteudo); //toda a variável conteúdo com as informações de cadastro do aluno
		printf("\n\n"); //duas linhas em branco
	}
	
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa no sistema
}

int deletar() //função de deletar um cadastro da base de dados
{
	char cpf[40]; //cria a string cpf com 40 espaços
	
	printf("Digite o CPF do usuário a ser deletado: "); //coleta o cpf a ser deletado
	scanf("%s", cpf); //guarda o cpf na variável criada
	
	remove(cpf); //remove o cpf da base de dados
		
	FILE *file; //abre a função de arquivos
	file = fopen(cpf, "r"); //abre o arquivo do cpf que pode ter sido deletado
	
	if (file == NULL) //se o cpf foi deletado
	{
		printf("O usuário foi deletado com sucesso do sistema!\n");
		system("pause");
	} 
	else //caso ele não exista 
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
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
		printf("\t3 - Deletar nomes\n\n"); 
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
			
			default:
				printf("Essa opção não está disponível!\n"); 
				system("pause");
				break;
		} //fim da seleção
	}
}

