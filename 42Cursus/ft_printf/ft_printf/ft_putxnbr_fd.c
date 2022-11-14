#include<stdio.h>
#include "Libft/libft.h"

void	ft_putxnbr_fd(int	n, int fd, int maj)
{
	long int	quotient;
	char		hexadecimalNumber[100];
	int			temp;
	int			i;

	quotient = (long int)n;
	i = 1;
	while(quotient!=0) 
	{
		temp = quotient % 16;
		if( temp < 10)
			temp = temp + 48; 
		else
			temp = temp + 87 - (32 * maj);
		hexadecimalNumber[i++]= temp;
		quotient = quotient / 16;
	}
	while (--i)
		ft_putchar_fd(hexadecimalNumber[i], fd);//write()
}


// int main() {
// 	long int decimalNumber,quotient;
// 	int i=1,j,temp;
// 	char hexadecimalNumber[100];
// 	printf("Enter any decimal number: ");
// 	scanf("%ld",&decimalNumber);
// 	quotient = decimalNumber;
	
// 	while(quotient!=0) {
// 		temp = quotient % 16;
// 		//To convert integer into character
// 		if( temp < 10)
// 			temp =temp + 48; 
// 		else
// 			temp = temp + 55;
// 		hexadecimalNumber[i++]= temp;
// 		quotient = quotient / 16;
// 	}
// 	printf("Equivalent hexadecimal value of decimal number %d: ",decimalNumber);
// 	for (j = i -1 ;j> 0;j--)
// 		printf("%c",hexadecimalNumber[j]);
// 	return 0;
// }