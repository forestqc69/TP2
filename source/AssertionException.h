/**
 * \file   AssertionException.h
 * \brief  Fichier contenant la déclaration de la classe AssertionException.
 * \author IFT-2008
 * \version 0.5
 * \date juin 2017
 */

#ifndef ASSERTIONEXCEPTION_H
#define ASSERTIONEXCEPTION_H

#include <string>
#include <stdexcept>
#include <sstream>

/**
 * \class AssertionException
 * \brief Classe utilitaire pour faciliter le développement. Lancée par la macro définie plus bas.
 */
class AssertionException: public std::logic_error {
public:
	AssertionException(const std::string & p_fichier,
			const unsigned int & p_ligne, const std::string & p_expression) :
			logic_error(""), m_expression(p_expression), m_fichier(p_fichier), m_ligne(p_ligne) {
		std::ostringstream os;
		os << std::endl;
		os << "AssertionException lancée!" << std::endl;
		os << "Fichier : " << m_fichier << std::endl;
		os << "Ligne   : " << m_ligne << std::endl;
		os << "Test    : " << m_expression << std::endl;
		m_message = os.str();
	}
	~AssertionException() throw () {
	}
	;
	const char * what() const throw (){
		return m_message.c_str();
	}

private:
	std::string m_expression;
	std::string m_fichier;
	std::string m_message;
	unsigned int m_ligne;
};

// --- Mode debug
#if !defined(NDEBUG)
#  define ASSERTION(f)     \
      if (!(f)) throw AssertionException(__FILE__,__LINE__, #f)

// --- Mode release
#else
#  define ASSERTION(f)

#endif  // --- if !defined (NDEBUG)
#endif  // --- ifndef ASSERTIONEXCEPTION_H
