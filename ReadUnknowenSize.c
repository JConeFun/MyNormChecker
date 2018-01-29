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
/*	This function was made to read a undifened quanity untill a new line is reached.
/	It was originaly intened to take a unknown number of chars from the console.
/	This function requires a file dircipter do that i may be used for more then just consol input.*/
char *ReadToNewLine(int fd)
{
	char	temp = "0";
	char	*file_address,*file_address_temp = NULL;
	int		i = 0;

	file_address_temp = (char *)malloc(sizeof(char) * 2);
	file_address = (char *)malloc(sizeof(char) * 2);
	file_address[1] = '\0';
	while (temp != '\n')
	{
		read(fd, &temp, 1);
		if (temp != '\n')
		{
			if (++i > 1)
			{
				free(file_address_temp);
				file_address_temp = file_address;//here we trade which pointer is holding the previous contents so the correct malloc size can be given.
				file_address = (char *)malloc(sizeof(char) * (i + 1));
				for (int j = 0; j < i; ++j) //this loop is copying the contents of the previous itteration
					file_address[j] = file_address_temp[j];
			}
			file_address[i - 1] = temp;
//			file_address[i] = '\0'; /*this line was here because its a good habit to make sure your string is terminated with the correct char.*/
//			The above line isn't actually needed in this function.
		}
	}
	file_address[i] = '\0';
	free(file_address_temp);
//	printf("i = %d file address = %s", i, file_address); /*this was for checking that the countents was correct and the number of chars was correct.*/
	return(file_address);
}