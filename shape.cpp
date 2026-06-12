#include <cmath>   /* sin,cos */
#include "shape.h"

/// ESTE ARQUIVO PODE RECEBER ACRESCIMOS NAS PARTES INDICADAS.
/// AS PARTES JAH IMPLEMENTADAS NAO PODEM SER SUPRIMIDAS OU MODIFICADAS.

#define MEU_PI 3.14159265358979323846

using namespace std;

///
/// LEITURA DE FORMAS DO ARQUIVO
///

/// Faz os passos comuns para ler qualquer forma.
/// Leh cor e largura do contorno.
void Shape::read(istream& X)
{
  X >> r >> g >> b >> width;
  if (X.fail() || r<0 || r>255 || g<0 || g>255 || b<0 || b>255 || width<=0.0)
    throw ios_base::failure("invalid shape parameters");
}

/// Faz os passos comuns para ler qualquer forma preenchivel.
/// Leh cor e largura do contorno (usando Shape::read) e depois se eh preenchida.
void FilledShape::read(istream& X)
{
  Shape::read(X); // Gera excecao se houver erro
  int Filled;
  X >> Filled;
  if (X.fail())
    throw ios_base::failure("invalid filled shape parameters");
  filled = (Filled != 0);
}

/// Leh uma linha de uma stream.
/// Leh cor e largura do contorno (usando Shape::read) e depois os 2 pontos.
/* Feito pelo aluno em 11 de junho de 2026 */
void Line::read(istream& X) {
    Shape::read(X);
    X >> x1 >> y1 >> x2 >> y2;
    if (X.fail()) throw ios_base::failure("invalid line parameters");
}

/// Leh um circulo de uma stream.
/// Leh cor, largura do contorno e se eh preenchida (usando FilledShape::read)
/// e depois o centro e o raio.
/* Feito pelo aluno em 11 de junho de 2026 */
void Circle::read(istream& X) {
    FilledShape::read(X);
    X >> xc >> yc >> rc;
    if (X.fail() || rc <= 0.0) throw ios_base::failure("invalid circle parameters");
}

/// Leh uma estrela de uma stream.
/// Leh cor, largura do contorno e se eh preenchida (usando FilledShape::read)
/// e depois o centro e o raio.
/* Feito pelo aluno em 11 de junho de 2026 */
void Star::read(istream& X) {
    FilledShape::read(X);
    X >> xc >> yc >> rc;
    if (X.fail() || rc <= 0.0) throw ios_base::failure("invalid star parameters");
}

/// Leh um retangulo de uma stream.
/// Leh cor, largura do contorno e se eh preenchida (usando FilledShape::read)
/// e depois os limites.
/* Feito pelo aluno em 11 de junho de 2026 */
void Rectangle::read(istream& X) {
    FilledShape::read(X);
    X >> xmin >> xmax >> ymin >> ymax;
    if (X.fail()) throw ios_base::failure("invalid rectangle parameters");
    if (xmin > xmax) swap(xmin, xmax);
    if (ymin > ymax) swap(ymin, ymax);
}

/// Leh um losango de uma stream.
/// Leh cor, largura do contorno e se eh preenchida (usando FilledShape::read)
/// e depois os limites.
/* Feito pelo aluno em 11 de junho de 2026 */
void Rombo::read(istream& X) {
    FilledShape::read(X);
    X >> xmin >> xmax >> ymin >> ymax;
    if (X.fail()) throw ios_base::failure("invalid rhombus parameters");
    if (xmin > xmax) swap(xmin, xmax);
    if (ymin > ymax) swap(ymin, ymax);
}

/// Leh um triangulo de uma stream.
/// Leh cor, largura do contorno e se eh preenchida (usando FilledShape::read)
/// e depois os 3 pontos.
/* Feito pelo aluno em 11 de junho de 2026 */
void Triangle::read(istream& X) {
    FilledShape::read(X);
    X >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (X.fail()) throw ios_base::failure("invalid triangle parameters");
}

///
/// SALVAMENTO DAS FIGURAS
///

