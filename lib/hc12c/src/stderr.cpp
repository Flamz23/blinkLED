/*****************************************************

     stderr.cpp - ANSI-C++ library: error handling
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               
                  Do not modify!
 *****************************************************/


/* Provides a useful variable-length argument error handling abstraction.

   Copyright (C) 1989 Free Software Foundation, Inc.
   written by Douglas C. Schmidt (schmidt@ics.uci.edu)

This file is part of GNU GPERF.

GNU GPERF is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 1, or (at your option)
any later version.

GNU GPERF is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU GPERF; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111, USA.  */

#include "comp.h"
#include <stdio.h>
#include <std.h>
#include <stdarg.h>
#include "stderr.h"
#include "trace.h"

#include <errno.h>
#ifndef errno
extern int errno;
#endif

char * Std_Err::program_name;

/* Sets name of program. */

void 
Std_Err::set_program_name (char *prog_name) 
{ 
  T (Trace t ("Std_Err::set_program_name");)
  program_name = prog_name;
}

/* Valid Options (prefixed by '%', as in printf format strings) include:
   'a': exit the program at this point (var-argument is the exit status!)
   'c': print a character
   'd': print a decimal number
   'e': call the function pointed to by the corresponding argument
   'f','g': print a double
   'n': print the name of the program (NULL if not set in constructor or elsewhere)
   'p': print out the appropriate errno value from sys_errlist
   's': print out a character string
   '%': print out a single percent sign, '%' */

void 
Std_Err::report_error (char *format, ...) 
{ 
  T (Trace t ("Std_Err::report_error");)
  typedef void (*PTF)();
  va_list argp;

  va_start (argp, format);
  for ( ; *format; format++) 
    {
      if (*format != '%') 
#ifndef _C_LIB_LIMIT_PUTC      
        putc (*format, stderr);
#else
        exit(1);
#endif
      else 
        {
          switch (*++format) 
            {
#ifndef _C_LIB_LIMIT_PUTC
            case '%' : putc ('%', stderr); break;
            case 'a' : exit (va_arg (argp, int));
            case 'c' : putc (va_arg (argp, int), stderr); break;
#else
            case '%' : exit(1); break;
            case 'a' : exit (va_arg (argp, int));
            case 'c' : exit(1); break;
#endif
#ifndef _C_LIB_LIMIT_IMPL
            case 'd' : fprintf (stderr, "%d", va_arg (argp, int)); break;
            case 'e' : (*va_arg (argp, PTF))(); break;
#if defined(__MCORE__)
            case 'f' : fprintf (stderr, "%g", va_arg8 (argp, double)); break;
#else
            case 'f' : fprintf (stderr, "%g", va_arg (argp, double)); break;
#endif
            case 'n' : fputs (program_name ? program_name : "error", stderr); break;
            case 'p' : fprintf (stderr, "%s: %s", va_arg (argp, char *), strerror (errno)); break;
            case 's' : fputs (va_arg (argp, char *), stderr); break;
#else
            case 'd' : exit(1); break;
            case 'e' : (*va_arg (argp, PTF))(); break;
            case 'f' : exit(1); break;
            case 'n' : exit(1); break;
            case 'p' : exit(1); break;
            case 's' : exit(1); break;
#endif
            }
        }
    }
  va_end (argp);
}

