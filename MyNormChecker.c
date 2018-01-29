/* *********************************************/
/*                                             */
/*											   */
/*   MyNormChecker.c                           */
/*											   */
/*   By: Jamie Cone                       	   */
/*											   */
/*   Created: 2018/01/27 12:23 by jamie cone   */
/*   Updated: 2018/01/27 10:33 by jamie cone   */
/*											   */
/* *********************************************/

#include "HeaderForMyNormChecker.h"

main(void)
{
	char	*file_address;
	char	temp;

	printf("What file do you want to check?(provied address if not in the same folder as this program)\n");
	file_address = ReadToNewLine(0, &file_address);
	printf("file address in main = %s", file_address);
	read(0, &temp, 1);
	free(file_address);
	return(0);
}






