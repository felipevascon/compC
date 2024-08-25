
/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Arquivo de testes da funcao DecodificarBase64
 *
 * $Author: felipe.farias $
 * $Date: 2024/08/14 23:42:12 $
 * $Log: aula0809.c,v $
 * Revision 1.1  2024/08/14 23:42:12  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0801.h"
#include "cores.h"

typedef size_t comprimentoObjeto;

#define NUMERO_ARGUMENTOS_TERMINAL			4

#define OK						0
#define NUMERO_ARGUMENTOS_INVALIDO			1
#define CARACTER_ESPECIAL_ALFABETO_INVALIDO		2
#define DIGITO_ALFABETO_INVALIDO			3
#define ALFABETO_NEGATIVO				4
#define ERRO_ALOCACAO_MEMORIA				5

#define END_OF_STRING					'\0'

int
main (int argc, char **argv)
{

	FILE *arquivoCodificado, *arquivoGerado;
  	char *memoriaTemporariaByte, *validacao;
  	byte *memoriaTemporariaChar;
  	ull tamanhoEntrada, tamanhoSaida;
  	tipoAlfabeto64 tipoAlfabetoEntrada;
  	tipoErros pacoteDecodificado;
  	comprimentoObjeto tamanhoArquivo;

	if (argc != NUMERO_ARGUMENTOS_TERMINAL)
	{
		printf ("\n%sERRO: O numero de argumentos passados no terminal invalido! Uso: <tipoAlfabeto> <arquivoCodificado> <arquivoAgerar>%s\n\n", RED, RESET);
		exit (NUMERO_ARGUMENTOS_INVALIDO);

	}

	if (argv[1][0] == '-')
	{
		printf ("\n%sERRO: O alfabeto esta negativo. Digite apenas o inteiro 0 (basico) ou 1 (seguro)!%s\n\n", RED, RESET);
		exit (ALFABETO_NEGATIVO);
	}

	tipoAlfabetoEntrada = (tipoAlfabeto64)strtoul(argv[1], &validacao, 10);

	if(*validacao != END_OF_STRING)
	{
		printf ("\n%sERRO: Caracteres especiais sao invalidos. Retire o \'%c\' do argumento do tipo do alfabeto!%s\n\n", RED, *validacao, RESET);
		exit (CARACTER_ESPECIAL_ALFABETO_INVALIDO);
	}

	if(tipoAlfabetoEntrada != basico64 && tipoAlfabetoEntrada != seguro)
	{
		printf ("\n%sERRO: Argumento destinado ao tipo do alfabeto invalido. Digite apenas o inteiro 0 (basico) ou 1 (seguro)!%s\n\n", RED, RESET);
		exit (DIGITO_ALFABETO_INVALIDO);
	}

	arquivoCodificado = fopen(argv[2], "r");
	if (arquivoCodificado == NULL)
	{

		printf ("\n%sERRO: Falha ao abrir o arquivo codificado para que seja possivel gerar o novo arquivo!%s\n\n", RED, RESET);
		exit (entradaInvalida);
	
	}

	fseek(arquivoCodificado, 0, SEEK_END);
	tamanhoArquivo = ftell(arquivoCodificado);
	fseek(arquivoCodificado, 0, SEEK_SET);

	memoriaTemporariaByte = (char *)malloc(tamanhoArquivo * sizeof(char));

	if (memoriaTemporariaByte == NULL)
	{

		printf ("\n%sERRO: Falha ao abrir o arquivo codificado para que seja possivel gerar o novo arquivo!%s\n\n", RED, RESET);
		fclose (arquivoCodificado);
		exit (ERRO_ALOCACAO_MEMORIA);
	
	}

	fread(memoriaTemporariaByte, 1, tamanhoArquivo, arquivoCodificado);
	fclose(arquivoCodificado);

	tamanhoEntrada = tamanhoArquivo;

	while (tamanhoArquivo % 4 != 0)
	{
    		memoriaTemporariaByte[tamanhoArquivo++] = '=';
	}

	memoriaTemporariaByte[tamanhoArquivo] = END_OF_STRING;

	tamanhoSaida = (tamanhoEntrada + 4) / 4 * 3;

	memoriaTemporariaChar = (byte *)malloc(tamanhoSaida * sizeof(byte)); 


	if (memoriaTemporariaChar == NULL)
	{

		printf ("\n%sERRO: Falha ao abrir o arquivo codificado para que seja possivel gerar o novo arquivo!%s\n\n", RED, RESET);
		free (memoriaTemporariaByte);
		exit (ERRO_ALOCACAO_MEMORIA);
	
	}

	pacoteDecodificado = DecodificarBase64(memoriaTemporariaByte, desabilitado, tipoAlfabetoEntrada, memoriaTemporariaChar, &tamanhoSaida);

	if (pacoteDecodificado != sucesso)
	{
		free(memoriaTemporariaByte);
		free(memoriaTemporariaChar);

		switch (pacoteDecodificado)
		{

			case entradaByteInvalida:
			printf("\n%sERRO: Entrada invalida!%s\n\n", RED, RESET);
			break;

			case saidaPacoteInvalido:
			printf("\n%sERRO: Saida invalida!%s\n\n", RED, RESET);
			break;

			default:
			printf("\n%sERRO: Falha ao gerar arquivo! numero: %u %s\n\n", RED, pacoteDecodificado, RESET);
			break;

		}

		exit (pacoteDecodificado);
	}

	arquivoGerado = fopen(argv[3], "w");
	if (arquivoGerado == NULL)
	{

		printf ("\n%sERRO: Falha ao abrir o arquivo a ser gerado!%s\n\n", RED, RESET);
		free (memoriaTemporariaByte);
		free (memoriaTemporariaChar);
		exit (saidaPacoteInvalido);

	}

	fwrite(memoriaTemporariaChar, 1, tamanhoSaida, arquivoGerado);
	fclose(arquivoGerado);
	free(memoriaTemporariaByte);
	free(memoriaTemporariaChar);

	return OK;
}

/* $RCSfile: aula0809.c,v $ */
