#include "catalogo.h"
#include <algorithm>

int Catalogo::operator+=(Filme &other){
    for(Filme &f : filmes){
        if(f == other){
            return -1;
        }
            
    }
    filmes.push_back(other);
    ordenaCatalogo();
    return (*this)(other.titulo);
}

std::vector <int> Catalogo::operator+=(std::vector <Filme> &others){
    std::vector <int> indices;
    for(auto &filme_recebe : others){
        int indice = (*this)(filme_recebe.titulo);
        if(indice == -1){
            (*this)+=filme_recebe;
        }       
    }
    for(auto &filme_recebe : others){
        int indice = (*this)(filme_recebe.titulo);
        indices.push_back(indice);       
    }
    return indices;
}

int Catalogo::operator() (std:: string &nome){
    for(unsigned int indice = 0; indice < filmes.size(); indice++){
        if(filmes.at(indice).titulo == nome){
            return indice;
        }
        
    }
    return -1; //remover warning control reaches end of non-void function
}

void Catalogo::ordenaCatalogo(){
    compFilme comp;
    std::sort(filmes.begin(),filmes.end(),comp);
}

void Catalogo::ordenaCatalogo(std:: vector <Filme> filmes){
    this->filmes.insert(this->filmes.end(), filmes.begin(),filmes.end());
    std::sort(filmes.begin(), filmes.end());

}

int Catalogo::operator-=(std::string &nome){
    unsigned int indice = 0;
    for(; indice < this->filmes.size(); indice++){
        if(filmes.at(indice).titulo == nome){
            filmes.erase(filmes.begin() + indice);
            return indice;
        }
    }
    return -1;
}

int Catalogo::operator() (std::string &nome, std::string nova_produtora){
    for(unsigned int i = 0; i < this->filmes.size(); i++){
        if(this->filmes.at(i).titulo == nome){
            filmes.at(i).produtora = nova_produtora;
            return i;           
        }
    }
    return -1;
    
}

int Catalogo::operator() (std::string &nome, double nova_critica){
    for(unsigned int i = 0; i < this->filmes.size(); i++){
        if(this->filmes.at(i).titulo == nome){
            this->filmes.at(i).critica = nova_critica;
            return i;
        }
    }
    return -1;
}

int Catalogo::editaFilme(std::string nome_filme, std::string novo_nome){
    int indice = (*this)(nome_filme);
    std::string repete_produtora = filmes.at(indice).produtora;
    double repete_critica = filmes.at(indice).critica;
    Filme novo_filme;
    (*this)-=nome_filme;
    novo_filme.titulo = novo_nome;
    novo_filme.produtora = repete_produtora;
    novo_filme.critica = repete_critica;
    (*this)+=novo_filme;
    return (*this)(novo_filme.titulo);

}

int Catalogo::buscaNota(){
    double nota = 0;
    int maxIndice = -1;
    for(unsigned int indice = 0; indice < filmes.size(); indice++){
        if(filmes.at(indice) > nota){
            nota = filmes.at(indice).critica;
            maxIndice = indice;
        }
    }
    std::cout << filmes.at(maxIndice) << std::endl;
    return maxIndice;
}

