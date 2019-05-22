/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:31:57 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/13 19:22:39 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <float.h>
#include <math.h>

#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

//#define ARG "|%#o|%#.o|%#o|%0o|%#.5o|%0.5o\"", 0U, 0U, 0U, 0U, 0U, 0U
#define ARG "%.1f", 1.99

int	main(void)
{
	double n = 0.0;
	int a;
	int b;
	char s[10] = "Hello";

	printf("My:\n");
	a = ft_printf(ARG);

	printf("\t\tres: %d\nOriginal:\n", a);

	b = printf(ARG);

	printf("\t\tres: %d\n", b);
	return (0);
}


/*
	  FAIL

Запилить округление
Решить проблему сравнения 0,0 и -0,0 без сравнения битовой маски(ну или с ней :D)


"%#7hho|%-01.5hho", ULLONG_MAX, ULLONG_MAX
"%#.3hho", 1234567


SOLVED Фиксануть пермишен 0!
SOLVED zero padding printf("{%05.s}", 0)
SOLVED 45 - 49  строки в print_di
SOLVED minimum field-width AND precision with NULL   ft_printf("%.2s", s) && ft_printf("%20s", s);
SOLVED На выводе лишний 0 при n = LLONG_MAX ft_printf("%l0.20ld", n) или не хватает 0 при LLONG_MIN
SURRENDER Добавить LL для d
SOLVED Почему IDE влияет на поведение библеотечной функции? (проверь способ компиляции мб тут clang) printf("%LLd", n);
SOLVED Краш где-то на дабл флаге + спецификатор printf("%#0.5lld", n);

*/
