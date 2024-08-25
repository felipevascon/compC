/******************************************************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Arquivo testes para as funcoes do aula0901.c com argumento opcoes curtas e longas no terminal
 *
 * $Author: felipe.farias $
 * $Date: 2024/08/24 18:54:16 $
 * $Log: aula0906.c,v $
 * Revision 1.1  2024/08/24 18:54:16  felipe.farias
 * Initial revision
 *
 *
 ******************************************************************************************************************/
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
	printf("\n%sUso(terceiro argumento eh opcional): <opcaoEscolhida> <arquivo_original> <arquivo_convertido>%s\n\n", CYAN, RESET);
	printf("%sOpcoes que podem ser utilizadas no primeiro argumento:%s\n", YELLOW, RESET);
	printf("  -d | -D | --dos: Converter um arquivo do formato Unix para o formato Microsoft (DOS);\n");
	printf("  -h | -H | --help: Exibir esta mensagem que instrui o uso do programa;\n");
	printf("  -s | -S | --show: Exibir o conteudo do arquivo;\n");
	printf("  -u | -U | --unix: Converter um arquivo do formato DOS para o formato Unix.\n\n");
}

int main(int argc, char **argv)
{
	int todasOpcoes;
	int opcaoContador = 0;
	int temOpcao = 0;
	unsigned contador;
	tipoErros resultadoConversaoUnixDos, resultadoConversaoDosUnix, resultanteExibirConteudo;
	char *opcoesCurtas = "dDhHsSuU";
	char *nomeArquivoOriginal;
	char *nomeArquivoConvertido;

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

	static struct option opcoesCurtasLongas[5] = 
	{
		{"dos", 0, NULL, 'd'},
		{"unix", 0, NULL, 'u'},
		{"show", 0, NULL, 's'},
		{"help", 0, NULL, 'h'},
		{NULL, 0, NULL, 0}
	};


	todasOpcoes = getopt_long(argc, argv, opcoesCurtas, opcoesCurtasLongas, &opcaoContador);


	if (todasOpcoes == -1)
	{
		printf("\n%sERRO: A opcao escolhida passada no terminal nao existe! Leia as instrucoes:%s\n\n", RED, RESET);
		ExibirOpcoesArgumentosInstrucao();
		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}


	else
	{
		while ((todasOpcoes) != -1)
		{
			break;
		}
	}

	switch (todasOpcoes)
	{

	case 'd':
	case 'D':
		if (optind >= argc)
		{
			printf("\n%sERRO: Nome do arquivo original nao apresentado no terminal!%s\n\n", RED, RESET);
			ExibirOpcoesArgumentosInstrucao();
			exit(NUMERO_ARGUMENTOS_INVALIDO);
		}

		nomeArquivoOriginal = argv[optind];

		if (optind + 1 >= argc) 
		{
    			nomeArquivoConvertido = NULL;
		}

		else 
		{
    			nomeArquivoConvertido = argv[optind + 1];
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
	
			printf("\n%sConversao do arquivo '%s' formato Unix para o Dos '%s' realizada com sucesso!%s\n\n", GREEN, argv[2], argv[3], RESET);

		}

		if (argc == NUMERO_ARGUMENTOS_MAXIMO - 1)
		{

			printf("\n%sComo o argumento opcional eh NULL, um arquivo temporario foi criado a partir do '%s' com sucesso!%s\n\n", GREEN, argv[2], RESET);
		}

		break;


	case 'u':
	case 'U':	
		if (optind >= argc)
		{
			printf("\n%sERRO: Nome do arquivo original nao apresentado no terminal!%s\n\n", RED, RESET);
			ExibirOpcoesArgumentosInstrucao();
			exit(NUMERO_ARGUMENTOS_INVALIDO);
		}

		nomeArquivoOriginal = argv[optind];

		if (optind + 1 >= argc) 
		{
    			nomeArquivoConvertido = NULL;
		}

		else 
		{
    			nomeArquivoConvertido = argv[optind + 1];
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
			printf("\n%sConversao do arquivo '%s' formato Dos para o Unix '%s' realizada com sucesso!%s\n\n", GREEN, argv[2], argv[3], RESET);
		}

		if (argc == NUMERO_ARGUMENTOS_MAXIMO - 1)
		{
			printf("\n%sComo o argumento opcional eh NULL, um arquivo temporario foi criado a partir do '%s' com sucesso!%s\n\n", GREEN, argv[2], RESET);
		}

		break;


	case 's':
	case 'S':
		if (optind >= argc)
		{
			printf("\n%sERRO: Nome do arquivo nao apresentado no terminal!%s\n\n", RED, RESET);
			ExibirOpcoesArgumentosInstrucao();
			exit(NUMERO_ARGUMENTOS_INVALIDO);
		}

		if (argc > NUMERO_ARGUMENTOS_MINIMO + 1)
		{
			printf("\n%sERRO: Numero de argumentos invalido! Para as opcoes -s | -S, uso: <nomeArquivo>!%s\n\n", RED, RESET);
			exit(NUMERO_ARGUMENTOS_INVALIDO);
		}

		resultanteExibirConteudo = ExibirConteudoArquivo(argv[optind]);

		if (resultanteExibirConteudo != sucesso)
		{
			switch (resultanteExibirConteudo)
			{
				case nomeArquivoInvalido:
				printf("\n%sERRO: Nome do arquivo invalido!%s\n\n", RED, RESET);
				break;

				case tipoArquivoInvalido:
				printf("\n%sERRO: Nao foi possivel abrir o arquivo!%s\n\n", RED, RESET);
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
		ExibirOpcoesArgumentosInstrucao();
		break;

	default:
		printf("\n%sERRO: A opcao inserida no terminal nao existe! Leia as instrucoes:%s\n\n", RED, RESET);
		ExibirOpcoesArgumentosInstrucao();

		exit(NUMERO_ARGUMENTOS_INVALIDO);
	}

	return OK;
}
/* $RCSfile: aula0906.c,v $ */
