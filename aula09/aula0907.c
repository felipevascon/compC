/************************************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Arquivo de testes para as funcoes do aula0901.c com todas opcoes e input e output
 *
 * $Author: felipe.farias $
 * $Date: 2024/08/25 17:41:19 $
 * $Log: aula0907.c,v $
 * Revision 1.1  2024/08/25 17:41:19  felipe.farias
 * Initial revision
 *
 *
 ************************************************************************************************/
#ifdef __linux__
#define _XOPEN_SOURCE	600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>

#include "aula0901.h"
#include "cores.h"

#define NUMERO_ARGUMENTOS_MINIMO	2
#define NUMERO_ARGUMENTOS_MAXIMO	4

#define OK				0
#define NUMERO_ARGUMENTOS_INVALIDO	1

#define END_OF_STRING			'\0'


void ExibirOpcoesArgumentosInstrucao(void)
{
	printf("\n%sUso: <opcaoEscolhida> <input=ArquivoOriginal> <output=ArquivoConvertido>%s\n", CYAN, RESET);
	printf("%sA ordem dos argumentos dos arquivos nao importa, trate 'input=' como original e 'output=' como convertido%s\n\n", CYAN, RESET);
	printf("%sOpcoes que podem ser utilizadas no primeiro argumento:%s\n", YELLOW, RESET);
	printf("  -d | -D | --dos: Converter um arquivo do formato Unix para o formato Microsoft (DOS);\n");
	printf("  -h | -H | --help: Exibir esta mensagem que instrui o uso do programa;\n");
	printf("  -s | -S | --show: Exibir o conteudo do arquivo;\n");
	printf("  -u | -U | --unix: Converter um arquivo do formato DOS para o formato Unix.\n\n");
}

