/* Level 9 Group B 
 * by Jahaan Rawat 
 */


#ifndef OPTIONS_TYPE_EXCEPTION_H
#define OPTIONS_TYPE_EXCEPTION_H

#include <iostream>

class NoOptionException {
private:
	std::string error_message = "Please add Option! (Perpetual American Exception Option Available only";

public:
	NoOptionException() {};
	~NoOptionException() {};

	std::string display_error() const {
		return error_message;
	}
};

#endif
