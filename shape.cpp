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
/* ACRESCENTAR */

/// Leh um circulo de uma stream.
/// Leh cor, largura do contorno e se eh preenchida (usando FilledShape::read)
/// e depois o centro e o raio.
/* ACRESCENTAR */

/// Leh uma estrela de uma stream.
/// Leh cor, largura do contorno e se eh preenchida (usando FilledShape::read)
/// e depois o centro e o raio.
/* ACRESCENTAR */

/// Leh um retangulo de uma stream.
/// Leh cor, largura do contorno e se eh preenchida (usando FilledShape::read)
/// e depois os limites.
/* ACRESCENTAR */

/// Leh um losango de uma stream.
/// Leh cor, largura do contorno e se eh preenchida (usando FilledShape::read)
/// e depois os limites.
/* ACRESCENTAR */

/// Leh um triangulo de uma stream.
/// Leh cor, largura do contorno e se eh preenchida (usando FilledShape::read)
/// e depois os 3 pontos.
/* ACRESCENTAR */

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
/* ACRESCENTAR */

/// Salva um circulo.
/// Salva o inicio "<circle" e os parametros do elemento;
/// depois, salva os parametros de estilo, usando FilledShape::save;
/// depois, salva o final "/>" do elemento.
/* ACRESCENTAR */

/// Salva um retangulo
/// Salva o inicio "<rect" e os parametros do elemento;
/// depois, salva os parametros de estilo, usando FilledShape::save;
/// depois, salva o final "/>" do elemento.
/* ACRESCENTAR */

/// Salva um triangulo
/// Salva o inicio "<polygon" e os parametros (3 pontos) do elemento;
/// depois, salva os parametros de estilo, usando FilledShape::save;
/// depois, salva o final "/>" do elemento.
/* ACRESCENTAR */

/// Salva um losango
/// Salva o inicio "<polygon" e os parametros (4 pontos) do elemento;
/// depois, salva os parametros de estilo, usando FilledShape::save;
/// depois, salva o final "/>" do elemento.
/* ACRESCENTAR */

/// Salva uma estrela
/// Salva o inicio "<polygon" e os parametros (10 pontos) do elemento;
/// depois, salva os parametros de estilo, usando FilledShape::save;
/// depois, salva o final "/>" do elemento.
/* ACRESCENTAR */
