/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 * Autor: Felipe Vasconcellos Nunes Gurgel Farias
 *
 * Descricao: codigo fonte das funcoes Codificar e Decodificar bases
 *
 * $Author: felipe.farias $
 * $Date: 2024/08/13 00:34:52 $
 * $Log: aula0801.c,v $
 * Revision 1.7  2024/08/13 00:34:52  felipe.farias
 * codigos fonte das funcoes codificar e decodificar bases
 *
 * Revision 1.6  2024/08/08 03:47:20  felipe.farias
 * codigo fonte das funcoes atualizado com funcao CodificarBase64
 *
 * Revision 1.5  2024/08/06 22:13:07  felipe.farias
 * codigo fonte da funcao DecodificarBase32 add
 *
 * Revision 1.4  2024/08/02 04:46:18  felipe.farias
 * inclusao da implementacao da funcao CodificarBase32
 *
 * Revision 1.3  2024/07/30 22:31:46  felipe.farias
 * prototipo de funcoes atualizado com a funcao DecodificarBase16
 *
 * Revision 1.2  2024/07/30 22:24:33  felipe.farias
 * correcao
 *
 * Revision 1.1  2024/07/28 18:43:43  felipe.farias
 * Initial revision
 *
 *
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aula0801.h"

#define BASE_16			"0123456789ABCDEF"

#define BASE_32_BASICO		"ABCDEFGHIJKLMNOPQRSTUVWXYZ234567"
#define BASE_32_ESTENDIDO	"0123456789ABCDEFGHIJKLMNOPQRSTUV"

#define BASE_64_BASICO		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"
#define BASE_64_SEGURO		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_"

#define END_OF_STRING	'\0'

tipoErros
CodificarBase16 ( byte *entradaByte,   /* (E) */ 
		  ull numeroBytes,	/* (E) */ 
		  char *pacoteBase16)  /* (S) */
{
	byte auxiliarPacoteBase;
	ull contador;

	if(!entradaByte)
	{
		return entradaByteInvalida;
	}

	if(!pacoteBase16)
	{
		return saidaPacoteInvalido;
	}

	for(contador = 0; contador < numeroBytes; contador++)
	{
	
		auxiliarPacoteBase = entradaByte[contador];

		pacoteBase16[2 * contador] = BASE_16[(auxiliarPacoteBase >> 4 & 0x0F)];
		pacoteBase16[2 * contador + 1] = BASE_16[(auxiliarPacoteBase & 0x0F)];
	}

	pacoteBase16[2 * numeroBytes] = END_OF_STRING;

	return sucesso;	

}


tipoErros
DecodificarBase16 (char *entradaByte,	/* (E) */
		   byte *pacoteBase16,	/* (S) */
		   ull *numeroBytes)	/* (S) */

{

	ull contador, tamanhoEntrada;
	byte valorByte;
	char nibbleAlto, nibbleBaixo;

	if(!entradaByte)
	{
		return entradaByteInvalida;
	}

	if(!pacoteBase16)
	{
		return saidaPacoteInvalido;
	}

	if(!numeroBytes)
	{
		return comprimentoInvalido;
	}

	tamanhoEntrada = strlen(entradaByte);

	
	if (tamanhoEntrada % 2 != 0)
	{
		return entradaNaoParInvalido;
	}

	
	*numeroBytes = (tamanhoEntrada / 2);	

	for(contador = 0; contador < tamanhoEntrada; contador += 2)
	{
	
		nibbleAlto = entradaByte[contador];
		nibbleBaixo = entradaByte[contador + 1];

		if (nibbleAlto >= '0' && nibbleAlto <= '9')
		{
			valorByte = (nibbleAlto - '0') << 4;
		}
		
		else if (nibbleAlto >= 'A' && nibbleAlto <= 'F')
		{
			valorByte = (nibbleAlto - 'A' + 10) << 4;
		}

		else if (nibbleAlto >= 'a' && nibbleAlto <= 'f')
		{
			valorByte = (nibbleAlto - 'a' + 10) << 4;
		}

		else
		{
			return nibbleAltoInvalido;
		}


		if (nibbleBaixo >= '0' && nibbleBaixo <= '9')
		{
			valorByte = valorByte | (nibbleBaixo - '0');
		}
		
		else if (nibbleBaixo >= 'A' && nibbleBaixo <= 'F')
		{
			valorByte = valorByte | (nibbleBaixo - 'A' + 10);
		}

		else if (nibbleBaixo >= 'a' && nibbleBaixo <= 'f')
		{
			valorByte = valorByte | (nibbleBaixo - 'a' + 10);
		}
		
		else
		{
			return nibbleBaixoInvalido;
		}
		
		pacoteBase16[contador / 2] = valorByte;
	}	

	return sucesso;

}


