#include <gtest/gtest.h>
#include "roverdispatcher.h"
#include <cmath>

roverdispatcher dispatcher;
TEST(parseRover,ut_1)
{
	std::string str("3 3 N");
	std::string exec("Incorrectly specified Rover.");
	bool result =true;
	try{
		dispatcher.parseRover(str);
	}catch (std::string &e) {
		result = !e.compare(exec)==0;
	}

	ASSERT_EQ(true,result);
}

TEST(parseRover,ut_2)
{
	std::string str("3 3 3 N");
	std::string exec("Incorrectly specified Rover.");
	bool result =true;
	try{
		dispatcher.parseRover(str);
	}catch (std::string &e) {
		result = !e.compare(exec)==0;
	}
	catch(const char* e){
		result=!exec.compare(e)==0;
	}
	ASSERT_EQ(false,result);
}

TEST(parseRover,ut_3)
{
	std::string str("3 N");
	std::string exec("Incorrectly specified Rover.");
	bool result =true;
	try{
		dispatcher.parseRover(str);
	}catch (std::string &e) {
		result = !e.compare(exec)==0;
	}
	catch(const char* e){
		result=!exec.compare(e)==0;
	}

	ASSERT_EQ(false,result);
}
TEST(parseVertex,ut_4)
{
	std::string str("3 3");
	std::string exec("vertex must be specified int int.");
	bool result =true;
	try{
		dispatcher.parseVertex(str);
	}catch (std::string &e) {
		result = !e.compare(exec)==0;
	}

	ASSERT_EQ(true,result);
}

TEST(parseVertex,ut_5)
{
	std::string str("3 3 N");
	std::string exec("vertex must be specified int int.");
	bool result =true;
	try{
		dispatcher.parseVertex(str);
	}catch (std::string &e) {
		result = !e.compare(exec)==0;
	}
	catch(const char* e){
		result=!exec.compare(e)==0;
	}

	ASSERT_EQ(false,result);
}

TEST(parseVertex,ut_6)
{
	std::string str("3");
	std::string exec("vertex must be specified int int.");
	bool result =true;
	try{
		dispatcher.parseVertex(str);
	}catch (std::string &e) {
		result = !e.compare(exec)==0;
	}
	catch(const char* e){
		result=!exec.compare(e)==0;
	}

	ASSERT_EQ(false,result);
}
TEST(mapUserHeading,ut_7)
{
	std::string str("3");
	std::string exec("Unknown user heading ");
	bool result =true;
	double out=0.0;
	try{
		dispatcher.mapUserHeading(str);
	}catch (std::string &e) {
		result = !e.compare(exec + str)==0;
	}
	catch(const char* e){
		result=!exec.compare(e)==0;
	}

	ASSERT_EQ(false,result);
}

