#include <stdlib.h>  //Libreria para limpiar pantalla
#include <iostream>
using namespace std;

#include "Clases Principales/Inicializar.cpp"

class Simulacion {
private: 

	Lista < Ciudad > * ciudades;
    Lista < Partido > * partidos;
    Lista < Candidato > * candidatos;
    Lista < Elecciones > * totalElecciones;

    Inicializar inicializar;
    OpcionesListas opcionLista; // Inicializa el objeto de la clase Opciones Listas
public:

    int Opcion;

    //Muestra de Menus
    void MostrarMenu();
    void SubMenuListas();
    void SubMenuConsultas();
    void SubMenuEstadisticas();
    void SubMenuInsercion();
    void EleccionSubMenuInsercion();
    string elegirPartido(); 
    string elegirCiudad(); 

    //Bloque de ejecuci�n
    void Menu();

    //Leer Archivos e inicializar Listas
    void leerArchivos() {

        Archivos Ciudades("Ciudades");
        Archivos Partidos("Partidos");
        Archivos Candidatos("Candidatos");

        ciudades = Ciudades.leerCiudades();
        partidos = Partidos.leerPartidos();
        candidatos = Candidatos.leerCandidatos();

        totalElecciones = new Lista < Elecciones > ;

    }
};

void Simulacion::Menu() {
    bool programa = true;

    leerArchivos();

    OpcionesConsultas opcionConsultas(ciudades, partidos, candidatos); // Inicializa el objeto de la clase Opciones Consultas
    OpcionesSimulacion opcionesSimulacion(ciudades, partidos, candidatos, totalElecciones);
    OpcionesEstadisticas opcionesEstadisticas(ciudades, partidos, candidatos, totalElecciones);

    while (programa) { // Bucle infinito del programa
        system("cls");
        MostrarMenu();
        Opcion = leerEntrada(1,6);

        switch (Opcion) {
            case 1: {
                system("cls"); // Limpia pantalla
                SubMenuListas(); // Muestra men�
                Opcion = leerEntrada(1,8);
                switch (Opcion) {
                    case 1: {
                        opcionLista.mostrarCiudades(ciudades);
                        system("Pause"); // Pausa el programa y espera a que se presione una tecla
                        break;
                    }
                    case 2: {
                        opcionLista.mostrarPartidos(partidos);
                        system("Pause"); // Pausa el programa y espera a que se presione una tecla
                        break;
                    }
                    case 3: {
                        string ciudad;
                        cout << "Elige la ciudad que desees ver los candidatos al concejo" << endl;
                    	opcionLista.mostrarCiudades(ciudades);
                    	Opcion = leerEntrada(0,ciudades->getTam()-1);
                        opcionLista.candidatosConcejo(ciudades->buscar(Opcion).getNombre(), candidatos);

                        break;
                    }
                    case 4: {
                        string ciudad;
                        cout << "Elige la ciudad que desees ver los candidatos a la alcaldia" << endl;
                    	opcionLista.mostrarCiudades(ciudades);
                        Opcion = leerEntrada(0,ciudades->getTam()-1);
                        opcionLista.candidatosAlcaldia(ciudades->buscar(Opcion).getNombre(), candidatos);
                        break;
                    }
                    case 5: {
                        opcionLista.candidatosAlcaldiaConsejoPartido("Alcaldia", candidatos, partidos);
                        break;
                    }
                    case 6: {
                        opcionLista.candidatosAlcaldiaConsejoPartido("Concejo", candidatos, partidos);

                        break;
                    }
                    case 7: {
                        opcionLista.candidatosAlcaldiaConsejoPartidoLista("Concejo", candidatos, partidos);
                        break;
                    }
                    case 8: {
                        opcionLista.candidatosAlcaldiaConsejoPartidoLista("Alcaldia", candidatos, partidos);
                        break;
                    }
                }
                break;
            }
            case 2: {
                system("cls");
                SubMenuConsultas();
                Opcion = leerEntrada(1,7);
                switch (Opcion) {
                    case 1: {
                        string partido, ciudad;
                        partido = elegirPartido();
                        ciudad = elegirCiudad();
                        opcionConsultas.consulta1(partido, ciudad);
                        break;
                    }
                    case 2: {
                        string partido;
                        partido = elegirPartido();
                        opcionConsultas.consulta2(partido);
                        break;
                    }
                    case 3: {
                        string partido;
                        partido = elegirPartido();
                        opcionConsultas.consulta3(partido);
                        break;
                        break;
                    }
                    case 4: {
                        string ciudad;
                        ciudad = elegirCiudad();
                        opcionConsultas.consulta4(ciudad);
                        break;
                    }
                    case 5: {
                        string ciudad;
                        ciudad = elegirCiudad();
                        opcionConsultas.consulta5(ciudad);
                        break;
                    }
                    case 6: {
                        string ciudad;
                        ciudad = elegirCiudad();
                        opcionConsultas.consulta6(ciudad);
                        break;
                    }
                    case 7: {
                        opcionConsultas.consulta7( * ciudades);
                        break;
                    }
                }
                break;
            }
            case 3: {
                system("cls");
                SubMenuEstadisticas();
                Opcion = leerEntrada(1,3);
                switch (Opcion) {
                    case 1: {
                        opcionesEstadisticas.estadisticaPorCiudad();
                        system("pause");
                        break;
                    }
                    case 2: {
                        cout << "Ingrese el tipo de eleccion: 1.Alcaldia 2.Concejo" << endl;
                        Opcion = leerEntrada(1,2);
                        if (Opcion == 1) {
                            opcionesEstadisticas.estadisticaEleccion("Alcaldia");

                        } else if (Opcion == 2) {
                            opcionesEstadisticas.estadisticaEleccion("Concejo");

                        }
                        system("pause");

                        break;
                    }
                    case 3: {
                        cout << "Ingrese el tipo de eleccion: 1.Alcaldia 2.Concejo" << endl;
                        Opcion = leerEntrada(1,2);
                        if (Opcion == 1) {
                            opcionesEstadisticas.estadisticaNacional("Alcaldia");

                        } else if (Opcion == 2) {
                            opcionesEstadisticas.estadisticaNacional("Concejo");

                        }
                        system("pause");

                        break;
                    }
                }
                break;
            }
            case 4: {
                system("cls");
                // REALIZAR SIMULACION 1.
                //SIMULAR 2. TODOS LOS VOTOS DE LA SIMULACION SE REINICIAN
                opcionesSimulacion.simularVotos();
                break;
            }
            case 5: {
                system("cls");
                SubMenuInsercion();
                Opcion = leerEntrada(1,3);

                string caso;

                switch (Opcion) {
                    case 1: { //Opciones para insertar
                        EleccionSubMenuInsercion();
                        Opcion = leerEntrada(1,3);
                        switch (Opcion) {
                            case 1: {
                                //Creaci�n del Objeto partido
                                Partido NuevoPartido = inicializar.inicializarPartido(partidos);
                                //Inserci�n en la lista de partidos
                                partidos -> insertar(NuevoPartido);

                                Opcion = 0;
                                break;
                            }
                            case 2: { // Insertar Candidato (Se necesita validaci�n de puesto, fecha nacimiento, estado civil)

                                //Creacion del objeto candidato para a�adirlo en la lista
                                Candidato nuevoCandidato = inicializar.inicializarCandidato(partidos, ciudades, candidatos);
                                //Inserci�n en la lista de candidatos
                                if(!(nuevoCandidato.getNombre() == ""))
                                    candidatos -> insertar(nuevoCandidato);
                                break;
                            }
                            case 3: {
                                //Se ingresan los datos de la nueva ciudad (Se necesita validaci�n cuando la ciudad ya existe)
                                //Creaci�n del Objeto Ciudad
                                Ciudad NuevaCiudad = inicializar.inicializarCiudad();
                                //Insercion en la lista de ciudades
                                ciudades -> insertar(NuevaCiudad);
                                break;
                            }
                        }
                        break;
                    }
                    case 2: { //Opciones para Modificar
                        EleccionSubMenuInsercion();
                        Opcion = leerEntrada(1,3);
                        switch (Opcion) {
                            case 1: {
                                //Encontrar el partido a modificar
                                string NombrePartido, RepresentanteLegal;
                                cout << "�Que partido deseas modificar?" << endl;
                                opcionLista.mostrarPartidos(partidos);
                                Opcion = leerEntrada(0,partidos->getTam()-1);

                                string auxNombrePartido = partidos->buscar(Opcion).getNombre();

                                //Inicializar Partido
                                Partido NuevoPartido = inicializar.inicializarPartido(partidos);

                                partidos -> modificar(NuevoPartido, Opcion);

                                for(int i = 0; i < candidatos->getTam(); i++)
                                {
                                    Candidato auxCandidato = candidatos->buscar(i);
                                    if(auxCandidato.getPartido().getNombre() == auxNombrePartido)
                                    {
                                        auxCandidato.setPartido(NuevoPartido);
                                        candidatos->modificar(auxCandidato,i);
                                    }

                                }

                                break;
                            }
                            case 2: { //Modificar Candidato

                                // Encontrar el candidato a modificar
                                int Opcion;

                                cout << "Selecciona el candidato que deseas modificar" << endl;
                                opcionLista.mostrarCandidatos(candidatos);
                                Opcion = leerEntrada(0,candidatos->getTam()-1);

                                // Creaci�n del objeto candidato para a�adirlo en la lista
                                Candidato nuevoCandidato = inicializar.inicializarCandidato(partidos, ciudades, candidatos);

                                // Inserci�n en la lista de candidatos
                                candidatos -> modificar(nuevoCandidato, Opcion);
                                break;
                            }
                            case 3: { //Modificar Ciudad

                                //Enconntrar la ciudad a modificar (Se necesita validaci�n cuando la ciudad ya existe)
                                string nombre, departamento;
                                int tamConcejo, censoElectoral, ciudad;
                                cout << "Selecciona la ciudad que desea modificar" << endl;
                                opcionLista.mostrarCiudades(ciudades);
                                ciudad = leerEntrada(0,ciudades->getTam()-1);

                                string auxNombreCiudad = ciudades->buscar(ciudad).getNombre();

                                //Creaci�n del Objeto Ciudad
                                Ciudad NuevaCiudad = inicializar.inicializarCiudad();
                                //Insercion en la lista de ciudades
                                ciudades -> modificar(NuevaCiudad, ciudad);

                                for(int i = 0; i < candidatos->getTam(); i++)
                                {
                                    Candidato auxCandidato = candidatos->buscar(i);
                                    if(auxCandidato.getCiudadNacimiento().getNombre() == auxNombreCiudad)
                                    {
                                        auxCandidato.setCiudadNacimiento(NuevaCiudad);
                                        candidatos->modificar(auxCandidato,i);
                                    }
                                    if(auxCandidato.getCiudadResidencia().getNombre() == auxNombreCiudad)
                                    {
                                        auxCandidato.setCiudadResidencia(NuevaCiudad);
                                        candidatos->modificar(auxCandidato,i);
                                    }

                                }
                                break;
                            }
                        }
                        break;
                    }
                    case 3: { //Opciones para Eliminar //Validaci�n, Si se eliminan partido, los Candidatos con ese partido quedan sin partido
                        EleccionSubMenuInsercion();
                        Opcion = leerEntrada(1,3);
                        switch (Opcion) {
                            case 1: { //Eliminar Partido
                                int Eleccion;
                                cout << "�Que partido deseas Eliminar?" << endl;
                                opcionLista.mostrarPartidos(partidos);
                                Eleccion = leerEntrada(0,partidos->getTam()-1);
                                //Guardar un partido auxiliar para eliminar los candidatos con ese partido
								Partido partidoAux = partidos->buscar(Eleccion);
								
                                partidos -> borrar(Eleccion);
                                
                                for(int i = 0; i < candidatos->getTam(); i++){
                                	Candidato candidatoAux = candidatos->buscar(i);
                                    string aux1 = candidatoAux.getPartido().getNombre();
                                    string aux2 = partidoAux.getNombre();

                                	if(candidatoAux.getPartido().getNombre() == partidoAux.getNombre()){
                                		candidatos->borrar(i);
									}
                                    candidatoAux = candidatos->buscar(i);
                                    while(candidatoAux.getPartido().getNombre() == partidoAux.getNombre())
                                    {
                                        candidatos->borrar(i);
                                        candidatoAux = candidatos->buscar(i);
                                    }
								}

								system("Pause");
								
                                break;
                            }
                            case 2: { //Eliminar Candidato

                                cout << "�Que candidato deseas Eliminar?" << endl;
                                opcionLista.mostrarCandidatos(candidatos);
                                Opcion = leerEntrada(0,candidatos->getTam()-1);

                                candidatos -> borrar(Opcion);

                                break;
                            }
                            case 3: { // Eliminar Ciudades

                                cout << "�Que ciudades deseas Eliminar?" << endl;
                                opcionLista.mostrarCiudades(ciudades);
                                Opcion = leerEntrada(0, ciudades->getTam()-1);
								
								Ciudad ciudadAux = ciudades->buscar(Opcion);
								
                                ciudades -> borrar(Opcion);
                                
                                //Borrar los candidatos que residan en esa ciudad
                                
                                for(int i = 0; i < candidatos->getTam(); i++){
                                	Candidato candidatoAux = candidatos->buscar(i);
                                	if(candidatoAux.getCiudadResidencia().getNombre() == ciudadAux.getNombre()){
                                		candidatos->borrar(i);
									}
                                    candidatoAux = candidatos->buscar(i);
                                    while(candidatoAux.getCiudadResidencia().getNombre() == ciudadAux.getNombre())
                                    {
                                        candidatos->borrar(i);
                                        candidatoAux = candidatos->buscar(i);
                                    }

								}
								
                                break;
                            }
                        }
                        break;
                    }
                }
                Opcion = 0;
                opcionConsultas.actualizar(ciudades, partidos, candidatos);
                break;
            }
            case 6: {
                system("cls");
                //FINALIZAR Y GUARDAR EN LOS ARCHIVOS PLANOS

                //Escribir en el archivo plano los partidos de la lista
                Archivos Partidos("Partidos");
                string textoPartidos;

                for (int i = 0; i < partidos -> getTam(); i++) {
                    Partido partido = partidos -> buscar(i); // Declaraci�n del partido de la lista para a�adir su informaci�n al texto plano
                    textoPartidos += partido.getNombre() + "," + partido.getRepresentanteLegal() + "\n";
                }

                Partidos.escribir(textoPartidos);

                //Escribir en el archivo plano las ciudades de la lista

                Archivos Ciudades("Ciudades");
                string textoCiudades;

                for (int i = 0; i < ciudades -> getTam(); i++) {
                    Ciudad ciudad = ciudades -> buscar(i);
                    textoCiudades += ciudad.getNombre() + "," + ciudad.getDepartamento() + "," + to_string(ciudad.getTamConcejo()) + "," + to_string(ciudad.getCensoElectoral()) + "\n";
                }

                Ciudades.escribir(textoCiudades);

                //Escribir en el archivo plano los candidatos de la lista

                Archivos Candidatos("Candidatos");
                string textoCandidatos;

                for (int i = 0; i < candidatos -> getTam(); i++) {
                    Candidato candidato = candidatos -> buscar(i);
                    textoCandidatos += candidato.getNombre() + "," + candidato.getApellido() + "," + candidato.getPuesto() + "," + candidato.getNumIdentificacion() + "," + candidato.getSexo() + "," + candidato.getEstadoCivil() + "," + candidato.getFechaNacimiento() + "," + candidato.getCiudadNacimiento().getNombre() + "," + candidato.getCiudadResidencia().getNombre() + "," + candidato.getPartido().getNombre()+",0\n";
                }
                
                Candidatos.escribir(textoCandidatos);

                programa = false;
                break;
            }
        }
    }
}
void Simulacion::MostrarMenu() {
    cout << "Registraduria Nacional del Estado Civil" << endl;
    cout << "Menu Principal" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "1. Buscar listas por categoria" << endl;
    cout << "2. Realizar consultas" << endl;
    cout << "3. Obtener Estadisticas" << endl;
    cout << "4. Simular Proceso electoral" << endl;
    cout << "5. Insertar, Modificar y Eliminar" << endl;
    cout << "6. Salir" << endl;
}

