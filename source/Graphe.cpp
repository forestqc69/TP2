/**
 * \file Graphe.cpp
 * \brief Implémentation d'un graphe orienté.
 * \author ?
 * \version 0.5
 * \date ?
 *
 *  Travail pratique numéro 2
 *
 */

#include "Graphe.h"
#include "AssertionException.h"
//vous pouvez inclure d'autres librairies si c'est nécessaire

namespace TP2
{
//Mettez l'implémentation de vos méthodes ici.

TP2::Graphe::Graphe(size_t nbSommets)
		{
}

TP2::Graphe::~Graphe()
{
}

void TP2::Graphe::resize(size_t nouvelleTaille)
		{
}

void TP2::Graphe::nommer(size_t sommet, const std::string& nom)
		{
}

void TP2::Graphe::ajouterArc(size_t source, size_t destination, float duree, float cout)
		{
}

void TP2::Graphe::enleverArc(size_t source, size_t destination)
		{
}

bool TP2::Graphe::arcExiste(size_t source, size_t destination) const
		{
}

std::vector<size_t> TP2::Graphe::listerSommetsAdjacents(size_t sommet) const
		{
}

std::string TP2::Graphe::getNomSommet(size_t sommet) const
		{
}

size_t TP2::Graphe::getNumeroSommet(const std::string& nom) const
		{
}

int TP2::Graphe::getNombreSommets() const
{
}

int TP2::Graphe::getNombreArcs() const
{
}

Ponderations TP2::Graphe::getPonderationsArc(size_t source, size_t destination) const
		{
}
}  //Fin du namespace
