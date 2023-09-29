#include "catalogo.h"
#include <fstream>

int main(){
    
    Catalogo c;
    int exit = 0;

    std::ofstream arquivo;


 
    while(exit < 8){
        
        std::cout << "Escolha uma opcao" << std::endl;
        std::cout << "1. Inicializar um filme e adiciona-lo no catalogo;" << std::endl;
        std::cout << "2. Insere mais de um filme de uma vez;" << std::endl;
        std::cout << "3. Imprimir o catalogo" << std::endl;
        std::cout << "4. Remove um filme do catalogo;" << std::endl;
        std::cout << "5. Busca um filme no catalogo;" << std::endl;
        std::cout << "6. Edicao dos dados do filme;" << std::endl;
        std::cout << "7. Busca pela maior nota dos filmes;" << std::endl;
        std::cout << "8. Para encerrar" << std::endl;

        std::cin >> exit;
        switch(exit){
            case(1):
                {
                Filme f;
                std::cout << "Insira o filme, produtora e critica atraves da tecla enter" << std::endl;
                std::cin >> f;
                c+=f;
                break;
                } 
            case(2):
                {
                int tamanho;
                std::vector <Filme> filmes_lote;
                std::cout << "Insira a quantidade de filmes a serem inseridos: ";
                std::cin >> tamanho;
                for(int i = 0; i < tamanho; i++){
                    Filme f;
                    std::cout << "Insira o filme, produtora e critica atraves da tecla enter" << std::endl;
                    std::cin >> f;
                    filmes_lote.push_back(f);
                }
                
                c+=filmes_lote;
                break;

                } 
            case(3):
                {
                std::cout << c << std::endl;
                break;
                }
            case(4):
                {
                std::string nome;
                std::cout << "Insira o nome do filme a ser removido: " << std::endl;
                std::cin.ignore();
                getline(std::cin, nome);
                c-=nome;        
                break;
                }
            case(5):
                {
                std::string nome = " ";
                std::cout << "Insira o nome do filme: " << std::endl;
                std::cin.ignore();
                getline(std::cin,nome);
                std::cout << c(nome) << std::endl;
                break;
                }
                
            case(6):
                {
                int opcao = 0;
                while(opcao < 4){
                    std::cout << "1. Para editar o nome do filme" << std::endl;
                    std::cout << "2. Para editar a produtora do filme" << std::endl;
                    std::cout << "3. Para editar a critica do filme" << std::endl;
                    std::cout << "4. Para voltar ao menu principal" << std::endl;
                    std::cin >> opcao;
                    switch(opcao){
                        case(1):
                        {
                            std::string nome_novo = " ";
                            std::string altera_nome = " ";
                            std::cout << "Insira o novo nome do filme: " << std::endl;
                            std::cin.ignore();
                            getline(std::cin, nome_novo);
                            std::cout << "Insira o nome que deseja alterar: " << std::endl;
                            getline(std::cin, altera_nome);
                            std::cout << "Nova posicao: " << c.editaFilme(altera_nome, nome_novo) << std::endl;
                            break;
                        }
                        case(2):
                        {
                            std::string produtora_nova = " ";
                            std::string altera_nome = " ";
                            std::cout << "Insira a nova produtora do filme: " << std::endl;
                            std::cin.ignore();
                            getline(std::cin, produtora_nova);
                            std::cout << "Insira o nome do filme que deseja alterar: " << std::endl;
                            getline(std::cin, altera_nome);
                            c(altera_nome,produtora_nova);
                            break;
                        }
                        case(3):
                        {
                            std::string altera_nome = " ";
                            double critica_nova = 0;
                            std::cout << "Insira a nova nota do filme: " << std::endl;
                            std::cin >> critica_nova;
                            std::cout << "Insira o nome do filme que deseja alterar: " << std::endl;
                            std::cin.ignore();
                            getline(std::cin, altera_nome);
                            c(altera_nome,critica_nova);
                            break;
                        }                        
                    }
                    
                break;   
                }
                break;
                }
            case(7):
            {
                std::cout << "O filme com a maior nota e sua posicao: " << c.buscaNota() << std::endl;
                break;
            }    
        }
    }

    arquivo.open("filmes.txt");
    
    arquivo << c;
    
    arquivo.close();
    return 0;
}
