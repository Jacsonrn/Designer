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
/* Feito pelo aluno em 10 de junho de 2026 */
class Line: public Shape {
public:
    Line(int R=0, int G=0, int B=0, double W=1.0, double X1=0.0, double Y1=0.0, double X2=0.0, double Y2=0.0) : Shape(R, G, B, W), x1(X1), y1(Y1), x2(X2), y2(Y2) {}
    pShape clone() const override { return new Line(*this); }
    void read(std::istream& X) override;
    void save(std::ostream& X) const override;
private:
    double x1, y1, x2, y2;
};

/// Classe que representa circulos
/* /* Feito pelo aluno em 10 de junho de 2026 */ 
class Circle: public FilledShape {
public:
    Circle(int R=0, int G=0, int B=0, double W=1.0, bool F=true, double XC=0.0, double YC=0.0, double RC=0.0) : FilledShape(R, G, B, W, F), xc(XC), yc(YC), rc(RC) {}
    pShape clone() const override { return new Circle(*this); }
    void read(std::istream& X) override;
    void save(std::ostream& X) const override;
private:
    double xc, yc, rc;
};

/// Classe que representa estrelas
/* Feito pelo aluno em 10 de junho de 2026 */
class Star: public FilledShape {
public:
    Star(int R=0, int G=0, int B=0, double W=1.0, bool F=true, double XC=0.0, double YC=0.0, double RC=0.0) : FilledShape(R, G, B, W, F), xc(XC), yc(YC), rc(RC) {}
    pShape clone() const override { return new Star(*this); }
    void read(std::istream& X) override;
    void save(std::ostream& X) const override;
private:
    double xc, yc, rc;
};


/// Classe que representa retangulos
/* /* Feito pelo aluno em 10 de junho de 2026 */
class Rectangle: public FilledShape {
public:
    Rectangle(int R=0, int G=0, int B=0, double W=1.0, bool F=true, double XMin=0.0, double XMax=0.0, double YMin=0.0, double YMax=0.0) : FilledShape(R, G, B, W, F), xmin(XMin), xmax(XMax), ymin(YMin), ymax(YMax) {}
    pShape clone() const override { return new Rectangle(*this); }
    void read(std::istream& X) override;
    void save(std::ostream& X) const override;
private:
    double xmin, xmax, ymin, ymax;
};

/// Classe que representa losangos
/* Feito pelo aluno em 10 de junho de 2026 */
class Rombo: public FilledShape {
public:
    Rombo(int R=0, int G=0, int B=0, double W=1.0, bool F=true, double XMin=0.0, double XMax=0.0, double YMin=0.0, double YMax=0.0) : FilledShape(R, G, B, W, F), xmin(XMin), xmax(XMax), ymin(YMin), ymax(YMax) {}
    pShape clone() const override { return new Rombo(*this); }
    void read(std::istream& X) override;
    void save(std::ostream& X) const override;
private:
    double xmin, xmax, ymin, ymax;
};

/// Classe que representa triangulos
/* Feito pelo aluno em 10 de junho de 2026 */
class Triangle: public FilledShape {
public:
    Triangle(int R=0, int G=0, int B=0, double W=1.0, bool F=true, double X1=0.0, double Y1=0.0, double X2=0.0, double Y2=0.0, double X3=0.0, double Y3=0.0) : FilledShape(R, G, B, W, F), x1(X1), y1(Y1), x2(X2), y2(Y2), x3(X3), y3(Y3) {}
    pShape clone() const override { return new Triangle(*this); }
    void read(std::istream& X) override;
    void save(std::ostream& X) const override;
private:
    double x1, y1, x2, y2, x3, y3;
};

#endif // _SHAPE_H_
