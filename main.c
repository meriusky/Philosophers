/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehernan <mehernan@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:18:18 by mehernan          #+#    #+#             */
/*   Updated: 2024/05/28 19:17:44 by mehernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h> //substituir per el meu printf
#include <pthread.h>

/*size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}*/

int	ft_atoi(const char *str)
{
	int	count;
	int	num;
	int	sign;

	count = 0;
	num = 0;
	sign = 1;
	while (str[count] == '\t' || str[count] == '\f' || str[count] == '\n'
		|| str[count] == '\r' || str[count] == '\v' || str[count] == ' ')
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign *= -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		num = (num * 10) + (str[count] - '0');
		count++;
	}
	return (num * sign);
}
void	check_num(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] > 47 && str[i] < 58) || str[i] == '-')
			i++;
		else
		{
			printf("Just numbers accepted\n");
			return (1); //quizas hay que poner error especifico
		}
		
	}
//	if (i == ft_strlen(str))
	return (ft_atoi(str));
}
int main(int argc, char *argv[])
{
	int fork;
	int i;
	int	time_to_die;
	int	time_to_sleep;   //mucha variable entiendo que esto no sera asi
	int	time_to_eat;

	i = 0;
	if (argc == 4)
	{
	//	while (argv[i])
	//	{
			fork = check_num(argv[1]);
			if(fork < 2)
			{
				printf("there is not enought philosophers🦉\n")
				return (1); //quizas hay que poner error especifico
			}
			time_to_die = check_num(argv[2]);
			time_to_sleep = check_num(argv[3]);
			time_to_eat = check_num(argv[4]);
			
	//	}
	}
}

/*🎀BENVINGUDA AL MAIN🎀
 * 1. Els arguments variaran entre 4 i 5
 * 		1.1number_of_philosophers
 * 		1.2time_to_die -> si el time to die llega y el filosofo no ha comido...💀
 * 		1.3time_to_sleep -> tiempo que un filosofo duerme
 * 		1.4time_to_eat -> tiempe que un filosofo que tarda en comer un filosofo
 * 		1.5number_of_times_each_philosopher_must_eat
 * 2. Funcio per pasar de caracter a int, molt important ppel temps
 * 3.Potser no cal diferenciar entre els arguments amb el opcional o sense, pero dmeoment els separo
 * */