void Simulacion::SubMenuListas() {
    cout << "Buscar Listas por categoria" << endl;
    cout << "1. Ciudades para las cuales se realizar� el proceso electoral." << endl;
    cout << "2. Partidos legalmente reconocidos." << endl;
    cout << "3. Todos los candidatos al concejo de una ciudad." << endl;
    cout << "4. Todos los candidatos a la alcald�a de una ciudad." << endl;
    cout << "5. Candidatos a cada una de las alcald�as, por partido." << endl;
    cout << "6. Candidatos a cada uno de los concejos, por partido." << endl;
    cout << "7. Por cada partido, la lista de candidatos a los concejos." << endl;
    cout << "8. Por cada partido, la lista de candidatos a las alcald�as." << endl;

}

void Simulacion::SubMenuConsultas() {
    cout << "Realizar una consulta" << endl;
    cout << "1. Dado un partido y una ciudad, mostrar la lista de sus candidatos al Concejo y el candidato a la alcald�a." << endl;
    cout << "2. Dado un partido mostrar la lista de candidatos a alcald�as de cada una de las diferentes ciudades." << endl;
    cout << "3. Dado un partido mostrar las listas de candidatos a cada uno de los diferentes concejos." << endl;
    cout << "4. Dada una ciudad, mostrar por cada partido, el candidato a la alcald�a y los candidatos al concejo" << endl;
    cout << "5. Dada una ciudad, mostrar el tarjet�n de candidatos a la alcald�a." << endl;
    cout << "6. Dada una ciudad, mostrar el tarjet�n de candidatos al concejo." << endl;
    cout << "7. Censo electoral. Por cada ciudad, mostrar la cantidad de personas habilitadas para votar." << endl;
}

