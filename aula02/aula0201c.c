/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao:Implementacao da funcao CalcularMaximoDivisorComum com for
 *
 * $Author: felipe.farias $
 * $Date: 2024/05/04 21:02:06 $
 * $Log: aula0201c.c,v $
 * Revision 1.1  2024/05/04 21:02:06  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#include <stdio.h>
#include "aula0201.h"

ull
CalcularMaximoDivisorComum (ull primeiroNumero, ull segundoNumero)
{
	ull contador;
	ull restoDivisao = 1;

	for(contador = 0; restoDivisao != 0; contador++)
	{
		restoDivisao = primeiroNumero % segundoNumero;
		primeiroNumero = segundoNumero;
		segundoNumero = restoDivisao;
	}
	return primeiroNumero;
}


/* $RCSfile: aula0201c.c,v $ */
