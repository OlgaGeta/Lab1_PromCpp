#ifndef FILE_HPP_

#define FILE_HPP_

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cctype>

#include <stdexcept>
#include <string>

class File {
public:
	explicit File(const char* fileName, const char* mode);

	~File();

	operator bool() const;

	bool is_open() const;
	bool is_correct() const;

	void close();

	File& operator<<(const std::string& str);
	File& operator>>(std::string& str);

private:
	File(const File&);
	File& operator=(const File&);

	FILE* fileHandle_;
	char mode_[2];
	bool isCorrect_;
};

#endif // !FILE_HPP_
