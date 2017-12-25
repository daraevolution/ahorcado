/*////////////////////////////////////////////////////////////////////////
//Consiste en el juego del ahorcado que todos conocen. Lo he hecho como //                                                                      
//practica personal de C++ basandome casi al 100% en el estándar ANSI.  //                                                           
//                                                                      //
////////////////////////////////////////////////////////////////////////*/

//Directivas del preprocesador...
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>

using namespace std; //Usamos el espacio de nombre "std" necesario para los flujos de salida y entrada

//Declaramos las variables globales que se usaran
char *palabra = (char *) malloc(21 * sizeof(char));
char NuevaPalabra[21]={'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
char dibujo=1;
char letra;
int aciertos=0;
int intentos = 10;

//Prototipos de las funciones (aun no siendo necesarios la mayoria)
int LongitudCadena();
bool ComprobarError(char letra);
void SeleccionarPalabra(vector<string> VectWords);
void ActualizarPalabra(char letra);
void Dibujar(char dibujo);
bool EsValida(char letra);
void LoadWordsFromFile();


//Load all words from file in a Vector
void LoadWordsFromFile()
{
    string line;
    vector<string> VectWords;

    //Se abre el fichero
	ifstream file("wordslist.txt");
	if (file.is_open())
	{
        //Se comprueba si tiene mas lineas iterando con .good
		while (file.good())
		{
            //Obtiene la linea del fichero
			getline(file,line);
            //Se mete el contenido de la linea del fichero en el vector
            VectWords.push_back(line);
		}
        //Se cierra el fichero
		file.close();
	}
	else
	{
		cout << "Unable to open file" << endl << endl;
	}

    vector<string>::iterator itwords = VectWords.begin();
    while(itwords != VectWords.end())
    {
        cout << " " << *itwords << endl;
        itwords = itwords + 1;
    }
    //Se selecciona la palabra random del vector
    SeleccionarPalabra(VectWords);
    //Se limpia el vector y se libera la memoria
    VectWords.clear();
}

//Funcion que comprueba si el usuario ha acertado o no
bool ComprobarError(char letra)
{
	for(int i=0;i<LongitudCadena();i++)
	{
		if (palabra[i]==letra)
        { 
            return 1;//Devolvemos 1 si hay alguna letra que coincide
        }
	}

	return 0; //Si no, devolvemos 0
}

//Procedimiento que elije una palabra basandose en el resultado de la funcion rand()
void SeleccionarPalabra(vector<string> VectWords)
{
    int SizeVWords = VectWords.size();
    int aleatorio = rand() % SizeVWords;
    string WordSelected = "";
	/* Comprueba que la memoria se asignó correctamente, en caso contrario se gestiona el error. */
	if (palabra == NULL) 
	{
		cout << "No se pudo asignar la memoria" << endl;
	}
	else
	{
		cout << "Se reservo la memoria" << endl;
	}
    WordSelected = VectWords[aleatorio];
    /*
    Se convierte la palabra de string a char pointer con c.str() y
    se rellena el char pointer con strcpy con la palabra convertida.
    */
    strcpy(palabra, WordSelected.c_str());
}


bool EsValida(char letra)
{
	for (int i=0;i<LongitudCadena();i++)
	{
		if (NuevaPalabra[i]==letra)
        { 
            return 0;
        }
	}

	return 1;
}


//Esta funcion devuelve la longitud de la palabra seleccionada
int LongitudCadena()
{
	int longitud=0;
	
	for(int i=0;!(palabra[i]=='\0');i++)
    {
		longitud=longitud+1;
    }
	return longitud;
}

//Este procedimiento simplemente actualiza la palabra del usuario segun sus aciertos
void ActualizarPalabra(char letra)
{
	for (int i=0;i < LongitudCadena();i++)
	{
		if (palabra[i]==letra) 
		{
			NuevaPalabra[i]=letra;
			aciertos+=1;
		}
		else if (NuevaPalabra[i]=='\0')
        { 
            NuevaPalabra[i]='-';
        }
	}
}

//Este otro muestra el dibujito. Hay varios, segun los errores cometidos hasta el momento
void Dibujar(char dibujo)
{

	switch (dibujo)
	{
        case 1:
            cout << "_______________" << endl;
            break; 
        case 2:
            cout << endl << "Ahorcado 1.0 by DaraEvolution" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << "|_______________" << endl;
            break;
        case 3:
            cout << endl << "Ahorcado 1.0 by DaraEvolution" << endl;
            cout << "_____________" << endl;
            cout << "|" << endl;
            cout << "|" << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << "|_______________" << endl;
            break;             
        case 4:
            cout << endl << "Ahorcado 1.0 by DaraEvolution" << endl;
            cout << "_____________" << endl;
            cout << "|           |" << endl;
            cout << "|           |" << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << "|_______________" << endl;
            break;

        case 5:
            cout << endl << "Ahorcado 1.0 by DaraEvolution" << endl;
            cout << "_____________" << endl;
            cout << "|           |" << endl;
            cout << "|           |" << endl;
            cout << "|          (_)" << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << "|_______________" << endl;
            break;

        case 6:
            cout << endl << "Ahorcado 1.0 by DaraEvolution" << endl;
            cout << "_____________" << endl;
            cout << "|           |" << endl;
            cout << "|           |" << endl;
            cout << "|          (_)" << endl;
            cout << "|           |" << endl;
            cout << "|           |" << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << "|_______________" << endl;
            break;

        case 7:
            cout << endl << "Ahorcado 1.0 by DaraEvolution" << endl;
            cout << "_____________" << endl;
            cout << "|           |" << endl;
            cout << "|           |" << endl;
            cout << "|          (_)" << endl;
            cout << "|           |" << endl;
            cout << "|          /|" << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << "|_______________" << endl;
            break;

        case 8:
            cout << endl << "Ahorcado 1.0 by DaraEvolution" << endl;
            cout << "_____________" << endl;
            cout << "|           |" << endl;
            cout << "|           |" << endl;
            cout << "|          (_)" << endl;
            cout << "|           |" << endl;
            cout << "|          /|\\" << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << "|_______________" << endl;
            break;

        case 9:
            cout << endl << "Ahorcado 1.0 by DaraEvolution" << endl;
            cout << "_____________" << endl;
            cout << "|           |" << endl;
            cout << "|           |" << endl;
            cout << "|          (_)" << endl;
            cout << "|           |" << endl;
            cout << "|          /|\\" << endl;
            cout << "|          / " << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << "|_______________" << endl;
            break;

        case 10:
            cout << endl << "Ahorcado 1.0 by DaraEvolution" << endl;
            cout << "_____________" << endl;
            cout << "|           |" << endl;
            cout << "|           |" << endl;
            cout << "|          (_)" << endl;
            cout << "|           |" << endl;
            cout << "|          /|\\" << endl;
            cout << "|          / \\" << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << '|' << endl;
            cout << "|_______________" << endl;
            cout << "THE END!!!!!!!!!" << endl;
            break;
	}
}



int main()
{
	srand(time(0));//Llamo a esta funcion para rand() se base despues en la hora del sistema
	               //para generar el numero aleatorio. Si no lo hiciera siempre serian
				   //los mismos.
    LoadWordsFromFile();
	ActualizarPalabra('a');//Y la mostramos en pantalla, quitando todos los caracteres excepto la a

  	for(;dibujo<intentos;)
	{
		if (aciertos==LongitudCadena())
		{
			Dibujar(dibujo);
			cout << endl << "Enhorabuena!!, has ganado, la palabra era: " << palabra <<	endl << endl;
            cout << "Se liberaran los punteros de char" << endl;
			free(palabra);
			return 0;
		}
			
		//system("clear");
		Dibujar(dibujo);
		cout << endl;
		cout << NuevaPalabra << endl << endl;	
		cout << "Introduce la letra que busques: ";
		cin >> letra;
		if (!EsValida(letra))
		{
			continue;
		}

		cout << endl;
		//system("clear");
		if (ComprobarError(tolower(letra)))
		{
			ActualizarPalabra(tolower(letra));
		}
		else
		{
			dibujo+=1;
		}
	} 
	Dibujar(dibujo);
	cout << "Has perdido..." << endl;
	cout << "La palabra era: " << palabra << endl << endl << endl;
	cout << "Se liberaran los punteros de char" << endl;
	free(palabra);
	return 0;
}