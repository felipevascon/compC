/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: implementacao das funcoes das matrizes
 *
 * $Author: felipe.farias $
 * $Date: 2024/06/21 17:26:13 $
 * $Log: aula0501.c,v $
 * Revision 1.7  2024/06/21 17:26:13  felipe.farias
 * correcao para o controle de versao para incluir determinate maior que 3
 *
 * Revision 1.6  2024/06/18 14:07:16  felipe.farias
 * inclusao da implentacao que cacula o complementar algebrico
 *
 * Revision 1.5  2024/06/17 20:49:03  felipe.farias
 * inclusao da implementacao da funcao menor complementar
 *
 * Revision 1.4  2024/06/11 22:09:45  felipe.farias
 * implementacao da funcao CalcularDeterminanteMatriz
 *
 * Revision 1.3  2024/06/10 01:35:14  felipe.farias
 * inclusao da implementacao da funcao ObterMatrizTransposta
 *
 * Revision 1.2  2024/06/09 22:46:46  felipe.farias
 * inclusao da implementacao da funcao MultiplicarMatrizes
 *
 * Revision 1.1  2024/06/01 04:04:29  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#include <stdio.h>

#include "cores.h"
#include "aula0501.h"


tipoErros
ExibirMatriz (us numeroLinhas,						/* numero de linhas matriz (E) */
              us numeroColunas,						/* numero de colunas matriz (E) */
              ld matriz[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS])	/* matriz (E) */

{
	
	int contadorLinha, contadorColuna;
	
	if(!matriz)
	{
		return enderecoMatrizInvalido;
	}
		
	for(contadorLinha =0;contadorLinha < numeroLinhas; contadorLinha++)
	{
		
		printf("\n");
		printf("%s|%s", BOLD_GREEN, RESET);
		
		for(contadorColuna = 0;contadorColuna < numeroColunas; contadorColuna++)
		{
			printf("%.10Lf", matriz[contadorLinha][contadorColuna]);		
		
				if(contadorColuna < numeroColunas - 1)
				{
					printf("\t");
				}
		
		}
	
			printf("%s|%s", BOLD_GREEN, RESET);
	}
	
	printf("\n\n");
	return OK; 

}


tipoErros
MultiplicarMatrizes (us primeiroNumeroLinhas,						/* numero linhas matriz 1 (E) */
                     us primeiroNumeroColunas,						/* numero colunas matriz 1 (E) */
		     us segundoNumeroLinhas,						/* numero linhas matriz 2 (E) */
		     us segundoNumeroColunas,						/* numero colunas matriz 2 (E) */
                     ld matrizA[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],		/* matriz 1(E) */
		     ld matrizB[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],		/* matriz 2(E) */
		     ld matrizProduto[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS])	/* matriz produto (S)*/

{
	us auxiliarMatrizA, auxiliarMatrizB, contador;


	if ((!matrizA) || (!matrizB) || (!matrizProduto))
	{
		return enderecoMatrizInvalido;
	}

	for (auxiliarMatrizA = 0; auxiliarMatrizA < primeiroNumeroLinhas; auxiliarMatrizA++)
	{
		for (auxiliarMatrizB = 0; auxiliarMatrizB < segundoNumeroColunas; auxiliarMatrizB++)
		{ 
		   for(contador = 0; contador < primeiroNumeroColunas; contador++)
		   {
		    matrizProduto[auxiliarMatrizA][auxiliarMatrizB] = matrizProduto[auxiliarMatrizA][auxiliarMatrizB] + (matrizA[auxiliarMatrizA][contador] * matrizB[contador][auxiliarMatrizB]);
		   }
		}
	}

	printf("\n");
	return OK;

}




tipoErros
ObterMatrizTransposta (us numeroLinhas,								/* numero linhas matriz original (E) */
                       us numeroColunas,							/* numero colunas matriz original (E) */
                       ld matrizOriginal[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],		/* matriz original(E) */
		       ld matrizTransposta[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS])	/* matriz transposta (S)*/

{

	us primeiroContador, segundoContador;

	for (primeiroContador = 0; primeiroContador < numeroColunas; primeiroContador++)
	{ 

	   for(segundoContador = 0; segundoContador < numeroLinhas; segundoContador++)
	   {

	    	matrizTransposta[segundoContador][primeiroContador] = matrizOriginal[primeiroContador][segundoContador];

	   }

	}
	
	printf("\n");
	return OK;

}




