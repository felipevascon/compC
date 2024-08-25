/*********************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: implementacao CalcularSerieHarmonicaAlternada com a biblioteca math
 *
 * $Author: felipe.farias $
 * $Date: 2024/05/27 05:54:07 $
 * $Log: aula0403e.c,v $
 * Revision 1.1  2024/05/27 05:54:07  felipe.farias
 * Initial revision
 *
 *
 *********************************************************************************/
#include <math.h>

#include "aula0401.h"


float
CalcularSerieHarmonicaAlternada(unsigned short int percentualSerieHarmonica)
{	

	if(percentualSerieHarmonica == 0)
	{
		return 0;
	}

	if((percentualSerieHarmonica % 2) == 0)
	{
		return -(1/pow(percentualSerieHarmonica, percentualSerieHarmonica)) + (CalcularSerieHarmonicaAlternada(percentualSerieHarmonica - 1));
	}
	
	return (1/pow(percentualSerieHarmonica, percentualSerieHarmonica)) + (CalcularSerieHarmonicaAlternada(percentualSerieHarmonica - 1));

}


/* $RCSfile: aula0403e.c,v $ */
