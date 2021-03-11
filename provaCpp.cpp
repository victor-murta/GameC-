#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h> //usleep; é em Microsegundos

using namespace std;


void mostraDados(int jogador[2], string armas[1]){
  cout << endl;
  cout << "---- Dados Jogador ---- " << endl;
  cout << "Vida: " << jogador[0] << endl;
  cout << "Ataque: " << jogador[1] << endl;
  cout << "Ama: " << armas[1] << endl;
  cout << endl;
}

void mostrarAdversarios(int ad[2]){
  
  cout << endl ;
  cout << "---- Adversarios ----" << endl;
  cout << "Vida: " << ad[0] << " / Ataque: " << ad[1] + 10 << endl;
  cout << "Arma: Machado" << endl;
  cout << endl;
}

void escolhaArmas(int Jogador[2] ,string choose_weapon){
  string arma_jogador[1];

	if (choose_weapon == "espada"){
		cout << endl ;
		cout << "Jogador selecionou a Espada ..." << endl;
		string arma_jogador[1] = {"Espada"};
    Jogador[1] += 15;
	}
	
  else if(choose_weapon == "escudo"){
    cout << "Jogador selecionou o Escudo ..." << endl;
    string arma_jogador[1] = {"Escudo"};
    Jogador[0] += 25;
  }

	else if(choose_weapon == "lanca"){
		cout << "Jogador selecionou a Lanca ..." << endl;
		string arma_jogador[1] = {"Lanca"};
		Jogador[1] += 10;
	}
		
	else if( choose_weapon == "machado"){
		cout << "Jogador selecionou o Machado ..." << endl;
		string arma_jogador[1] = {"Machado"};
		Jogador[1] += 25; 
    
	}
	
	else if (choose_weapon == "arco"){
		cout << "Jogador selecionou o Arco ..." << endl;
		string arma_jogador[1] = {"Arco"};
		Jogador[1] += 7;
    
	}
	else{
		cout << "Voce ficou sem armas..." << endl;
		string arma_jogador[1] = {"Punho"};
    Jogador[1] += 5;

	}
 usleep(2000000);
}


void desenvolvimentoDoJogo1(int jogador[2], int adversario[2],string arma_j[1]){
  while (jogador[0] >= 0 || adversario[1] >= 0){
    if (jogador[0] <= 0 || adversario[0] <= 0){
        break;
      }
      
    
    string escolhaAD = " ";
    int defenda_j = 0;
    int defenda_a = 0;
    int vez = 0;
    for (vez = 0; vez <= 150; vez++){
      if (jogador[0] <= 0){
        cout << "Voce PERDEU ... Game Over" << endl;
        break;
      }
      if (adversario[0] <= 0){
        cout << "Jogador ZEROU o jogo ..." << endl;
        
        break;
      }
      
      cout << "  ---- Partida FINAL ----" << endl;
      mostraDados(jogador, arma_j);
      mostrarAdversarios(adversario);
      
      if (vez % 2 != 0){
        //Vez do adversário
        //Escolha do adversário se vai atacar ou defender
        string escolhaAdversario[] = {"Atacar", "Defender"};
        srand(time(NULL));
        int r = rand()%2;
        cout << "---- Escolha ----" << endl;
        cout << "- Vez do adversario ... " << endl;
        cout << "- Adversario escolheu " << escolhaAdversario[r] << " ..." << endl;
        usleep(2000000);
        if (defenda_j == 1){
          jogador[0] = jogador[0] + 10 - adversario[1] ;
          defenda_j = 0;
        }
        if (escolhaAdversario[r] == "Atacar") {
          jogador[0] -= adversario[1];
        }
        else{

        }
          
      }
      else if (vez % 2 == 0){
        //Vez do jogador
        cout << "---- Escolha ----" << endl;
        cout << "- Atacar" << endl;
        cout << "- Defender" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolhaAD;

        if (escolhaAD == "atacar"){
          if (defenda_a == 1){
            cout << "Defesas do adversario " << defenda_a << endl;
            adversario[0] += 10 - jogador[1];
          }

          cout << "Atacando ..." << endl;
          adversario[0] -= jogador[1];
        }
        else if (escolhaAD == "defender"){
          cout << "Defendendo ..." << endl;
          defenda_j += 1;
        }
      }
      usleep(2000000);
      system("clear");
    }
  }}

