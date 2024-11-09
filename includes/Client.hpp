#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "RawBits.hpp"
#include "Request.hpp"

class Client {
	private:
		int _fd;
		bool _readyToResponse;
		Request _request;
	public:
		Client();
		~Client();

		int getClientFd(void) const;
		void setReadyToresponse(bool boolean);
		bool const &isReadyToResponse(void) const; 
		void setClientFd(int fd);
		void pushRequest(char str[BUFFER_SIZE]);
};

#endif