tipoErros
CalcularMenorComplementar (us ordemMatriz,						/* ordem da matriz (E) */
 		           us linhaElemento,						/* linha do elemento (E) */
			   us colunaElemento,						/* coluna do elemento (E) */
		      	   ld matriz[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],	/* matriz (E) */
		       	   ld *menorComplementar)					/* menor complementar (S) */

{


	us linhaOriginal, colunaOriginal, linhaAuxiliar, colunaAuxiliar;
	ld matrizMenor[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS];

	if(ordemMatriz - 1 == 0)
	{
		menorComplementar[0] = matriz[0][0];
	}

	if(linhaElemento > ordemMatriz || colunaElemento > ordemMatriz || linhaElemento == 0 || colunaElemento == 0)
	{
		return linhaColunaInvalida;
	}


	for(linhaAuxiliar = 0, linhaOriginal = 0; linhaAuxiliar < ordemMatriz - 1; linhaAuxiliar++, linhaOriginal++)
	{
		if(linhaAuxiliar == linhaElemento - 1)
		{
			linhaOriginal++;
		}
			
		for(colunaAuxiliar = 0, colunaOriginal = 0; colunaAuxiliar < ordemMatriz - 1; colunaAuxiliar++, colunaOriginal++)
		{

			if(colunaAuxiliar == colunaElemento - 1)
			{		
				colunaOriginal++;
			}

			matrizMenor[linhaAuxiliar][colunaAuxiliar] = matriz[linhaOriginal][colunaOriginal];
		}

	}

	CalcularDeterminanteMatriz(ordemMatriz - 1, matrizMenor, menorComplementar);
	
	return OK;
}



tipoErros
CalcularComplementoAlgebrico (us ordemMatriz,						/* ordem da matriz (E) */
 		              us linhaElemento,						/* linha do elemento (E) */
			      us colunaElemento,					/* coluna do elemento (E) */
		      	      ld matriz[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],	/* matriz (E) */
		       	      ld *complementoAlgebrico)					/* complemento algebrico (S) */

{

	ld multiplicador;
	ld menorComplementar[1];


	if(linhaElemento > ordemMatriz || colunaElemento > ordemMatriz || linhaElemento == 0 || colunaElemento == 0)
	{
		return linhaColunaInvalida;
	}

	if((linhaElemento + colunaElemento) % 2 == 0)
	{
		multiplicador = 1;
		
	}

	else
	{
		multiplicador = -1;
	}

	CalcularMenorComplementar (ordemMatriz, linhaElemento, colunaElemento, matriz, menorComplementar);
	complementoAlgebrico[0] = multiplicador * menorComplementar[0];

	return OK;
}





tipoErros
CalcularDeterminanteMatriz (us ordemMatriz,						/* ordem da matriz (E) */
              		    ld matriz[NUMERO_MAXIMO_LINHAS][NUMERO_MAXIMO_COLUNAS],	/* matriz (E) */
              		    ld *determinante)						/* determinante (S) */


{

	us contador = 0;
	ld resultadoDeterminante = 0;
	ld complementoAlgebrico;
	tipoErros determinanteRetorno;

	if(ordemMatriz == 1)
	{

		*determinante = matriz[0][0];
	}


	if(ordemMatriz == 2)
	{

		*determinante = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
	}


	if(ordemMatriz == 3)
	{

	*determinante = matriz[0][0] * matriz[1][1] * matriz[2][2] -
		        matriz[0][0] * matriz[1][2] * matriz[2][1] +
		        matriz[0][1] * matriz[1][2] * matriz[2][0] -
		        matriz[0][1] * matriz[1][0] * matriz[2][2] +
		        matriz[0][2] * matriz[1][0] * matriz[2][1] -
		        matriz[0][2] * matriz[1][1] * matriz[2][0] ;
	}
	

	if(ordemMatriz > 3)
	{
		for(contador = 0; contador < ordemMatriz; contador++)
		{
		
			determinanteRetorno = CalcularComplementoAlgebrico(ordemMatriz, 1, contador + 1, matriz, &complementoAlgebrico);
			resultadoDeterminante += matriz[0][contador] * complementoAlgebrico;
			if(determinanteRetorno != sucesso)
			return determinanteRetorno;		
		}

		*determinante = resultadoDeterminante;
	}	

	return OK;
}


/* $RCSfile: aula0501.c,v $ */
