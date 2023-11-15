#include <iostream>

using namespace std;
char board[500][500];
char equiv[28];
int width,height;
int chang;
char ini,fin;
int main(int argc, char** argv) {
    while(cin>>height>>width&&height){
        for(int i=0;i<height;++i){
            for(int j=0;j<width;++j){
                cin>>board[i][j];
            }
        }
        for(int i=0;i<27;++i){
            equiv[i]='A'+i;
        }
        cin>>chang;
        for(int i=0;i<chang;++i){
            cin>>ini>>fin;
            for(int j=0;j<27;++j){
                if(equiv[j]==ini) equiv[j]=fin;
            }
        }
        for(int i=0;i<height;++i){
            for(int j=0;j<width;++j){
                cout<<equiv[board[i][j]-'A'];
            }
            cout<<"\n";
        }
    }
    return 0;
}
