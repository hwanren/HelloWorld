#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "A.hpp"

using namespace CppUnit;
using namespace std;

class TestA : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE(TestA);
  CPPUNIT_TEST(testGiveZero);
  CPPUNIT_TEST(testGiveOne);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void);
  void tearDown(void);

protected:
  void testGiveZero(void);
  void testGiveOne(void);

private:
  A *mTestObj;
};

void TestA::testGiveZero(void)
{
  CPPUNIT_ASSERT(0 == mTestObj->giveZero(100));
}


void TestA::testGiveOne(void)
{
  CPPUNIT_ASSERT(1 == mTestObj->giveOne(10.0));
}

void TestA::setUp(void)
{
  mTestObj = new A();
}

void TestA::tearDown(void)
{
  delete mTestObj;
}

CPPUNIT_TEST_SUITE_REGISTRATION(TestA);


int main(int argc, char **argv)
{
  CPPUNIT_NS::TestResult testResult;
  CPPUNIT_NS::TestResultCollector collectedResults;
  testResult.addListener(&collectedResults);

  CPPUNIT_NS::BriefTestProgressListener progress;
  testResult.addListener(&progress);

  CPPUNIT_NS::TestRunner testRunner;
  testRunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
  testRunner.run(testResult);

  CPPUNIT_NS::CompilerOutputter compilerOutputter(&collectedResults, cerr);
  compilerOutputter.write();

  ofstream xmlFileOut("cppTestA_Results.xml");
  XmlOutputter xmlOut(&collectedResults, xmlFileOut);
  xmlOut.write();

  return collectedResults.wasSuccessful() ? 0 : 1;
}
