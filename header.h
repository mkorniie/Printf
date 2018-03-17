/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:34:43 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:34:45 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include "libft/libft.h"

int			N_OF_F;
static char	*convs[] = { "schar*", "Swchar_t*", "pvoid*", "dint",
						"Dlong", "iint", "ounsigned int", "Ounsigned long",
						"uunsigned int", "Uunsigned long", "xunsigned int", "Xunsigned int",
						"cchar", "Cwint_t", "edouble", "Edouble",
						"fdouble", "Fdouble", "gdouble", "Gdouble",
						"adouble", "Adouble", "nint*", NULL};
						 // 0 || (cvs12 14 16 18 20
int			ERROR;
int**		UNISTRINGS;
int			CURR;
void		ft_addustring(void);
int			ft_changewidth(int *flg, char	*res, char x);
int			ft_printf(const char * restrict format, ...);
int			ft_parce(const char * restrict s, char *c, char ***flags);
int			ft_isspecifier(char x);
int			ft_modifpart1(int mod, int cvs);
int			ft_modifpart2(int mod, int cvs);
int			ft_isMod(char *flag);
int			ft_arrlen(char **arr);
int			ft_isvalid(char x);
int			ft_isflag(char *flag, char x);
int			ft_isflag(char *flag, char x);
uintmax_t	ft_powl(long num, long deg);
void		ft_freestrarr(char **split);
void ft_freeintarr(int **split, int len);
int			*ft_widthPres(char *flag, int zeroflag);
int			*ft_findflag(char *flag);
char		*ft_validflag(char *temp);
char		*ft_chartostr(char c);
char		*ft_ubase(uintmax_t src, uintmax_t len, const char *pattern);
char		*ft_unicode(unsigned int src, int flag);
char		*ft_litoa(long n);
char		*ft_ulitoa(unsigned long n);
char		*ft_strjoinfree(char const *s1, char const *s2, int s_to_delete);
char		**ft_convert(va_list	ap, char	**flags);
char		**ft_fieldflags(char **res, char **flags);
char 		*ft_scnv(va_list	ap);
char 		*ft_sccnv(va_list	ap);
char 		*ft_pcnv(va_list	ap);
char 		*ft_dcnv(va_list	ap);
char		*ft_dccnv(va_list	ap);
char		*ft_icnv(va_list	ap);
char		*ft_ocnv(va_list	ap);
char		*ft_occnv(va_list	ap);
char		*ft_ucnv(va_list	ap);
char		*ft_uccnv(va_list	ap);
char		*ft_xcnv(va_list	ap);
char		*ft_xccnv(va_list	ap);
char		*ft_ccnv(va_list	ap);
char		*ft_cccnv(va_list	ap);
char		*ft_ecnv(va_list	ap);
char		*ft_eccnv(va_list	ap);
char		*ft_fcnv(va_list	ap);
char		*ft_fccnv(va_list	ap);
char		*ft_gcnv(va_list	ap);
char		*ft_gccnv(va_list	ap);
char		*ft_acnv(va_list	ap);
char		*ft_accnv(va_list	ap);
char		*ft_ncnv(va_list	ap);
char		*ft_hhocnv(va_list	ap);
char		*ft_hhucnv(va_list	ap);
char		*ft_hhxcnv(va_list	ap);
char		*ft_hhxccnv(va_list	ap);
char		*ft_hdcnv(va_list	ap);
char		*ft_hocnv(va_list	ap);
char		*ft_hucnv(va_list	ap);
char		*ft_hxcnv(va_list	ap);
char		*ft_hxccnv(va_list	ap);
char		*ft_lxcnv(va_list	ap);
char		*ft_lxccnv(va_list	ap);
char		*ft_dintmax_tcnv(va_list	ap);
char		*ft_ouintmax_tcnv(va_list	ap);
char		*ft_uuintmax_tcnv(va_list	ap);
char		*ft_xuintmax_tcnv(va_list	ap);
char		*ft_xcuintmax_tcnv(va_list	ap);
char		*ft_dssize_tcnv(va_list	ap);
char		*ft_osize_tcnv(va_list	ap);
char		*ft_usize_tcnv(va_list	ap);
char		*ft_xsize_tcnv(va_list	ap);
char		*ft_xcsize_tcnv(va_list	ap);
char		*ft_hhdcnv(va_list	ap);

static char	*(*ft_cvs[])(va_list	ap) = { &ft_scnv,			&ft_sccnv,			&ft_pcnv,			&ft_dcnv,
											&ft_dccnv,			&ft_icnv,			&ft_ocnv,			&ft_occnv,
											&ft_ucnv,			&ft_uccnv,			&ft_xcnv,			&ft_xccnv,
											&ft_ccnv,			&ft_cccnv,			&ft_ecnv,			&ft_eccnv,
											&ft_fcnv,			&ft_fccnv,			&ft_gcnv,			&ft_gccnv,
											&ft_acnv,			&ft_accnv,			&ft_ncnv,			&ft_hhocnv,
											&ft_hhucnv,			&ft_hhxcnv,			&ft_hhxccnv,		&ft_hdcnv,
											&ft_hocnv,			&ft_hucnv,			&ft_hxcnv,			&ft_hxccnv, 
											&ft_lxcnv,			&ft_lxccnv,			&ft_dintmax_tcnv,	&ft_ouintmax_tcnv,
											&ft_uuintmax_tcnv,	&ft_xuintmax_tcnv,	&ft_xcuintmax_tcnv,	&ft_dssize_tcnv,
											&ft_osize_tcnv,		&ft_usize_tcnv,		&ft_xsize_tcnv,		&ft_xcsize_tcnv,
											&ft_hhdcnv,			NULL};
char		*ft_zero(char	*res, int wp[2], char x);
char		*ft_hash(char	*res, int wp[2], char x);
char		*ft_leftadj(char	*res, int wp[2], char x);
char		*ft_space(char	*res, int wp[2], char x);
char		*ft_plus(char	*res, int wp[2], char x);
static char	*(*ft_flags[])(char	*res, int wp[2], char x) = {&ft_zero,				&ft_hash,			&ft_space,		&ft_plus,
															&ft_leftadj,		NULL};
#endif
