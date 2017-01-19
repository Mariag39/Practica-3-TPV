#include "Error.h"



Error::Error(string const& msg): msgError(msg)
{
	
}

const string& Error::mensaje() {
	return msgError;
}

Error::~Error()
{
}
