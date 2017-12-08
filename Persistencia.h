#pragma once
#include<stdio.h>	
#include<iostream>
#include<string>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
class Persistencia
{
public:

	static vector<vector<int>> retorna_grafo(int& dim) {
		dim = 0;
		fstream arquivo;
		arquivo.open("ExemploRedeFluxo.txt");
		if (arquivo.is_open()) {
			int x;
			int tamanho_matriz;
			arquivo >> tamanho_matriz;
			dim = tamanho_matriz;
			vector<vector<int>> matriz;
			
			for (int i = 0; i < tamanho_matriz; i++) {
				vector<int> linha;
				for (int j = 0; j < tamanho_matriz; j++) {
					arquivo >> x;
					linha.push_back(x);
					cout << x << " ";
				}
				matriz.push_back(linha);
				cout << endl;
			}
			return matriz;
		}
		return *new vector<vector<int>>;
	}


	Persistencia();
	~Persistencia();
};

