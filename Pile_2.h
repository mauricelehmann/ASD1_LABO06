#ifndef Pile_hpp
#define Pile_hpp

#include <ostream>
#include <iostream>
// Forward declarations
template <typename T> class Pile;
template <typename T> std::ostream& operator<<( std::ostream& os,
                                               const Pile<T>& p);

// Type Pile
template <typename T>
class Pile {
  friend std::ostream& operator<< <>( std::ostream& os,
                                     const Pile<T>& p);

public:
  using value_type = T;
  using pointer = value_type*;
  using reference = value_type&;
  using const_reference = const value_type&;

private:
  pointer donnees;
  size_t taille;
  const size_t CAPACITE;

public:
  Pile(size_t _capacite)
  : CAPACITE(_capacite), taille(0)
  {
    donnees = (pointer) ::operator new(CAPACITE * sizeof(value_type));
  }

  ~Pile()
  {
    for (int i = 0 ; i < taille; i++) {
        //On détruit les objets via leur destructeur
        (donnees+i)->value_type::~value_type();
    }
    //On libère la mémoire alouée
    ::operator delete(donnees);
  }

  Pile(const Pile& other)
  :CAPACITE(other.CAPACITE), taille(other.taille)
  {
    donnees = (pointer) ::operator new(CAPACITE * sizeof(value_type));
    for (size_t i = 0; i < taille; i++) {
        pointer newObject = new(donnees+i) value_type(other.donnees[i]);
    }
  }

  void empiler(const value_type& v)
  {
    if(taille <= CAPACITE){
        pointer newObject = new(donnees+taille++) value_type(v);
    }else{
        throw "La pile est pleine!\n";
    }
  }

  void depiler()
  {
    if(taille > 0){
        //On detruit l'objet en mémoire via son destructeur
        (donnees+taille - 1)->value_type::~value_type();
        //On réduit la taille
        taille--;
    }else{
        throw "La pile est vide!\n";
    }
  }

  const_reference sommet() const
  {
    return donnees[taille-1];
  }

};

// ne pas modifier
template <typename T>
std::ostream& operator<<( std::ostream& os,
                         const Pile<T>& p)
{
  os << "Pile(" << p.taille << "/" << p.CAPACITE << "): ";
  size_t i = p.taille;
  while(i > 0)
    os << p.donnees[--i] << " ";
  return os;
}

#endif /* Pile_hpp */
