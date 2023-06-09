#include <string>

class Ciudad {
private: std::string nombre;
    std::string departamento;
    int tamConcejo;
    int censoElectoral;

public:

    Ciudad(): tamConcejo(0),
              censoElectoral(0) {} // Constructor vac�o

    Ciudad(std::string nombre, std::string departamento, int tamConcejo, int censoElectoral) {
        this -> nombre = nombre;
        this -> departamento = departamento;
        this -> tamConcejo = tamConcejo;
        this -> censoElectoral = censoElectoral;
    }

    // M�todos getter para acceder a los atributos
    std::string getNombre() {
        return nombre;
    }
    std::string getDepartamento() {
        return departamento;
    }
    int getTamConcejo() {
        return tamConcejo;
    }
    int getCensoElectoral() {
        return censoElectoral;
    }

    // M�todo toString para la clase Ciudad
    std::string toString() {
        std::string datos;
        datos = getNombre() + "," + getDepartamento() + "," + std::to_string(getTamConcejo()) + "," + std::to_string(getCensoElectoral());
        return datos;
    }
};