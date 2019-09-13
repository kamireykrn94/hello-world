#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;
//inicio das classes
class downlaod{
    private:
        string _resultado;
    public:
        //organizar e inicio do download 
        void insert(string _link1, string downresu){
            _resultado="youtube-dl -u victorunreal -p skysound --all-subs "+downresu+"-o '/tmp/youtube-dl/%(title)s.%(ext)s' "+_link1;
            system(_resultado.c_str());
        }
        //criar nova pasta no /tmp
        void newdirtmp(){
            system("mkdir /tmp/youtube-dl");
        }
        //copiar arquivos do tmp para pasta no cruy
        void cparquivos(){
            system("cp /tmp/youtube-dl/*.mp4 $HOME/Downloads/");
            system("cp /tmp/youtube-dl/*ptBR.ass $HOME/Downloads/");
        }
        //remover os arquivos da pasta tmp
        void rmtmp(){
            system("rm -r /tmp/youtube-dl/");
        }
        void downfilas(string resolucao){
            _resultado="youtube-dl -u victorunreal -p skysound --all-subs -a /tmp/youtube-dl/fila.txt "+resolucao+"-o '/tmp/youtube-dl/%(title)s.%(ext)s'";
            system(_resultado.c_str());
        }
};
class menus{
    public:
        int opi=0, opiresu;
        string _link;
        string resul;
        void menuprincipal(){
            system("clear");
            cout<<"--------------------------------------"<<endl;
            cout<<"        DOWNLOAD CRUNCHYROLL"<<endl;
            cout<<"--------------------------------------"<<endl<<endl;
            cout<<"1 - Download CRUNCHYROLL"<<endl;
            cout<<"2 - Download CRUNCHYROLL via fila"<<endl;
            cout<<"3 - Download CRUNCHYROLL so legenda"<<endl;
            cout<<"4 - Terminar programa"<<endl<<endl<<"Opição: ";
            cin>>opi;
        }
        void menuqualidade(){
            system("clear");
            cout<<"FAZENDO DOWNLOAD DO VIDEO"<<endl<<endl<<"Informe a url da CRUNCHYROLL: ";
            cin>>_link;
            cout<<"--------------------------------------"<<endl;
            cout<<"       Escolha resolução"<<endl;
            cout<<"--------------------------------------"<<endl;
            cout<<"1 - 480p"<<endl<<"2 - 720p"<<endl<<"3 - 1080p"<<endl<<endl<<"opição: ";
            cin>>opiresu;
            switch (opiresu){
                case 1:
                    resul="-f 'best[height <= 480]' ";
                    break;
                case 2:
                    resul="-f 'best[height <= 720]' ";
                    break;
                case 3:
                    resul="-f 'best[height <= 1080]' ";
                    break;
                default:
                    break;
            }
        }
};
// fim das classes
// download unico arquivo
int downsimplis(){
    //classe
    downlaod down;
    menus menu2;
    //menu    
    menu2.menuqualidade();
    //inicio do download
    down.newdirtmp();
    down.insert(menu2._link, menu2.resul);
    down.cparquivos();
    down.rmtmp();
    system("clear");  
}
int downfila(){
    int i=0, count=100, valormtx=0, contador;
    downlaod down2;
    menus menu3;
    string fila2;
    ofstream filadown;
    system("mkdir /tmp/youtube-dl");
    filadown.open("/tmp/youtube-dl/fila.txt");

    for ( i = 0; i<count; i++){
        menu3.menuqualidade();
        filadown<<menu3._link<<endl;
        fila2=menu3.resul;
        cout<<"1 - continuar adicionar"<<endl<<"2 - Iniciar download"<<endl<<"opição: ";
        cin>>contador;
        if(contador==1){
            valormtx=valormtx+1;
        }else{
            count=i;
        }
       cout<<menu3._link;
    }
    filadown.close();
    down2.newdirtmp();
    down2.downfilas(fila2);
}
//menu
int main(){
    menus menu1;
    do{
        menu1.menuprincipal();
        switch (menu1.opi){
            case 1:
                system("clear");
                downsimplis();
                break;
            case 2:
                system("clear");
                downfila();
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                system("clear");
                cout<<"OPIÇÃO INVALIDA";
                main();
                break;
        }
    }while(menu1.opi!=4);
system("clear");
return 0;
}