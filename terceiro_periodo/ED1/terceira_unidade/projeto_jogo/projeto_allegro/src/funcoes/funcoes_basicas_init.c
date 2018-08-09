// Bibliotecas da ALLEGRO 5
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

#include <string.h>

#include "funcoes_basicas_init.h"

// Macros


void error_msg(char* text, ALLEGRO_DISPLAY* window) {
    al_show_native_message_box(window, "ERRO",
        "Ocorreu o seguinte erro e o programa será finalizado:",
        text, NULL, ALLEGRO_MESSAGEBOX_ERROR);
}    

bool inicializarSprite(ALLEGRO_DISPLAY** window, 
                 ALLEGRO_TIMER** timer,
                 ALLEGRO_EVENT_QUEUE** fila_eventos,
                 ALLEGRO_BITMAP** folha_sprites,
                 ALLEGRO_BITMAP** fundo
                )
{
    if( !al_init() ) {
        error_msg("Falha ao inicializar a Allegro!", *window);
        return false;
    }

    if( !al_init_image_addon() ) {
        error_msg("Falha ao inicializar o addon de imagens!", *window);
        return false;
    }

    *timer = al_create_timer(1.0/FPS);
    if(!*timer) {
        error_msg("Erro ao criar o timer!", *window);
        return false;
    }

    *window = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if(!*window) {
        error_msg("Erro ao inicializar a janela", *window);
        al_destroy_timer(*timer);
        return false;
    }

    al_set_window_title(*window, "Testanto sprite");

    *fila_eventos = al_create_event_queue();
    if(!*fila_eventos) {
        error_msg("Falha ao criar fila de eventos", *window);
        al_destroy_timer(*timer);
        al_destroy_display(*window);
        return false;
    }


    // Carrega a folha de sprites na variavel
    *folha_sprites = al_load_bitmap("/home/jglord/eclipse-workspace/UfersaEstudos/Ufersa/src/UfersaCC/terceiro_periodo/ED1/terceira_unidade/projeto_jogo/projeto_allegro/imagens/run2Teste.bmp");
    if(!folha_sprites) {
        error_msg("Falha ao criar folha de sprite", *window);
        al_destroy_timer(*timer);
        al_destroy_display(*window);
        al_destroy_event_queue(*fila_eventos);
        return false;
    }

    al_convert_mask_to_alpha(*folha_sprites, al_map_rgb(255, 0, 255));

    
    //carrega o fundo
    *fundo = al_load_bitmap("/home/jglord/eclipse-workspace/UfersaEstudos/Ufersa/src/UfersaCC/terceiro_periodo/ED1/terceira_unidade/projeto_jogo/projeto_allegro/imagens/backgroundTeste.png");
    if (!fundo){
        error_msg("Falha ao carregar fundo", *window);
        al_destroy_timer(*timer);
        al_destroy_display(*window);
        al_destroy_event_queue(*fila_eventos);
        al_destroy_bitmap(*folha_sprites);
        return 0;
    }

    al_register_event_source(*fila_eventos, al_get_display_event_source(*window));
    al_register_event_source(*fila_eventos, al_get_timer_event_source(*timer));
    al_start_timer(*timer);

    return true;
}

bool inicializarWindow(ALLEGRO_DISPLAY** window) {

    if(!al_init()) {
        error_msg("Erro ao inicializar a allegro5", *window);
        return false;
    }

    if(!al_init_image_addon()) {
        error_msg("Erro ao inicializar addon de image", *window);
        return false;
    }

    *window = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if(!*window) {
        error_msg("Falha ao inicializar window", *window);
        return false;
    }

    

    return true;
}

// Carrega imagem posicionada em algum ponto da tela
bool carregarImgP(ALLEGRO_DISPLAY** window, ALLEGRO_BITMAP** img,char* file, float px, float py) {

    // Carrega o bitmap em *img
    *img = al_load_bitmap(file);
    if(!*img) {
        error_msg("Erro ao carregar a imagem!", *window);
        al_destroy_display(*window);
        return false;
    }

    al_convert_mask_to_alpha(*img, al_map_rgb(255, 0, 255));
    
    // Posiciona na tela no local esperado
    al_draw_bitmap(*img, px, py, 0);

    return true;

}