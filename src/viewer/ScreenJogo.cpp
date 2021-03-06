#include "../../include/ScreenJogo.hpp"
#include "../../include/Config.hpp"
#include "../../include/MusicManager.hpp"
#include "../../include/TextureManager.hpp"

ScreenJogo::ScreenJogo( GameRef& gameRef )
    : Screen( gameRef ) {
    loadAssets();
}

void ScreenJogo::loadAssets() {
    TextureManager::add( "backgroundJogo", "jogo.jpg" );
    background.setTexture( TextureManager::get( "backgroundJogo" ) );

    TextureManager::add( "barraModelo", "barra_model.png" );
    barModel.setTexture( TextureManager::get( "barraModelo" ) );

    MusicManager::add( "musicJogar", "background.ogg" );
    music = &MusicManager::get( "musicJogar" );
}
void ScreenJogo::draw() {
    barModel.setPosition(640, 30);

    window->clear();

    window->draw( background );

    window->draw( barModel );

    window->display();
}
void ScreenJogo::update() {
    if( *isAudioOn && music->getStatus() != sf::SoundSource::Status::Playing ) {
        music->play();
    }

    while( window->pollEvent( *event ) ) {
        if( event->type == sf::Event::Closed ) {
            music->stop();
            window->close();
        }
    }

    draw();
}
