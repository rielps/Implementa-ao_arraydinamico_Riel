#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__
#include <stdexcept>  

class arraydinamico {
  private:
    int *lista;
    unsigned int size_, capacity_;
  void increase_capacity(){
      int *newarray = new int[capacity_+100];
      for (int unsigned i = 0; i<size_; i++){
        newarray[i] = lista[i];
      }
      delete [] lista;
      lista = newarray;
      capacity_= capacity_ + 100;
  }
  
public:
  arraydinamico(){ // define os parametros
    size_ = 0;
    capacity_ = 100;
    this->lista = new int[capacity_];
    
      
  }
  ~arraydinamico(){
    delete [] lista; //remove o que está na memoria do array
  }

  unsigned int size(){
    return size_; //retorna a variavel com a quantidade de elementos armazenados na lista
  }

  unsigned int capacity(){
    return capacity_; //quantidade de espaços de memoria que estão dispostos na lista
  }

  double percent_occupied() {
    if (capacity_== 0){
      return 0.0; //se não dá pra armazenar nada na lista, não terá nenhum dado armazenado
    }
    else {
      return (static_cast<double>(size_) / capacity_); //retorna a regra de 3: capacity=1 and size = x -> size/capacity   
        }
  }

  bool insert_at(int index, int value) { //indice a ser digitado, valor a ser alocado no indice
    if (size_==capacity_){ //precisa de espaço para alocar o conteudo pra o ponteiro da frente
      increase_capacity();
    }
    size_++; //aumenta size pra que tenha espaço encaixar o novo numero
    for (int i=size_; i > index; i--){
      lista[i] = lista[i-1]; //move os elementos para direita
      }
      lista[index] = value; //adiciona o numero no index desejado
      return true; //true por ser do tipo boleana
    }
    
  bool remove_at(int unsigned index){
    if (index >= size_){ //verificando se a operação é valida
      return false;
    }
    for (int unsigned i=index; i < size_; i++){
      lista[i] = lista[i+1]; //ovendo os elementos para a direita até que i seja igual ao index
    }
    size_--; //deixando de exibir o ultimo elemento
    return true; //true por ser booleana
  }

  void push_back(int value){
    if (this->size_ == this-> capacity_){
      increase_capacity(); //verifica a possibilidade de inserir um elemento, caso size = capacity, aumenta a capacidade
    }
    this->lista[size_++] = value; //adiciona o valor no ultimo indice
  }

  void push_front(int unsigned value){
    if(size_==capacity_){ //verifica a possibilidade de inserir um elemento, caso size = capacity, aumenta a capacidade
      increase_capacity();
    }
    size_++; //adiciona 1 a quantidade de elementos
    for (int unsigned i=0; i<size_-1; i++){
      lista[i + 1] = lista[i]; //move todos os elementos para a direita
      
    }
    lista[0] = value; //adiciona o elemento no primeiro indice da lista

  }

  int get_at(int unsigned index){
    if (index >= size_){ //se o indice não for valido, retorna -1
      return -1;
    }
    return lista[index]; //retorna lista na posição do index pedido
   }

  bool pop_back(){
    if (size_==0){
      return false;
    }
    size_--; //"esconde" o ultimo elemento
    return true;

    
  }
  
  bool pop_front(){
    remove_at(0); //chama a funçao remove_at pra remover o primeiro elemento
    return true;
  }

      
      
      
int back(){
  if (size_ == 0) {
    return -1;
  } 
  return lista[size_-1]; // retorna o ultimo elemento da lista
  }
    


  int front(){
  if (size_ == 0){
    return -1;
  }
  return lista[0]; //retorna o primeiro elemento da lista
  } 

  
bool remove(int value){
  int ind;
  for (int unsigned i=0; i <= size_-1; i++){
    if (value==lista[i]){ // verifica se o elemento estiver na lista, se estiver:
      ind = lista[i-1]; 
      remove_at(ind); // remove ele
    }
  }
    return true;
  }  
// Remove value do vetor caso esteja presente

  int find(int value) {
    for (unsigned int i = 0; i < size_; i++) {
      if (lista[i] == value) {
          return i; // Retornar o índice do valor encontrado
          break;
        }
    }
    return -1; // Retornar -1 se o valor não for encontrado
  }

 




int count(int value) {
  int qtd = 0;
  for (int unsigned i=0; i<=size_; i++){
    if (value==lista[i]){ //conta quantas vezes value está presente na lista
      qtd++; //atribue a essa variavel
    }
  }
   return qtd;
  } // Retorna quantas vezes value occorre no vetor

  int sum() {
    int soma = 0;
    for (int unsigned i=0; i<size_; i++) {
      soma = soma + lista[i];  // soma todos os elementos e atribue a variavel soma
    }
  return soma; //retorna soma
  



  //void push_front(int value) {
    
   // Adiciona um elemento no ``início'' do vetor
  // Remove elemento do índice index
  }
 };
#endif 