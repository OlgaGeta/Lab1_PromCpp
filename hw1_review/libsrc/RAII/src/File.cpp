#include "../../../include/RAII/File.hpp"

File::File(const char* fileName, const char* mode) : fileHandle_(nullptr) {
	if (strcmp(mode, "r") != 0 && strcmp(mode, "w") != 0)
		throw std::runtime_error("Invalid mode.\n");

	strcpy(mode_, mode);
	fileHandle_ = fopen(fileName, mode);
	if (fileHandle_)
		isCorrect_ = true;
	else
		isCorrect_ = false;

	//if (!fileHandle_) {
	//	throw std::runtime_error("Failed to open file.\n");
	//}
}

File::~File() {
	close();
}

File::operator bool() const
{
	return isCorrect_;
}

bool File::is_open() const {
	return fileHandle_ != nullptr;
}

bool File::is_correct() const {
	return isCorrect_;
}

void File::close() {
	if (fileHandle_) {
		fclose(fileHandle_);
		strcpy(mode_, "");
		isCorrect_ = false;
	}
}

File& File::operator<<(const std::string& str) {
	if (fileHandle_ == 0)
		throw std::runtime_error("File is not open.\n");

	if (strcmp(mode_, "w") != 0)
		throw std::runtime_error("File is not open for writing.\n");

	if (isCorrect_)
		if (fprintf(fileHandle_, "%s", str.c_str()) != 1)
			isCorrect_ = false;

	fflush(fileHandle_);

	return *this;
}

File& File::operator>>(std::string& str) {
	str.clear();

	if (fileHandle_ == 0)
		throw std::runtime_error("File is not open.\n");

	if (strcmp(mode_, "r") != 0)
		throw std::runtime_error("File is not open for reading.\n");

	if (feof(fileHandle_))
	{
		isCorrect_ = false;
		return *this;
	}

	if (!isCorrect_)
	{
		char symbol = fgetc(fileHandle_);

		if (symbol == EOF)
		{
			isCorrect_ = false;
			return *this;
		}

		while (symbol != EOF && !isspace(symbol))
		{
			str += symbol;
			symbol = fgetc(fileHandle_);
		}
	}

	return *this;
}

File::File(const File&) {

}

File& File::operator=(const File&) {
	return *this;
}

