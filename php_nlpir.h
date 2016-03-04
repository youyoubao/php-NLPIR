/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_NLPIR_H
#define PHP_NLPIR_H

extern zend_module_entry nlpir_module_entry;
#define phpext_nlpir_ptr &nlpir_module_entry

#define PHP_NLPIR_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_NLPIR_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_NLPIR_API __attribute__ ((visibility("default")))
#else
#	define PHP_NLPIR_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(nlpir);
PHP_MSHUTDOWN_FUNCTION(nlpir);
PHP_RINIT_FUNCTION(nlpir);
PHP_RSHUTDOWN_FUNCTION(nlpir);
PHP_MINFO_FUNCTION(nlpir);

PHP_FUNCTION(confirm_nlpir_compiled);	/* For testing, remove later. */
PHP_FUNCTION(NLPIR_Init);
PHP_FUNCTION(NLPIR_Exit);
PHP_FUNCTION(NLPIR_GetLastErrorMsg);
PHP_FUNCTION(NLPIR_ParagraphProcess);
PHP_FUNCTION(NLPIR_ParagraphProcessA);
PHP_FUNCTION(NLPIR_ImportUserDict);
PHP_FUNCTION(NLPIR_FileProcess);
PHP_FUNCTION(NLPIR_AddUserWord);
PHP_FUNCTION(NLPIR_SaveTheUsrDic);
PHP_FUNCTION(NLPIR_DelUsrWord);
PHP_FUNCTION(NLPIR_GetKeyWords);
PHP_FUNCTION(NLPIR_GetFileKeyWords);
PHP_FUNCTION(NLPIR_ImportKeyBlackList);
PHP_FUNCTION(NLPIR_GetNewWords);
PHP_FUNCTION(NLPIR_GetFileNewWords);
PHP_FUNCTION(NLPIR_FingerPrint);
PHP_FUNCTION(NLPIR_SetPOSmap);
PHP_FUNCTION(NLPIR_FinerSegment);
PHP_FUNCTION(NLPIR_GetEngWordOrign);
PHP_FUNCTION(NLPIR_WordFreqStat);
PHP_FUNCTION(NLPIR_FileWordFreqStat);


/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(nlpir)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(nlpir)
*/

/* In every utility function you add that needs to use variables 
   in php_nlpir_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as NLPIR_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define NLPIR_G(v) TSRMG(nlpir_globals_id, zend_nlpir_globals *, v)
#else
#define NLPIR_G(v) (nlpir_globals.v)
#endif

#endif	/* PHP_NLPIR_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
