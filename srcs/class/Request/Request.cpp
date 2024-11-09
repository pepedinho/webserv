/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Request.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:15:03 by ibaby             #+#    #+#             */
/*   Updated: 2024/11/09 20:07:241 by ibaby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/Request.hpp" 
#include <map>
#include <stdexcept>
#include <string>
#include <variant>

Request::Request() {
	_method = 0;
	_path = "";
	_Host = "";
}

Request::~Request() {
}

int	Request::method( void ) const {
	return (_method);
}

const std::string&	Request::path( void ) const {
	return (_path);
}

const std::string&	Request::host( void ) const {
	return (_Host);
}

const std::string&	Request::find( std::string key ) const {
	if (_others.find(key) == _others.end())
		throw std::invalid_argument(key + "key not found");

	return (_others.at(key));
}

void	Request::method( int newMethod ) {
	_method = newMethod;
}

void	Request::host( std::string newHost ) {
	_Host = newHost;
}

void	Request::path( std::string newPath ) {
	_path = newPath;
}

void Request::addRequest(std::string str) {
	_request += str;
	if (_request.find("\r\n\r\n") == std::string::npos) {
		return ;
	}
	parseRequest();
}

void Request::parseRequest(void) {
	
}

std::ostream& operator<<(std::ostream& os, const Request& request ) {
	os
	<< "Request {\n"
	<< "\t" << "method: ";
	if (request.method() | GET_) {
		os << "GET";
	} else if (request.method() | POST_) {
		os << "POST";
	} else if (request.method() | DELETE_) {
		os << "DELETE";
	} else if (request.method() | OPTIONS_) {
		os << "OPTIONS";
	}  else {
		os << "none";
	} os << std::endl;

	os
	<< "\t" << "path: " << request.path()
	<< "\t" << "host: " << request.host()
	<< std::endl;

	std::map<std::string, std::string>::const_iterator it = request._others.begin(), ite = request._others.end();
	for (it = it; it != ite; it++) {
		std::cout << "\t" << it->first << ": " << it->second << std::endl;
	}

	os << "}" << std::endl;

	return os;
}