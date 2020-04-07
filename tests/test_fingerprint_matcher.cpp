#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <fstream>
#include "fingerprinter_configuration.h"
#include "fingerprint_matcher.h"
#include "utils.h"

namespace chromaprint
{

TEST(FingerprintMatcher, Match)
{
	const int32_t fp1_data[] = { 1889975932, -257508804, -240734660, -236548548, -1275161041, -1283549650, -1288796626, -1288845782, -231944646, -227770598, -227596006, -428984294, 1717901370, 1847860266, 1848063034, 1849045002, 978722826, 994451466, 1002856472, 969236792, 969204600, 2026173048, 2026215160, 2026348248, 2022681304, -393368872, -393430280, -393429272, -1462980951, -1471637847, -1475836247, -1475752279, -1408508261, -1404080485, -1404098886, -1395845206, -1260649558, -185335378, -194965314, -262004554, -262000394, -261962634, -253506554, -235820026, -235689979, -210588412, -212693436, -216889788, -216889804, -1288588764, -1288375764, -1285242323, -1309883603, -1309878993, -1578117826, -1276185314, -1284510370, -1284669458, -1284683793, -1284683779, -1284548771, -1285074676, -1284157156, -1217105619, -1242275539, -1246273217, -1246338786, -1112055010, -1118472386, -1117960918, -1088601046, -1084668806, -1101269797, -19311413, -19377013, -27759477, -15127142, -48616006, -65392726, -597817414, -589954150, -657063522, -661311010, -661643170, -644866018, -879632354, -610950114, -610948034, -606815169, -1688355556, -1184907508, -1176519156, -1109817764, -1386707332, -1390831876, -1491496216, -1491500312, -1506163992, -1557658904, -1590950929, -1607728786, -1603534722, -521333698, -525386690, -256956306, -257017634, -257017650, 1370385550, 1403976846, 1391445390, 1458405790, 1449972222, 1584197934, 1585410350, 1581195839, 1602167353, 1568612921, 1551839800, 1558123048, 1490825577, 1486627321, 1485595851, 1485616331, 416066651, 416132123, 416197643, 467577871, 442403855, 440304655, 507478045, 507150399, 507166847, 505077871, 505110766, 1046175982, 1046110463, 1062863055, 1014628813, 1014694876, 477704956, 349775612, 886646376, 886650488, 349707865, 278404699, 282599130, 299636714, 301741482, 284964010, 276582554, 276578442, 276611210, 352309434, 352236794, 352236766, 1442751822, 1476306255, 1191163167, 1191031101, 1459467068, 1585427260, 1581228348, 1579147564, 1579017580, 1579017452, 1582298364, 1607389405, 1574617551, 1557840350, 1560003070, 1551618558, 1551463550, 1547527286, 1547527414, 1547003350, 1549231830, 1557394166, -594291978, -578776362, -578767242, -679434394, -1748979865, -1211650084, -1244225828, -1319663940, -1319270740, -1287814484, -1287798084, -1287793988, -1287851028, -1287784979, -1284680593, -1586531201, -1578114017, -1594890977, -1578186993, -1578187249, -1586510305, -1553074377, -1553144522, -1553407978, -1557344201, -1590738889, -1523711658, -444714402, -436329922, -436395474, -402902226, -402910946, -419680246, -402820069, -402795479, -436208615, -453055479, -461374199, 1685898841, 1681703659, 1681654523, 1681855067, -193064325, -184667797 };
	const int32_t fp2_data[] = { -1288792466, -1288780246, -1288845782, -231977158, -226662118, -496031718, 1718564890, 1713642554, 1847931962, 1847996442, 1047928842, 978722826, 1002840075, 969367608, 969204024, 2026173048, 2026149496, 2026348280, 2022686424, -124802344, -393368872, -393429256, -1467171160, -1471365463, -1475836247, -1475836247, -1475752263, -1404080485, -1404080485, -1395841350, -1529080918, -1261174358, -193723970, -194826082, -262004490, -261992330, -253574058, -252457978, -235821049, -235755515, -210583804, -212693436, -216889788, -216820172, -1288658396, -1284181460, -1310407891, -1309884113, -1309813458, -1309682402, -1284506338, -1284510338, -1284677649, -1284683793, -1284552739, -1284549811, -1284026100, -1284222659, -1242271443, -1246404289, -1246273250, -1246338786, -1107860706, -1117956290, -1117960918, -1084668822, -1101409030, -19303205, -19377013, -27757429, -27775861, -14996070, -48615494, -60932182, -597817414, -657063010, -661188130, -661573154, -644865954, -644784098, -611196898, -610950122, -606755777, -606815171, -614615780, -1184909812, -1109420532, -1126592932, -1403478276, -1390823684, -1491495252, -1506032984, -1506065748, -1574436177, -1591213074, -1607729106, -529792978, -521391058, -257087442, -256956290, 1890465998, 1940813966, 1387191438, 1391363470, 1382908302, 1449955518, 1450045678, 1580068910, 1580146991, 1596858925, 1567564345, 1551839801, 1560220201, 1560089131, 1486627627, 1486628186, 1485628490, 1485614154, 411872346, 412003406, 432978958, 467573775, 442401805, 440370205, 507478068, 507166772, 440057957, 437936357, 442196199, 442196199, 450506951, 536477893, 477823445, 477696756, 486089340, 483993196, 483993196, 479805048, 345521737, 345517771, 362299386, 299373994, 299636138, 274464954, 8126602, 8142986, 16568474, 16707770, 12498170, 79602718, 1157539086, 1174381855, 1207805245, 1191031068, 1191153948, 1182699804, 1444852028, 1579066732, 1579148780, 1579017452, 1583342780, 1600050589, 534430095, 534496159, 1568391646, 1568232830, 1568502830, 1547527214, 1547002918, 1551327574, 1551262294, 1553453654, -577387946, -578776490, -545216905, -1752912011, -1748652076, -1782071596, -1780511052, -1327659348, -1319271764, -1317240148, -1287863636, -1287851347, -1288834067, -1288834577, -1322396185, -1603406729, -1594889129, -1594950377, -1594962681, -1594962169, -1586505929, -1553078985, -1574313705, -1574309881, -1574223817, -1557462681, -1486220425, -436329866, -436395410, -440651217, -436456674, -402902770, -402836469, -402820037, -402817991, -436208631, -436225015, -167993525, 1971094107, 1966916347, 1966953050, 1967002202, -176287382, -184668054, -188926869, -188992263, -188777271, -188818231, -33628727 };

//	const int32_t fp1_data[] = { 1 << 28, 2 << 28, 3 << 28 };
//	const int32_t fp2_data[] = { 4 << 28, 1 << 28, 2 << 28, 3 << 28 };

	std::vector<uint32_t> fp1(fp1_data, fp1_data + sizeof(fp1_data)/sizeof(fp1_data[0]));
	std::vector<uint32_t> fp2(fp2_data, fp2_data + sizeof(fp2_data)/sizeof(fp2_data[0]));

	FingerprintMatcher matcher(CreateFingerprinterConfiguration(CHROMAPRINT_ALGORITHM_TEST2));
	matcher.Match(fp1, fp2);
}

};
