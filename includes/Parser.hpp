/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahri <itahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:32:51 by itahri            #+#    #+#             */
/*   Updated: 2024/11/07 15:21:23 by itahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_HPP
#define PARSER_HPP

#include "includes.hpp"
#include "Server.hpp"

#define GET_ 1;
#define POST_ 2;
#define DELETE_ 3;

struct Data {
  public:
    Data();
    ~Data();
    Data& operator=(const Data& src);
    int           _port;
    std::string   _serverName;
    std::string   _root;
    std::string   _uploadFolder;
    int           _allowedMethodes;
    std::string   _errorPage;
    bool          _autoIndex;
    std::string   _cgi; // temporary a string maybe a special struc later
    unsigned int  _clientMaxBodySize;
    std::string   _location;
    std::string   _index;
};

class Pars {
  private:
    static std::vector<Server>& parseConfigFile(std::string configFilePath);
    static void parseConfigPath(std::string path);
    static void handleLine(std::string &line, Data *data, int &lineNumber);
    static void parseServer(Server &serv, std::ifstream& configFile, int &lineNumber);

  public:
    static std::vector<Server> parse(std::string path);

    void addPort(Data* data, std::string port);
    void addServName(Data* data, std::string name);
    void addRootDir(Data* data, std::string path);
    void addUpFoldDir(Data* data, std::string path);
    void addAllowedMethodes(Data* data, std::string w);
    void addErrPage(Data* data, std::string path);
    void addAutoIndex(Data* data, std::string w);
    void addCgi(Data* data, std::string cgi);
    void addClientMBodyS(Data* data, std::string size);
    void addLocationDir(Data* data, std::string loc);
    void addIndex(Data* data, std::string index);
};

std::string trim(const std::string& str);
void trimn(std::string& str);

#endif
