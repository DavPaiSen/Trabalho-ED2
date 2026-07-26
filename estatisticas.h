#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include "grafos.h"
#include "profundidade.h"

int conexo(Grafo* g);

void grauDosVertices(Grafo* g);

int direcionado(Grafo* g);

int temCiclo(Grafo* g);

#endif