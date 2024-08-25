/*************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Codigo fonte da funcoes do roteiro aula07
 *
 * $Author: felipe.farias $
 * $Date: 2024/08/23 01:58:51 $
 * $Log: aula0701.c,v $
 * Revision 1.4  2024/08/23 01:58:51  felipe.farias
 * correcao
 *
 * Revision 1.3  2024/08/19 23:56:01  felipe.farias
 * codigo fonte da funcao DesenharReta incluido
 *
 * Revision 1.2  2024/08/17 20:34:36  felipe.farias
 * codigo fonte da funcao LimparMonitor add
 *
 * Revision 1.1  2024/08/17 18:34:14  felipe.farias
 * Initial revision
 *
 *
 *************************************************************/
#ifdef __linux__
#define _XOPEN_SOURCE	600
#endif

#if defined (__FreeBSD__) && defined (__STRICT_ANSI__)
#define __LONG_LONG_SUPPORTED
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <time.h>

#include "aula0701.h"
#include "cores.h"

char *ObterCodigoAnsiCor(char *nomeCor, tipoFundoTexto fundoTexto)
{
	if(!nomeCor)
	{
		return fundoTexto == fundo ? BLACK_BACKGROUND : WHITE;
	}

    	if(strcmp(nomeCor, "preto") == 0)
	{
        	return fundoTexto == fundo ? BLACK_BACKGROUND : BLACK;
    	}	 

	else if (strcmp(nomeCor, "verde") == 0)
	{
        	return fundoTexto == fundo ? GREEN_BACKGROUND : GREEN;
    	} 

	else if (strcmp(nomeCor, "amarelo") == 0)
	{
        	return fundoTexto == fundo ? YELLOW_BACKGROUND : YELLOW;
    	} 

	else if (strcmp(nomeCor, "vermelho") == 0)
	{
        	return fundoTexto == fundo ? RED_BACKGROUND : RED;
    	} 

	else if (strcmp(nomeCor, "azul") == 0)
	{
        	return fundoTexto == fundo ? BLUE_BACKGROUND : BLUE;
    	} 

	else if (strcmp(nomeCor, "magenta") == 0)
	{
        	return fundoTexto == fundo ? MAGENTA_BACKGROUND : MAGENTA;
    	} 

	else if (strcmp(nomeCor, "ciano") == 0)
	{
        	return fundoTexto == fundo ? CYAN_BACKGROUND : CYAN;
    	} 

	else if (strcmp(nomeCor, "branco") == 0)
	{
        	return fundoTexto == fundo ? WHITE_BACKGROUND : WHITE;
    	} 

	else 
	{
        	return fundoTexto == fundo ? BLACK_BACKGROUND : WHITE;
    	}
}


