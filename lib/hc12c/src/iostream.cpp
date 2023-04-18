/*****************************************************

     iostream.cpp - ANSI-C++ library: iostreams
 ----------------------------------------------------
   Copyright (c) Metrowerks, Basel, Switzerland
               
                  Do not modify!
 *****************************************************/

/* This is part of libio/iostream, providing -*- C++ -*- input/output.
Copyright (C) 1993 Free Software Foundation

This file is part of the GNU IO Library.  This library is free
software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option)
any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this library; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

As a special exception, if you link this library with files
compiled with a GNU compiler to produce an executable, this does not cause
the resulting executable to be covered by the GNU General Public License.
This exception does not however invalidate any other reasons why
the executable file might be covered by the GNU General Public License. */

/* Written by Per Bothner (bothner@cygnus.com). */

#ifdef __GNUC__
#pragma implementation
#endif
//#define _STREAM_COMPAT

#include "comp.h"
#include <iostream.h>
#include "libiop.h"
#include <stdio.h>  /* Needed for sprintf */
#include <ctype.h>
#include "cstring.h"
#include <limits.h>
#include "floatio.h"

#ifdef _LIMITATION_XA
#include <string.h>
#endif

#define BUF   (MAXEXP+MAXFRACT+1) /* + decimal point */

//#define isspace(ch) ((ch)==' ' || (ch)=='\t' || (ch)=='\n')

istream::istream(streambuf *sb, ostream* tied)
{
  init (sb, tied);
  _gcount = 0;
}

int skip_ws(streambuf* sb)
{
    int ch;
    for (;;) {
  ch = sb->sbumpc();
  if (ch == EOF || !isspace(ch))
      return ch;
    }
}

istream& istream::get(char& c)
{
    if (ipfx1()) {
  int ch = _strbuf->sbumpc();
  if (ch == EOF) {
    set(ios::eofbit|ios::failbit);
    _gcount = 0;
  }
  else {
    c = (char)ch;
    _gcount = 1;
  }
    }
    else
      _gcount = 0;
    return *this;
}

int istream::peek()
{
  if (!good())
    return EOF;
  if (_tie && rdbuf()->in_avail() == 0)
    _tie->flush();
  int ch = _strbuf->sgetc();    
  if (ch == EOF)
    set(ios::eofbit);
  return ch;
}

istream& istream::ignore(int n /* = 1 */, int delim /* = EOF */)
{
    _gcount = 0;
    if (ipfx1()) {
  register streambuf* sb = _strbuf;
  if (delim == EOF) {
      _gcount = sb->ignore(n);
      return *this;
  }
  for (;;) {
#if 0
      if (n != MAXINT) // FIXME
#endif
      if (--n < 0)
    break;
      int ch = sb->sbumpc();
      if (ch == EOF) {
    set(ios::eofbit|ios::failbit);
    break;
      }
      _gcount++;
      if (ch == delim)
    break;
  }
    }
    return *this;
}

#if __S12LISA__
istream& istream::read(char *s , long int n )
#else
istream& istream::read(char *s , streamsize n )
#endif
{
    if (ipfx1()) {
  _gcount = _strbuf->sgetn(s, n);
  if (_gcount != n)
      set(ios::failbit|ios::eofbit);
    }
    else
      _gcount = 0;
    return *this;
}

int istream::sync ()
{
  streambuf *sb = rdbuf ();
  if (sb == NULL)
    return EOF;
  if (sb->sync ()) // Later: pubsync
    {
      setstate (ios::badbit);
      return EOF;
    }
  else
    return 0;
}

istream& istream::seekg(streampos pos)
{
    pos = _strbuf->pubseekpos(pos, ios::in);
#ifndef _NYI_ALTERNATIVE_CASTING    
    if (pos == streampos(EOF))
#else
    if (pos == (streampos)(EOF))
#endif    
  set(ios::badbit);
    return *this;
}

