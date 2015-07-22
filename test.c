#include "NLPIR.h"
#include <stdio.h>
#include <string.h>


int main(int argc,char *argv[]) 
{
	const char *dictDir, *inputChar;
	const char *sResult;
	int encoding;

	encoding = 1;
	dictDir = "../20150702124141_ICTCLAS2015/汉语分词20140928/";
	inputChar = "今天天气错哈，逛公园去";

	if(NLPIR_Init(dictDir, encoding, 0)) {
		printf("init success\n");
	} else {
		printf("init error: %s", NLPIR_GetLastErrorMsg);
		return -1;
	}

	//NLPIR_ImportUserDict
	
	sResult = NLPIR_ParagraphProcess(inputChar, 1);
	printf("NLPIR_ParagraphProcess result : %s \n\n",sResult);

	int nCount, i; //结果数量
	const result_t *arrayResult;
	arrayResult = NLPIR_ParagraphProcessA(inputChar, &nCount, true);
	printf("NLPIR_ParagraphProcessA result : %s \n\n",sResult);
	for(i = 0; i < nCount; i++) {
		printf("\n\tStart=%d Length=%d spos=%s ipos=%d Word_ID=%d Word_type=%d weight=%d\n",
		arrayResult[i].start,
		arrayResult[i].length,
		arrayResult[i].sPOS,
		arrayResult[i].iPOS,
		arrayResult[i].word_ID,
		arrayResult[i].word_type,
		arrayResult[i].weight);
	}

	if(NLPIR_FileProcess("../20150702124141_ICTCLAS2015/汉语分词20140928/Readme.txt", "Readme_s.txt", 1)) {
		printf("\nNLPIR_FileProcess success \n\n");
	} else {
		printf("\nNLPIR_FileProcess faile \n\n");
	}
	//问题：输出内容是乱码

	if(NLPIR_AddUserWord("错哈	n") && NLPIR_SaveTheUsrDic()) {
		printf("\nNLPIR_AddUserWord success \n\n");
		sResult = NLPIR_ParagraphProcess(inputChar, 1);
		printf("NLPIR_ParagraphProcess result : %s \n\n",sResult);
	}

	NLPIR_DelUsrWord("错哈");
	NLPIR_SaveTheUsrDic();

	sResult = NLPIR_GetKeyWords("欢迎使用NLPIR/ICTCLAS2014分词系统NLPIR分词系统前身为2000年发布的ICTCLAS词法分析系统，从2009年开始，为了和以前工作进行大的区隔，并推广NLPIR自然语言处理与信息检索共享平台，调整命名为NLPIR分词系统。张华平博士先后倾力打造十余年，内核升级十余次，先后获得了2010年钱伟长中文信息处理科学技术奖一等奖，2003年国际SIGHAN分词大赛综合第一名，2002年国内973评测综合第一名。全球用户突破30万，包括中国移动、华为、中搜、3721、NEC、中华商务网、硅谷动力、云南日报等企业，清华大学、新疆大学、华南理工、麻省大学等机构：同时，ICTCLAS广泛地被《科学时报》、《人民日报》海外版、《科技日报》等多家媒体报道。您可以访问Google进一步了解ICTCLAS的应用情况。", 50, 1);
    printf("NLPIR_GetKeyWords result : %s \n\n",sResult);

    sResult = NLPIR_GetFileKeyWords("../20150702124141_ICTCLAS2015/汉语分词20140928/Readme.txt", 50, 1);
    printf("NLPIR_GetFileKeyWords result : %s \n\n",sResult);

    NLPIR_ImportKeyBlackList("blacklist");
    sResult = NLPIR_GetKeyWords("欢迎使用NLPIR/ICTCLAS2014分词系统NLPIR分词系统前身为2000年发布的ICTCLAS词法分析系统，从2009年开始，为了和以前工作进行大的区隔，并推广NLPIR自然语言处理与信息检索共享平台，调整命名为NLPIR分词系统。张华平博士先后倾力打造十余年，内核升级十余次，先后获得了2010年钱伟长中文信息处理科学技术奖一等奖，2003年国际SIGHAN分词大赛综合第一名，2002年国内973评测综合第一名。全球用户突破30万，包括中国移动、华为、中搜、3721、NEC、中华商务网、硅谷动力、云南日报等企业，清华大学、新疆大学、华南理工、麻省大学等机构：同时，ICTCLAS广泛地被《科学时报》、《人民日报》海外版、《科技日报》等多家媒体报道。您可以访问Google进一步了解ICTCLAS的应用情况。", 50, 1);
    printf("NLPIR_ImportKeyBlackList result : %s \n\n",sResult);

    sResult = NLPIR_GetNewWords("世界工厂网，一个独具特色的实体制造型厂家聚集的电子商务门户网站。 世界工厂网致力于为实体型生产企业提供沟通的平台，主要为生产商、贸易商、以及商务服务企业提供电子商务平台服务，在这里您可以简单快捷的建立自己的网上商铺、将商店扩张到客户触手可及的领域，海量搜索供求信息，分享商业经验，交流创富秘密！ 自2009年1月底上线以来，国内超过50万家优秀的实体生产厂家和600多万贸易商加入了网站，世界工厂网成为国内知名的直接面向生产厂家的低成本采购平台，世界工厂网的注册会员在网站上先后接到了500多万次询盘。 世界工厂网的拥有一支有着丰富企业电子商务实战经验的高效人才队伍，其推出的各种服务必将更加贴近企业的实际需求，世界工厂拥有强大的网络运营管理能力和较强的程序开发能力，汲取了各种B2B优点并结合自己的创新，为企业打造全球最具竞争力和影响力的实用型电子商务网站，并为客户提供最优质的量身打造的全方位企业电子商务服务； 世界工厂网拥有一批高素质的年轻服务队伍，能够为企业提供强大的产品后台保障。 项目定位精确,服务专业、稳定,网站上线以后受到各大媒体的关注和广大用户的良好反馈。", 50, 1);
    printf("NLPIR_GetNewWords result : %s \n\n",sResult);

	sResult = NLPIR_GetFileNewWords("gongchang.txt", 50, 1);
	printf("NLPIR_GetFileNewWords result : %s \n\n",sResult);


	unsigned long lFinger = NLPIR_FingerPrint("世界工厂网，一个独具特色的实体制造型厂家聚集的电子商务门户网站。 世界工厂网致力于为实体型生产企业提供沟通的平台，主要为生产商、贸易商、以及商务服务企业提供电子商务平台服务，在这里您可以简单快捷的建立自己的网上商铺、将商店扩张到客户触手可及的领域，海量搜索供求信息，分享商业经验，交流创富秘密！ 自2009年1月底上线以来，国内超过50万家优秀的实体生产厂家和600多万贸易商加入了网站，世界工厂网成为国内知名的直接面向生产厂家的低成本采购平台，世界工厂网的注册会员在网站上先后接到了500多万次询盘。 世界工厂网的拥有一支有着丰富企业电子商务实战经验的高效人才队伍，其推出的各种服务必将更加贴近企业的实际需求，世界工厂拥有强大的网络运营管理能力和较强的程序开发能力，汲取了各种B2B优点并结合自己的创新，为企业打造全球最具竞争力和影响力的实用型电子商务网站，并为客户提供最优质的量身打造的全方位企业电子商务服务； 世界工厂网拥有一批高素质的年轻服务队伍，能够为企业提供强大的产品后台保障。 项目定位精确,服务专业、稳定,网站上线以后受到各大媒体的关注和广大用户的良好反馈。"); 
	printf("NLPIR_FingerPrint result : %d \n\n",lFinger);

	NLPIR_SetPOSmap(ICT_POS_MAP_FIRST);
	

	sResult = NLPIR_FinerSegment("中华人民共和国");
	printf("NLPIR_FinerSegment result : %s \n\n",sResult);

	sResult = NLPIR_GetEngWordOrign("drives");
	printf("NLPIR_GetEngWordOrign result : %s \n\n",sResult);

	sResult = NLPIR_WordFreqStat("世界工厂网，一个独具特色的实体制造型厂家聚集的电子商务门户网站。 世界工厂网致力于为实体型生产企业提供沟通的平台，主要为生产商、贸易商、以及商务服务企业提供电子商务平台服务，在这里您可以简单快捷的建立自己的网上商铺、将商店扩张到客户触手可及的领域，海量搜索供求信息，分享商业经验，交流创富秘密！ 自2009年1月底上线以来，国内超过50万家优秀的实体生产厂家和600多万贸易商加入了网站，世界工厂网成为国内知名的直接面向生产厂家的低成本采购平台，世界工厂网的注册会员在网站上先后接到了500多万次询盘。 世界工厂网的拥有一支有着丰富企业电子商务实战经验的高效人才队伍，其推出的各种服务必将更加贴近企业的实际需求，世界工厂拥有强大的网络运营管理能力和较强的程序开发能力，汲取了各种B2B优点并结合自己的创新，为企业打造全球最具竞争力和影响力的实用型电子商务网站，并为客户提供最优质的量身打造的全方位企业电子商务服务； 世界工厂网拥有一批高素质的年轻服务队伍，能够为企业提供强大的产品后台保障。 项目定位精确,服务专业、稳定,网站上线以后受到各大媒体的关注和广大用户的良好反馈。");
	printf("NLPIR_WordFreqStat result : %s \n\n",sResult);

	sResult = NLPIR_FileWordFreqStat("gongchang.txt");
	printf("NLPIR_FileWordFreqStat result : %s \n\n",sResult);

	NLPIR_Exit();
	return 0;
}