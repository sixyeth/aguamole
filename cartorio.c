#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar da string

int registro() //função responsável por cadastrar usuario no sistema
{
    //inicio criação de variáveis/string
	char arquivo[40]; //armazenando o nome do arquivo a ser criado
	char cpf[40]; //armazenando o CPF do usuário
    char nome[40]; //armazenando o nome do usuário
    char sobrenome[40]; //armazenando o sobrenome do usuário
    char cargo[40]; //armazenando o cargo do usuário
    //final da criação de variáveis
    
    printf("Digite o CPF a ser cadastrado: "); //escrevendo na tela
    scanf("%s", cpf); //salvando o cpf cadastrado
    
    strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
    
    FILE *file; //procura na bibliopteca e cria o arquivo
    file = fopen(arquivo,"w"); //cria o arquivo, escrevendo com o "w"
    fprintf(file,cpf); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a"); //adiciona uma virgula pra melhor visualização
    fprintf(file,", "); //adição da virgula
    fclose(file); //fechando a pasta
    
    printf("Digite o nome a ser cadastrado: "); //escrevendo na tela
    scanf("%s",nome); //armazena o nome digitado
    
    file = fopen(arquivo,"a"); //escrevendo o nome no arquivo
    fprintf(file,nome); //salvando o nome no arquivo
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a"); //colocando virgula pra melhor visualização
    fprintf(file,", "); //adição da virgula
    fclose(file); //fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); //escrevendo na tela
    scanf("%s",sobrenome); //armazena o sobrenome digitado
    
    file = fopen(arquivo,"a"); //escrevendo o sobrenome no arquivo
    fprintf(file,sobrenome); //salvando o sobrenome no arquivo
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a"); //adiciona uma virgula pra melhor visualização
    fprintf(file,", "); //adição da virgula
    fclose(file); //fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: "); //escrevendo na tela
    scanf("%s",cargo);
    
    file = fopen(arquivo,"a"); //escrevendo o cargo no arquivo
    fprintf(file,cargo); //salva o cargo no arquivo
    fclose(file); //fecha o arquivo
    
    system("pause"); //pausando a tela pra ler
}

int consulta()
{
    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
    
	char cpf[40]; //armazena o CPF a ser consultado
    char conteudo[200]; //armazena o conteudo do arquivo
    
    printf("Digite o CPF a ser consultado: "); //escrevendo na tela, solicitando o CPF
    scanf("%s",cpf); //armazena o CPF digitado
    
    FILE *file; //ponteiro para o arquivo
    file = fopen(cpf,"r"); //abre o arquivo em modo leitura
    
    if(file == NULL) //verifica se o arquivo nao foi encontrado
    {
    	printf("Não foi posível localicar o arquivo!\n");
	}
    
    while(fgets(conteudo, 200, file) != NULL) //procura o conteudo do arquivo linha por linha
    {
    	printf("\nEssas são as informações do Usuário: ");
    	printf("%s", conteudo); //imprime o conteudo do arquivo
    	printf("\n\n");
	}
	
	fclose(file); //fechando o arquivo
	system("pause"); //pausando a tela pra ler
}

int deletar()
{
	char cpf[40]; //armazena o cpf a ser deletado
	
	printf("Digite o CPF do usuário a ser deletado: "); //escrevendo na tela, solicitando o cpf
	scanf("%s",cpf); //localizando o usuario a ser deletado
	
	remove(cpf); //deletando o usuário
	
	FILE *file; //ponteiro pro arquivo
	file = fopen(cpf,"r"); //tenta abrir o arquivo do CPF
	
	if(file == NULL) //verificando se o arquivo não foi encontrado
	{
		printf("O Usuário não se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //variável do menu
	int laco=1; //variavel de controle de loop
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //limpando a tela
		
        setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	    printf("### Cartório Agua mole ### \n\n"); //inicio do menu
	    printf("Escolha a opção desejada do Menu: \n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n"); 
	    printf("\t4 - Sair do sistema\n");
	    printf("Opção: "); //fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuario
	
	    system("cls"); //responsavel por limpar a tela
	    
	    
	    switch(opcao) //inicio da seleção do menu
	    {
	    	case 1:
	    	registro(); //chamada da função registro
			break;
			
			case 2:
			consulta(); //chamada da função consulta
		    break;
		    
		    case 3:
		    deletar(); //chamada da função deletar
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema!"); 
		    return 0; //agradecendo e fechando o programa
		    break;
		    
		    default:
		    printf("essa opção não tá disponível, tente novamente.\n");
		    system("pause");
		    break;
		    	
		}  //fim da seleção

    }
}
