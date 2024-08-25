/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Implementacao da funcao CalcularMaximoDivisorComum com do..while 
 *
 * $Author: felipe.farias $
 * $Date: 2024/05/05 18:35:25 $
 * $Log: aula0201b.c,v $
 * Revision 1.2  2024/05/05 18:35:25  felipe.farias
 * correcao do tipo da variavel NumeroAuxiliar
 *
 * Revision 1.1  2024/05/04 19:59:03  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include "aula0201.h"

ull
CalcularMaximoDivisorComum (ull primeiroNumero, ull segundoNumero)
{
	ull numeroAuxiliar;
	do
	{
		if(segundoNumero == 0)
		{
			return primeiroNumero;
		}
		else
		{
			numeroAuxiliar = segundoNumero;
			segundoNumero = primeiroNumero % segundoNumero;
			primeiroNumero = numeroAuxiliar;
		}
	}
	while (segundoNumero != 0);

	return primeiroNumero;


}
/* $RCSfile: aula0201b.c,v $ */
