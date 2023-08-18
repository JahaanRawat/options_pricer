/* Level 9 Group A
 * by Jahaan Rawat
 */

#ifndef OPTION_EXCEPTION_TYPE_H
#define OPTION_EXCEPTION_TYPE_H

#include <iostream>
class OptionTypeException {
	public:
		OptionTypeException() {};
		~OptionTypeException() {};

		virtual std::string display_error() const = 0;
};

class PutCallParityException: public OptionTypeException {
	private:
		std::string error_message = "Put Call parity is not applicable!";

	public:
		PutCallParityException() {};
		~PutCallParityException() {};

		std::string display_error() const {
			return error_message;
		}
};

class NotImplementedException: public OptionTypeException {
private:
	std::string error_message = "The following method is not implemented!";

public:
	NotImplementedException() {};
	~NotImplementedException() {};

	std::string display_error() const {
		return error_message;
	}
};


#endif