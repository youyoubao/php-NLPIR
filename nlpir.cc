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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_nlpir.h"
#include "NLPIR.h"

/* If you declare any globals in php_nlpir.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(nlpir)
*/

/* True global resources - no need for thread safety here */
static int le_nlpir;

/* {{{ nlpir_functions[]
 *
 * Every user visible function must have an entry in nlpir_functions[].
 */
const zend_function_entry nlpir_functions[] = {
    PHP_FE(confirm_nlpir_compiled,    NULL)        /* For testing, remove later. */
    PHP_FE(NLPIR_Init,    NULL)
    PHP_FE(NLPIR_Exit,    NULL)
    PHP_FE(NLPIR_GetLastErrorMsg,    NULL)
    PHP_FE(NLPIR_ParagraphProcess,    NULL)
    PHP_FE(NLPIR_ParagraphProcessA,    NULL)
    PHP_FE(NLPIR_ImportUserDict,    NULL)
    PHP_FE(NLPIR_FileProcess,    NULL)
    PHP_FE(NLPIR_AddUserWord,    NULL)
    PHP_FE(NLPIR_SaveTheUsrDic,    NULL)
    PHP_FE(NLPIR_DelUsrWord,    NULL)
    PHP_FE(NLPIR_GetKeyWords,    NULL)
    PHP_FE(NLPIR_GetFileKeyWords,    NULL)
    PHP_FE(NLPIR_ImportKeyBlackList,    NULL)
    PHP_FE(NLPIR_GetNewWords,    NULL)
    PHP_FE(NLPIR_GetFileNewWords,    NULL)
    PHP_FE(NLPIR_FingerPrint,    NULL)
    PHP_FE(NLPIR_SetPOSmap,    NULL)
    PHP_FE(NLPIR_FinerSegment,    NULL)
    PHP_FE(NLPIR_GetEngWordOrign,    NULL)
    PHP_FE(NLPIR_WordFreqStat,    NULL)
    PHP_FE(NLPIR_FileWordFreqStat,    NULL)
    PHP_FE_END    /* Must be the last line in nlpir_functions[] */
};
/* }}} */

/* {{{ nlpir_module_entry
 */
zend_module_entry nlpir_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    "nlpir",
    nlpir_functions,
    PHP_MINIT(nlpir),
    PHP_MSHUTDOWN(nlpir),
    PHP_RINIT(nlpir),        /* Replace with NULL if there's nothing to do at request start */
    PHP_RSHUTDOWN(nlpir),    /* Replace with NULL if there's nothing to do at request end */
    PHP_MINFO(nlpir),
#if ZEND_MODULE_API_NO >= 20010901
    PHP_NLPIR_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_NLPIR
