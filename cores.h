/*******************************************************************************
 *
 * Universidade Federal do Rio de Janeiro
 * Escola Politecnica
 * Departamento de Eletronica e de Computacao
 * EEL270 - Computacao II - Turma 2024/1
 * Prof. Marcelo Luiz Drumond Lanza
 *
 * Autor: Prof. Marcelo Luiz Drumond Lanza
 * Descricao:
 *   Definicao das sequencias de escape (codigos ANSI) correspondentes as oito
 * cores basicas para caracteres e fundo (foreground e background) e suas
 * variacoes.
 *
 * $Author$
 * $Date$
 * $Log$
 *
 ******************************************************************************/

#ifndef	CORES_ANSI
#define CORES_ANSI														"cores.h $Revision$"

/* Regular text */
#define BLACK																	"\e[0;30m"
#define RED																		"\e[0;31m"
#define GREEN																	"\e[0;32m"
#define YELLOW																"\e[0;33m"
#define BLUE																	"\e[0;34m"
#define MAGENTA																"\e[0;35m"
#define CYAN																	"\e[0;36m"
#define WHITE																	"\e[0;37m"

/* Regular bold text */
#define BOLD_BLACK														"\e[1;30m"
#define BOLD_RED															"\e[1;31m"
#define BOLD_GREEN														"\e[1;32m"
#define BOLD_YELLOW														"\e[1;33m"
#define BOLD_BLUE															"\e[1;34m"
#define BOLD_MAGENTA													"\e[1;35m"
#define BOLD_CYAN															"\e[1;36m"
#define BOLD_WHITE														"\e[1;37m"

/* Regular underline text */
#define UNDERLINE_BLACK												"\e[4;30m"
#define UNDERLINE_RED													"\e[4;31m"
#define UNDERLINE_GREEN												"\e[4;32m"
#define UNDERLINE_YELLOW											"\e[4;33m"
#define UNDERLINE_BLUE												"\e[4;34m"
#define UNDERLINE_MAGENTA											"\e[4;35m"
#define UNDERLINE_CYAN												"\e[4;36m"
#define UNDERLINE_WHITE												"\e[4;37m"

/* Regular background */
#define BLACK_BACKGROUND											"\e[40m"
#define RED_BACKGROUND												"\e[41m"
#define GREEN_BACKGROUND											"\e[42m"
#define YELLOW_BACKGROUND											"\e[43m"
#define BLUE_BACKGROUND												"\e[44m"
#define MAGENTA_BACKGROUND										"\e[45m"
#define CYAN_BACKGROUND												"\e[46m"
#define WHITE_BACKGROUND											"\e[47m"

/* High intensity background */ 
#define BLACK_HIGH_INTENSITY_BACKGROUND				"\e[0;100m"
#define RED_HIGH_INTENSITY_BACKGROUND					"\e[0;101m"
#define GREEN_HIGH_INTENSITY_BACKGROUND				"\e[0;102m"
#define YELLOW_HIGH_INTENSITY_BACKGROUND			"\e[0;103m"
#define BLUE_HIGH_INTENSITY_BACKGROUND				"\e[0;104m"
#define MAGENTA_HIGH_INTENSITY_BACKGROUND			"\e[0;105m"
#define CYAN_HIGH_INTENSITY_BACKGROUND				"\e[0;106m"
#define WHITE_HIGH_INTENSITY_BACKGROUND				"\e[0;107m"

/* High intensity text */
#define HIGH_INTENSITY_BLACK									"\e[0;90m"
#define HIGH_INTENSITY_RED										"\e[0;91m"
#define HIGH_INTENSITY_GREEN									"\e[0;92m"
#define HIGH_INTENSITY_YELLOW									"\e[0;93m"
#define HIGH_INTENSITY_BLUE										"\e[0;94m"
#define HIGH_INTENSITY_MAGENTA								"\e[0;95m"
#define HIGH_INTENSITY_CYAN										"\e[0;96m"
#define HIGH_INTENSITY_WHITE									"\e[0;97m"

/* Bold high intensity text */
#define BOLD_HIGH_INTENSITY_BLACK							"\e[1;90m"
#define BOLD_HIGH_INTENSITY_RED								"\e[1;91m"
#define BOLD_HIGH_INTENSITY_GREEN							"\e[1;92m"
#define BOLD_HIGH_INTENSITY_YELLOW						"\e[1;93m"
#define BOLD_HIGH_INTENSITY_BLUE							"\e[1;94m"
#define BOLD_HIGH_INTENSITY_MAGENTA						"\e[1;95m"
#define BOLD_HIGH_INTENSITY_CYAN							"\e[1;96m"
#define BOLD_HIGH_INTENSITY_WHITE							"\e[1;97m"

/* Reset */
#define RESET																	"\e[0m"
#define COLOR_RESET														"\e[0m"

#endif

/* $RCSfile$ */
