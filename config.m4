dnl $Id$
dnl config.m4 for extension nlpir

dnl PHP Extension wrapper for NLPIR, a nature language
dnl process tool pack.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(nlpir, for nlpir support,
dnl Make sure that the comment is aligned:
dnl [  --with-nlpir             Include nlpir support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(nlpir, whether to enable nlpir support,
dnl Make sure that the comment is aligned:
[  --enable-nlpir           Enable nlpir support])

if test "$PHP_NLPIR" != "no"; then
  dnl Write more examples of tests here...

  # --with-nlpir -> check with-path
  SEARCH_PATH="/usr/local /usr"     # you might want to change this
  SEARCH_FOR="/include/nlpir.h"  # you most likely want to change this
  if test -r $PHP_NLPIR/$SEARCH_FOR; then # path given as parameter
    NLPIR_DIR=$PHP_NLPIR
  else # search default path list
    AC_MSG_CHECKING([for nlpir files in default path])
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        NLPIR_DIR=$i
        AC_MSG_RESULT(found in $i)
      fi
    done
  fi
  dnl
  if test -z "$NLPIR_DIR"; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Please reinstall the nlpir distribution])
  fi

  # --with-nlpir -> add include path
  PHP_ADD_INCLUDE($NLPIR_DIR/include)

  # --with-nlpir -> check for lib and symbol presence
  LIBNAME=nlpir # you may want to change this
  LIBSYMBOL=nlpir # you most likely want to change this 

  PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  [
    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $NLPIR_DIR/$PHP_LIBDIR, NLPIR_SHARED_LIBADD)
    AC_DEFINE(HAVE_NLPIRLIB,1,[ ])
  ],[
    AC_MSG_ERROR([wrong nlpir lib version or lib not found])
  ],[
    -L$NLPIR_DIR/$PHP_LIBDIR -lm
  ])

  CFLAGS="-Wall -pthread $CFLAGS"
  LDFLAGS="$LDFLAGS -lpthread"
  CPPFLAGS="$CPPFLAGS -DOS_LINUX -lNLPIR"

  PHP_SUBST(NLPIR_SHARED_LIBADD)

  PHP_NEW_EXTENSION(nlpir, nlpir.c, $ext_shared)
fi
