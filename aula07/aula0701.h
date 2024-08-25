/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Prototipo das funcoes do roteiro aula07
 *
 * $Author: felipe.farias $
 * $Date: 2024/08/19 23:56:01 $
 * $Log: aula0701.h,v $
 * Revision 1.3  2024/08/19 23:56:01  felipe.farias
 * prototipo da funcao DesenharReta incluido
 *
 * Revision 1.2  2024/08/17 20:34:36  felipe.farias
 * prototipo da funcao LimparMonitor add
 *
 * Revision 1.1  2024/08/17 18:34:14  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#ifndef _AULA0701_
#define _AULA0701_		"@(#)aula0701.h $Revision: 1.3 $"

#ifndef _linux_
#define _XOPEN_SOURCE		600
#endif

#define OK			0
#define APAGADO 		' '
#define ACESO 			' '
#define DEFEITUOSO 		'.'
#define NUMERO_MAXIMO_LINHAS 	250
#define NUMERO_MAXIMO_COLUNAS 	800
#define NUMERO_MAXIMO_VERTICES 	50


typedef enum
{
  sucesso,
  numeroLinhasInvalido,
  numeroColunasInvalido,
  corInvalida,
  percentualDefeituososInvalido,
  percentualApagadosInvalido,
  percentualInvalido,
  pixelDefeituoso,
  parametrosInvalidos
} 
tipoErros;


typedef enum
{
  apagado,
  aceso,
  defeituoso = -1
}
tipoPixel;


typedef enum
{
  fundo,
  texto
} 
tipoFundoTexto;


char *
ObterCodigoAnsiCor(char *nomeCor, /* E */
                   tipoFundoTexto fundoTexto);

tipoErros
MostrarMonitor(useconds_t tempoEspera,                                         /* E */
               tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E */
               unsigned numeroLinhas,                                          /* E */
               unsigned numeroColunas,                                         /* E */
               char *corFundo,                                                 /* E */
               char *corPixelApagado,                                          /* E */
               char *corPixelAceso,                                            /* E */
 	       char *corPixelDefeituoso);			       	       /* E */


    
tipoErros
GerarDistribuicaoInicial(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
                         unsigned numeroLinhas,                                          /* E   */
                         unsigned numeroColunas,                                         /* E   */
                         float percentualDefeituosos,                                    /* E   */
                         float percentualApagados);				         /* E   */


tipoErros
LimparMonitor(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
              unsigned numeroLinhas,                                          /* E   */
              unsigned numeroColunas,                                         /* E   */
              char *corFundo,                                                 /* E   */
              char *corPixelApagado,                                          /* E   */
              char *corPixelAceso,                                            /* E   */
              char *corPixelDefeituoso);			              /* E   */


tipoErros
DesenharReta(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],    /* E/S */
             unsigned numeroLinhas, 						/* E   */
             unsigned numeroColunas, 						/* E   */
             unsigned linhaA, 							/* E   */
             unsigned colunaA, 							/* E   */
             unsigned linhaB, 							/* E   */
             unsigned colunaB, 							/* E   */
             char *corFundo, 							/* E   */
             char *corPixelApagado, 						/* E   */
             char *corPixelAceso, 						/* E   */
	     char *corPixelDefeituoso);				 		/* E   */


#endif

/* $RCSfile: aula0701.h,v $ */
