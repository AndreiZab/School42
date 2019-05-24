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

//#define ARG "|%#o|%#.o|%#o|%0o|%#.5o|%0.5o\"", 0U, 0U, 0U, 0U, 0U, 0U
#define ARG "%f", -123.123

int	main(void)
{
	double n = 0.0;
	int a;
	int b;
	char s[10] = "Hello";

	printf("Original:\n");
	printf("\t\tres: %d\nMy:\n", printf(ARG));
	printf("\t\tres: %d\n", ft_printf(ARG));
	return (0);
}


/*
	  FAIL

??? Norme: ./ft_printf.h Error: global scope bad aligned
Округление чисел кратным степени 2
SURRENDER фейл округления у 20х знаков "%.20f", 1.025978542436587568678

SOLVED В файлу принт_ф s = "inf" или поэлементно
SOLVED Решить проблему сравнения 0,0 и -0,0 без сравнения битовой маски(ну или с ней :D)
SOLVED Добавить определение знака по битам fuck yeah
SOLVED "%07.1f", -7.3
SOLVED Зеро педдинг сломался с - шириной и точностью (решить или пордом вызова функций или починкой печати ширины) "% 05.0f", -7.3
SOLVED Не верное окргугление .0 ввиду того, что p.p = -1 "%.0f", 573.924
SOLVED "%#7hho|%-01.5hho", ULLONG_MAX, ULLONG_MAX
SOLVED "%#.3hho", 1234567 Попробовать пермише >= длинны строки после перевода или переработать структуру вывода :с
SOLVED Фиксануть пермишен 0!
SOLVED Зеро педдинг сломался с - шириной и точностью (решить или пордом вызова функций или починкой печати ширины) "% 05.0f", -7.3
Запилино, правлю баги (SOLVED) Запилить округление
SOLVED zero padding printf("{%05.s}", 0)
SOLVED 45 - 49  строки в print_di
SOLVED minimum field-width AND precision with NULL   ft_printf("%.2s", s) && ft_printf("%20s", s);
SOLVED На выводе лишний 0 при n = LLONG_MAX ft_printf("%l0.20ld", n) или не хватает 0 при LLONG_MIN
SURRENDER Добавить LL для d
SOLVED Почему IDE влияет на поведение библеотечной функции? (проверь способ компиляции мб тут clang) printf("%LLd", n);
SOLVED Краш где-то на дабл флаге + спецификатор printf("%#0.5lld", n);

void    show_binary(void *vptr, int count)
{
	char    *ptr;
	unsigned char    mask;

	ptr = (char*)vptr;
	ptr += count / 8 - 1;
	while (count > 0)
	{

		mask = (1 << 7);
		while (mask != 0 && count > 0)
		{
			if (*ptr & mask)
				ft_putchar('1');
			else
				ft_putchar('0');
			--count;
			mask = mask >> 1;
		}
		--ptr;
	}
}

*/