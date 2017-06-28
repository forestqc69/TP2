/**
 * \file Graphe.h
 * \brief Gestion d'un graphe.
 * \author IFT-2008
 * \version 0.5
 * \date juin 2017
 *
 *  Travail pratique numéro 2
 *
 */

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <list>
//Vous pouvez ajouter d'autres librairies de la STL

#ifndef _GRAPHE__H
#define _GRAPHE__H

namespace TP2
{

/**
* \struct Ponderations
* \brief Une struture utilisée pour stocker les pondérations utilisées sur les arcs
*/
struct Ponderations
{
	float duree;		// La durée du trajet en heures (ex. 3.15 heures entre Québec et Montréal)
	float cout;			// Le cout du trajet en dollars (ex. 70.50 $ entre Québec et Montréal)

	Ponderations(float d, float c) : duree(d), cout(c) {}
};

/**
 * \class Graphe
 * \brief Classe représentant un graphe
 */
class Graphe
{
public:

	Graphe(size_t nbSommets = 10);
	~Graphe();

	// Change la taille du graphe en utilisant un nombre de sommet = nouvelleTaille
	void resize(size_t nouvelleTaille);

	// Donne un nom à un sommet en utlisant son numéro (indice dans le vector).
	void nommer(size_t sommet, const std::string& nom);

	// Ajoute un arc au graphe
	void ajouterArc(size_t source, size_t destination, float duree, float cout);

	// Supprime un arc du graphe
	void enleverArc(size_t source, size_t destination);

	// Vérifie si un arc existe
	bool arcExiste(size_t source, size_t destination) const;

	// Retourne la liste de successeurs d'un sommmet
	std::vector<size_t> listerSommetsAdjacents(size_t sommet) const;

	// Retourne le nom d'un sommet
	std::string getNomSommet(size_t sommet) const;

	// Retourne le numéro d'un sommet
	size_t getNumeroSommet(const std::string& nom) const;

	// Retourne le nombre de sommet du graphe
	int getNombreSommets() const;

	// Retourne le nombre des arcs du graphe
	int getNombreArcs() const;

	// Retourne les pondérations se trouvant dans un arc (source -> destination)
	Ponderations getPonderationsArc(size_t source, size_t destination) const;

	//Ne touchez pas à cette fonction !
	friend std::ostream& operator<<(std::ostream& out, const Graphe& g)
	{
		out << "Le graphe contient " << g.nbSommets << " sommet(s) et " 
			<< g.nbArcs << " arc(s)" << std::endl << std::endl;
		for (size_t i = 0; i < g.nbSommets; ++i) 
		{
			out << "Sommet " << g.noms[i] << ": " << std::endl << "Voisins: ";

			if (g.listesAdj[i].size() == 0) 
				out << "Rien";
			else 
			{
				for (auto it = g.listesAdj[i].begin(); it != g.listesAdj[i].end(); ++it) 
					out << g.noms[it->destination] << ", ";
			}
			out << std::endl;
		}
		return out;
	}

	//Vous pouvez ajoutez d'autres méthodes publiques si vous sentez leur nécessité

private:

	std::vector<std::string> noms; /*!< les noms des sommets */

	struct Arc
	{
		size_t destination;
		Ponderations poids;

		Arc(size_t dest, Ponderations p) : destination(dest), poids(p) {}
	};

	std::vector<std::list<Arc> > listesAdj; /*!< les listes d'adjacence */


	size_t nbSommets;	// Le nombre de sommets dans le graphe
	size_t nbArcs;		// Le nombre des arcs dans le graphe


	//Vous pouvez ajoutez des méthodes privées si vous sentez leur nécessité

};

}//Fin du namespace

#endif
