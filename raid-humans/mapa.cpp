#include "mapa.h"
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
using namespace tinyxml2;
using namespace std;
using namespace sf;

mapa:mapa(){}

mapa::~mapa(){}



void mapa::setMapa()(){
    //leemos el tmx
    doc.LoadFile(archivo)
    cout<<"XML leido"<<endl;
    //empezamos a cargar sus params, map es lo 1o que nos encontramos en el xml
    mapa = doc.FirstChildElement("map");

    _tileHeight = 0;
    _tileWidth  = 0;

    //leemos anchura y altura del mapa y los tiles
    mapa->QueryIntAttribute("width",&_width);
    mapa->QueryIntAttribute("height",&_height);
    mapa->QueryIntAttribute("tilewidth",&_tileWidth);
    mapa->QueryIntAttribute("tileheight",&_tileHeight);


    // obtenemos tiles
    imageTileset = mapa->FirstChildElement("tileset");
    ficheroimg   = (string)imageTileset->FirstChildElement("image")->Attribute("source");
    imageTileset->QueryIntAttribute("tilewidth", &_tilesetWidth);
    imageTileset->QueryIntAttribute("tileheight", &_tilesetHeight)

    // obtenemos la imagen del tileset
    imagen = mapa->FirstChildElement("tileset")->FirstChildElement("image");
    imagen->QueryIntAttribute("width",&_imageWidth);
    imagen->QueryIntAttribute("height",&_imageHeight);

    while(imageTileset){
        if(!_tilesetTexture.loadFromFile(ficheroimg)){
        cout<<"No se ha podido cargar la textura"<<endl;
            exit(0);
        }
        _tilesetTexture.loadFromFile(ficheroimg);
    }

    cout<<"Textura leida"<<endl;

    // leemos y obtenemos el numero de capas
    layer = mapa->FirstChildElement("layer");
    _numLayers = 0;
    while(layer){
        _numLayers++;
        layer = layer->NextSiblingElement("layer");
    }
    cout << "Num de capas: " <<_numLayers<<endl;


    // creamos un array de tiles
    filas       = _tilesetTexture.getSize().y/_tileHeight;
    columnas    = _tilesetTexture.getSize().x/_tileWidth;
    posicion    = 0;
    _tilesetSprite = new sf::Sprite[filas*columnas];// +1?
    int t = 0;
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            posicion++;
            _tilesetSprite[posicion].setTexture(_tilesetTexture);
            _tilesetSprite[posicion].setTexture(sf::IntRect(j*_tileWidth,i*_tileHeight,_tileWidth,_tileHeight));//16*j,16*i,16,16
        }
    }
    colisionMap = new bool*[height];
    for(int i = 0; i< height; i++){
        colisionMap[i]=new bool[width];
    }
    int _tilemap[_numLayers][_height][_width];
    //cargamos los GUIDs
    XMLElement *data[_numLayers];
    XMLElement *layer;
    data[0] = mapa->FirstChildElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
    layer = mapa->FirstChildElement("layer");

    for(int l=0,l<_numLayers;l++){
        nombreLayer[l]=(sf::String)layer->Attribute("name");
        for(int y=0;y<_height;y++){
            for(int x=0;x<_width;x++){
                data[l]->QueryIntAttribute("gid",&_tilemap[l][y][x]);
                if(l==_numLayers-1){
                    if(_tileMap[l][y][x]!=0){
                        colisionMap[y][x]=true;
                    }else{
                        colisionMap[y][x]=false;
                    }
                }
                data[l]=data[l]->NextSiblingElement("tile");
            }
        }
        if(data[l]==0){
            data[l+1]=layer->NexrtSiblingElement("layer")->FirstChildElement("data")->FirstChildElement("tile");
        }
    }
//mapa loadSPrite
    //cargamos y resevamos memoria para la matriz 4d
    _tileMapSprite = new sf::Sprite***[_numLayers];
    for(int i=0;i<_numLayers;i++){
        _tileMapSprite[i]=new sf::Sprite**[_height];
    }

    for(int l=0;l<_numLayers;l++){
        for(int y=0;y<_height;y++){
            _tileMapSprite[l][y]=new sf::Sprite*[_width];
            for(int x=0;x<_width;x++){
                _tileMapSprite[l][y][x]=new sf::Sprite();
            }
        }
    }

    //creamos array de sprites

    for(int l=0;l<_numLayers;l++){
        for(int y=0;y<_height;y++){
            for(int x=0;x<_width;x++){
                gid = _tilemap[l][y][x]-1;
                if(gid>=filas*columnas){// if(gid>=_tilesetWidth*_tilesetHeight)?
                    cout<<"Error"<<endl;
                }else if(gid>0){
                    _tileMapSprite[l][y][x]->setTextureRect(_tilesetSprite[gid].getTextureRect());//?
                    _tileMapSprite[l][y][x]=new sf::Sprite(_tilesetTexture,_tilesetSprite[gid].getTextureRect());
                    _tileMapSprite[l][y][x]->setPosition(x*_tileWidth,y*_tileHeight);
                }else{
                    _tileMapSprite[l][y][x]=NULL;
                }
            }
        }
    }
}
void mapa::setActivateLayer(int layer){
    _activeLayer=layer;
}
void mapa::drawMapa(sf::RenderWindow& Window){
    //for(int l=0;l<_numLayers;l++){
        for(int y=0;y<_height;y++){
            for(int x=0;x<_width;x++){
                 if(_tileMapSprite[_activeLayer][x][y]!=NULL){
                    window.draw(*(_tileMapSprite[_activeLayer][x][y]));
                 }
            }
        }
    //}
}