istream& istream::seekg(streamoff off, _seek_dir dir)
{
  streampos pos = _IO_seekoff (_strbuf, off, (int) dir, _IOS_INPUT);
#ifndef _NYI_ALTERNATIVE_CASTING      
  if (pos == streampos(EOF))
#else
  if (pos == (streampos)(EOF))
#endif
    set(ios::badbit);
  return *this;
}

streampos istream::tellg()
{
#if 0
    streampos pos = _strbuf->pubseekoff(0, ios::cur, ios::in);
#else
    streampos pos = _IO_seekoff (this->_strbuf, 0, _IO_seek_cur, _IOS_INPUT);
#endif
#ifndef _NYI_ALTERNATIVE_CASTING      
    if (pos == streampos(EOF))
#else
    if (pos == (streampos)(EOF))
#endif
  set(ios::badbit);
    return pos;
}

istream& istream::operator>>(char& c)
{
#ifdef _C_LIB_LIMIT_IMPL
    if(this==(istream*)&cin) {
      char str[2];
      str[0]=c;
      str[1]='\0';
      scanf("%s", str);
      return *this;
    }
#endif
    if (ipfx0()) {
  int ch = _strbuf->sbumpc();
  if (ch == EOF)
      set(ios::eofbit|ios::failbit);
  else
      c = (char)ch;
    }
    return *this;
}

istream&
istream::operator>> (char* ptr)
{
#ifdef _C_LIB_LIMIT_IMPL
    if(this==(istream*)&cin) {
      scanf("%s", ptr);
      return *this;
    }
#endif

  register char *p = ptr;
  int w = width(0);
  if (ipfx0())
    {
      register streambuf* sb = _strbuf;
      for (;;)
  {
    int ch = sb->sbumpc();
    if (ch == EOF)
      {
        set(ios::eofbit);
        break;
      }
    else if (isspace(ch) || w == 1)
      {
        sb->sputbackc(ch);
        break;
      }
    else *p++ = ch;
    w--;
  }
      if (p == ptr)
  set(ios::failbit);
    }
  *p = '\0';
  return *this;
}

#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define LONGEST long long
#else
#define LONGEST long
#endif

static int read_int(istream& stream, unsigned LONGEST& val, int& neg)
{
    if (!stream.ipfx0())
      return 0;
    register streambuf* sb = stream.rdbuf();
    int base = 10;
    int ndigits = 0;
    register int ch = skip_ws(sb);
    if (ch == EOF)
  goto eof_fail;
    neg = 0;
    if (ch == '+') {
  ch = skip_ws(sb);
    }
    else if (ch == '-') {
  neg = 1;
  ch = skip_ws(sb);
    }
    if (ch == EOF) goto eof_fail;
    if (!(stream.flags() & ios::basefield)) {
  if (ch == '0') {
      ch = sb->sbumpc();
      if (ch == EOF) {
    val = 0;
    return 1;
      }
      if (ch == 'x' || ch == 'X') {
    base = 16;
    ch = sb->sbumpc();
    if (ch == EOF) goto eof_fail;
      }
      else {
    sb->sputbackc(ch);
    base = 8;
    ch = '0';
      }
  }
    }
    else if ((stream.flags() & ios::basefield) == ios::hex)
  base = 16;
    else if ((stream.flags() & ios::basefield) == ios::oct)
  base = 8;
    val = 0;
    for (;;) {
  if (ch == EOF)
      break;
  int digit;
  if (ch >= '0' && ch <= '9')
      digit = ch - '0';
  else if (ch >= 'A' && ch <= 'F')
      digit = ch - 'A' + 10;
  else if (ch >= 'a' && ch <= 'f')
      digit = ch - 'a' + 10;
  else
      digit = 999;
  if (digit >= base) {
      sb->sputbackc(ch);
      if (ndigits == 0)
    goto fail;
      else
    return 1;
  }
  ndigits++;
  val = base * val + digit;
  ch = sb->sbumpc();
    }
    return 1;
  fail:
    stream.set(ios::failbit);
    return 0;
  eof_fail:
    stream.set(ios::failbit|ios::eofbit);
    return 0;
}