tipoErros MostrarMonitor(useconds_t tempoEspera,
                         tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
                         unsigned numeroLinhas,
                         unsigned numeroColunas,
                         char *corFundo,
                         char *corPixelApagado,
                         char *corPixelAceso,
                         char *corPixelDefeituoso)
{
	unsigned contador, contadorAuxiliar;
	char *pixelFundo, *pixelApagado, *pixelAceso, *pixelDefeituoso, *caracterDelimitadorFundo, *caracterDelimitadorTexto;

	if(numeroLinhas < 1 || numeroLinhas > NUMERO_MAXIMO_LINHAS)
	{
    		return numeroLinhasInvalido;
	}

	if(numeroColunas < 1 || numeroColunas > NUMERO_MAXIMO_COLUNAS)
	{
    		return numeroColunasInvalido;
	}

	if(strcmp(corFundo, corPixelAceso) == 0 || strcmp(corFundo, corPixelApagado) == 0 || strcmp(corFundo, corPixelDefeituoso) == 0)
	{
    		return corInvalida;
	}


	pixelAceso = ObterCodigoAnsiCor(corPixelAceso, fundo);
	pixelApagado = ObterCodigoAnsiCor(corPixelApagado, fundo);
	pixelDefeituoso = ObterCodigoAnsiCor(corPixelDefeituoso, texto);
	pixelFundo = ObterCodigoAnsiCor(corFundo, fundo);
	caracterDelimitadorFundo = ObterCodigoAnsiCor(corPixelAceso, fundo);
	caracterDelimitadorTexto = ObterCodigoAnsiCor(corFundo, texto);

	system("clear");


	for(contador = 0; contador < numeroColunas + 4; contador++)
	{
    		printf("%s%s-", caracterDelimitadorTexto, caracterDelimitadorFundo);
	}

	printf("%s\n", RESET);

	for(contador = 0; contador < numeroLinhas; contador++)
	{
		printf("%s%s| ", caracterDelimitadorTexto, caracterDelimitadorFundo);
    		for(contadorAuxiliar = 0; contadorAuxiliar < numeroColunas; contadorAuxiliar++)
		{
        		switch(monitor[contador][contadorAuxiliar])
			{

            			case aceso:
					printf("%s%c", pixelAceso, ACESO);
				break;

            			case apagado:
					printf("%s%c", pixelApagado, APAGADO);
				break;

            			case defeituoso:
					printf("%s%s%c", pixelDefeituoso, pixelFundo, DEFEITUOSO);
				break;
				
				default:
        				printf("%s%s%c", pixelApagado, pixelFundo, APAGADO);

			}

		}
    		printf("%s%s |%s\n", caracterDelimitadorTexto, caracterDelimitadorFundo, RESET);
				

	}

	for(contador = 0; contador < numeroColunas + 4; contador++)
	{
    		printf("%s%s-", caracterDelimitadorTexto, caracterDelimitadorFundo);
	}

	printf("%s\n", RESET);

	usleep(tempoEspera);

	return sucesso;

}


tipoErros
GerarDistribuicaoInicial(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],
                         unsigned numeroLinhas,
                         unsigned numeroColunas,
                         float percentualDefeituosos,
                         float percentualApagados)
{

	unsigned numeroApagados, numeroDefeituosos, totalPixels, contador, contadorAuxiliar;

	if(numeroLinhas < 1 || numeroLinhas > NUMERO_MAXIMO_LINHAS)
	{
    		return numeroLinhasInvalido;
	}

	if(numeroColunas < 1 || numeroColunas > NUMERO_MAXIMO_COLUNAS)
	{
    		return numeroColunasInvalido;
	}

	if(percentualDefeituosos < 0 || percentualDefeituosos > 100)
	{
        	return percentualDefeituososInvalido;
    	}

	if(percentualApagados < 0 || percentualApagados > 100)
	{
        	return percentualApagadosInvalido;
    	}

  	if (percentualDefeituosos + percentualApagados > 100)
  	{
    		return percentualInvalido;
  	}


	totalPixels = numeroLinhas * numeroColunas;
	numeroDefeituosos = (unsigned)(totalPixels * (percentualDefeituosos / 100.0));
	numeroApagados = (unsigned)(totalPixels * (percentualApagados / 100.0));

	for(contador = 0; contador < numeroLinhas; contador++)
	{
    		for(contadorAuxiliar = 0; contadorAuxiliar < numeroColunas; contadorAuxiliar++)
		{
        		monitor[contador][contadorAuxiliar] = aceso;
    		}
	}

	srand(time(NULL));

	while(numeroDefeituosos > 0)
	{
    		contador = rand() % numeroLinhas;
    		contadorAuxiliar = rand() % numeroColunas;

    		if(monitor[contador][contadorAuxiliar] == aceso)
		{
        		monitor[contador][contadorAuxiliar] = defeituoso;
        		numeroDefeituosos--;
    		}
	}

	while(numeroApagados > 0)
	{
    		contador = rand() % numeroLinhas;
    		contadorAuxiliar = rand() % numeroColunas;

    		if(monitor[contador][contadorAuxiliar] == aceso)
		{
        		monitor[contador][contadorAuxiliar] = apagado;
        		numeroApagados--;
    		}
	}

	return sucesso;

}


