// Bibliotecas nativas do C
#include <stdio.h>
#include <stdbool.h>

// Bibliotecas da ALLEGRO 5
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>

// Bibliotecas do projeto
#include "funcoes/funcoes_basicas.h"

ALLEGRO_DISPLAY* window = NULL;
ALLEGRO_EVENT_QUEUE* fila_eventos = NULL;
ALLEGRO_TIMER* timer = NULL;
ALLEGRO_BITMAP* folha_sprites = NULL;
ALLEGRO_BITMAP* fundo = NULL;

void variaveisBoneco(tSprite* boneco);

int main(void) {

    int desenha = 1;
    bool sair = false;

    tSprite boneco;

    variaveisBoneco(&boneco);
    if( !inicializar(&window, &timer, &fila_eventos, &folha_sprites, &fundo) ) {
        return -1;
    };
    

    while(!sair) {
        ALLEGRO_EVENT evento;
        al_wait_for_event(fila_eventos, &evento);

        /*- EVENTOS -*/
        if(evento.type == ALLEGRO_EVENT_TIMER) {

            // A cada disparo do timer o contador de frames incrementa
            boneco.cont_frames++;

            // Se alcancar a quantidade de frames necessaria pra mudar o sprite
            if(boneco.cont_frames >= boneco.frames_sprite) {

                // Reseta o contador de frames e incrementa a coluna 
                // atual da folha pra mostrar o proximo sprite
                boneco.cont_frames = 0;
                boneco.coluna_atual++;

                // Se chegou na ultima coluna da folha de sprites
                if( boneco.coluna_atual >= boneco.colunas_folha) {
                    // Coluna inicial
                    boneco.coluna_atual = 0;

                    //incrementa a linha, se passar da ultima, volta pra primeira
                    boneco.linha_atual = (boneco.linha_atual+1) % boneco.linhas_folha;
                    
                    //calcula a posicao Y da folha que sera mostrada
                    boneco.regiao_y_folha = boneco.linha_atual * boneco.altura_sprite;
                }
                //calcula a regiao X da folha que sera mostrada
                boneco.regiao_x_folha = boneco.coluna_atual * boneco.largura_sprite;
            }
                // Verifica se o sprite ta perto das bordas X da tela
                if( boneco.pos_x_sprite > LARGURA_TELA - 150 || boneco.pos_x_sprite < 20) {
                    // Inverte o sentido da velocidade X pra andar ao contrario
                    boneco.vel_x_sprite = -boneco.vel_x_sprite;
                }

                //atualiza as posicoes X Y do sprite de acordo com a velocidade, positiva ou negativa
                boneco.pos_x_sprite += boneco.vel_x_sprite;
                boneco.pos_y_sprite += boneco.vel_y_sprite;

                desenha = 1;
            }
            else if( evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE ) {
                sair = true;
            }

            /* -- ATUALIZA TELA -- */
            if( desenha ) {

                al_draw_bitmap_region(fundo,0,0,LARGURA_TELA,ALTURA_TELA,0,0,0);

                // Movendo para a direita, positivo
                if(boneco.vel_x_sprite > 0) {
                    al_draw_bitmap_region(folha_sprites, 
                        boneco.regiao_x_folha, 
                        boneco.regiao_y_folha,
                        boneco.largura_sprite,
                        boneco.altura_sprite,
                        boneco.pos_x_sprite,
                        boneco.pos_y_sprite,0);
                }
                else {
                    al_draw_scaled_bitmap(folha_sprites, 
                        boneco.regiao_x_folha, 
                        boneco.regiao_y_folha,
                        boneco.largura_sprite,
                        boneco.altura_sprite,
                        boneco.pos_x_sprite + boneco.largura_sprite,
                        boneco.pos_y_sprite,
                        -boneco.largura_sprite,
                        boneco.altura_sprite,0
                        );
                }
                al_flip_display();
                desenha = 0;
            }

        }

    al_destroy_display(window);
    al_destroy_event_queue(fila_eventos);
    al_destroy_timer(timer);
    al_destroy_bitmap(folha_sprites);
    al_destroy_bitmap(fundo);   
   
   return 0;  
}


void variaveisBoneco(tSprite* boneco) {

    // largura e altura de cada sprite dentro da folha
    boneco->altura_sprite=140, boneco->largura_sprite=108;
    // quantos sprites tem em cada linha da folha, e a atualmente mostrada
    boneco->colunas_folha=4, boneco->coluna_atual=0;
    // quantos sprites tem em cada coluna da folha, e a atualmente mostrada
    boneco->linha_atual=0, boneco->linhas_folha=2;
    // posicoes X e Y da folha de sprites que serao mostradas na tela
    boneco->regiao_x_folha=0, boneco->regiao_y_folha=0;
    // quantos frames devem se passar para atualizar para o proximo sprite
    boneco->frames_sprite=4, boneco->cont_frames=0;
    // posicao X Y da janela em que sera mostrado o sprite
    boneco->pos_x_sprite=50, boneco->pos_y_sprite=150;
    // velocidade X Y que o sprite ira se mover pela janela
    boneco->vel_x_sprite=10, boneco->vel_y_sprite=0;

}