TEST(mapUserHeading,ut_8)
{
	std::string str("N");
	std::string exec("Unknown user heading ");
	bool result =true;
	double out=0.0;
	try{
		out=dispatcher.mapUserHeading(str);
		result=out==(M_PI/2);
	}catch (std::string &e) {
		result = !e.compare(exec + str)==0;
	}
	catch(const char* e){
		result=!exec.compare(e)==0;
	}

	ASSERT_EQ(true,result);
}
TEST(mapUserHeading,ut_9)
{
	std::string str("E");
	std::string exec("Unknown user heading ");
	bool result =true;
	double out=0.0;
	try{
		out=dispatcher.mapUserHeading(str);
		result=out==0.0;
	}catch (std::string &e) {
		result = !e.compare(exec + str)==0;
	}
	catch(const char* e){
		result=!exec.compare(e)==0;
	}

	ASSERT_EQ(true,result);
}
TEST(mapUserHeading,ut_10)
{
	std::string str("S");
	std::string exec("Unknown user heading ");
	bool result =true;
	double out=0.0;
	try{
		out=dispatcher.mapUserHeading(str);
		result=out==(3*M_PI/2);
	}catch (std::string &e) {
		result = !e.compare(exec + str)==0;
	}
	catch(const char* e){
		result=!exec.compare(e)==0;
	}

	ASSERT_EQ(true,result);
}
TEST(mapUserHeading,ut_11)
{
	std::string str("W");
	std::string exec("Unknown user heading ");
	bool result =true;
	double out=0.0;
	try{
		out=dispatcher.mapUserHeading(str);
		result=out==(M_PI);
	}catch (std::string &e) {
		result = !e.compare(exec + str)==0;
	}
	catch(const char* e){
		result=!exec.compare(e)==0;
	}

	ASSERT_EQ(true,result);
}
TEST(mapUserHeading,ut_12)
{
	std::string str("3 N");
	std::string exec("Unknown user heading ");
	bool result =true;
	double out=0.0;
	try{
		out=dispatcher.mapUserHeading(str);
		result=out==(M_PI/2);
	}catch (std::string &e) {
		result = !e.compare(exec + str)==0;
	}
	catch(const char* e){
		result=!exec.compare(e)==0;
	}

	ASSERT_EQ(false,result);
}
TEST(mapControllerHeading,ut_13)
{
	double str(1000.0);
	std::string exec("Unknown Controller Handling");
	bool result =true;
	std::string out;
	std::string val("N");
	try{
		out=dispatcher.mapControllerHeading(str);
		result=out.compare(val);
	}catch (std::string &e) {
		result = !e.compare(exec)==0;
	}
	catch(const char* e){
		result=!exec.compare(e)==0;
	}

	ASSERT_EQ(false,result);
}

TEST(mapControllerHeading,ut_14)
{
	double str(M_PI/2);
	std::string exec("Unknown Controller Handling");
	bool result =true;
	std::string val("N");
	std::string out;
	try{
		out=dispatcher.mapControllerHeading(str);
		result=out.compare(val)==0;
	}catch (std::string &e) {
		result = !e.compare(exec)==0;
	}
	catch(const char* e){
		result=!exec.compare(e)==0;
	}

	ASSERT_EQ(true,result);
}
TEST(mapControllerHeading,ut_15)
{
	double str(0.0);
	std::string exec("Unknown Controller Handling");
	bool result =true;
	std::string val("E");
	std::string out;
	try{
		out=dispatcher.mapControllerHeading(str);
		result=out.compare(val)==0.0;
	}catch (std::string &e) {
		result = !e.compare(exec)==0;
	}
	catch(const char* e){
		result=!exec.compare(e)==0;
	}

	ASSERT_EQ(true,result);
}
TEST(mapControllerHeading,ut_16)
{
	double str(3*M_PI/2);
	std::string exec("Unknown Controller Handling");
	bool result =true;
	std::string val("S");
	std::string out;
	try{
		out=dispatcher.mapControllerHeading(str);
		result=out.compare(val)==(0);
	}catch (std::string &e) {
		result = !e.compare(exec)==0;
	}
	catch(const char* e){
		result=!exec.compare(e)==0;
	}

	ASSERT_EQ(true,result);
}
TEST(mapControllerHeading,ut_17)
{
	double str(M_PI);
	std::string exec("Unknown Controller Handling");
	bool result =true;
	std::string val("W");
	std::string out;
	try{
		out=dispatcher.mapControllerHeading(str);
		result=out.compare(val)==(0);
	}catch (std::string &e) {
		result = !e.compare(exec)==0;
	}
	catch(const char* e){
		result=!exec.compare(e)==0;
	}

	ASSERT_EQ(true,result);
}
TEST(mapControllerHeading,ut_18)
{
	double str(-1.0);
	std::string exec("Unknown Controller Handling");
	bool result =true;
	double out=0.0;
	try{
		dispatcher.mapControllerHeading(str);

	}catch (std::string &e) {
		result = !e.compare(exec)==0;
	}
	catch(const char* e){
		result=!exec.compare(e)==0;
	}

	ASSERT_EQ(false,result);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