ZEND_GET_MODULE(nlpir)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("nlpir.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_nlpir_globals, nlpir_globals)
    STD_PHP_INI_ENTRY("nlpir.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_nlpir_globals, nlpir_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_nlpir_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_nlpir_init_globals(zend_nlpir_globals *nlpir_globals)
{
    nlpir_globals->global_value = 0;
    nlpir_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(nlpir)
{
    /* If you have INI entries, uncomment these lines
    REGISTER_INI_ENTRIES();
    */

    // 标注集
    REGISTER_LONG_CONSTANT("NLPIR_POS_MAP_NUMBER", POS_MAP_NUMBER, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("NLPIR_ICT_POS_MAP_FIRST", ICT_POS_MAP_FIRST, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("NLPIR_ICT_POS_MAP_SECOND", ICT_POS_MAP_SECOND, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("NLPIR_PKU_POS_MAP_SECOND", PKU_POS_MAP_SECOND, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("NLPIR_PKU_POS_MAP_FIRST", PKU_POS_MAP_FIRST, CONST_CS | CONST_PERSISTENT);

    // 字符集
    REGISTER_LONG_CONSTANT("NLPIR_GBK_CODE", GBK_CODE, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("NLPIR_UTF8_CODE", UTF8_CODE, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("NLPIR_BIG5_CODE", BIG5_CODE, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("NLPIR_GBK_FANTI_CODE", GBK_FANTI_CODE, CONST_CS | CONST_PERSISTENT);
    REGISTER_LONG_CONSTANT("NLPIR_UTF8_FANTI_CODE", UTF8_FANTI_CODE, CONST_CS | CONST_PERSISTENT);

    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(nlpir)
{
    /* uncomment this line if you have INI entries
    UNREGISTER_INI_ENTRIES();
    */
    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(nlpir)
{
    return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(nlpir)
{
    return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(nlpir)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "nlpir support", "enabled");
    php_info_print_table_end();

    /* Remove comments if you have entries in php.ini
    DISPLAY_INI_ENTRIES();
    */
}
/* }}} */


/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_nlpir_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_nlpir_compiled)
{
    char *arg = NULL;
    int arg_len, len;
    char *strg;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
        return;
    }

    len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "nlpir", arg);
    RETURN_STRINGL(strg, len, 0);
}

PHP_FUNCTION(NLPIR_Init)
{
    const char *dictDir;
    int encoding, slen;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|l", &dictDir, &slen, &encoding) == FAILURE)
    {
        RETURN_NULL();
    }

    if(NLPIR_Init(dictDir, encoding, 0)) {
        RETURN_STRING("SUCCESS", 1);
    } else {
        php_error(E_WARNING, "NLPIR_Init faile !");
        RETURN_STRING("FAIL", 1);
    }
}

PHP_FUNCTION(NLPIR_ParagraphProcess)
{
    const char *inputChar;
    int slen, flag;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|l", &inputChar, &slen, &flag) == FAILURE)
    {
        RETURN_NULL();
    }
    RETURN_STRING(NLPIR_ParagraphProcess(inputChar, flag), 1);
}

PHP_FUNCTION(ParagraphProcessA)
{
    const char *inputChar, *tmpchar;
    const result_t *arrayResult;
    int nCount, i, slen; //结果数量
    zval *aResultT;
    
    array_init(return_value); //返回值是数组

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &inputChar, &slen) == FAILURE)
    {
        RETURN_NULL();
    }
    arrayResult = NLPIR_ParagraphProcessA(inputChar, &nCount, true);
    for (i = 0; i < nCount; i++) {
        MAKE_STD_ZVAL(aResultT);
        array_init(aResultT);
        add_assoc_long(aResultT, "start", arrayResult[i].start);
        add_assoc_long(aResultT, "length", arrayResult[i].length);
        add_assoc_string(aResultT, "sPOS", (char *)(arrayResult[i].sPOS), 1);
        add_assoc_long(aResultT, "iPOS", arrayResult[i].iPOS);
        add_assoc_long(aResultT, "word_ID", arrayResult[i].word_ID);
        add_assoc_long(aResultT, "word_type", arrayResult[i].word_type);
        add_assoc_long(aResultT, "weight", arrayResult[i].weight);
        add_index_zval(return_value, i, aResultT);
    }
}

PHP_FUNCTION(NLPIR_Exit) {
    NLPIR_Exit();
}

PHP_FUNCTION(NLPIR_GetLastErrorMsg) {
    RETURN_STRING(NLPIR_GetLastErrorMsg(), 1);
}

PHP_FUNCTION(NLPIR_ImportUserDict) {
    const char *sFilename;
    int slen;
    zend_bool bOverwrite = 1;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|b", &sFilename, &slen, &bOverwrite) == FAILURE)
    {
        RETURN_NULL();
    }

    RETURN_LONG(NLPIR_ImportUserDict(sFilename, bOverwrite));
}

PHP_FUNCTION(NLPIR_FileProcess) {
    const char *sSourceFilename, *sResultFilename;
    int srclen, sretlen;
    zend_bool bPOStagged = 1;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ss|b", &sSourceFilename, &srclen, &sResultFilename, &sretlen, &bPOStagged) == FAILURE)
    {
        RETURN_NULL();
    }

    RETURN_DOUBLE(NLPIR_FileProcess(sSourceFilename, sResultFilename, bPOStagged));
}

PHP_FUNCTION(NLPIR_AddUserWord) {
    const char *sWord;
    int slen;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &sWord, &slen) == FAILURE)
    {
        RETURN_NULL();
    }

    RETURN_BOOL(NLPIR_AddUserWord(sWord));
}

PHP_FUNCTION(NLPIR_SaveTheUsrDic) {
    RETURN_BOOL(NLPIR_SaveTheUsrDic());
}

PHP_FUNCTION(NLPIR_DelUsrWord) {
    const char *sWord;
    int slen;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &sWord, &slen) == FAILURE)
    {
        RETURN_NULL();
    }

    RETURN_LONG(NLPIR_DelUsrWord(sWord));
}

PHP_FUNCTION(NLPIR_GetKeyWords) {
    const char *sLine;
    int slen;
    long nMaxKeyLimit = 50;
    zend_bool bWeightOut = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|lb", &sLine, &slen, &nMaxKeyLimit, &bWeightOut) == FAILURE)
    {
        RETURN_NULL();
    }

    RETURN_STRING(NLPIR_GetKeyWords(sLine, nMaxKeyLimit, bWeightOut), 1);
}

PHP_FUNCTION(NLPIR_GetFileKeyWords) {
    const char *sFilename;
    int slen;
    long nMaxKeyLimit = 50;
    zend_bool bWeightOut = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|lb", &sFilename, &slen, &nMaxKeyLimit, &bWeightOut) == FAILURE)
    {
        RETURN_NULL();
    }

    RETURN_STRING(NLPIR_GetFileKeyWords(sFilename, nMaxKeyLimit, bWeightOut), 1);
}

PHP_FUNCTION(NLPIR_ImportKeyBlackList) {
    const char *sFilename;
    int slen;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &sFilename, &slen) == FAILURE)
    {
        RETURN_NULL();
    }

    RETURN_LONG(NLPIR_ImportKeyBlackList(sFilename));
}

PHP_FUNCTION(NLPIR_GetNewWords) {
    const char *sLine;
    int slen;
    long nMaxKeyLimit = 50;
    zend_bool bWeightOut = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|lb", &sLine, &slen, &nMaxKeyLimit, &bWeightOut) == FAILURE)
    {
        RETURN_NULL();
    }

    RETURN_STRING(NLPIR_GetNewWords(sLine, nMaxKeyLimit, bWeightOut), 1);
}

PHP_FUNCTION(NLPIR_GetFileNewWords) {
    const char *sFilename;
    int slen;
    long nMaxKeyLimit = 50;
    zend_bool bWeightOut = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|lb", &sFilename, &slen, &nMaxKeyLimit, &bWeightOut) == FAILURE)
    {
        RETURN_NULL();
    }

    RETURN_STRING(NLPIR_GetFileNewWords(sFilename, nMaxKeyLimit, bWeightOut), 1);
}

PHP_FUNCTION(NLPIR_FingerPrint) {
    const char *sLine;
    int slen;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &sLine, &slen) == FAILURE)
    {
        RETURN_NULL();
    }

    RETURN_LONG(NLPIR_FingerPrint(sLine));
}