#ifdef _C_LIB_LIMIT_IMPL
#define READ_INT(TYPE) \
istream& istream::operator>>(TYPE& i)\
{\
    if(this==(istream*)&cin) {\
      scanf("%d", i);\
      return *this;\
    }\
    unsigned LONGEST val; int neg;\
    if (read_int(*this, val, neg)) {\
  if (neg) val = -val;\
  i = (TYPE)val;\
    }\
    return *this;\
}
#else
#define READ_INT(TYPE) \
istream& istream::operator>>(TYPE& i)\
{\
    unsigned LONGEST val; int neg;\
    if (read_int(*this, val, neg)) {\
  if (neg) val = -val;\
  i = (TYPE)val;\
    }\
    return *this;\
}
#endif


READ_INT(short)
READ_INT(unsigned short)
READ_INT(int)
READ_INT(unsigned int)
READ_INT(long)
READ_INT(unsigned long)
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
READ_INT(long long)
READ_INT(unsigned long long)
#endif
#if _G_HAVE_BOOL
READ_INT(bool)
#endif

#if !defined(_NYI_LONG_DOUBLE)
istream& istream::operator>>(long double& x)
{
    if (ipfx0())
  scan("%lg", &x);
    return *this;
}
#endif

istream& istream::operator>>(double& x)
{
#ifdef _C_LIB_LIMIT_IMPL
    if(this==(istream*)&cin) {
      scanf("%f", x);
      return *this;
    }
#endif
    if (ipfx0())
  scan("%lg", &x);
    return *this;
}

istream& istream::operator>>(float& x)
{
#ifdef _C_LIB_LIMIT_IMPL
    if(this==(istream*)&cin) {
      scanf("%f", x);
      return *this;
    }
#endif
    if (ipfx0())
  scan("%g", &x);
    return *this;
}

istream& istream::operator>>(register streambuf* sbuf)
{
#ifdef _C_LIB_LIMIT_IMPL
    if(this==(istream*)&cin) {
      scanf("%s", sbuf->_IO_read_ptr);
      return *this;
    }
//  char* _IO_read_ptr; /* Current read pointer */
//  char* _IO_read_end; /* End of get area. */
#endif
    if (ipfx0()) {
  register streambuf* inbuf = rdbuf();
  // FIXME: Should optimize!
  for (;;) {
      register int ch = inbuf->sbumpc();
      if (ch == EOF) {
    set(ios::eofbit);
    break;
      }
      if (sbuf->sputc(ch) == EOF) {
    set(ios::failbit);
    break;
      }
  }
    }
    return *this;
}

#if !defined(_NYI_PLAIN_CHAR)
ostream& ostream::operator<<(char c)
#else
ostream& ostream::operator<<(signed char c)
#endif
{
#ifdef _C_LIB_LIMIT_IMPL
    char str[2];
    str[0]=c;
    str[1]='\0';
    if(this==(ostream*)&cout || this==(ostream*)&cerr || this==(ostream*)&clog) {
      printf("%s", str);
      return *this;
    }
#endif
    if (opfx()) {
#if 1
  // This is what the cfront implementation does.
  if (_strbuf->sputc(c) == EOF)
    goto failed;
#else
  // This is what cfront documentation and current ANSI drafts say.
  int w = width(0);
  char fill_char = fill();
  register int padding = w > 0 ? w - 1 : 0;
  register streambuf *sb = _strbuf;
  if (!(flags() & ios::left) && padding) // Default adjustment.
      if (_IO_padn(sb, fill_char, padding) < padding)
        goto failed;
  if (sb->sputc(c) == EOF)
    goto failed;
  if (flags() & ios::left && padding) // Left adjustment.
      if (_IO_padn(sb, fill_char, padding) < padding)
        goto failed;
#endif
  osfx();
    }
    return *this;
  failed:
    set(ios::badbit);
    osfx();
    return *this;
}

