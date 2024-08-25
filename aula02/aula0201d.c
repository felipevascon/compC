/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Implementacao funcao CalcularMaximoDivisorComum usando while
 *
 * $Author: felipe.farias $
 * $Date: 2024/05/04 21:33:38 $
 * $Log: aula0201d.c,v $
 * Revision 1.1  2024/05/04 21:33:38  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include "aula0201.h"

ull CalcularMaximoDivisorComum (ull primeiroNumero, ull segundoNumero)
{

	ull restoDivisao;
	restoDivisao = 1;

	while (restoDivisao != 0)
	{
		restoDivisao = primeiroNumero % segundoNumero;
		primeiroNumero = segundoNumero;
		segundoNumero = restoDivisao;
	}
	
	return primeiroNumero;
}



/* $RCSfile: aula0201d.c,v $ */
