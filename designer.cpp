#include <iostream>
#include <fstream>
#include <string>
/* ACRESCENTAR SE NECESSARIO */

#include "designer.h"

/// ESTE ARQUIVO PODE RECEBER ACRESCIMOS NAS PARTES INDICADAS.
/// AS PARTES JAH IMPLEMENTADAS NAO PODEM SER SUPRIMIDAS OU MODIFICADAS.

using namespace std;

/// Construtor especifico
Designer::Designer(double Width, double Height):
  width(Width>=0.0 ? Width : 0.0), height(Height>=0.0 ? Height : 0.0), VS()
{}

/// Construtor por copia
/* Feito pelo aluno em 09 de junho de 2026 */
Designer::Designer(const Designer& D) : width(D.width), height(D.height) {
    for (auto S : D.VS) {
        if (S) VS.push_back(S->clone());
    }
}

/// Construtor por movimento
/*  Feito pelo aluno em 09 de junho de 2026  */
Designer::Designer(Designer&& D) noexcept : width(D.width), height(D.height), VS(move(D.VS)) {
    D.width = 0.0;
    D.height = 0.0;
}

/// Atribuicao por copia
Designer& Designer::operator=(const Designer& D)
{
  // Teste de autoatribuicao
  if (this==&D) return *this;

  /*  Feito pelo aluno em 09 de junho de 2026  */
  clear(); 
    width = D.width;
    height = D.height;
    for (auto S : D.VS) {
        if (S) VS.push_back(S->clone());
    }
  return *this;
}

/// Atribuicao por movimento
Designer& Designer::operator=(Designer&& D) noexcept
{
  // Teste de autoatribuicao
  if (this==&D) return *this;

  /*  Feito pelo aluno em 10 de junho de 2026  */
  clear();
    width = D.width;
    height = D.height;
    VS = move(D.VS);
    D.width = 0.0;
    D.height = 0.0;
  return *this;
}

/// Limpa o desenho
void Designer::clear() noexcept
{
  width = height = 0.0;
  /*  Feito pelo aluno em 10 de junho de 2026 */
  for (auto S : VS) delete S; // Libera a memória de cada ponteiro
    VS.clear();                 // Esvazia o vetor
}

/// Inclusao de nova forma no desenho
void Designer::include(const Shape& S)
{
  /* Feito pelo aluno em 12 de junho de 2026 */
  VS.push_back(S.clone());
}

/// Leitura de arquivo com as formas
void Designer::read(const string& fileName)
{
  ifstream arq(fileName);
  if (!arq.is_open())
  {
    string msg = "could not open file "+fileName;
    throw ios_base::failure(msg);
  }

  // Leh o cabecalho
  string texto;
  double W,H;
  arq >> texto >> W >> H;
  if (!arq.good() || texto!="DESIGNER" || W<=0.0 || H<=0.0)
    throw ios_base::failure("invalid file");

  // Cria um novo Designer temporario, inicialmente vazio (sem formas)
  Designer prov(W,H);

  // Laco de leitura das diversas formas do desenho.
  // Permanece ateh o fim do arquivo.
  bool arquivo_acabou = false;
  char tipo_forma;

  do
  {
    // Leh o tipo de forma (char)
    arq >> tipo_forma;
    // Testa se acabou o arquivo
    if (!arq.good())
    {
      arquivo_acabou = true;
      continue;
    }
    tipo_forma = toupper(tipo_forma);

    // Cria dinamicamente (aloca) a nova forma de acordo com o caractere tipo_forma.
    // Se o caractere nao for nenhum dos identificadores de formas,
    // ignora o restante da linha do arquivo
    /* Feito pelo aluno em 12 de junho de 2026 */
    Shape* nova_forma = nullptr;
  switch(tipo_forma) {
    case 'I': nova_forma = new Line(); break; // Verifique qual letra o professor exige para Linha
    case 'C': nova_forma = new Circle(); break;
    case 'R': nova_forma = new Rectangle(); break;
    case 'T': nova_forma = new Triangle(); break;
    case 'L': nova_forma = new Rombo(); break; // L representa o Losango
    case 'S': nova_forma = new Star(); break;
    default:
        string ignorar;
        getline(arq, ignorar);
        break;
}

    // Se a nova forma foi alocada (caractere corresponde a uma das formas):
    // - Leh a forma do arquivo (em um try para capturar as excecoes na leitura)
    // - Acrescenta a forma no vetor de formas do Designer temporario (prov)
    /* Feito pelo aluno em 12 de junho de 2026 */
    if (nova_forma != nullptr) {
    try {
        nova_forma->read(arq);
        prov.VS.push_back(nova_forma);
    } catch (...) {
        delete nova_forma;
        throw;
    }
}
  }
  while(!arquivo_acabou);

  // Testa o numero de formas lidas
  if (prov.getNumShapes() == 0) throw ios_base::failure("empty file");

  // Faz *this assumir o conteudo de prov
  *this = move(prov);
}

/// Salvamento do desenho em formato SVG
void Designer::save(const string& fileName) const
{
  // Nao exporta se o desenho for vazio
  if (getNumShapes()==0 || width<=0 || height<=0) throw logic_error("empty designer");

  // Abre o arquivo SVG para escrita
  ofstream arq(fileName);
  if (!arq.is_open())
  {
    string msg = "could not open file "+fileName;
    throw ios_base::failure(msg);
  }

  // Escreve o cabecalho inicial
  arq << "<svg"
      << " width=" << '"' << width << '"'
      << " height=" << '"' << height << '"'
      << " xmlns=" << '"' << "http://www.w3.org/2000/svg"  << '"'
      << ">\n";

  // Salva as formas
  for (auto S : VS)
  {
    if (S!=nullptr) S->save(arq); // NUNCA deve ser nullptr, mas nao custa garantir
    arq << endl;
  }

  // Escreve o rodapeh final
  arq << "</svg>" << endl;
}