/* Write VAL on STREAM.
   If SIGN<0, val is the absolute value of a negative number.
   If SIGN>0, val is a signed non-negative number.
   If SIGN==0, val is unsigned. */

static void write_int(ostream& stream, unsigned LONGEST val, int sign)
{
#define WRITE_BUF_SIZE (10 + sizeof(unsigned LONGEST) * 3)
    char buf[WRITE_BUF_SIZE];
    register char *buf_ptr = buf+WRITE_BUF_SIZE; // End of buf.
    char *show_base = "";
    int show_base_len = 0;
    int show_pos = 0; // If 1, print a '+'.

    // Now do the actual conversion, placing the result at the *end* of buf.
    // Note that we use separate code for decimal, octal, and hex,
    // so we can divide by optimizable constants.
    if ((stream.flags() & ios::basefield) == ios::oct) { // Octal
  do {
      *--buf_ptr = (val & 7) + '0';
      val = val >> 3;
  } while (val != 0);
  if ((stream.flags() & ios::showbase) && (*buf_ptr != '0'))
      *--buf_ptr = '0';
    }
    else if ((stream.flags() & ios::basefield) == ios::hex) { // Hex
#if __S12LISA__	
  char *xdigs = (char *)((stream.flags() & ios::uppercase) ? "0123456789ABCDEF0X" : "0123456789abcdef0x");
#else
   char *xdigs = (stream.flags() & ios::uppercase) ? "0123456789ABCDEF0X"
      : "0123456789abcdef0x";
#endif 
  do {
      *--buf_ptr = xdigs[val & 15];
      val = val >> 4;
  } while (val != 0);
  if ((stream.flags() & ios::showbase)) {
      show_base = xdigs + 16; // Either "0X" or "0x".
      show_base_len = 2;
  }
    }
    else { // Decimal
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
  // Optimization:  Only use long long when we need to.
  while (val > UINT_MAX) {
      *--buf_ptr = (val % 10) + '0';
      val /= 10;
  }
  // Use more efficient (int) arithmetic for the rest.
  register unsigned int ival = (unsigned int)val;
#else
  register unsigned LONGEST ival = val;
#endif
  do {
      *--buf_ptr = (ival % 10) + '0';
      ival /= 10;
  } while (ival != 0);
  
  if (sign > 0 && (stream.flags() & ios::showpos))
    show_pos=1;
  }
    int buf_len = buf+WRITE_BUF_SIZE - buf_ptr;
    int w = stream.width(0);

    // Calculate padding.
    int len = buf_len+show_pos;
    if (sign < 0) len++;
    len += show_base_len;
    int padding = len > w ? 0 : w - len;

    // Do actual output.
    register streambuf* sbuf = stream.rdbuf();
    ios::fmtflags pad_kind =
  stream.flags() & (ios::left|ios::right|ios::internal);
    char fill_char = stream.fill();
    if (padding > 0
  && pad_kind != (ios::fmtflags)ios::left
  && pad_kind != (ios::fmtflags)ios::internal) // Default (right) adjust.
  if (_IO_padn(sbuf, fill_char, padding) < padding)
    goto failed;
    if (sign < 0 || show_pos)
      {
  char ch = sign < 0 ? '-' : '+';
  if (sbuf->sputc(ch) < 0)
    goto failed;
      }
    if (show_base_len)
#ifdef _LIMITATION_HC05
  exit(1);
#else
  if (_IO_sputn(sbuf, show_base, show_base_len) <= 0)
    goto failed;
#endif
    if (pad_kind == (ios::fmtflags)ios::internal && padding > 0)
      if (_IO_padn(sbuf, fill_char, padding) < padding)
  goto failed;
#ifdef _LIMITATION_HC05
  exit(1);
#else
    if (_IO_sputn (sbuf, buf_ptr, buf_len) != buf_len)
      goto failed;
#endif
    if (pad_kind == (ios::fmtflags)ios::left && padding > 0) // Left adjustment
      if (_IO_padn(sbuf, fill_char, padding) < padding)
  goto failed;
    stream.osfx();
    return;
  failed:
    stream.set(ios::badbit);
    stream.osfx();
}