tipoErros
CodificarBase32 (byte *entradaByte,  			/* (E) */
		 ull numeroBytes,  			/* (E) */
		 tipoAlfabetoBase32 escolherAlfabeto,	/* (E) */
		 char *pacoteBase32)			/* (S) */
{
	
	ull numeroBlocosBytes;
	ul contadorBloco, contadorByte, posicaoSaida;
	byte blocoEntrada[5], blocoSaida[8];
	const char *tipoAlfabetoEntrada;

	if(!entradaByte)
	{
		return entradaByteInvalida;
	}

	if(!pacoteBase32)
	{
		return saidaPacoteInvalido;
	}

	switch (escolherAlfabeto)
	{
		case basico:
		tipoAlfabetoEntrada = BASE_32_BASICO;
		break;

		case estendido:
		tipoAlfabetoEntrada = BASE_32_ESTENDIDO;
		break;

		default:
		return baseInvalida;

	}

	numeroBlocosBytes = (numeroBytes + 4) / 5;

	posicaoSaida = 0;

	for(contadorBloco = 0; contadorBloco < numeroBlocosBytes; contadorBloco++)
	{
	
		for (contadorByte = 0; contadorByte < 5; contadorByte++)
		{

			if (contadorBloco * 5 + contadorByte < numeroBytes)
			{
				blocoEntrada[contadorByte] = entradaByte[contadorBloco * 5 + contadorByte];
			}

			else
			{
				blocoEntrada[contadorBloco] = 0;
			}

		}



		blocoSaida[0] = (blocoEntrada[0] & 0xF8) >> 3;
		blocoSaida[1] = ((blocoEntrada[0] & 0x07) << 2) | ((blocoEntrada[1] & 0xC0) >> 6);
		blocoSaida[2] = (blocoEntrada[1] & 0x3E) >> 1;
		blocoSaida[3] = ((blocoEntrada[1] & 0x01) << 4) | ((blocoEntrada[2] & 0xF0) >> 4);
		blocoSaida[4] = ((blocoEntrada[2] & 0x0F) << 1) | ((blocoEntrada[3] & 0x80) >> 7);
		blocoSaida[5] = (blocoEntrada[3] & 0x7C) >> 2;
		blocoSaida[6] = ((blocoEntrada[3] & 0x03) << 3) | ((blocoEntrada[4] & 0xE0) >> 5);
		blocoSaida[7] = blocoEntrada[4] & 0x1F;


		for (contadorByte = 0; contadorByte < 8; contadorByte++)
		{

			if(contadorBloco * 5 + (contadorByte * 5) / 8 < numeroBytes || contadorByte < (numeroBytes % 5) * 8 / 5)
			{
				pacoteBase32[posicaoSaida] = tipoAlfabetoEntrada[blocoSaida[contadorByte]];		
			}

			else

			{
				pacoteBase32[posicaoSaida] = '=';
			
			}
		
			posicaoSaida++;

		}

	}

	pacoteBase32[posicaoSaida] = END_OF_STRING;

	return sucesso;

}


tipoErros
DecodificarBase32 (char *entradaByte,			/* (E) */
		   tipoAlfabetoBase32 escolherAlfabeto,	/* (E) */
		   byte *pacoteBase32, 			/* (S) */
		   ull *numeroBytes )			/* (S) */