/// Faz os passos comuns para salvar qualquer forma.
/// Salva cor e largura da linha.
void Shape::save(ostream& X) const
{
  X << " stroke=" << '"' << "rgb("
    << r << ',' << g << ',' << b << ')' << '"';
  X << " stroke-width=" << '"' << width << '"';
}

/// Faz os passos comuns para salvar qualquer forma preenchivel.
/// Usa Shape::save e depois salva cor do preenchimento.
void FilledShape::save(ostream& X) const
{
  Shape::save(X);
  X << " fill=" << '"';
  if (filled)
  {
    X << "rgb(" << r << ',' << g << ',' << b << ')';
  }
  else
  {
    X << "transparent";
  }
  X << '"';
}

/// Salva uma linha.
/// Salva o inicio "<line" e os parametros do elemento;
/// depois, salva os parametros de estilo, usando Shape::save;
/// depois, salva o final "/>" do elemento.
/* Feito pelo aluno em 11 de junho de 2026 */
void Line::save(ostream& X) const {
    X << "<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\"";
    Shape::save(X);
    X << " />";
}

/// Salva um circulo.
/// Salva o inicio "<circle" e os parametros do elemento;
/// depois, salva os parametros de estilo, usando FilledShape::save;
/// depois, salva o final "/>" do elemento.
/* Feito pelo aluno em 11 de junho de 2026 */
void Circle::save(ostream& X) const {
    X << "<circle cx=\"" << xc << "\" cy=\"" << yc << "\" r=\"" << rc << "\"";
    FilledShape::save(X);
    X << " />";
}

/// Salva um retangulo
/// Salva o inicio "<rect" e os parametros do elemento;
/// depois, salva os parametros de estilo, usando FilledShape::save;
/// depois, salva o final "/>" do elemento.
/* Feito pelo aluno em 11 de junho de 2026 */
void Rectangle::save(ostream& X) const {
    X << "<rect x=\"" << xmin << "\" y=\"" << ymin << "\" width=\"" << (xmax - xmin) << "\" height=\"" << (ymax - ymin) << "\"";
    FilledShape::save(X);
    X << " />";
}

/// Salva um triangulo
/// Salva o inicio "<polygon" e os parametros (3 pontos) do elemento;
/// depois, salva os parametros de estilo, usando FilledShape::save;
/// depois, salva o final "/>" do elemento.
/* Feito pelo aluno em 11 de junho de 2026 */
void Triangle::save(ostream& X) const {
    X << "<polygon points=\"" << x1 << "," << y1 << " " << x2 << "," << y2 << " " << x3 << "," << y3 << "\"";
    FilledShape::save(X);
    X << " />";
}

/// Salva um losango
/// Salva o inicio "<polygon" e os parametros (4 pontos) do elemento;
/// depois, salva os parametros de estilo, usando FilledShape::save;
/// depois, salva o final "/>" do elemento.
/* Feito pelo aluno em 11 de junho de 2026 */
void Rombo::save(ostream& X) const {
    double xmed = (xmin + xmax) / 2.0;
    double ymed = (ymin + ymax) / 2.0;
    X << "<polygon points=\"" << xmed << "," << ymin << " " << xmax << "," << ymed << " "
      << xmed << "," << ymax << " " << xmin << "," << ymed << "\"";
    FilledShape::save(X);
    X << " />";
}

/// Salva uma estrela
/// Salva o inicio "<polygon" e os parametros (10 pontos) do elemento;
/// depois, salva os parametros de estilo, usando FilledShape::save;
/// depois, salva o final "/>" do elemento.
/* Feito pelo aluno em 11 de junho de 2026 */
void Star::save(ostream& X) const {
    X << "<polygon points=\"";
    for (int i = 0; i < 10; i++) {
        double theta = MEU_PI * (i / 5.0 + 0.5);
        double rp = (i % 2 == 0) ? rc : rc / 2.5;
        double xp = xc + rp * cos(theta);
        double yp = yc - rp * sin(theta);
        X << xp << "," << yp;
        if (i < 9) X << " ";
    }
    X << "\"";
    FilledShape::save(X);
    X << " />";
}