ostream& ostream::operator<<(int n)
{
#ifdef _C_LIB_LIMIT_IMPL
    if(this==(ostream*)&cout || this==(ostream*)&cerr || this==(ostream*)&clog) {
      printf("%d", n);
      return *this;
    }
#endif
    if (opfx()) {
  int sign = 1;
  unsigned int abs_n = (unsigned)n;
  if (n < 0 && (flags() & (ios::oct|ios::hex)) == 0)
      abs_n = -((unsigned)n), sign = -1;
  write_int(*this, abs_n, sign);
    }
    return *this;
}

ostream& ostream::operator<<(unsigned int n)
{
#ifdef _C_LIB_LIMIT_IMPL
    if(this==(ostream*)&cout || this==(ostream*)&cerr || this==(ostream*)&clog) {
      printf("%u", n);
      return *this;
    }
#endif
    if (opfx()) {
      write_int(*this, n, 0);
    }
    return *this;
}


ostream& ostream::operator<<(long n)
{
#ifdef _C_LIB_LIMIT_IMPL
    if(this==(ostream*)&cout || this==(ostream*)&cerr || this==(ostream*)&clog) {
      printf("%ld", n);
      return *this;
    }
#endif
    if (opfx()) {
  int sign = 1;
  unsigned long abs_n = (unsigned long)n;
  if (n < 0 && (flags() & (ios::oct|ios::hex)) == 0)
      abs_n = -((unsigned long)n), sign = -1;
  write_int(*this, abs_n, sign);
    }
    return *this;
}

ostream& ostream::operator<<(unsigned long n)
{
#ifdef _C_LIB_LIMIT_IMPL
    if(this==(ostream*)&cout || this==(ostream*)&cerr || this==(ostream*)&clog) {
      printf("%lu", n);
      return *this;
    }
#endif
    if (opfx()) {
  write_int(*this, n, 0);
    }
    return *this;
}

#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
ostream& ostream::operator<<(long long n)
{
    if (opfx()) {
  int sign = 1;
  unsigned long long abs_n = (unsigned long long)n;
  if (n < 0 && (flags() & (ios::oct|ios::hex)) == 0)
      abs_n = -((unsigned long long)n), sign = -1;
  write_int(*this, abs_n, sign);
    }
    return *this;
}


ostream& ostream::operator<<(unsigned long long n)
{
    if (opfx())
  write_int(*this, n, 0);
    return *this;
}
#endif /*__GNUC__*/

