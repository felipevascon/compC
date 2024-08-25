/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Implementacao da funcao CalcularExponencial usando recursividade
 *
 * $Author: felipe.farias $
 * $Date: 2024/05/25 23:59:25 $
 * $Log: aula0401a.c,v $
 * Revision 1.1  2024/05/25 23:59:25  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/


#include <stdio.h>
#include <math.h>
#include <limits.h>

#include "aula0401.h"

ld
CalcularExponencial (double basePotencia, int expoentePotencia)
{
	
	if (expoentePotencia == 0)
	{	
		return 1;
	}
	
	
	if (basePotencia == 0 && expoentePotencia < 0)
	{		
		return HUGE_VAL;
	}
	
	if (basePotencia == 0 && expoentePotencia > 0)
	{	
		return basePotencia;
	}
	
	
	if (basePotencia != 0 && expoentePotencia > 0)
	{
		return basePotencia * (CalcularExponencial(basePotencia, expoentePotencia - 1));

	}
	
	return (1 / basePotencia) * (CalcularExponencial (basePotencia, expoentePotencia + 1));
}


/* $RCSfile: aula0401a.c,v $ */