{

	ull tamanhoEntrada, contadorEntrada;
	ull contadorSaida = 0;
	char *tipoAlfabetoEntrada;
	us valorCaracter, contadorCaracter;
	us caracterEncontrado = 0;
	us bitsPendentes = 0;
	us memoriaTemporaria = 0;


	if(!entradaByte)
	{
		return entradaByteInvalida;
	}

	if(!pacoteBase32)
	{
		return saidaPacoteInvalido;
	}

	if(!numeroBytes)
	{
		return comprimentoInvalido;
	}

	switch (escolherAlfabeto)
	{
		case basico:
		tipoAlfabetoEntrada = BASE_32_BASICO;
		break;

		case estendido:
		tipoAlfabetoEntrada = BASE_32_ESTENDIDO;
		break;

		default:
		return baseInvalida;
	}

	tamanhoEntrada = strlen(entradaByte);
	if(tamanhoEntrada % 8 != 0)
	{

		return entradaNaoParInvalido;

	}

	for(contadorEntrada = 0; contadorEntrada < tamanhoEntrada; contadorEntrada++)
	{
		for(contadorCaracter = 0; tipoAlfabetoEntrada[contadorCaracter] != END_OF_STRING; contadorCaracter++)
		{

			if(entradaByte[contadorEntrada] == tipoAlfabetoEntrada[contadorCaracter])
			{

				valorCaracter = contadorCaracter;
				caracterEncontrado = 1;
				break;

			}

		}
	
		if (!caracterEncontrado)
		{

			return entradaInvalida;

		}

		memoriaTemporaria = (memoriaTemporaria << 5) | valorCaracter;
		bitsPendentes += 5;

		if (bitsPendentes >= 8)
		{
			bitsPendentes -= 8;
			pacoteBase32[contadorSaida++] = (byte)((memoriaTemporaria >> bitsPendentes) & 0xFF);
		}

	}

	*numeroBytes = contadorSaida;

	return sucesso;

}


tipoErros
CodificarBase64 (byte *entradaByte,  			/* (E) */
		 ull numeroBytes,  			/* (E) */
		 tipoFinalLinha finalLinha,		/* (E) */
		 tipoAlfabeto64 escolherAlfabeto,	/* (E) */
		 char *pacoteBase64)			/* (S) */

{

	ull comprimentoSaida; 
	ull contadorEntrada = 0;
	ull contadorCodificado = 0;
	ull contadorBloco;
	byte blocoEntrada[3];
	char blocoSaida[4];
	char *tipoAlfabetoEntrada;

	if(!entradaByte)
	{
		return entradaByteInvalida;
	}

	if(!pacoteBase64)
	{
		return saidaPacoteInvalido;
	}


	switch (escolherAlfabeto)
	{
		case basico:
		tipoAlfabetoEntrada = BASE_64_BASICO;
		break;

		case estendido:
		tipoAlfabetoEntrada = BASE_64_SEGURO;
		break;

		default:
		return baseInvalida;

	}

	for (contadorEntrada = 0; contadorEntrada < numeroBytes; contadorEntrada+=3)
	{
		for(contadorBloco = 0; contadorBloco < 3; contadorBloco++)
		{

			if (contadorEntrada + contadorBloco < numeroBytes)
			{

				blocoEntrada[contadorBloco] = entradaByte[contadorEntrada + contadorBloco];

			}
			
			else
			{

				blocoEntrada[contadorBloco] = 0;

			}

		}

		blocoSaida[0] = tipoAlfabetoEntrada[blocoEntrada[0] >> 2];
		blocoSaida[1] = tipoAlfabetoEntrada[((blocoEntrada[0] & 0x03) << 4) | (blocoEntrada[1] >> 4)];
		blocoSaida[2] = tipoAlfabetoEntrada[((blocoEntrada[1] & 0x0F) << 2) | (blocoEntrada[2] >> 6)];
		blocoSaida[3] = tipoAlfabetoEntrada[blocoEntrada[2] & 0x3F];

		for (contadorBloco = 0; contadorBloco < 4; contadorBloco++)
		{

			if (contadorEntrada + contadorBloco < numeroBytes + 1)
			{

				pacoteBase64[contadorCodificado++] = blocoSaida[contadorBloco];
		
			}

			else
			{

				pacoteBase64[contadorCodificado++] = '=';

			}

		}
	}
	
	if (finalLinha == habilitado)
	{

		comprimentoSaida = contadorCodificado;
		for (contadorEntrada = 0; contadorEntrada < comprimentoSaida; contadorEntrada++)
		{
			if (contadorEntrada > 0 && contadorEntrada % 76 == 0)
			{

				pacoteBase64[contadorCodificado++] = '\n';
		
			}

		}
	}

	pacoteBase64[contadorCodificado] = END_OF_STRING;

	return sucesso;

}