ostream& ostream::operator<<(double n)
{
#ifdef _C_LIB_LIMIT_IMPL
    if(this==(ostream*)&cout || this==(ostream*)&cerr || this==(ostream*)&clog) {
      printf("%f", n);
      return *this;
    }
#endif

    if (opfx()) {
  // Uses __cvt_double (renamed from static cvt), in Chris Torek's
  // stdio implementation.  The setup code uses the same logic
  // as in __vsbprintf.C (also based on Torek's code).
  int format_char;
  if ((flags() & ios::floatfield) == ios::fixed)
      format_char = 'f';  
  else if ((flags() & ios::floatfield) == ios::scientific)
      format_char = flags() & ios::uppercase ? 'E' : 'e';
  else
      format_char = flags() & ios::uppercase ? 'G' : 'g';
  int prec = precision();
  if (prec <= 0 && !(flags() & ios::fixed))
    prec = 6; /* default */


  // Do actual conversion.
#ifdef _IO_USE_DTOA
  if (_IO_outfloat(n, rdbuf(), format_char, width(0),
       prec, flags(),
       flags() & ios::showpos ? '+' : 0,
       fill()) < 0)
      set(ios::badbit|ios::failbit); // ??
#else
  int fpprec = 0; // 'Extra' (suppressed) floating precision.
  if (prec > MAXFRACT) {
      if (flags() & (ios::fixed|ios::scientific) & ios::showpos)
    fpprec = prec - MAXFRACT;
      prec = MAXFRACT;
  }
  int negative;
  char buf[BUF];
  int sign = '\0';
  char *cp = buf;
  *cp = 0;
  int size = __cvt_double(n, prec,
        flags() & ios::showpoint ? 0x80 : 0,
        &negative,
        format_char, cp, buf + sizeof(buf));
  if (negative) sign = '-';
  else if (flags() & ios::showpos) sign = '+';
  if (*cp == 0)
      cp++;

  // Calculate padding.
  int fieldsize = size + fpprec;
  if (sign) fieldsize++;
  int padding = 0;
  int w = width(0);
  if (fieldsize < w)
      padding = w - fieldsize;

  // Do actual output.
  register streambuf* sbuf = rdbuf();
  register i;
  char fill_char = fill();
  ios::fmtflags pad_kind =
      flags() & (ios::left|ios::right|ios::internal);
  if (pad_kind != (ios::fmtflags)ios::left // Default (right) adjust.
      && pad_kind != (ios::fmtflags)ios::internal)
      for (i = padding; --i >= 0; ) sbuf->sputc(fill_char);
  if (sign)
      sbuf->sputc(sign);
  if (pad_kind == (ios::fmtflags)ios::internal)
      for (i = padding; --i >= 0; ) sbuf->sputc(fill_char);
  
  // Emit the actual concented field, followed by extra zeros.
  _IO_sputn (sbuf, cp, size);
  for (i = fpprec; --i >= 0; ) sbuf->sputc('0');

  if (pad_kind == (ios::fmtflags)ios::left) // Left adjustment
      for (i = padding; --i >= 0; ) sbuf->sputc(fill_char);
#endif
  osfx();
    }
  return *this;
}

ostream& ostream::operator<<(const char*_LIBDEF_FAR_CPP_PTR s)
{
#ifdef _C_LIB_LIMIT_IMPL
    if(this==(ostream*)&cout || this==(ostream*)&cerr || this==(ostream*)&clog) {
      printf("%s", s);
      return *this;
    }
#endif
  if (opfx())
    {
      if (s == NULL)
  s = "(null)";
      int len = strlen(s);
// FIXME: Should we: if (w && len>w) len = w;
      int w = width(0);
      char fill_char = fill();
      register streambuf *sbuf = rdbuf();
      register int padding = w > len ? w - len : 0;
      if (!(flags() & ios::left) && padding > 0) // Default adjustment.
  if (_IO_padn(sbuf, fill_char, padding) != padding)
    goto failed;
      if (_IO_sputn (sbuf, s, len) != len)
  goto failed;
      if (flags() & ios::left && padding > 0) // Left adjustment.
  if (_IO_padn(sbuf, fill_char, padding) != padding)
    goto failed;
      osfx();
    }
  return *this;
 failed:
  set(ios::badbit);
  osfx();
  return *this;
}

#if 0
ostream& ostream::operator<<(const void *p)
{ Is in osform.cc, to avoid pulling in all of _IO_vfprintf by this file. */ }
#endif

ostream& ostream::operator<<(register streambuf* sbuf)
{
#ifdef _C_LIB_LIMIT_IMPL
    if(this==(ostream*)&cout || this==(ostream*)&cerr || this==(ostream*)&clog) {
      printf("%s", sbuf->_IO_write_ptr);
      return *this;
    }
//  char* _IO_write_base; /* Start of put area. */
//  char* _IO_write_ptr;  /* Current put pointer. */
#endif
  if (opfx())
    {
      char buffer[_IO_BUFSIZ];
      register streambuf* outbuf = _strbuf;
      for (;;)
  {
    _IO_size_t count = _IO_sgetn(sbuf, buffer, _IO_BUFSIZ);
    if (count <= 0)
      break;
#ifdef _LIMITATION_HC05
  exit(1);
#else
    if (_IO_sputn(outbuf, buffer, count) != count)
      {
        set(ios::badbit);
        break;
      }
#endif
  }
      osfx();
    }
  return *this;
}

