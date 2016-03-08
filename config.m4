dnl $Id$
dnl config.m4 for extension nlpir

dnl PHP Extension wrapper for NLPIR, a nature language
dnl process tool pack.

PHP_ARG_ENABLE(nlpir, whether to enable nlpir support,
dnl Make sure that the comment is aligned:
[  --enable-nlpir           Enable nlpir support])

if test "$PHP_NLPIR" != "no"; then
  dnl Check if bundled NLPIR is complete.
  PHP_REQUIRE_CXX()

  # --enable-nlpir -> check for lib and symbol presence
  LIBNAME=NLPIR64 # you may want to change this
  LIBSYMBOL=NLPIR_Exit # you most likely want to change this 

  CPPFLAGS="$CPPFLAGS -DOS_LINUX"

  PHP_CHECK_LIBRARY($LIBNAME, $LIBSYMBOL,
  [
    PHP_ADD_INCLUDE(./NLPIR/include)
    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, ./NLPIR/lib, NLPIR_SHARED_LIBADD)
    AC_DEFINE(HAVE_NLPIRLIB,1,[Whether NLPIR support is present and requested])
  ],[
    AC_MSG_ERROR([Wrong NLPIR lib version or lib not found])
  ],[
    -pthread -L./NLPIR/lib -lm
  ])

  PHP_SUBST(NLPIR_SHARED_LIBADD)

  PHP_NEW_EXTENSION(nlpir, nlpir.cc, $ext_shared)
fi
