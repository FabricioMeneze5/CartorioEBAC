#include <stdio.h>	//biblioteca de comunicacao como o usuario
#include <stdlib.h> //biblioteca de alocacao de memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel pela string

int registrar() //inicio da funcao para cadastrar usuarios
{
	setlocale(LC_ALL, "Portuguese_Brazil.1252");//alocacao de idioma
	
//criacao de strings,variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char curso[40];
//final da criacao de strings

	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);//salvar string CPF

	strcpy(arquivo, cpf); // responsavel por copiar os valores do cpf para o arquivo
	FILE *file;			  // cria o arquivo no banco de dados

	file = fopen(arquivo, "w"); // salva o arquivo na pasta com o nome "arquivo" que o n do cpf
	fprintf(file, "\n\nCPF: ");
	fprintf(file, cpf); // salva o valor da variavel
	fclose(file);		// fecha o arquivo

	file = fopen(arquivo, "a");
	fprintf(file, "\nNome: ");
	fclose(file);

	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);//salvar string nome

	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, "\nSobrenome: ");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);//salvar string sobrenome

	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, "\nCurso: ");
	fclose(file);

	printf("Digite o curso a ser cadastrado: ");
	scanf("%s", curso);//salvar string curso

	file = fopen(arquivo, "a");
	fprintf(file, curso);
	fclose(file);
	
	file = fopen(arquivo, "a");//organizacao visuao do arquivo
	fprintf(file, "\n");
	fclose(file);

	system("pause");
}//fim da funcao de cadastro

int consultar()//inicio da funcao para consultar cpf cadastrado
{
	setlocale(LC_ALL, "Portuguese_Brazil.1252");//alocacao de idioma
//ciacao das variaveis
	char cpf[40];
	char conteudo[200];
//fim da criacao das variaveis

	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);//salva o cpf a ser cunsultado

	FILE *file;//abrir arquivo a ser lido
	file = fopen(cpf, "r"); //"r" para ler o arquivo(read)

	if (file == NULL)//caso cpf NAO seja encontrado
	{
		printf("\nCPF não localizado!\n");
		
	}
	
	else{//caso cpf seja encontrado
	printf("\nEssas são as informações do usuário: ");
	}
	

	while (fgets(conteudo, 200, file) != NULL)//informacoes do arquivo (cpf)
	{
		printf("%s", conteudo);
	}
	printf("\n");
	fclose(file);

	system("pause");
}//fim da funcao de consulta

int deletar()//inicio da funcao para deletar cpf cadastrado
{
	char cpf[40];//criacao de string

	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);//salva numero para ser apagado
	
	printf("\n");//organizacao visual do arquivo
	
	FILE *file;	//abertuda de arquivo
	file = fopen(cpf, "r");//leitura
	
	if (file == NULL)//caso cpf NAO seja encontrado
	{
		printf("CPF não localizado!\n\n");
		system("pause");
	}
	
	else //mensagem de confirmacao que cpf foi apagado
	{
	printf("CPF deletado com sucesso!\n\n");
	system("pause");
	}
	fclose(file);

	remove(cpf);//responsavel por apagar cpf
}//fim da funcao para remover cpf cadastrado

int main()
{
	int opcao = 0; // Definindo variáveis.
	int izanami = 1;

	for (izanami = 1; izanami = 1;)
	{
		system("cls"); // cls comando de limpar a tela.

		setlocale(LC_ALL, "Portuguese_Brazil.1252"); // Definindo a Linguagem.

		printf("### Cartório da EBAC ###\n\n"); // Inicio do menu.
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); // Fim do menu

		scanf("%d", &opcao); // Armazenamento da escolha do usuario.

		system("cls");

		switch (opcao)
		{ // inicio da selecao.
		case 1:
			registrar();
			break;

		case 2:
			consultar();
			break;

		case 3:
			deletar();
			break;

		default:
			printf("Essa opção não está disponível\n");//caso numero nao for encontrado
			system("pause");
			break;
		} // fim da seleção.
	}
}//fim do programa
