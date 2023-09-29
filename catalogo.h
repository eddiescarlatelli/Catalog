#include <iostream>
#include <string>
#include <vector>

struct Filme{
    std::string titulo;
    std::string produtora;
    double critica;
    bool operator< (Filme &other){
        return this->titulo.size() < other.titulo.size();
    }
    bool operator> (Filme &other){
        return this->titulo.size() > other.titulo.size();
    }
    bool operator== (Filme &other){
        return this->titulo == other.titulo;
    }
    friend std::ostream &operator<< (std::ostream &output, Filme &other){
        output << "(" << other.titulo << ";" << other.produtora << ";" << other.critica << ")";
        return output;
    }
    friend std::istream &operator>> (std::istream &input, Filme &other){
        input.ignore();
        getline(input, other.titulo);
        getline(input, other.produtora);
        input >> other.critica;
        return input;

    }
    bool operator>(double nota){
        return critica > nota;
    }
};
struct compFilme{
    bool operator() (Filme &a, Filme &b){
        return a.titulo < b.titulo;
    }
};
class Catalogo{
    public:
        int operator+= (Filme &);
        int operator-= (std::string &);
        int operator() (std::string &);
        std::vector <int> operator+= (std::vector <Filme> &);
        friend std::ostream &operator<< (std::ostream &output, Catalogo &other){
            for(auto &f : other.filmes){
                output << f << std::endl;            
            }
            return output;
        }
        int operator() (std::string &, std::string);
        int operator() (std::string &, double);
        int editaFilme (std::string, std::string);
        int buscaNota();

        
    private:
        std::vector <Filme> filmes;
        int max_filmes;
        void ordenaCatalogo();
        void ordenaCatalogo(std::vector <Filme>);

};