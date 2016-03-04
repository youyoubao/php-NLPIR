dnl $Id$
dnl config.m4 for extension nlpir

dnl PHP Extension wrapper for NLPIR, a nature language
dnl process tool pack.

PHP_ARG_ENABLE(nlpir, whether to enable nlpir support,
dnl Make sure that the comment is aligned:
[  --enable-nlpir           Enable nlpir support])

if test "$PHP_NLPIR" != "no"; then
  dnl Check if bundled NLPIR is complete.

  # --enable-nlpir -> check with-path
  PHP_ADD_INCLUDE(./NLPIR/include)

  # --enable-nlpir -> check for lib and symbol presence
  LIBNAME=nlpir # you may want to change this
  LIBSYMBOL=nlpir # you most likely want to change this 

  PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  [
    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, ./NLPIR/lib, NLPIR_SHARED_LIBADD)
    AC_DEFINE(HAVE_NLPIRLIB,1,[ ])
  ],[
    AC_MSG_ERROR([wrong nlpir lib version or lib not found])
  ],[
    -L./NLPIR/lib -lm
  ])

  CFLAGS="-Wall -pthread $CFLAGS"
  LDFLAGS="$LDFLAGS -lpthread"
  CPPFLAGS="$CPPFLAGS -DOS_LINUX -lNLPIR"

  PHP_SUBST(NLPIR_SHARED_LIBADD)

  PHP_NEW_EXTENSION(nlpir, nlpir.c, $ext_shared)
fi