tipoErros
LimparMonitor(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS], /* E/S */
              unsigned numeroLinhas,                                          /* E   */
              unsigned numeroColunas,                                         /* E   */
              char *corFundo,                                                 /* E   */
              char *corPixelApagado,                                          /* E   */
              char *corPixelAceso,                                            /* E   */
              char *corPixelDefeituoso)			              	      /* E   */
{

	unsigned contadorLinhas, contadorColunas;

	if(numeroLinhas < 1 || numeroLinhas > NUMERO_MAXIMO_LINHAS)
	{
    		return numeroLinhasInvalido;
	}

	if(numeroColunas < 1 || numeroColunas > NUMERO_MAXIMO_COLUNAS)
	{
    		return numeroColunasInvalido;
	}

	if(strcmp(corFundo, corPixelAceso) == 0 || strcmp(corFundo, corPixelApagado) == 0 || strcmp(corFundo, corPixelDefeituoso) == 0)
	{
    		return corInvalida;
	}

	for (contadorLinhas = 0; contadorLinhas < numeroLinhas; contadorLinhas++)
	{
		for (contadorColunas = 0; contadorColunas < numeroColunas; contadorColunas++)
		{
			if (monitor[contadorLinhas][contadorColunas] != defeituoso)
			{
				monitor[contadorLinhas][contadorColunas] = apagado;
			}
		}
	}

	return sucesso;
}


tipoErros
DesenharReta(tipoPixel monitor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],    /* E/S */
             unsigned numeroLinhas, 						/* E   */
             unsigned numeroColunas, 						/* E   */
             unsigned linhaA, 							/* E   */
             unsigned colunaA, 						        /* E   */
             unsigned linhaB, 							/* E   */
             unsigned colunaB, 						        /* E   */
             char *corFundo, 							/* E   */
             char *corPixelApagado, 						/* E   */
             char *corPixelAceso, 						/* E   */
	     char *corPixelDefeituoso)				 		/* E   */

{
	int deltaHorizontal, deltaVertical, sinalHorizontal, sinalVertical, falha, falhaDupla, linhaAuxiliar, colunaAuxiliar;

	if (linhaA >= numeroLinhas || linhaB >= numeroLinhas)
	{
        	return numeroLinhasInvalido;
	}

	if (colunaA >= numeroColunas || colunaB >= numeroColunas)
	{
        	return numeroColunasInvalido;
	}

	deltaHorizontal = (colunaB > colunaA) ? (colunaB - colunaA) : (colunaA - colunaB);
	deltaVertical = (linhaB > linhaA) ? (linhaB - linhaA) : (linhaA - linhaB);
	sinalHorizontal = (deltaHorizontal > 0) ? 1 : -1;
	sinalVertical = (deltaVertical > 0) ? 1 : -1;

	linhaAuxiliar = linhaA;
	colunaAuxiliar = colunaA;
	falha = (deltaHorizontal - deltaVertical);


	while(1)
	{

        	if(linhaAuxiliar > numeroLinhas && colunaAuxiliar > numeroColunas)
		{
            			return parametrosInvalidos;
        	}

    		if(linhaAuxiliar < numeroLinhas && colunaAuxiliar < numeroColunas)
		{
        		if(monitor[linhaAuxiliar][colunaAuxiliar] == defeituoso)
			{
            			return pixelDefeituoso;
        		}

       	 		monitor[linhaAuxiliar][colunaAuxiliar] = aceso;
    		}

    		if(linhaAuxiliar == linhaB && colunaAuxiliar == colunaB)
		{
        		break;
    		}

		falhaDupla = falha * 2;

		if(falhaDupla > -deltaVertical)
		{

			falha -= deltaVertical;
			colunaAuxiliar += sinalHorizontal;	


		}

		if(falhaDupla < deltaHorizontal)
		{

			falha += deltaHorizontal;
			linhaAuxiliar += sinalVertical;	

		}

	}

	return sucesso;
}


/* $RCSfile: aula0701.c,v $ */
