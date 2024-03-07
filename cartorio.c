#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar da string

int registro() //fun��o respons�vel por cadastrar usuario no sistema
{
    //inicio cria��o de vari�veis/string
	char arquivo[40]; //armazenando o nome do arquivo a ser criado
	char cpf[40]; //armazenando o CPF do usu�rio
    char nome[40]; //armazenando o nome do usu�rio
    char sobrenome[40]; //armazenando o sobrenome do usu�rio
    char cargo[40]; //armazenando o cargo do usu�rio
    //final da cria��o de vari�veis
    
    printf("Digite o CPF a ser cadastrado: "); //escrevendo na tela
    scanf("%s", cpf); //salvando o cpf cadastrado
    
    strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
    
    FILE *file; //procura na bibliopteca e cria o arquivo
    file = fopen(arquivo,"w"); //cria o arquivo, escrevendo com o "w"
    fprintf(file,cpf); //salva o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a"); //adiciona uma virgula pra melhor visualiza��o
    fprintf(file,", "); //adi��o da virgula
    fclose(file); //fechando a pasta
    
    printf("Digite o nome a ser cadastrado: "); //escrevendo na tela
    scanf("%s",nome); //armazena o nome digitado
    
    file = fopen(arquivo,"a"); //escrevendo o nome no arquivo
    fprintf(file,nome); //salvando o nome no arquivo
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a"); //colocando virgula pra melhor visualiza��o
    fprintf(file,", "); //adi��o da virgula
    fclose(file); //fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); //escrevendo na tela
    scanf("%s",sobrenome); //armazena o sobrenome digitado
    
    file = fopen(arquivo,"a"); //escrevendo o sobrenome no arquivo
    fprintf(file,sobrenome); //salvando o sobrenome no arquivo
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a"); //adiciona uma virgula pra melhor visualiza��o
    fprintf(file,", "); //adi��o da virgula
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
    	printf("N�o foi pos�vel localicar o arquivo!\n");
	}
    
    while(fgets(conteudo, 200, file) != NULL) //procura o conteudo do arquivo linha por linha
    {
    	printf("\nEssas s�o as informa��es do Usu�rio: ");
    	printf("%s", conteudo); //imprime o conteudo do arquivo
    	printf("\n\n");
	}
	
	fclose(file); //fechando o arquivo
	system("pause"); //pausando a tela pra ler
}

int deletar()
{
	char cpf[40]; //armazena o cpf a ser deletado
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //escrevendo na tela, solicitando o cpf
	scanf("%s",cpf); //localizando o usuario a ser deletado
	
	remove(cpf); //deletando o usu�rio
	
	FILE *file; //ponteiro pro arquivo
	file = fopen(cpf,"r"); //tenta abrir o arquivo do CPF
	
	if(file == NULL) //verificando se o arquivo n�o foi encontrado
	{
		printf("O Usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //vari�vel do menu
	int laco=1; //variavel de controle de loop
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); //limpando a tela
		
        setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	    printf("### Cart�rio Agua mole ### \n\n"); //inicio do menu
	    printf("Escolha a op��o desejada do Menu: \n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n"); 
	    printf("\t4 - Sair do sistema\n");
	    printf("Op��o: "); //fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuario
	
	    system("cls"); //responsavel por limpar a tela
	    
	    
	    switch(opcao) //inicio da sele��o do menu
	    {
	    	case 1:
	    	registro(); //chamada da fun��o registro
			break;
			
			case 2:
			consulta(); //chamada da fun��o consulta
		    break;
		    
		    case 3:
		    deletar(); //chamada da fun��o deletar
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema!"); 
		    return 0; //agradecendo e fechando o programa
		    break;
		    
		    default:
		    printf("essa op��o n�o t� dispon�vel, tente novamente.\n");
		    system("pause");
		    break;
		    	
		}  //fim da sele��o

    }
}