void desenvolvimentoDoJogo(int jogador[2], int adversario[2],string arma_j[1]){
  
  while (jogador[0] != 0 || adversario[1] != 0){
    if (jogador[0] <= 0){
        break;
        
      }
      if (adversario[0] <= 0){
        break;
      }
    
    string escolhaAD = " ";
    int ctPartida = 1;
    int defenda_j = 0;
    int defenda_a = 0;
    int vez = 0;
    for (vez = 0; vez <= 150; vez++){
      if (jogador[0] <= 0){
        cout << "Voce PERDEU ... Game Over" << endl;
        break;
      }
      if (adversario[0] <= 0){
        cout << "Jogador VENCEU a partida ..." << endl;
        ctPartida += 1;
        int Org[2] = {200, 30};
        desenvolvimentoDoJogo1(jogador, Org, arma_j);
        break;
        usleep(200000);
        system("clear");
      }
      
      cout << "  ---- Partida " << ctPartida << " ----" << endl;
      mostraDados(jogador, arma_j);
      mostrarAdversarios(adversario);
      
      if (vez % 2 != 0){
        //Vez do adversário
        //Escolha do adversário se vai atacar ou defender
        string escolhaAdversario[] = {"Atacar", "Defender"};
        srand(time(NULL));
        int r = rand()%2;
        cout << "---- Escolha ----" << endl;
        cout << "- Vez do adversario ... " << endl;
        cout << "- Adversario escolheu " << escolhaAdversario[r] << " ..." << endl;
        usleep(2000000);
        if (defenda_j == 1){
          jogador[0] =  jogador[0] + 10 - adversario[1] ;
          defenda_j = 0;
        }
        if (escolhaAdversario[r] == "Atacar") {
          jogador[0] -= adversario[1];
        }
        else{

        }
          
      }
      else if (vez % 2 == 0){
        //Vez do jogador
        cout << "---- Escolha ----" << endl;
        cout << "- Atacar" << endl;
        cout << "- Defender" << endl;
        cout << "Escolha uma opcao: ";
        cin >> escolhaAD;

        if (escolhaAD == "atacar"){
          if (defenda_a == 1){
            cout << "Defesas do adversario " << defenda_a << endl;
            adversario[0] =jogador[0] + 10 - jogador[1];
          }

          cout << "Atacando ..." << endl;
          adversario[0] -= jogador[1];
        }
        else if (escolhaAD == "defender"){
          cout << "Defendendo ..." << endl;
          defenda_j += 1;
        }
      }
      usleep(2000000);
      system("clear");
    }
  }}



int main(int arv, char *argv[]){
	int Jogador[2];
	char arma_jogador[1];

	//tipos de classes
	int Org[2] = {200, 30};
	int Zumbi[2] = {50,10};
	int Humano[2] = {100 ,25};	
	int Anao[2] = {120, 25};
		
	printf(
		"----Classes----\n"
		"-Org\n"
		"-Zumbi\n"
		"-Humano\n"
		"-Anao\n"	
	);
	
	string escolha = " ";
	cout << "Escolha uma opcao: ";
	cin >> escolha;
	
	if (escolha == "org"){
		int Jogador[] = {200, 30};
		cout << endl ;
		cout << "Jogador selecionou Org " << endl;
		cout << "Org ";
		cout <<"Ataque: " <<Jogador[1] <<" / Vida: "<< Jogador[0] << endl;
		cout << endl ;

    printf(
		"---- Armas ----\n"
		"-Espada\n"
		"-Lanca\n"
		"-Escudo\n"
		"-Machado\n" 
		"-Arco\n"
	  );
    string choose_weapon ;
    string arma_jogador[1];
    cout << "Escolha uma arma: ";
    cin >> choose_weapon;
    escolhaArmas(Jogador ,choose_weapon);
    
    system("clear");
    desenvolvimentoDoJogo(Jogador, Anao, arma_jogador);

    
	
		
	}else if ( escolha == "zumbi"){
		int Jogador[] = {50, 10};
		cout << endl ;
		cout << "Jogador selecionou zumbi" << endl;
		cout <<"Ataque: " <<Jogador[1] <<" / Vida: "<<Jogador[0] << endl;
		cout << endl ;

     printf(
		"---- Armas ----\n"
		"-Espada\n"
		"-Lanca\n"
		"-Escudo\n"
		"-Machado\n" 
		"-Arco\n"
    );
    string choose_weapon ;
    string arma_jogador[1];
    cout << "Escolha uma arma: ";
    cin >> choose_weapon;
    escolhaArmas(Jogador, choose_weapon);

    system("clear");
    desenvolvimentoDoJogo(Jogador, Anao, arma_jogador);
		
	}else if ( escolha == "humano"){
		int Jogador[] = {100, 25};
		cout << endl ;
		cout << "Jogador selecionou humano" << endl;
		cout <<"Ataque: " <<Jogador[1] <<" / Vida: "<<Jogador[0] << endl;
		cout << endl ;

    printf(
		"---- Armas ----\n"
		"-Espada\n"
		"-Lanca\n"
		"-Escudo\n"
		"-Machado\n" 
		"-Arco\n"
    );
    string choose_weapon ;
    string arma_jogador[1];
    cout << "Escolha uma arma: ";
    cin >> choose_weapon;
    escolhaArmas(Jogador, choose_weapon);

    system("clear");
    desenvolvimentoDoJogo(Jogador, Anao, arma_jogador);
		
	}else if ( escolha == "anao"){
		int Jogador[] = {120, 25};
		cout << endl ;
		cout << "Jogador selecionou anao" << endl;
		cout <<"Ataque: " <<Jogador[1] <<" / Vida: "<<Jogador[0] << endl;
		cout << endl ;

    printf(
		"---- Armas ----\n"
		"-Espada\n"
		"-Lanca\n"
		"-Escudo\n"
		"-Machado\n" 
		"-Arco\n"
    );
    string choose_weapon ;
    string arma_jogador[1];
    cout << "Escolha uma arma: ";
    cin >> choose_weapon;
    escolhaArmas(Jogador ,choose_weapon);

    system("clear");
    desenvolvimentoDoJogo(Jogador, Anao, arma_jogador);
    		
	}else{
		cout << "Nao entendi";
		cout << endl ;
	}

		
return 0;
}

