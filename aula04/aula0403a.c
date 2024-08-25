/*************************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: Implementacao CalcularSerieHarmonicaAlternada com exponencial/recursiva
 *
 * $Author: felipe.farias $
 * $Date: 2024/05/27 03:29:59 $
 * $Log: aula0403a.c,v $
 * Revision 1.1  2024/05/27 03:29:59  felipe.farias
 * Initial revision
 *
 *
 *************************************************************************************/
#include "aula0401.h"


float
CalcularSerieHarmonicaAlternada (unsigned short int percentualSerieHarmonica)
{
	
	int termoAuxiliar = 0;

	if (percentualSerieHarmonica == 0)
	{
		return termoAuxiliar;
	}
	
	if (percentualSerieHarmonica % 2 == 0)
	{
		return CalcularSerieHarmonicaAlternada(percentualSerieHarmonica - 1) - (1/ (float)CalcularExponencial(percentualSerieHarmonica, percentualSerieHarmonica));
	}

	return (CalcularSerieHarmonicaAlternada(percentualSerieHarmonica - 1)) + (1/(float)CalcularExponencial(percentualSerieHarmonica, percentualSerieHarmonica));

}



/* $RCSfile: aula0403a.c,v $ */