ostream::ostream(streambuf* sb, ostream* tied)
{
  init (sb, tied);
}

ostream& ostream::seekp(streampos pos)
{
    pos =_strbuf->pubseekpos(pos, ios::out);
#ifndef _NYI_ALTERNATIVE_CASTING
    if (pos == streampos(EOF))
#else
    if (pos == (streampos)EOF)
#endif
  set(ios::badbit);
    return *this;
}

ostream& ostream::seekp(streamoff off, _seek_dir dir)
{
  streampos pos = _IO_seekoff (_strbuf, off, (int) dir, _IOS_OUTPUT);
#ifndef _NYI_ALTERNATIVE_CASTING
    if (pos == streampos(EOF))
#else
    if (pos == (streampos)EOF)
#endif
  set(ios::badbit);
  return *this;
}

streampos ostream::tellp()
{
#if 1
    streampos pos = _IO_seekoff (_strbuf, 0, _IO_seek_cur, _IOS_OUTPUT);
#else
    streampos pos = _strbuf->pubseekoff(0, ios::cur, ios::out);
#endif
#ifndef _NYI_ALTERNATIVE_CASTING
    if (pos == streampos(EOF))
#else
    if (pos == (streampos)EOF)
#endif
  set(ios::badbit);
    return pos;
}

ostream& ostream::flush()
{
    if (_strbuf->sync())
  set(ios::badbit);
    return *this;
}

ostream& flush(ostream& outs)
{
  return outs.flush();
}

istream& ws(istream& ins)
{
    if (ins.ipfx1()) {
  int ch = skip_ws(ins._strbuf);
  if (ch == EOF)
      ins.set(ios::eofbit);
  else
      ins._strbuf->sputbackc(ch);
    }
    return ins;
}

// Skip white-space.  Return 0 on failure (EOF), or 1 on success.
// Differs from ws() manipulator in that failbit is set on EOF.
// Called by ipfx() and ipfx0() if needed.

int istream::_skip_ws()
{
    int ch = skip_ws(_strbuf);
    if (ch == EOF) {
  set(ios::eofbit|ios::failbit);
  return 0;
    }
    else {
  _strbuf->sputbackc(ch);
  return 1;
    }
}

#ifdef _C_LIB_LIMIT_IMPL
ostream dummy;
#endif
    
ostream& ends(ostream& outs)
{

#ifdef _C_LIB_LIMIT_IMPL
  if(&outs==(ostream*)&cout) {
    printf("\0");
    return dummy;
  }
#endif

    outs.put('\0');
    return outs;
}

ostream& endl(ostream& outs)
{

#ifdef _C_LIB_LIMIT_IMPL
  if(&outs==(ostream*)&cout) {
    printf("\n");
    return dummy;
  }
#endif

    return flush(outs.put('\n'));
}

ostream& ostream::write(const char*_LIBDEF_FAR_CPP_PTR s, streamsize n)
{
    if (opfx()) {
  if (_IO_sputn(_strbuf, s, n) != n)
  set(ios::failbit);
    }
    return *this;
}

void ostream::do_osfx()
{
    if (flags() & ios::unitbuf)
  flush();
    if (flags() & ios::stdio) {
  fflush(stdout);
  fflush(stderr);
    }
}

iostream::iostream(streambuf* sb, ostream* tied)
{
  ostream::init (sb, tied);
}

// NOTE: extension for compatibility with old libg++.
// Not really compatible with fistream::close().
#ifdef _STREAM_COMPAT
void ios::close()
{
  if (_strbuf->_flags & _IO_IS_FILEBUF)
    ((struct filebuf*)rdbuf())->close();
  else if (_strbuf != NULL)
    rdbuf()->sync();
  _strbuf = NULL;
  _state = badbit;
}

int istream::skip(int i)
{
    int old = (_flags & ios::skipws) != 0;
    if (i)
  _flags |= ios::skipws;
    else
  _flags &= ~ios::skipws;
    return old;
}
#endif

