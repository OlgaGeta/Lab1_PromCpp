#include "gtest/gtest.h"

#include <fstream>

#include "../../../../libsrc/RAII/src/File.cpp"

TEST(FileDoesntExist, OpenReading) {
	remove("testfile.txt");

	File f("testfile.txt", "r");
	EXPECT_FALSE(f.is_open());
}

TEST(FileDoesntExist, OpenWriting) {
	remove("testfile.txt");

	File f("testfile.txt", "w");
	EXPECT_TRUE(f.is_open());
}

TEST(FileExist, OpenReading) {
	std::ofstream file("testfile.txt");

	File f("testfile.txt", "r");
	EXPECT_TRUE(f.is_open());
}

TEST(FileExist, OpenWriting) {
	File f("testfile.txt", "w");
	EXPECT_TRUE(f.is_open());
}

TEST(FileDoesntExist, CloseReading) {
	remove("testfile.txt");

	File f("testfile.txt", "r");
	f.close();

	EXPECT_FALSE(f.is_open());
}

TEST(FileDoesntExist, isCorrectReading) {
	remove("testfile.txt");

	File f("testfile.txt", "r");

	EXPECT_FALSE(f.is_correct());
}

TEST(FileExist, isCorrectReading) {
	std::ofstream file("testfile.txt");
	file.close();

	File f("testfile.txt", "r");

	EXPECT_TRUE(f.is_correct());
}

TEST(FileDoesntExist, Reading) {
	remove("testfile.txt");

	File f("testfile.txt", "r");

	std::string str;
	
	EXPECT_THROW(f >> str, std::runtime_error);
}

TEST(FileDoesntExist, Writing) {
	remove("testfile.txt");

	File f("testfile.txt", "w");

	std::string test_string = "hello";
	f << test_string;

	f.close();

	std::ifstream input_file("testfile.txt");

	std::string str;
	input_file >> str;

	input_file.close();

	EXPECT_EQ(str, test_string);
}

TEST(FileExist, Writing) {
	std::ofstream output_file("testfile.txt");

	std::string test_string = "123";
	output_file << test_string;

	output_file.close();

	File f("testfile.txt", "w");

	std::string test_string2 = "hello";
	f << test_string2;

	f.close();

	std::ifstream input_file("testfile.txt");

	std::string str;
	input_file >> str;

	input_file.close();

	EXPECT_EQ(str, test_string2);
}

TEST(FileDoesntExist, DestructorReading) {
	remove("testfile.txt");

	File f("testfile.txt", "r");
	f.~File();

	EXPECT_FALSE(f.is_open());
	EXPECT_FALSE(f.is_correct());
}

// section of reading tests, stands for fix !Correct

TEST(FileExistButEmpty, Reading) { // checking empty file
	std::string data_from_file;
	std::ofstream file("test.txt");
	file.close(); 
	File f("test.txt", "r");

	f >> data_from_file;
	EXPECT_EQ(data_from_file, "");
	EXPECT_FALSE(f.is_correct());
}

TEST(FileExistNonEmpty, Reading) { // checking file with some stuff
	std::string data_from_file; 
	std::ofstream file("test.txt"); 
	std::string data_to_file = "prekol :clown_face"; 
	file << data_to_file; 
	file.close(); 
	File f("test.txt", "r"); 

	f >> data_from_file; 
	EXPECT_EQ(data_from_file, data_to_file); 
	EXPECT_TRUE(f.is_correct()); 
}

// section of nullptr for FILE* test, stands for fix 39: fileHandle_ = nullptr;
TEST(FileExist, CloseReading) { 
	std::ofstream file("test.txt"); 
	File f("test.txt", "r"); 
	f.close(); 

	EXPECT_FALSE(f.is_open()); 
}
