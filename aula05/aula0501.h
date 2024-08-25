/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Definicoes dos prototipos das funcoes das matrizes
 *
 * $Author: felipe.farias $
 * $Date: 2024/06/11 22:09:45 $
 * $Log: aula0501.h,v $
 * Revision 1.4  2024/06/11 22:09:45  felipe.farias
 * inclusao de tres pÂrototipos de funcao
 *
 * Revision 1.3  2024/06/10 01:35:14  felipe.farias
 * inclusao do prototipo da funcao ObterMatrizTransposta
 *
 * Revision 1.2  2024/06/09 22:46:46  felipe.farias
 * inclusao do prototipo da funcao MultiplicarMatrizes
 *
 * Revision 1.1  2024/06/01 04:04:29  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#ifndef _AULA0501_
#define _AULA0501_		"@(#)aula0501.h $Revision: 1.4 $"


#define OK 			0
#define NUMERO_MAXIMO_LINHAS	100
#define NUMERO_MAXIMO_COLUNAS	100



typedef unsigned short us;
typedef long double ld;

typedef enum
{
	sucesso,
	enderecoMatrizInvalido,
	linhaColunaInvalida

}

tipoErros;

tipoErros
ExibirMatriz (us,						/* numero de linhas matriz (E) */
              us,						/* numero de colunas matriz 1 (E) */
              ld[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS]);	/* matriz (E) */




tipoErros
MultiplicarMatrizes (us,						/* numero de linhas matriz 1 (E)    */
 		     us,						/* numero de colunas matriz 1 (E)   */
		     us,						/* numero de linhas matriz 2 (E)    */
		     us,						/* numero de colunas da matriz 2 (E)*/
		     ld[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],	/* matriz 1 (E) */
		     ld[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],	/* matriz 2 (E) */
              	     ld[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS]);	/* matriz produto (S) */


tipoErros
ObterMatrizTransposta (us,							/* numero de linhas matriz original (E)    */
 		       us,							/* numero de colunas matriz original (E)   */
		       ld[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],		/* matriz original (E) */
		       ld[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS]);	/* matriz transposta (S) */


tipoErros
CalcularMenorComplementar (us,							/* ordem da matriz (E) */
 		           us,							/* linha do elemento (E) */
			   us,							/* coluna do elemento (E) */
		      	   ld[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],	/* matriz (E) */
		       	   ld *);						/* menor complementar (S) */


tipoErros
CalcularComplementoAlgebrico (us,						/* ordem da matriz (E) */
 		              us,						/* linha do elemento (E) */
			      us,						/* coluna do elemento (E) */
		      	      ld[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],	/* matriz (E) */
		       	      ld *);						/* complemento algebrico (S) */


tipoErros
CalcularDeterminanteMatriz (us,							/* ordem da matriz (E) */
              		    ld[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],	/* matriz (E) */
              		    ld *);						/* determinante (S) */


#endif
/* $RCSfile: aula0501.h,v $ */
