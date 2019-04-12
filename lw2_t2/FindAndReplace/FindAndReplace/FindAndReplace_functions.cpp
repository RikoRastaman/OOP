#include "pch.h"
#include <string>
#include "FindAndReplace_functions.h"

std::string findAndReplace(std::string& originalString, const std::string& search, const std::string& replace)
{
	if ((search == "") || (replace == ""))
	{
		return originalString;
	}
	size_t pos = 0;
	while ((pos = originalString.find(search, pos)) != std::string::npos) {
		originalString.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return originalString;
}