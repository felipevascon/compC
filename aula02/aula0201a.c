/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Implementacao da funcao CalcularMaximoDivisorComum com recursividade
 *
 * $Author: felipe.farias $
 * $Date: 2024/05/04 16:52:42 $
 * $Log: aula0201a.c,v $
 * Revision 1.1  2024/05/04 16:52:42  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>

#include "aula0201.h"

#define VALOR_ZERO	0


ull
CalcularMaximoDivisorComum (ull primeiroNumero, ull segundoNumero)
{

	if (segundoNumero == VALOR_ZERO)
	{
		return primeiroNumero;
	}
	
	return CalcularMaximoDivisorComum (segundoNumero, primeiroNumero % segundoNumero);

}

/* $RCSfile: aula0201a.c,v $ */
