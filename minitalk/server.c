/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:46:57 by tlai              #+#    #+#             */
/*   Updated: 2024/03/13 19:50:10 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Server
/*
man signal: 
"the signal()function allows for a signal to be caught...""
*/

/*
The line i = i | 1; is performing a bitwise OR operation on i + the integer 1.

OR operation: each bit of the 1. operand compared with corresponding bit of 2. operand. 
If either bit is 1, the corresponding result bit is set to 1.

In this case, the operation is ensuring that the least significant bit 
(the rightmost bit) of i is set to 1, 
because 1 in binary is represented as 00000001.

Here's an example:

If i was 4 (which is 0100 in binary), after i = i | 1;, 
	i would be 5 (which is 0101 in binary).
If i was 5 (which is 0101 in binary), after i = i | 1;, 
	i would still be 5.
So, this operation is effectively setting the least significant bit of i to 1, 
regardless of its previous value.
*/

void sig_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("SIG1 received");
	else if (signum == SIGUSR2)
		ft_printf("SIG2 received");
}

int	main(void)
{
	struct sigaction sa;
	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	int	pid;

	pid = getpid();
	ft_printf("The server PID is: %d\n", pid);

	if (sigaction(SIGINT, &sa, NULL) == -1)
		ft_printf("Error");
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

// void	bit_sig(int sig)
// {
// 	static int	i = 0;
// 	static int	bits = 0;
// 	char		c;

// 	if (sig == SIGUSR1 || sig == SIGUSR2)
// 	{
// 		i = i << 1;
// 		if (sig == SIGUSR1)
// 			i = i | 1;
// 		bits++;
// 		if (bits == 8)
// 		{
// 			c = (char)i;
// 			if (c == '\0')
// 				write(1, " ", 1);
// 			else
// 				write(1, &c, 1);
// 			bits = 0;
// 			i = 0;
// 		}
// 	}
// }

// int	main(void)
// {
// 	int	pid;

// 	pid = getpid();
// 	ft_printf("The server PID is: %d\n", pid);
// 	signal(SIGUSR1, bit_sig);
// 	signal(SIGUSR2, bit_sig);
// 	while (1)
// 		pause();
// 	return (0);
// }

/*
1. The bit_sig function is defined to handle signals. It has two static variables i and bits. 
i is used to store the binary value of the character being received, 
and bits keeps track of how many bits have been received.

2. When a SIGUSR1 or SIGUSR2 signal is received, 
i is shifted left by one bit (which is like multiplying it by 2), 
and if the signal was SIGUSR1, a 1 is added to i. 
This effectively constructs the binary representation of a character bit by bit, 
with SIGUSR1 representing a 1 bit and SIGUSR2 representing a 0 bit.

3.After 8 bits have been received (which is the size of a char in C), 
the binary value stored in i is converted to a char and assigned to c. 
If c is the null character ('\0'), a space is written to the standard output. 
Otherwise, c is written to the standard output. Then bits and i are reset to 0 to prepare for the next character.

4. In the main function, the process ID of the server is printed to the standard output. 
Then the bit_sig function is set as the handler for SIGUSR1 and SIGUSR2 signals. 
Finally, the server enters an infinite loop where it pauses until it receives a signal.
*/