void Simulacion::SubMenuEstadisticas() {
    cout << "Estadisticas" << endl;
    cout << "1. Ver el reporte por ciudad" << endl;
    cout << "2. Ver el reporte por alcaldia o concejo" << endl;
    cout << "3. Ver el reporte total nacional" << endl;
}

void Simulacion::SubMenuInsercion() {
    cout << "1. Insertar" << endl;
    cout << "2. Modificar" << endl;
    cout << "3. Eliminar" << endl;
}

void Simulacion::EleccionSubMenuInsercion() {
    cout << "1. Partido" << endl;
    cout << "2. Candidato" << endl;
    cout << "3. Ciudad" << endl;
}

string Simulacion::elegirPartido()
{
    int pos = 0;
    cout << "Escriba el número del partido que desea elegir: " << endl;
    opcionLista.mostrarPartidos(partidos);
    pos = leerEntrada(0,partidos->getTam()-1);
    return partidos->buscar(pos).getNombre();
}

string Simulacion::elegirCiudad()
{
    int pos = 0;
    cout << "Escriba el número de la ciudad que desea elegir: " << endl;
    opcionLista.mostrarCiudades(ciudades);
    pos = leerEntrada(0,ciudades->getTam()-1);
    return ciudades->buscar(pos).getNombre();
}


