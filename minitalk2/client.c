/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:47:00 by tlai              #+#    #+#             */
/*   Updated: 2024/03/13 19:52:20 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
PID: Process IDentifier
In the context of operating systems like Unix, Linux, or macOS,
a PID is a unique number that identifies each running process.
This number is used by the system to track the process's state and
manage its resources.

In programming, you might use a PID to interact with specific processes.
For example,
you send signals to a process (like telling it to terminate) using its PID.
*/

#include "minitalk.h"

// client
/*
man kill: send signal to a process
*/

void	send_char(unsigned char c, int pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		usleep(10000);
	}
}

void	send_signals(char *string, int pid)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		send_char(string[i], pid);
		// usleep(1000);
		i++;
	}
	send_char('\0', pid);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac < 3)
	{
		ft_printf("Enter PID and 'whats on your mind':) \n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid == 0)
	{
		ft_printf("Invalid PID \n");
		return (1);
	}
	i = 2;
	while (i < ac)
	{
		send_signals(av[i], pid);
		// usleep(1000);
		i++;
	}
	return (0);
}

/*
Client starts
  |
  v
Gets process ID and strings from command line arguments
  |
  v
For each string:
  |
  v
  For each character in the string:
    |
    v
    send_char function called
      |
      v
      For each bit in the character:
        |
        v
        If bit is 1, send SIGUSR1 signal to server
        |
        v
        If bit is 0, send SIGUSR2 signal to server
        |
        v
      Sleep for 100 microseconds
      |
      v
  Sleep for 1000 microseconds
  |
  v
Send null character to server to indicate end of string
  |
  v
Sleep for 10000 microseconds
  |
  v
Client ends
*/