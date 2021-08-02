#include "TripleLong.h"

TripleLong::TripleLong()
	: isMinus(false)
{
}

TripleLong::TripleLong(const string& val)
	: val(val)
{
	isMinus = val[0] == '-';
}

TripleLong::~TripleLong()
{
}

const string TripleLong::SetVal(const string& val)
{
	this->val = val;
	isMinus = val[0] == '-';
	return GetVal();
}

const string TripleLong::GetVal() const
{
	return val;
}

TripleLong& TripleLong::operator=(const TripleLong& rhs)
{
	SetVal(rhs.val);
	return *this;
}

TripleLong TripleLong::operator+(TripleLong& rhs)
{
	int r_size = 0, v_size = 0, ov_size = 0;

	v_size = val.size();
	ov_size = rhs.val.size();
	r_size = min(v_size, ov_size) + 1;

	int i = 0, sum = 0, ten = 0, miss = max(v_size, ov_size) - (r_size - 1);
	string result = "", add = "";
	result.resize(r_size + 1, '0');

	for (i = 0; i < miss; i++)
		add += "0";

	if (v_size > ov_size)
		rhs.val = add + rhs.val;
	else
		val = add + val;

	for (i = r_size - 1; i >= 0; --i)
	{
		sum = (val.c_str()[i] - '0') + (rhs.val.c_str()[i] - '0') + ten;
		ten = sum / 10;
		sum = sum % 10;
		result[i + 1] = sum + '0';
	}
	result[0] = ten + '0';

	for (i = 0; result[i] == '0'; i++);

	return TripleLong(result.c_str() + i);
}

TripleLong TripleLong::operator-(TripleLong& rhs)
{
	return TripleLong();
}

TripleLong TripleLong::operator*(TripleLong& rhs)
{
	return TripleLong();
}

TripleLong TripleLong::operator/(TripleLong& rhs)
{
	return TripleLong();
}

TripleLong TripleLong::operator%(TripleLong& rhs)
{
	return TripleLong();
}
