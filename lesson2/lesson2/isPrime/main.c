#include <stdio.h>
#include <math.h>
int isPrime(int number){
		int flag,limit;
		//0, 1 are not prime numbers
		//2 is a prime
		if(number == 0 || number == 1 || number % 2 == 0) return 0;
		if(number == 2) return 1;
		limit = sqrt(number);
		flag = 1;
		for (int i = 3; i<=limit;i+=2){
			if(number%i==0){flag=0;break;}
		}

		return flag;
	}

int main()
	{
		int userInput = 0;
		do{
			printf("Input not negative integer number:");
			scanf("%d",&userInput);
		}while (userInput<0);

		isPrime(userInput) ? printf("%d - is a prime number\n",userInput) : printf("%d - is not a prime number\n",userInput);
		return 0;
	}
