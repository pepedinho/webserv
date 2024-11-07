#ifndef GLOBALDATA_HPP
#define GLOBALDATA_HPP

#include "Server.hpp"
#include "includes.hpp"
#include "utils.hpp"
#include <exception>
#include <vector>
#include <map>

class GlobalData {
	private:
		std::map<int, Server> _servMap;
		int _epoll_fd;
		struct epoll_event _events[MAX_EVENTS];
		void initEpoll(std::vector<Server> &servVec);
		void addToEpoll(int fd, uint32_t events);
		int waitFdsToBeReady(void);
		Client &searchClient(const int fd) const;
		void addNewClient(Server &server);
		void initServers(std::vector<Server> &servVec);
		void handleClientIn(int fd);
	public:
		GlobalData();

		~GlobalData();

		void runServers(std::vector<Server> &servVec);
		void closeServers(void);
};

#endif