PHP_FUNCTION(NLPIR_SetPOSmap) {
    long nPOSmap;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &nPOSmap) == FAILURE)
    {
        RETURN_NULL();
    }

    RETURN_BOOL(NLPIR_SetPOSmap(nPOSmap));
}

PHP_FUNCTION(NLPIR_FinerSegment) {
    const char *sLine;
    int slen;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &sLine, &slen) == FAILURE)
    {
        RETURN_NULL();
    }

    RETURN_STRING(NLPIR_FinerSegment(sLine), 1);
}

PHP_FUNCTION(NLPIR_GetEngWordOrign) {
    const char *sWord;
    int slen;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &sWord, &slen) == FAILURE)
    {
        RETURN_NULL();
    }

    RETURN_STRING(NLPIR_GetEngWordOrign(sWord), 1);
}

PHP_FUNCTION(NLPIR_WordFreqStat) {
    const char *sText;
    int slen;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &sText, &slen) == FAILURE)
    {
        RETURN_NULL();
    }

    RETURN_STRING(NLPIR_WordFreqStat(sText), 1);
}

PHP_FUNCTION(NLPIR_FileWordFreqStat) {
    const char *sFilename;
    int slen;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &sFilename, &slen) == FAILURE)
    {
        RETURN_NULL();
    }

    RETURN_STRING(NLPIR_FileWordFreqStat(sFilename), 1);
}


/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
