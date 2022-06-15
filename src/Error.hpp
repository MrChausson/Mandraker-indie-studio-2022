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

class MissingModelType : public AError {
    public:
        MissingModelType(std::string msg) {this->_msg = msg;};
};

class MissingCollisionableComponent : public AError {
    public:
        MissingCollisionableComponent(std::string msg) {this->_msg = msg;};
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

class CameraNotFound : public AError {
    public:
        CameraNotFound() {this->_msg = "CameraComponent not found"; };
};

class PlacableNotFound : public AError {
    public:
        PlacableNotFound() {this->_msg = "Placable Component not found"; };
};

#endif /* !ERROR_HPP_ */
