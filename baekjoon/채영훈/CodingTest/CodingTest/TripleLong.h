#pragma once
#include <string>

using namespace std;

struct TripleLong
{
public:
	TripleLong();
	TripleLong(const string& val);
	~TripleLong();

	const string SetVal(const string& val);
	const string GetVal() const;

	TripleLong& operator=(const TripleLong& rhs);
	TripleLong operator+(TripleLong& rhs);
	TripleLong operator-(TripleLong& rhs);
	TripleLong operator*(TripleLong& rhs);
	TripleLong operator/(TripleLong& rhs);
	TripleLong operator%(TripleLong& rhs);
private:
public:
private:
	bool isMinus;
	string val;
};