tipoErros
DecodificarBase64 (char *entradaByte,			/* (E) */
		   tipoFinalLinha finalLinha,		/* (E) */
		   tipoAlfabeto64 escolherAlfabeto,	/* (E) */
		   byte *pacoteBase64, 			/* (S) */
		   ull *numeroBytes)			/* (S) */

{

	ull comprimentoEntrada, comprimentoSaida;
	ull contadorEntrada = 0;
	ull contadorSaida = 0;
	us contadorBloco, caracterEncontrado, contadorAuxiliar;
	byte blocoSaida[4];
	char *tipoAlfabetoEntrada;

	if(!entradaByte)
	{
		return entradaByteInvalida;
	}

	if(!pacoteBase64)
	{
		return saidaPacoteInvalido;
	}

	if(!numeroBytes)
	{
		return comprimentoInvalido;
	}

	switch (escolherAlfabeto)
	{
		case basico:
		tipoAlfabetoEntrada = BASE_64_BASICO;
		break;

		case estendido:
		tipoAlfabetoEntrada = BASE_64_SEGURO;
		break;

		default:
		return baseInvalida;
	}

	comprimentoEntrada = strlen(entradaByte);
	if(comprimentoEntrada % 4 != 0)
	{

		return entradaNaoParInvalido;

	}

	comprimentoSaida = (comprimentoEntrada / 4) * 3;

	if (entradaByte[comprimentoEntrada - 1] == '=')
	{

		comprimentoSaida = comprimentoSaida - 1;

	}

	if (entradaByte[comprimentoEntrada - 2] == '=')
	{

		comprimentoSaida = comprimentoSaida - 1;

	}

	*numeroBytes = comprimentoSaida;

	for(contadorEntrada = 0; contadorEntrada < comprimentoEntrada; contadorEntrada += 4)
	{

		for (contadorBloco = 0; contadorBloco < 4; contadorBloco++)
		{

			if(entradaByte[contadorEntrada + contadorBloco] == '=')
			{

				blocoSaida[contadorBloco] = 0;

			}

			else
			{
			
				for (contadorAuxiliar = 0; tipoAlfabetoEntrada[contadorAuxiliar] != END_OF_STRING; contadorAuxiliar++)
				{

					if(tipoAlfabetoEntrada[contadorAuxiliar] == entradaByte[contadorEntrada + contadorBloco])
					{

						blocoSaida[contadorBloco] = contadorAuxiliar;
						caracterEncontrado = 1;
						break;

					}

				}
				
				if (!caracterEncontrado)
				{

					return entradaInvalida;

				}

			}

		}

		if (contadorSaida < comprimentoSaida)
		{

			pacoteBase64[contadorSaida++] = (blocoSaida[0] << 2) | (blocoSaida[1] >> 4);

		}

		if (contadorSaida < comprimentoSaida)
		{

			pacoteBase64[contadorSaida++] = (blocoSaida[1] << 4) | (blocoSaida[2] >> 2);

		}
	
		if (contadorSaida < comprimentoSaida)
		{

			pacoteBase64[contadorSaida++] = (blocoSaida[2] << 6) | blocoSaida[3];

		}

	}

	return sucesso;

}
/* $RCSfile: aula0801.c,v $ */
