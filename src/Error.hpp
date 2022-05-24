/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_
    #include <exception>
    #include <string>

class AError : public std::exception {
    public:
        std::string what() {return (this->_msg);};
    protected:
        std::string _msg;
};

class Error_file : public AError {
    public:
        Error_file() {this->_msg = "Failed to open the file"; };
        Error_file(std::string filename) {this->_msg = "Failed to open the file " + filename; }; 
};

class ComponentNotFound : public AError {
    public:
        ComponentNotFound(int type) {this->_msg = "Component not found of type " + std::to_string(type) ; };
        ComponentNotFound() {this->_msg = "Component not found"; };
};
#endif /* !ERROR_HPP_ */
