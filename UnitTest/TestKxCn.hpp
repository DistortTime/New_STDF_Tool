#include <cxxtest/TestSuite.h>

#include "DataTypes.hpp"

class TestKxCn : public CxxTest::TestSuite 
{
  public:
    void setUp()
    {
    }
    void tearDown()
    {
    }

    void testConstructor0()
    {
      const size_t size = 0;
      KxTYPE<Cn, size> stdfStr;
      TS_ASSERT_EQUALS(stdfStr.max_size(), size);
      TS_ASSERT_EQUALS(stdfStr.storage(), size);
      TS_ASSERT_EQUALS(stdfStr.to_string(), "");
    }

    void testConstructor1()
    {
      const size_t size = 10;
      KxTYPE<Cn, size> stdfStr;
      TS_ASSERT_EQUALS(stdfStr.max_size(), size);
      TS_ASSERT_EQUALS(stdfStr.storage(), size);
      TS_ASSERT_EQUALS(stdfStr.to_string(), ",,,,,,,,,");
    }

    void testConstructor2()
    {
      const size_t size = 100;
      KxTYPE<Cn, size> stdfStr;
      Cn data[size];
      for(size_t i = 0; i < size; i++)
      {
        stdfStr[i] = data[i] = "ABCD";
      }
      TS_ASSERT_EQUALS(stdfStr.max_size(), size);
      TS_ASSERT_EQUALS(stdfStr.storage(), 5*size);
      TS_ASSERT_EQUALS(stdfStr[88].to_string(), data[88].to_string());
      TS_ASSERT_EQUALS(stdfStr[99].to_string(), data[99].to_string());
      std::basic_string<char> str;
      for(size_t i = 0; i < size-1; i++) str.append("ABCD,"); str.append("ABCD");
      TS_ASSERT_EQUALS(stdfStr.to_string(), str);
      stdfStr.clear();
      str.clear(); str.assign(size-1, ',');
      TS_ASSERT_EQUALS(stdfStr.to_string(), str);
    }

    void testWriteRead1()
    {
      const char *filename = "TestKxCn.testWriteRead1.txt";

      const size_t size = 1;

      KxTYPE<Cn, size> stdfStrIn;
      std::ofstream outfile(filename, std::ofstream::binary);
      stdfStrIn.write(outfile);
      outfile.close();

      KxTYPE<Cn, size> stdfStrOut;
      std::ifstream infile(filename, std::ifstream::binary);
      stdfStrOut.read(infile);
      outfile.close();

      TS_ASSERT_EQUALS(stdfStrIn.max_size(), 1u);
      TS_ASSERT_EQUALS(stdfStrOut.max_size(), 1u);
      TS_ASSERT_EQUALS(stdfStrIn.storage(), 1u);
      TS_ASSERT_EQUALS(stdfStrOut.storage(), 1u);
      TS_ASSERT_EQUALS(stdfStrIn.to_string(), stdfStrOut.to_string())
    }

    void testWriteRead2()
    {
      const char *filename = "TestKxCn.testWriteRead2.txt";

      const size_t size = 10;

      KxTYPE<Cn, size> stdfStrIn;
      std::ofstream outfile(filename, std::ofstream::binary);
      stdfStrIn.write(outfile);
      outfile.close();

      KxTYPE<Cn, size> stdfStrOut;
      std::ifstream infile(filename, std::ifstream::binary);
      stdfStrOut.read(infile);
      outfile.close();

      TS_ASSERT_EQUALS(stdfStrIn.max_size(), 10u);
      TS_ASSERT_EQUALS(stdfStrOut.max_size(), 10u);
      TS_ASSERT_EQUALS(stdfStrIn.storage(), 10u);
      TS_ASSERT_EQUALS(stdfStrOut.storage(), 10u);
      TS_ASSERT_EQUALS(stdfStrIn.to_string(), stdfStrOut.to_string())
    }

    void testWriteRead3()
    {
      const char *filename = "TestKxCn.testWriteRead3.txt";

      const size_t size = 20;
      Cn data[size];

      KxTYPE<Cn, size> stdfStrIn;
      for(size_t i = 0; i < size; i++)
      {
        stdfStrIn[i] = data[i] = "ABCDEF";
      }
      std::ofstream outfile(filename, std::ofstream::binary);
      stdfStrIn.write(outfile);
      outfile.close();

      KxTYPE<Cn, size> stdfStrOut;
      std::ifstream infile(filename, std::ifstream::binary);
      stdfStrOut.read(infile);
      outfile.close();

      TS_ASSERT_EQUALS(stdfStrIn.max_size(), 20u);
      TS_ASSERT_EQUALS(stdfStrOut.max_size(), 20u);
      TS_ASSERT_EQUALS(stdfStrIn.storage(), 140u);
      TS_ASSERT_EQUALS(stdfStrOut.storage(), 140u);
      TS_ASSERT_EQUALS(stdfStrIn.to_string(), stdfStrOut.to_string());
      std::basic_string<char> str;
      for(size_t i = 0; i < size-1; i++) str.append("ABCDEF,"); str.append("ABCDEF");
      TS_ASSERT_EQUALS(stdfStrIn.to_string(), str);
      TS_ASSERT_EQUALS(stdfStrOut.to_string(), str);
    }

};
