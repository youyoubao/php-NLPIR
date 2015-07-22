dnl $Id$
dnl config.m4 for extension nlpir

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

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

  dnl # --with-nlpir -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/nlpir.h"  # you most likely want to change this
  dnl if test -r $PHP_NLPIR/$SEARCH_FOR; then # path given as parameter
  dnl   NLPIR_DIR=$PHP_NLPIR
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for nlpir files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       NLPIR_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$NLPIR_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the nlpir distribution])
  dnl fi

  dnl # --with-nlpir -> add include path
  dnl PHP_ADD_INCLUDE($NLPIR_DIR/include)

  dnl # --with-nlpir -> check for lib and symbol presence
  dnl LIBNAME=nlpir # you may want to change this
  dnl LIBSYMBOL=nlpir # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $NLPIR_DIR/$PHP_LIBDIR, NLPIR_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_NLPIRLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong nlpir lib version or lib not found])
  dnl ],[
  dnl   -L$NLPIR_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(NLPIR_SHARED_LIBADD)

  PHP_NEW_EXTENSION(nlpir, nlpir.c, $ext_shared)
fi
