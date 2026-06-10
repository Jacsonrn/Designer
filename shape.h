#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <iostream>

/// ESSE ARQUIVO PODE RECEBER ACRESCIMOS NAS PARTES INDICADAS.
/// AS PARTES JAH IMPLEMENTADAS NAO PODEM SER SUPRIMIDAS OU MODIFICADAS.

class Shape;
using pShape = Shape*;

/// Classe base de todas as formas
class Shape
{
public:
  // Construtor (especifico e default)
  Shape(int R=0, int G=0, int B=0, double W=1.0):
    r(R),
    g(G),
    b(B),
    width(W)
  {}

  /* Feito pelo aluno em 09 de junho de 2026 */
  virtual pShape clone() const = 0;

  // Leh uma forma generica de uma stream.
  // Leh a cor da forma e a largura do contorno.
  virtual void read(std::istream& X);

  // Salva a cor da forma e a largura do contorno em formato SVG
  virtual void save(std::ostream& X) const;

protected:
  // A cor da forma.
  // Precisa ser consultado pela FilledShape (por isso eh protegido).
  int r,g,b;

private:
  // Largura do contorno da forma
  double width=1.0;
};

/// Classe base de todas as formas que podem ser preenchidas ou nao
class FilledShape: public Shape
{
public:
  // Construtor (especifico e default)
  FilledShape(int R=0, int G=0, int B=0, int W=1, bool F=true):
    Shape(R,G,B,W),
    filled(F)
  {}

  // Leh uma forma preenchivel generica de uma stream.
  // Leh cor e largura (usando Shape::read) e depois se eh preenchida ou nao.
  void read(std::istream& X) override;

  // Salva a forma preenchivel em formato SVG.
  // Salva a cor e largura (usando Shape::save) e o depois se eh preenchida ou nao.
  void save(std::ostream& X) const override;

private:
  // forma preenchida ou nao
  bool filled=true;
};

/// Classe que representa linhas
/* ACRESCENTAR */

/// Classe que representa circulos
/* ACRESCENTAR */

/// Classe que representa estrelas
/* ACRESCENTAR */

/// Classe que representa retangulos
/* ACRESCENTAR */

/// Classe que representa losangos
/* ACRESCENTAR */

/// Classe que representa triangulos
/* ACRESCENTAR */

#endif // _SHAPE_H_