int main(int argc, char **argv)
{
	int todasOpcoes, subopcao;
	int temOpcao = 0;
	unsigned contador;
	tipoErros resultadoConversaoUnixDos, resultadoConversaoDosUnix, resultanteExibirConteudo;
	char *opcoesCurtas = "dDhHsSuU";
  	char *nomeArquivoOriginal = NULL;
	char *nomeArquivoConvertido = NULL;
  	char *posicoes[] = {"input", "output", NULL};
  	char *posicaoOpcao = NULL;


	for (contador = 1; contador < argc; contador++)
	{
    		if (argv [contador][0] == '-')
		{
      			temOpcao = 1;
		}

	}

	if (argc < NUMERO_ARGUMENTOS_MINIMO || argc > NUMERO_ARGUMENTOS_MAXIMO || !temOpcao)
	{
		printf("\n%sERRO: Numero de argumentos invalido! Leia as seguintes instrucoes do programa:%s\n\n", RED, RESET);
		ExibirOpcoesArgumentosInstrucao();

		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

	struct option opcoesCurtasLongas[] = 
	{
		{"dos", 0, NULL, 'd'},
		{"unix", 0, NULL, 'u'},
		{"show", 0, NULL, 's'},
		{"help", 0, NULL, 'h'},
		{NULL, 0, NULL, 0}
	};


	todasOpcoes = getopt_long(argc, argv, opcoesCurtas, opcoesCurtasLongas, NULL);


	if (todasOpcoes == -1)
	{
		printf("\n%sERRO: A opcao escolhida passada no terminal nao existe! Leia as instrucoes:%s\n\n", RED, RESET);
		ExibirOpcoesArgumentosInstrucao();
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}


	for (contador = optind; contador < argc; contador++)
	{
		if (strncmp(argv[contador], "input=", 6) == 0)
		{
			nomeArquivoOriginal = argv[contador] + 6;
		}
		else if (strncmp(argv[contador], "output=", 7) == 0)
		{
			nomeArquivoConvertido = argv[contador] + 7;
		}
	}


	while ((todasOpcoes) != -1)
	{
		
		switch (todasOpcoes)
		{

			case 'd':
			case 'D':
			if (optind < argc)
			{

				subopcao = getsubopt(&argv[optind], posicoes, &posicaoOpcao);
				switch (subopcao)
				{
					case 0:
					nomeArquivoOriginal = posicaoOpcao;
					break;

					case 1:
					nomeArquivoConvertido = posicaoOpcao;
					break;

					default:
					printf("\n%sERRO: Argumentos do arquivo original e/ou convertido invalido(s)! Leia as instrucoes:%s\n\n", RED, RESET);
					ExibirOpcoesArgumentosInstrucao();

					exit(NUMERO_ARGUMENTOS_INVALIDO);
				}

				optind++;
			}

			resultadoConversaoUnixDos = ConverterArquivoFormatoUnixParaFormatoDos(nomeArquivoOriginal, nomeArquivoConvertido);
			if (resultadoConversaoUnixDos != sucesso)
			{
				switch (resultadoConversaoUnixDos)
				{
					case nomeArquivoInvalido:
					printf("\n%sERRO: Nome do arquivo invalido!%s\n\n", RED, RESET);
					break;

					case tipoArquivoInvalido:
					printf("\n%sERRO: O arquivo original nao esta no formato Unix!%s\n\n", RED, RESET);
					break;

					case arquivoInvalido:
					printf("\n%sERRO: Nao foi possivel abrir o arquivo!%s\n\n", RED, RESET);
					break;

					case erroAlocacaoMemoria:
					printf("\n%sERRO: Nao foi possivel realizar alocacao de memoria!%s\n\n", RED, RESET);
					break;

					case erroGerarArquivoTemporario:
					printf("\n%sERRO: Nao foi possivel gerar o arquivo temporario!%s\n\n", RED, RESET);
					break;

					case erroRenomearArquivoSalvo:
					printf("\n%sERRO: Nao foi possivel renomear o arquivo salvo!%s\n\n", RED, RESET);
					break;

					case erroRenomearArquivoOriginal:
					printf("\n%sERRO: Nao foi possivel renomear o arquivo original!%s\n\n", RED, RESET);
					break;

					default:
					printf("\n%sERRO: Nao foi possivel executar a funcao!%s\n\n", RED, RESET);
					break;
				}
		
				exit(resultadoConversaoUnixDos);

			}
			if (argc == NUMERO_ARGUMENTOS_MAXIMO)
			{

				printf("\n%sConversao do arquivo formato Unix para o Dos realizada com sucesso!%s\n\n", GREEN, RESET);

			}

			if (argc == NUMERO_ARGUMENTOS_MAXIMO - 1)
			{

				printf("\n%sComo o argumento opcional eh NULL, um arquivo temporario foi criado com sucesso!%s\n\n", GREEN, RESET);
			}

			break;

			case 'u':
			case 'U':
			if (optind < argc)
			{

				subopcao = getsubopt(&argv[optind], posicoes, &posicaoOpcao);
				switch (subopcao)
				{
					case 0:
					nomeArquivoOriginal = posicaoOpcao;
					break;

					case 1:
					nomeArquivoConvertido = posicaoOpcao;
					break;

					default:
					printf("\n%sERRO: Argumentos do arquivo original e/ou convertido invalido(s)! Leia as instrucoes:%s\n\n", RED, RESET);
					ExibirOpcoesArgumentosInstrucao();

					exit(NUMERO_ARGUMENTOS_INVALIDO);
				}

				optind++;
			}

			resultadoConversaoDosUnix = ConverterArquivoFormatoDosParaFormatoUnix(nomeArquivoOriginal, nomeArquivoConvertido);

			if (resultadoConversaoDosUnix != sucesso)
			{
				switch (resultadoConversaoDosUnix)
				{

					case nomeArquivoInvalido:
					printf("\n%sERRO: Nome do arquivo invalido!%s\n\n", RED, RESET);
					break;

					case tipoArquivoInvalido:
					printf("\n%sERRO: O arquivo original inserido no terminal nao esta no formato DOS!%s\n\n", RED, RESET);
					break;

					case arquivoInvalido:
					printf("\n%sERRO: Nao foi possivel abrir o arquivo!%s\n\n", RED, RESET);
					break;

					case erroAlocacaoMemoria:
					printf("\n%sERRO: Nao foi possivel realizar alocacao de memoria!%s\n\n", RED, RESET);
					break;

					case erroGerarArquivoTemporario:
					printf("\n%sERRO: Nao foi possivel gerar o arquivo temporario!%s\n\n", RED, RESET);
					break;

					case erroRenomearArquivoSalvo:
					printf("\n%sERRO: Nao foi possivel renomear o arquivo salvo!%s\n\n", RED, RESET);
					break;

					case erroRenomearArquivoOriginal:
					printf("\n%sERRO: Nao foi possivel renomear o arquivo original!%s\n\n", RED, RESET);
					break;

					default:
					printf("\n%sERRO: Nao foi possivel executar a funcao!%s\n\n", RED, RESET);
					break;
				}
	
				exit(resultadoConversaoDosUnix);
			}

			if (argc == NUMERO_ARGUMENTOS_MAXIMO)
			{
				printf("\n%sConversao do arquivo formato Dos para o Unix realizada com sucesso!%s\n\n", GREEN, RESET);
			}

			if (argc == NUMERO_ARGUMENTOS_MAXIMO - 1)
			{
				printf("\n%sComo o argumento opcional eh NULL, um arquivo temporario foi criado a partir do com sucesso!%s\n\n", GREEN, RESET);
			}

			break;

			case 's':
			case 'S':
			if (optind < argc)
			{

				subopcao = getsubopt(&argv[optind], posicoes, &posicaoOpcao);
				switch (subopcao)
				{
					case 0:
					nomeArquivoOriginal = posicaoOpcao;
					break;

					default:
					printf("\n%sERRO: Argumentos do arquivo original e/ou convertido invalido(s)! Leia as instrucoes:%s\n\n", RED, RESET);
					ExibirOpcoesArgumentosInstrucao();

					exit(NUMERO_ARGUMENTOS_INVALIDO);
				}

				optind++;
			}

			if (argc > NUMERO_ARGUMENTOS_MINIMO + 1)
			{
				printf("\n%sERRO: Numero de argumentos invalido! Para as opcoes -s | -S | --show, uso: <input=nomeArquivo>!%s\n\n", RED, RESET);
				ExibirOpcoesArgumentosInstrucao();
				exit(NUMERO_ARGUMENTOS_INVALIDO);
			}

			resultanteExibirConteudo = ExibirConteudoArquivo(nomeArquivoOriginal);

			if (resultanteExibirConteudo != sucesso)
			{
				switch (resultanteExibirConteudo)
				{
					case nomeArquivoInvalido:
					printf("\n%sERRO: Nome do arquivo invalido!%s\n\n", RED, RESET);
					break;

					case tipoArquivoInvalido:
					printf("\n%sERRO: Favor utilizar arquivos de entrada .c!%s\n\n", RED, RESET);
					break;

					case arquivoInvalido:
					printf("\n%sERRO: Nao foi possivel abrir o arquivo!%s\n\n", RED, RESET);
					break;

					default:
					printf("\n%sERRO: Nao foi possivel gerar a funcao que exibe o conteudo do arquivo!%s\n\n", RED, RESET);
					break;
				}

					exit(resultanteExibirConteudo);
			}

			break;

			case 'h':
			case 'H':

				if (argc > NUMERO_ARGUMENTOS_MINIMO + 1)
				{
					printf("\n%sERRO: Numero de argumentos invalido! Para as opcoes de ajuda basta usar um unico argumento: -h | -H | --help !%s\n\n", RED, RESET);
					ExibirOpcoesArgumentosInstrucao();
					exit(NUMERO_ARGUMENTOS_INVALIDO);
				}

				ExibirOpcoesArgumentosInstrucao();
			break;

			default:
				printf("\n%sERRO: A opcao inserida no terminal nao existe! Leia as instrucoes:%s\n\n", RED, RESET);
				ExibirOpcoesArgumentosInstrucao();
		
		}
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	
	}

	return OK;
}

/* $RCSfile: aula0907.c,v $ */

