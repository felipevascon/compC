/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: implementacao funcao CalcularSerieHarmonicaAlternada com while
 *
 * $Author: felipe.farias $
 * $Date: 2024/05/27 05:31:09 $
 * $Log: aula0403d.c,v $
 * Revision 1.1  2024/05/27 05:31:09  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#include "aula0401.h"

float
CalcularSerieHarmonicaAlternada(unsigned short int percentualSerieHarmonica)
{
	
	float termoAuxiliar = 0;
	
	if (percentualSerieHarmonica == 0)
	{
		return termoAuxiliar;
	}	

	while(percentualSerieHarmonica > 0)
	{	
		if ((percentualSerieHarmonica %2) == 0)
		{
			termoAuxiliar = (termoAuxiliar) - (1/((float)CalcularExponencial (percentualSerieHarmonica, percentualSerieHarmonica)));
		}
		
		if ((percentualSerieHarmonica %2) == 1)
		{
			termoAuxiliar = (termoAuxiliar) + (1/((float)CalcularExponencial (percentualSerieHarmonica, percentualSerieHarmonica)));
		}
		
		percentualSerieHarmonica--;
	}
	
	return termoAuxiliar;
}

/* $RCSfile: aula0403d.c,v $ */
