<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('nlpir')) {
	dl('nlpir.' . PHP_SHLIB_SUFFIX);
}
$module = 'nlpir';
$functions = get_extension_funcs($module);
echo "Functions available in the test extension:$br\n";
foreach($functions as $func) {
    echo $func."$br\n";
}

echo "$br\n";
$function = 'confirm_' . $module . '_compiled';
if (extension_loaded($module)) {
	$str = $function($module);
} else {
	$str = "Module $module is not compiled into PHP";
}

echo "\n NLPIR_Init :";
$a = NLPIR_Init("/usr/local/src/nlpir/my/20150702124141_ICTCLAS2015/汉语分词20140928/", 1);
if($a !== 'SUCCESS') {
	echo NLPIR_GetLastErrorMsg();
	die();
}
echo "\n";

echo "\n ParagraphProcess :";
echo ParagraphProcess("今天天气不错呀，出去逛公园吧", 1);
echo "\n";


echo "\n ParagraphProcessA :";
$a = ParagraphProcessA("今天天气不错呀，出去逛公园吧");
print_r($a);
echo "\n";

 

echo "$str\n";

?>
