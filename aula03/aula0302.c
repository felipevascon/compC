/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: tratamento de erros/Implementacao main/Chamada CalcularTermoSerie
 *Fibonacci
 *
 * $Author: felipe.farias $
 * $Date: 2024/05/11 17:51:16 $
 * $Log: aula0302.c,v $
 * Revision 1.2  2024/05/11 17:51:16  felipe.farias
 * correcao em um termo de tratamento
 *
 * Revision 1.1  2024/05/11 16:38:32  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#include "cores.h"
#include "aula0301.h"

#define NUMERO_ARGUMENTOS				2	

#define SUCESSO						0
#define NUMERO_ARGUMENTOS_INVALIDO			3		
#define ARGUMENTO_CARACTER_INVALIDO			4
#define ARGUMENTO_CARACTER_HIFEN			5
#define TAMANHO_MAXIMO_UNSIGNED_SHORT_EXCEDIDO		6
#define TAMANHO_MAXIMO_UNSIGNED_LONG_EXCEDIDO      	7
#define TAMANHO_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO	8


#define END_OF_STRING					'\0'

int
main (int argc, char *argv[])
{	
	us numeroTermos, contador;
	ull chamarSerieFibonacci;
	char *validacao;
	unsigned long numeroAuxiliar;
	
	ull resultadoReferencia = 0;
	ull resultadoSeguinteInferiorReferencia = 0;

	/*tratamento numero de argumentos*/
	if (argc != NUMERO_ARGUMENTOS)
	{
	
		printf ("\n%s%sERRO: Numero de argumentos invalido, Uso:<inteiro>. %s\n\n", RED, WHITE_BACKGROUND, RESET);	
		exit (NUMERO_ARGUMENTOS_INVALIDO);
	}
	
	/*tratamento de caracteres especiais*/
	for	(contador = 1; contador < NUMERO_ARGUMENTOS; contador++)
	{
			if (argv[contador][0] == '-')
			{
				printf ("\n%s%sERRO: Termo contem caractere hifen '-', Uso: <inteiro positivo>. %s\n\n", RED, WHITE_BACKGROUND, RESET);
				exit (ARGUMENTO_CARACTER_HIFEN);
			}
	}	
		
	
	/*conversao de tipos para adequacao do problema*/	
	numeroAuxiliar = strtoul (argv[1], &validacao, 10);	
	numeroTermos = (us) numeroAuxiliar;
	
	if (*validacao != END_OF_STRING)
	{
		printf("\n%s%sERRO: Termo contem caracter especial. Caracteres especiais nao sao validos. \'%c\' %s\n\n", RED, WHITE_BACKGROUND, *validacao, RESET);
		exit (ARGUMENTO_CARACTER_INVALIDO);
	
	}

	/*tratamento de limite do tipo*/
	if (errno == ERANGE)
	{
	
		printf("\n%s%sERRO: Termo inserido ultrapassa valor maximo de conversao para o tipo unsigned long(limite:%lu). %s\n\n", RED, WHITE_BACKGROUND, ULONG_MAX, RESET);
		exit (TAMANHO_MAXIMO_UNSIGNED_LONG_EXCEDIDO);

	}	
	
	if(numeroAuxiliar > USHRT_MAX)
	{
		printf("\n%s%sERRO: O numero de termos nao pode ultrapassar o valor maximo do tipo unsigned short (limite:%u). %s\n\n", RED, WHITE_BACKGROUND, USHRT_MAX, RESET);
		exit (TAMANHO_MAXIMO_UNSIGNED_SHORT_EXCEDIDO);
	}
	

	printf("\n");
	
	for (contador = 0; contador <= numeroTermos; contador++)
	{
		/*variavel criada para diminuir termo de chamada da funcao*/
		chamarSerieFibonacci = CalcularTermoSerieFibonacci (contador);
			
			/*verificacao do momento em que o resultado de uma funcao de fibonacci diminui em relacao ao resultado anterior*/
			resultadoReferencia = resultadoSeguinteInferiorReferencia;
			resultadoSeguinteInferiorReferencia = chamarSerieFibonacci;
		
			if (resultadoSeguinteInferiorReferencia < resultadoReferencia)
			{
				printf ("%s%sF (%hu) ultrapassa o limite permitido para o tipo unsigned long long.%s\n\n", RED, WHITE_BACKGROUND, contador,RESET);
				exit (TAMANHO_MAXIMO_UNSIGNED_LONG_LONG_EXCEDIDO);
			}
		
		printf("%s%sF (%hu) = %llu%s\n",BLACK, WHITE_BACKGROUND, contador, chamarSerieFibonacci, RESET);	
	}	
	printf("\n");
	return SUCESSO;
}

/* $RCSfile: aula0302.c,v $ */
